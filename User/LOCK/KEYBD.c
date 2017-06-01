
#include "main.h"


//con 录入指纹
//con2 删除指纹
//con2长按 初始化
void GPIO_INIT_DEL(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; //GPIO 定义
	EXTI_InitTypeDef EXTI_InitStructure; //外部中断定义
	NVIC_InitTypeDef NVIC_InitStructure; //嵌套中断定义
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOA, ENABLE);					  											 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;                 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

    //将EXTI0指向PA12  
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA,EXTI_PinSource9);  
    //EXTI0中断线配置  
//    EXTI_InitTypeDef EXTI_InitStructure;  
    EXTI_InitStructure.EXTI_Line=EXTI_Line12;  
    EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;  
    EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;  //按下按键低电平
    EXTI_InitStructure.EXTI_LineCmd=ENABLE;  
    EXTI_Init(&EXTI_InitStructure);  

    //EXTI0中断向量配置  
//    NVIC_InitTypeDef NVIC_InitStructure;  
    NVIC_InitStructure.NVIC_IRQChannel=EXTI4_15_IRQn;  
    NVIC_InitStructure.NVIC_IRQChannelPriority=0x01;  
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;  
    NVIC_Init(&NVIC_InitStructure);  
}
void GPIO_INIT_ADD(void)
{

	GPIO_InitTypeDef GPIO_InitStructure; //GPIO 定义
	EXTI_InitTypeDef EXTI_InitStructure; //外部中断定义
	NVIC_InitTypeDef NVIC_InitStructure; //嵌套中断定义
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOA, ENABLE);					  											 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;                 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

    //将EXTI0指向PA8  
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA,EXTI_PinSource0);  
    //EXTI0中断线配置  
    //EXTI_InitTypeDef EXTI_InitStructure;  
    EXTI_InitStructure.EXTI_Line=EXTI_Line11;  
    EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;  
    EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;  //按下按键低电平
    EXTI_InitStructure.EXTI_LineCmd=ENABLE;  
    EXTI_Init(&EXTI_InitStructure);  

    //EXTI0中断向量配置  
    //NVIC_InitTypeDef NVIC_InitStructure;  
    NVIC_InitStructure.NVIC_IRQChannel=EXTI4_15_IRQn;  
    NVIC_InitStructure.NVIC_IRQChannelPriority=0x01;  
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;  
    NVIC_Init(&NVIC_InitStructure);  
}

void GPIO_INIT_RST(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; //GPIO 定义
	EXTI_InitTypeDef EXTI_InitStructure; //外部中断定义
	NVIC_InitTypeDef NVIC_InitStructure; //嵌套中断定义
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOB, ENABLE);					  											 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;                 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

    //将EXTI0指向PB14
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB,EXTI_PinSource14);  
    //EXTI0中断线配置  
    //EXTI_InitTypeDef EXTI_InitStructure;  
    EXTI_InitStructure.EXTI_Line=EXTI_Line14;  
    EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;  
    EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;  //按下按键低电平
    EXTI_InitStructure.EXTI_LineCmd=ENABLE;  
    EXTI_Init(&EXTI_InitStructure);  

    //EXTI0中断向量配置  
    //NVIC_InitTypeDef NVIC_InitStructure;  
    NVIC_InitStructure.NVIC_IRQChannel=EXTI4_15_IRQn;  
    NVIC_InitStructure.NVIC_IRQChannelPriority=0x01;  
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;  
    NVIC_Init(&NVIC_InitStructure);  


}

void GPIO_INIT_LOGO(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; //GPIO 定义
	EXTI_InitTypeDef EXTI_InitStructure; //外部中断定义
	NVIC_InitTypeDef NVIC_InitStructure; //嵌套中断定义
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOB, ENABLE);					  											 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;                 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

    //将EXTI0指向PB9
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB,EXTI_PinSource9);  
    //EXTI0中断线配置  
    //EXTI_InitTypeDef EXTI_InitStructure;  
    EXTI_InitStructure.EXTI_Line=EXTI_Line9;  
    EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;  
    EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;  //按下按键低电平
    EXTI_InitStructure.EXTI_LineCmd=ENABLE;  
    EXTI_Init(&EXTI_InitStructure);  

    //EXTI0中断向量配置  
    //NVIC_InitTypeDef NVIC_InitStructure;  
    NVIC_InitStructure.NVIC_IRQChannel=EXTI4_15_IRQn;  
    NVIC_InitStructure.NVIC_IRQChannelPriority=0x01;  
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;  
    NVIC_Init(&NVIC_InitStructure);  


}


UINT8 GET_ButtonDEL(void)
{
	return(bis(GPIOA,GPIO_Pin_12));//S2
}

UINT8 GET_ButtonADD(void)
{
	return(bis(GPIOA,GPIO_Pin_11));//S1
}

UINT8 GET_ButtonRST(void)
{
	return(bis(GPIOB,GPIO_Pin_14));
}

//键盘灯
/********************************************
函数：GPIO
功能：gpio配置
参数：无
返回：无
********************************************/
void GPIO_KBDLED(void)
 {	 
		
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOA, ENABLE);																 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;				  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; 
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

 }	



 /********************************************
 函数：Disp_send_Byte
 功能：给595发送一个字节值
 参数：数值
 返回：无
 ********************************************/
// void Disp_send_Byte(unsigned char disp_dat)
// {
//	 unsigned char i;
//	 for(i=0;i<8;i++)
//		 {
//		 D595_DAT_CLK_L;
//		 if(disp_dat & 0x01)
//			 {
//			 D595_DAT_H;
//			 }
//		 else 
//			 D595_DAT_L;
//		 D595_OUT_CLK_L;
//		 disp_dat	>>= 1;
//		 D595_DAT_CLK_H;
//		 D595_OUT_CLK_H;
//		 }
// }

 /********************************************
 函数：Disp_send_Byte
 功能：显示一位数字
 参数：数值
 返回：无
 ********************************************/
 void Disp_KBD(unsigned int dat16)
 {
 	KBLED_H;
//	switch (dat16)
//		{
//		case 1:KBLED_1_H;break;
//		case 2:KBLED_2_H;break;
//		case 3:KBLED_3_H;break;
//		case 4:KBLED_4_H;break;
//		case 5:KBLED_5_H;break;
//		case 6:KBLED_6_H;break;
//		case 7:KBLED_7_H;break;
//		case 8:KBLED_8_H;break;
//		case 9:KBLED_9_H;break;
//		case 10:KBLED_x_H;break;
//		case 11:KBLED_0_H;break;
//		case 12:KBLED_c_H;break;
//		}
 }
  void Disp_KBD_Rst(void)
  {
	 KBLED_L;
  }


 void KEYBD_INIT(void)
 {
//	 GPIO_INIT_DEL();
//	 GPIO_INIT_ADD();
	 GPIO_INIT_RST();
	 GPIO_INIT_LOGO();
	 GPIO_KBDLED();
 }
void KEYBD_lp_INIT(void)
{
	KBLED_H;
}



//TSM12

#define	 TSM12_WAddress 0xD0





/* EOF */

//#define 				TSM12_SCL_H 		sbi(GPIOB,GPIO_Pin_6)
//#define 				TSM12_SCL_L 		cbi(GPIOB,GPIO_Pin_6)
//#define 				TSM12_SDA_H  		sbi(GPIOB,GPIO_Pin_5)
//#define 				TSM12_SDA_L  		cbi(GPIOB,GPIO_Pin_5)
//#define 				TSM12_SDA_I  		bis(GPIOB,GPIO_Pin_5)

void GPIO_INIT_INT_TSM12(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; //GPIO 定义
	EXTI_InitTypeDef EXTI_InitStructure; //外部中断定义
	NVIC_InitTypeDef NVIC_InitStructure; //嵌套中断定义
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOB, ENABLE);					  											 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;                 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

    //将EXTI0指向P
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB,EXTI_PinSource7);  
    //EXTI0中断线配置  
//    EXTI_InitTypeDef EXTI_InitStructure;  
    EXTI_InitStructure.EXTI_Line=EXTI_Line7;  
    EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;  
    EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;  //按下按键低电平
    EXTI_InitStructure.EXTI_LineCmd=ENABLE;  
    EXTI_Init(&EXTI_InitStructure);  

    //EXTI0中断向量配置  
//    NVIC_InitTypeDef NVIC_InitStructure;  
    NVIC_InitStructure.NVIC_IRQChannel=EXTI4_15_IRQn;  
    NVIC_InitStructure.NVIC_IRQChannelPriority=0x01;  
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;  
    NVIC_Init(&NVIC_InitStructure);  
}

void GPIO_INIT_EN_TSM12(void)
 {	 
		
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOB, ENABLE);																 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;			  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; 
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}


//模拟I2C
#define _TSM12_SIMULATE_IIC
#ifdef _TSM12_SIMULATE_IIC

#define	SCL_1_TSM12()	    sbi(GPIOB,GPIO_Pin_6)// = 1
#define	SCL_0_TSM12()	    cbi(GPIOB,GPIO_Pin_6)// = 0

#define	SDA_DAT_TSM12	    bis(GPIOB,GPIO_Pin_5)//
#define	SDA_1_TSM12()	    sbi(GPIOB,GPIO_Pin_5)// = 1
#define	SDA_0_TSM12()	    cbi(GPIOB,GPIO_Pin_5)// = 0


void IIc_init_TSM12(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOB, ENABLE);					  											 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6;                 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; 
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void IIC_WR_MODE_TSM12(void)
{
	//SDA_USE = 8;
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOB, ENABLE);					  											 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;                 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; 
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	sbi(GPIOB,GPIO_Pin_5);
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void IIC_RD_MODE_TSM12(void)
{
	//SDA_USE = 0;
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOB, ENABLE);					  											 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;                 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);	
}

void IIC_DELAY_TSM12(void)
{
	int iic_delay;

	for (iic_delay=0; iic_delay < 200; iic_delay++);
}

int SDA_V_TSM12(void)
{
	return (int)SDA_DAT_TSM12;
}

void START_CONDITION_TSM12(void)
{
	IIC_WR_MODE_TSM12();
	//IIC_DELAY_TSM12();IIC_DELAY_TSM12();
	SDA_1_TSM12();
	SCL_1_TSM12();
	IIC_DELAY_TSM12();
	SDA_0_TSM12();
	IIC_DELAY_TSM12();
	SCL_0_TSM12();
	IIC_DELAY_TSM12();
}

void STOP_CONDITION_TSM12(void)
{
	IIC_WR_MODE_TSM12();
	SDA_0_TSM12();
	SCL_1_TSM12();
	IIC_DELAY_TSM12();
	SDA_1_TSM12();
	IIC_DELAY_TSM12();
}

void IIC_WRITE_ACK_TSM12(void)
{
	IIC_WR_MODE_TSM12();
	SDA_0_TSM12();
	SCL_0_TSM12();
	IIC_DELAY_TSM12();
	SCL_1_TSM12();
	IIC_DELAY_TSM12();
	SCL_0_TSM12();
	IIC_DELAY_TSM12();
}

int IIC_READ_ACK_TSM12(void)
{
	int nRet;

	IIC_RD_MODE_TSM12();
	SCL_0_TSM12();
	IIC_DELAY_TSM12();
	SCL_1_TSM12();
	IIC_DELAY_TSM12();
	nRet = SDA_V_TSM12();
	SCL_0_TSM12();
	IIC_DELAY_TSM12();
	return nRet;
}

UINT8 IIC_WRITE_TSM12(UINT8 x)
{
	int iic_iter;

	IIC_WR_MODE_TSM12();

	for (iic_iter = 0; iic_iter < 8; iic_iter++)
	{
		SCL_0_TSM12();
		//( ((x) & (1 << (7-iic_iter))) != 0 ) ? SDA_1() : SDA_0();
		if(( ((x) & (1 << (7-iic_iter))) != 0 ))
			 SDA_1_TSM12();
		else
			 SDA_0_TSM12();
		IIC_DELAY_TSM12();
		SCL_1_TSM12();
		IIC_DELAY_TSM12();
		SCL_0_TSM12();
		if (iic_iter == 7)
			break;
		IIC_DELAY_TSM12();
	}
	return (IIC_READ_ACK_TSM12() == 0);
}

int IIC_READ_TSM12(void)
{
	int iic_iter;
	int x = 0;

	IIC_RD_MODE_TSM12();

	for (iic_iter = 0; iic_iter < 8; iic_iter++)
	{
		SCL_0_TSM12();
		IIC_DELAY_TSM12();
		SCL_1_TSM12();
		IIC_DELAY_TSM12();
		x += SDA_V_TSM12();
		x <<= 1;
		SCL_0_TSM12();
		IIC_DELAY_TSM12();
	}
	return (x >> 1);
}

int SetIICRegister_TSM12(UINT32 slvAddr,UINT32 addr,UINT8 data)
{
	BOOL bRet, bRet2;
	int nRetry = 0;

	STOP_CONDITION_TSM12();
	do
	{
		bRet = TRUE;
		START_CONDITION_TSM12();
		bRet2 = IIC_WRITE_TSM12((BYTE)slvAddr); bRet = bRet && bRet2;
		bRet2 = IIC_WRITE_TSM12((BYTE)addr); bRet = bRet && bRet2;
		bRet2 = IIC_WRITE_TSM12((BYTE)data); bRet = bRet && bRet2;
		STOP_CONDITION_TSM12();
		if (bRet)
			break;

		nRetry ++;
	} while(nRetry < 5);
	SDA_0_TSM12();
	SCL_0_TSM12();
	return bRet;
}

int GetIICRegister_TSM12(UINT32 slvAddr,UINT32 addr,UINT8 *data)
{
	BOOL bRet, bRet2;
	int nRetry = 0;

	STOP_CONDITION_TSM12();
	do
	{
		bRet = TRUE;
		START_CONDITION_TSM12();
		bRet2 = IIC_WRITE_TSM12((BYTE)slvAddr); bRet = bRet && bRet2;
		bRet2 = IIC_WRITE_TSM12((BYTE)addr); bRet = bRet && bRet2;
		//STOP_CONDITION();
		IIC_DELAY_TSM12();
		START_CONDITION_TSM12();
		bRet2 = IIC_WRITE_TSM12((BYTE)(slvAddr + 1)); bRet = bRet && bRet2;
		*data = (BYTE)IIC_READ_TSM12();
		IIC_READ_ACK_TSM12();
		STOP_CONDITION_TSM12();
		if (bRet)
			break;

		nRetry ++;
	} while(nRetry < 5);
	SDA_0_TSM12();
	SCL_0_TSM12();
	return bRet;
}


#endif 

#define TSM12_WAddress  0xD0		  // TSM12 Write Address

void TSM12_Init(void)
{
	IIc_init_TSM12();
	GPIO_INIT_INT_TSM12();
	GPIO_INIT_EN_TSM12();

// H/W POWER ON RESET DELAY 100mSEC
	//i2c_en = 0;               //TSM12 I2C Enable
	delay_ms(100);
	TSM12_I2C_EN;

// S/W RESET
	SetIICRegister_TSM12(TSM12_WAddress,0x09,0x0F);

// Sensitivity Set

	SetIICRegister_TSM12(TSM12_WAddress,0x02,0x88);
	SetIICRegister_TSM12(TSM12_WAddress,0x03,0x88);
	SetIICRegister_TSM12(TSM12_WAddress,0x04,0x88);
	SetIICRegister_TSM12(TSM12_WAddress,0x05,0x88);
	SetIICRegister_TSM12(TSM12_WAddress,0x06,0x88);
	SetIICRegister_TSM12(TSM12_WAddress,0x07,0x88);

	SetIICRegister_TSM12(TSM12_WAddress,0x08,0x33);

	SetIICRegister_TSM12(TSM12_WAddress,0x0A,0x00);
	SetIICRegister_TSM12(TSM12_WAddress,0x0B,0x00);
	SetIICRegister_TSM12(TSM12_WAddress,0x0C,0x00);
	SetIICRegister_TSM12(TSM12_WAddress,0x0D,0x00);

// S/W Reset OFF
	SetIICRegister_TSM12(TSM12_WAddress,0x09,0x03);

}

void TSM12_lp_Init(void)
{
	Go_sleep_mode();
	TSM12_I2C_uEN;
}

void Noise_State(void)
{
	// Noise State  Channel Reset  Restart//
	SetIICRegister_TSM12(TSM12_WAddress,0x09,0x0F);//Enable Software Reset 

	SetIICRegister_TSM12(TSM12_WAddress,0x09,0x03);//Disable Software Reset 
}

void Exit_sleep_mode(void)
{
	SetIICRegister_TSM12(TSM12_WAddress,0x09,0x03);//Disable Sleep Mode 
}

void Go_sleep_mode(void)
{
	SetIICRegister_TSM12(TSM12_WAddress,0x09,0x07);//Enable Sleep Mode 
}

UINT8 TSM12_Reading_Start(void)
{
	UINT8 reg_data1,reg_data2,reg_data3;
	GetIICRegister_TSM12(TSM12_WAddress,0x10,&reg_data1);//
	GetIICRegister_TSM12(TSM12_WAddress,0x11,&reg_data2);//
	GetIICRegister_TSM12(TSM12_WAddress,0x12,&reg_data3);//

	if(((reg_data1>>0) & 0x3)>= 0x02)//key#
		{Disp_KBD(3);return KEYBD_c;}
	else if(((reg_data1>>2) & 0x3)>= 0x02)//key9
		{Disp_KBD(6);return KEYBD_9;}
	else if(((reg_data1>>4) & 0x3)>= 0x02)//key3
		{Disp_KBD(9);return KEYBD_3;}
	else if(((reg_data1>>6) & 0x3)>= 0x02)//key6
		{Disp_KBD(12);return KEYBD_6;}
	else if(((reg_data2>>0) & 0x3)>= 0x02)//key0
		{Disp_KBD(5);return KEYBD_0;}
	else if(((reg_data2>>2) & 0x3)>= 0x02)//key8
		{Disp_KBD(2);return KEYBD_8;}
	else if(((reg_data2>>4) & 0x3)>= 0x02)//key2
		{Disp_KBD(8);return KEYBD_2;}
	else if(((reg_data2>>6) & 0x3)>= 0x02)//key5
		{Disp_KBD(11);return KEYBD_5;}
	else if(((reg_data3>>0) & 0x3)>= 0x02)//key*
		{Disp_KBD(10);return KEYBD_x;}
	else if(((reg_data3>>2) & 0x3)>= 0x02)//key7
		{Disp_KBD(7);return KEYBD_7;}
	else if(((reg_data3>>4) & 0x3)>= 0x02)//key1
		{Disp_KBD(4);return KEYBD_1;}
	else if(((reg_data3>>6) & 0x3)>= 0x02)//key4
		{Disp_KBD(1);return KEYBD_4;}
	return 0;
}

uint8 Check_PassWord(uint8 * pswd,uint8 * pswd_in)
{
	uint8 bufi,psdi;
	
	for(bufi=0;bufi<(PASSWORD_BUF_LEN-PASSWORD_LEN);bufi++)
		{
		for(psdi=0;psdi<PASSWORD_LEN;psdi++)
			{
			if(pswd_in[bufi+psdi]!=pswd[psdi])
				break;//一旦比对不上就从头开始比
			}
		if(psdi>=PASSWORD_LEN)//密码通过
			return RT_OK;
		}
	return RT_FAIL;
}

uint8 USER_GETPASSWORD(uint8 * password)
{

	if(statedelay(0,PASSWORD_OUTTIME,&Sys_Pswd,Bp_PASSWORD_IN))//有密码
		{
		//VOICE(12,0);//-叮-叮
		if(PassWord_Buf_i < PASSWORD_LEN)
			{
			return 2;
			}
		else
			{
			memcpy(password,PassWord_Buf,PASSWORD_LEN);
			return RT_OK;
			}
		}
	return RT_FAIL;
}

uint8 USER_PassWordCheck(uint8 * pswd)
{
//	uint8 CardID[4];
	uint8 usernub,iderr;
	
	Flash_Read(DB_TABLE_USERID_ADDRS,DB_Data,DB_TABLE_USERID_LEN);
	
	for(usernub=0;usernub<DB_USERID_NUB;usernub++)
		{	
		if(DB_Data[usernub*DB_USERID_LEN]==DB_TURE)//启用
			{
			iderr = Check_PassWord(&DB_Data[usernub*DB_USERID_LEN+DB_I_USERID_PSWD],pswd);
			if(iderr == RT_OK)//密码通过
				{
//				if(usernub == 0)//管理员
//					return 2;
				return RT_OK;	
				}
			}
		}
	return RT_FAIL;		


}


uint8 PASSWORD_Enroll(void)
{
	uint16 Enroll_ID;
	uint8 password[PASSWORD_LEN];
	uint8 password_chk[PASSWORD_LEN];
	uint8 rtn;

	Enroll_ID = USER_Get_Enroll_USERID();
	rtn = USER_GETPASSWORD(password);
	if(rtn == RT_OK)
		{
		VOICE(15,0);//-请重新输入-密码
		rtn = USER_GETPASSWORD(password_chk);
		if(rtn == RT_OK)
			{
			rtn = Check_PassWord(password,password_chk);
			if(rtn == RT_OK)
				{
				USER_UPDATA_USERID(Enroll_ID,password);
				VOICE(2,0);//-密码-添加成功
				KeyBD_State_Rst();
				Sys_Task = PS_AutoIdentify;//空闲时为比对
				}
			}

		}
	if(rtn == 2)
		{
		VOICE(8,0);//-密码位数输入错误
		}	
	else if(rtn == RT_FAIL)
		{
		VOICE(20,0);//-密码-添加失败
		}
	return RT_OK;
}

uint8 PASSWORD_Identify(void)
{
	uint8 rtn;

	if(PassWord_Buf_i >= PASSWORD_LEN)
		{
		rtn = USER_PassWordCheck(PassWord_Buf);
//		if(rtn == 2)//管理员
//			{
//			VOICE(9,46);//-管理员-验证成功
//			KeyBD_State_Rst();
//			Sys_Task = PS_AutoIdentify;//空闲时为比对
//			SETBIT(Sys_Pswd,Bp_ADMINPASSWORD_OK);
//			}		
		if(rtn == RT_OK)
			{
			VOICE(2,0);//-锁已开启请按把手//VOICE(14,46);//-密码-验证成功
			MOTO_Forward();
			SETBIT(Sys_State,Bs_DOOR_OPEN);
			KeyBD_State_Rst();
			Sys_Task = PS_AutoIdentify;//空闲时为比对
			SETBIT(Sys_Pswd,Bp_PASSWORD_OK);
			}
		else
			{
			VOICE(7,0);//-密码-验证失败
			}
		}
	else
		{
		VOICE(8,0);//-密码位数输入错误
		}	
	return RT_OK;
}

void PASSWORD_MAIN(void)
{

	switch(Sys_Task)
		{
		case PS_AutoEnroll://添加密码
			if(TESTBIT(Sys_Pswd,Bp_PASSWORD_IN))//
				{
				Sys_Channel = Sc_Pswd;
				}
			else
				break;//通过状态读取选择通道(卡-密-指纹)
			if(TESTBIT(Sys_Pswd,Bp_ADMINPASSWORD_OK))
				{
				ClearPassWord();//密码使用后清空
				//CLRBIT(Sys_Pswd,Bp_CHECK_ADMINPASSWORD);//验证管理员完成
				VOICE(15,0);//-请输入6到10位-密码
				PASSWORD_Enroll();
				}
			break;
		case PS_AutoIdentify://验证密码
			if((TESTBIT(Sys_Pswd,Bp_PASSWORD_IN))&&(TESTBIT(Sys_State,Bs_DOOR_OPEN)==0))//键入密码
				{
				CLRBIT(Sys_Pswd,Bp_PASSWORD_IN);
				PASSWORD_Identify();
				ClearPassWord();//密码使用后清空
				}	
			break;
		case PS_DeleteChar://删除卡
			//CmdDeleteChar();
			break;
		case PS_Empty://清空卡

			break;
		default:
			break;	
		}
}


void KEYBD_MAIN(void)
{
	uint8 keybuf;//,rtn;
	if(TESTBIT(Sys_Key,Bk_KEYBD_INT))//键盘
		{
		CLRBIT(Sys_Key,Bk_KEYBD_INT);
		keybuf = Key_value;//TSM12_Reading_Start();
		if(keybuf == KEYBD_x)
			{
			KeyBD_State_Rst();
			Sys_Task = PS_AutoIdentify;//空闲时为比对
			}
		else if(keybuf == KEYBD_c)
			{
			if(TESTBIT(Sys_Pswd,Bp_CHECK_ADMINPASSWORD))//需要先验证管理员	
				{
				CLRBIT(Sys_Pswd,Bp_PASSWORD_IN);
				if(RT_OK== Check_PassWord(PassWord_Admin,PassWord_Buf))//密码通过
					{
					VOICE(19,0);//-管理员-验证成功
					SETBIT(Sys_Pswd,Bp_ADMINPASSWORD_OK);
					CLRBIT(Sys_Pswd,Bp_CHECK_ADMINPASSWORD);//验证管理员完成
					}
				else
					{
					VOICE(20,15);//-验证失败-请重新输入
					KeyBD_State_Rst();
					}				
				ClearPassWord();//密码使用后清空
				}
//			else
//				SETBIT(Sys_Pswd,Bp_PASSWORD_IN);
			}
		else
			{
//			PassWord_Buf[PassWord_Buf_i++] = keybuf;		
//			if(PassWord_Buf_i>19)PassWord_Buf_i=19;
			}
		}
		
	if(TESTBIT(Sys_Key,Bk_KEY_RST))//复位
		{//GotoSleep_cnt=0;
		if(GET_ButtonRST() == 0)
			{
			delay_ms(200);
			if(GET_ButtonRST() == 1)return;//去抖
			delay_ms(1000);
			if(GET_ButtonRST() == 1)//已释放认为是短按
				{
				Sys_Task = PS_AutoEnroll;
				VOICE(14,0);//-请验证管理员
				SETBIT(Sys_Pswd,Bp_CHECK_ADMINPASSWORD);
				//while(GET_ButtonRST() == 1);//等待释放
				CLRBIT(Sys_Pswd,Bp_ADMINPASSWORD_OK);	
				return;	
				}
			delay_ms(2000);
			if(GET_ButtonRST() == 0)
				{
				VOICE(22,2);//-正在恢复出厂设置请稍后-叮叮-叮
				FP_POWER_ON();
				if(CmdEmpty()!=PS_OK)
				{
					VOICE(21,0);//return;
				}
				memset(DB_Data,0,FLASH_PAGE_SIZE);
				Flash_Write(DB_TABLE_LOCKSTATE_ADDRS,DB_Data,DB_TABLE_LOCKSTATE_LEN);
				Flash_Write(DB_TABLE_USERID_ADDRS,DB_Data,DB_TABLE_USERID_LEN);
				Flash_Write(DB_TABLE_FPID_ADDRS,DB_Data,DB_TABLE_FPID_LEN);
				Flash_Write(DB_TABLE_CARDID_ADDRS,DB_Data,DB_TABLE_CARDID_LEN);
				delay_ms(1000);
				//复位系统	
				SW_RESET();
				delay_ms(1000);
				}
			}

		}
	
//	if(TESTBIT(Sys_Key,Bk_KEY_ADD))
//		{
//		CLRBIT(Sys_Key,Bk_KEY_ADD);
//		if(GET_ButtonADD() == 0)//添加
//			{
//			delay_ms(500);
//			if(GET_ButtonADD() == 0)
//				{
//				Sys_Task = PS_AutoEnroll;
//				VOICE(26,0);//-请验证管理员
//				SETBIT(Sys_Pswd,Bp_CHECK_ADMINPASSWORD);
//				while(GET_ButtonADD() == 1);//等待释放
//				CLRBIT(Sys_Pswd,Bp_ADMINPASSWORD_OK);
//				}
//			}
//		}	
//		if(TESTBIT(Sys_Key,Bk_KEY_DEL))
//		{
//		CLRBIT(Sys_Key,Bk_KEY_DEL);
//		if(GET_ButtonDEL() == 0)//删除
//			{
//			delay_ms(500);
//			if(GET_ButtonDEL() == 0)
//				{
//				Sys_Task = PS_DeleteChar;
//				VOICE(27,0);//-请验证要删除的用户
//				CLRBIT(Sys_Pswd,Bp_ADMINPASSWORD_OK);				
//				}
//			}	
//		}
	

}


