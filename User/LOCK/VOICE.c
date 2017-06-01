
#include "main.h"

void GPIO_INIT_VBusy(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOB, ENABLE);					  											 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;                 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

UINT8 GET_VBusy_State(void)
{
	return(bis(GPIOB,GPIO_Pin_11));//
}

//Ä£ÄâI2C
#define _VOICE_SIMULATE_IIC
#ifdef _VOICE_SIMULATE_IIC

//#define	SCL_USE	    GpioRegs.GPAUSE1.bit.GPA12
//#define	SDA_USE	    GpioRegs.GPAUSE1.bit.GPA13

#define	SCL_1()	    sbi(GPIOB,GPIO_Pin_10)// = 1
#define	SCL_0()	    cbi(GPIOB,GPIO_Pin_10)// = 0

#define	SDA_DAT	    bis(GPIOB,GPIO_Pin_2)//
#define	SDA_1()	    sbi(GPIOB,GPIO_Pin_2)// = 1
#define	SDA_0()	    cbi(GPIOB,GPIO_Pin_2)// = 0

void IIc_init(void)
{
	//SCL_USE=8;
	//SDA_USE=8;

	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOB, ENABLE);					  											 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_10;                 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; 
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void IIC_WR_MODE(void)
{
	//SDA_USE = 8;
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOB, ENABLE);					  											 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;                 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; 
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void IIC_RD_MODE(void)
{
	//SDA_USE = 0;
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOB, ENABLE);					  											 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;                 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);	
}

void IIC_DELAY(void)
{
	int iic_delay;

	for (iic_delay=0; iic_delay < 200; iic_delay++);
}

int SDA_V(void)
{
	return (int)SDA_DAT;
}

void START_CONDITION(void)
{
	IIC_WR_MODE();
	SDA_1();
	SCL_1();
	IIC_DELAY();
	SDA_0();
	IIC_DELAY();
	SCL_0();
	IIC_DELAY();
}

void STOP_CONDITION(void)
{
	IIC_WR_MODE();
	SDA_0();
	SCL_1();
	IIC_DELAY();
	SDA_1();
	IIC_DELAY();
}

void IIC_WRITE_ACK(void)
{
	IIC_WR_MODE();
	SDA_0();
	SCL_0();
	IIC_DELAY();
	SCL_1();
	IIC_DELAY();
	SCL_0();
	IIC_DELAY();
}

int IIC_READ_ACK(void)
{
	int nRet;

	IIC_RD_MODE();
	SCL_0();
	IIC_DELAY();
	SCL_1();
	IIC_DELAY();
	nRet = SDA_V();
	SCL_0();
	IIC_DELAY();
	return nRet;
}

UINT8 IIC_WRITE(UINT8 x)
{
	int iic_iter;

	IIC_WR_MODE();

	for (iic_iter = 0; iic_iter < 8; iic_iter++)
	{
		SCL_0();
		//( ((x) & (1 << (7-iic_iter))) != 0 ) ? SDA_1() : SDA_0();
		if(( ((x) & (1 << (7-iic_iter))) != 0 ))
			 SDA_1();
		else
			 SDA_0();
		IIC_DELAY();
		SCL_1();
		IIC_DELAY();
		SCL_0();
		if (iic_iter == 7)
			break;
		IIC_DELAY();
	}
	return (IIC_READ_ACK() == 0);
}

int IIC_READ(void)
{
	int iic_iter;
	int x = 0;

	IIC_RD_MODE();

	for (iic_iter = 0; iic_iter < 8; iic_iter++)
	{
		SCL_0();
		IIC_DELAY();
		SCL_1();
		IIC_DELAY();
		x += SDA_V();
		x <<= 1;
		SCL_0();
		IIC_DELAY();
	}
	return (x >> 1);
}

int SetIICRegister(UINT32 slvAddr,UINT32 addr,UINT8 data)
{
	BOOL bRet, bRet2;
	int nRetry = 0;

	STOP_CONDITION();
	do
	{
		bRet = TRUE;
		START_CONDITION();
		bRet2 = IIC_WRITE((BYTE)slvAddr); bRet = bRet && bRet2;
		bRet2 = IIC_WRITE((BYTE)addr); bRet = bRet && bRet2;
		bRet2 = IIC_WRITE((BYTE)data); bRet = bRet && bRet2;
		STOP_CONDITION();
		if (bRet)
			break;

		nRetry ++;
	} while(nRetry < 5);
	SDA_0();
	SCL_0();
	return bRet;
}

int GetIICRegister(UINT32 slvAddr,UINT32 addr,UINT8 *data)
{
	BOOL bRet, bRet2;
	int nRetry = 0;

	STOP_CONDITION();
	do
	{
		bRet = TRUE;
		START_CONDITION();
		bRet2 = IIC_WRITE((BYTE)slvAddr); bRet = bRet && bRet2;
		bRet2 = IIC_WRITE((BYTE)addr); bRet = bRet && bRet2;
		//STOP_CONDITION();
		IIC_DELAY();
		START_CONDITION();
		bRet2 = IIC_WRITE((BYTE)(slvAddr + 1)); bRet = bRet && bRet2;
		*data = (BYTE)IIC_READ();
		STOP_CONDITION();
		if (bRet)
			break;

		nRetry ++;
	} while(nRetry < 5);
	SDA_0();
	SCL_0();
	return bRet;
}


#endif 

UINT8 VOICE_IIC_WRITE(UINT8 x)
{
	int iic_iter;

	SCL_1();
	delay_ms(5);
	SCL_0();
	delay_ms(5);
	

	for (iic_iter = 0; iic_iter < 8; iic_iter++)
	{
		SCL_0();
		//if(( ((x) & (1 << (7-iic_iter))) != 0 ))
		if(( ((x) & (1 << (iic_iter))) != 0 ))
			 SDA_1();
		else
			 SDA_0();
		delay_us(300);//IIC_DELAY();
		SCL_1();
		delay_us(300);//IIC_DELAY();
		SCL_0();
		if (iic_iter == 7)
			break;
		delay_us(300);//IIC_DELAY();
	}
	return (0);
}


void VOICE_INIT(void)
{
	GPIO_INIT_VBusy();
	IIc_init();
}

void VOICE_lp_INIT(void)
{
	GPIO_INIT_VBusy();
	IIc_init();
	SDA_0();
	SCL_0();
}

//void VOICE(UINT8 *voice,UINT8 len)
//{
//	UINT8 i;

//	if(len>0)
//		{
//		for(i=0;i<len;i++)
//			{
//			VOICE_IIC_WRITE(voice[i]);
//			while(GET_VBusy_State);
//			}
//		}
//	else
//		VOICE_IIC_WRITE(voice[0]);

//}

void VOICE(UINT8 voice1,UINT8 voice2)
{
	VOICE_IIC_WRITE(voice1);
	if(voice2)
		{
		while(GET_VBusy_State()==0);
		VOICE_IIC_WRITE(voice2);	
		}
}


UINT8 VOICE_test(UINT8 x)
{UINT8 i=0;
	IIc_init();
	while(1)
		{
		VOICE_IIC_WRITE(i);
			i++;
		delay_ms(2000);
		}

}


