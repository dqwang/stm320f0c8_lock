////////////////////////////////////////////////////////////////////////////////
// ��Ȩ:     ������Ƽ����Źɷ����޹�˾
// �ļ���:   
// �汾��    v1.0
// ��������: IAR  v5.30
// ����:     �ں���
// ��������: 2013.12
// ����:       SPI
// ����ļ�: 
// �޸���־��
////////////////////////////////////////////////////////////////////////////////
#include "main.h"

#include "SX1276_Hal.h"

////////////////////////////////////////////////////////////////////////////////
// �������� : RF��ʼ��IO��
// ������� : ��
// ���ز��� : ��
// ˵��     : 
////////////////////////////////////////////////////////////////////////////////

//void Init_LoraIO_CS_LP(void)//PB5
//{	
//    GPIO_InitTypeDef GPIO_InitStructure;    
//    //GPIOB
//    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE);

//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;       
//    GPIO_Init(GPIOB, &GPIO_InitStructure);
//}
//void Init_LoraIO_RST_LP(void)//PB1
//{	
//    GPIO_InitTypeDef GPIO_InitStructure;    
//    //GPIOB
//    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE);

//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
//    GPIO_Init(GPIOB, &GPIO_InitStructure);
//}
//void Init_LoraIO_DIO1_LP(void)//PA12  �ж�
//{

//    GPIO_InitTypeDef GPIO_InitStructure;    
//    //GPIOA
//    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE);

//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;	
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;       
//    GPIO_Init(GPIOA, &GPIO_InitStructure);
//}
//void Init_LoraIO_DIO2_LP(void)//PA12  �ж�
//{

//    GPIO_InitTypeDef GPIO_InitStructure;    
//    //GPIOA
//    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE);

//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;	
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;       
//    GPIO_Init(GPIOA, &GPIO_InitStructure);
//}

//void Init_LoraIO_DIO3_LP(void)//PA8
//{	  
//    GPIO_InitTypeDef GPIO_InitStructure;    
//    //GPIOA
//    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE);

//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;	
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;       
//    GPIO_Init(GPIOA, &GPIO_InitStructure);
//}

//void Init_LoraIO_DIO0_LP(void)//PB12  �ж�
//{  
//    GPIO_InitTypeDef GPIO_InitStructure;    
//    //GPIOB
//    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE);

//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;	
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;       
//    GPIO_Init(GPIOB, &GPIO_InitStructure);
//}

//void Init_LoraIO_SPI_LP(void)//PB13-14-15
//{  
//    GPIO_InitTypeDef GPIO_InitStructure;    
//    //GPIOB
//    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE);

//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;	
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;       
//    GPIO_Init(GPIOB, &GPIO_InitStructure);
//}

//void Init_LoraIO_LP(void)//
//{  
//	Init_LoraIO_CS_LP();
//	Init_LoraIO_RST_LP();
//	Init_LoraIO_DIO1_LP();
//	//Init_LoraIO_DIO2_LP();
//	Init_LoraIO_DIO3_LP();
//	Init_LoraIO_DIO0_LP();
//	//Init_LoraIO_SPI_LP();
//}

void Init_LoraIO_PW(void)//PC13
{	
    GPIO_InitTypeDef GPIO_InitStructure;    
    //GPIOC
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOC, ENABLE);					  											 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;                 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; 
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}


void Init_LoraIO_CS(void)//PF6//PB5
{	
    GPIO_InitTypeDef GPIO_InitStructure;    
    //GPIOF
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOF, ENABLE);					  											 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;                 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; 
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOF, &GPIO_InitStructure);
}
void Init_LoraIO_RST(void)//PA9//PB1
{	
    GPIO_InitTypeDef GPIO_InitStructure;    
    //GPIOA
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOA, ENABLE);					  											 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;                 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; 
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

}

void Init_LoraIO_DIO1(void)//PA10//PA12  �ж�
{
//    NVIC_InitTypeDef NVIC_InitStructure;  
//    EXTI_InitTypeDef EXTI_InitStructure;  
    GPIO_InitTypeDef GPIO_InitStructure;    
    //GPIOA
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOA, ENABLE);					  											 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;                 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);


//	EXTI_ClearITPendingBit(EXTI_Line12);  
//	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource12);//PC12  ΪGPIOA��PIN12  
//	EXTI_InitStructure.EXTI_Line= EXTI_Line12; //PC12��Ϊ��EXTI_Line12	
//	EXTI_InitStructure.EXTI_Mode= EXTI_Mode_Interrupt;	 
//	EXTI_InitStructure.EXTI_Trigger= EXTI_Trigger_Rising;	//�жϷ�ʽΪ�������½���  
//	EXTI_InitStructure.EXTI_LineCmd=ENABLE;  
//	EXTI_Init(&EXTI_InitStructure);  
//		  
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);   //NVIC  
//	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;  
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority= 0;  
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority= 2;		   
//	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;	  
//	NVIC_Init(&NVIC_InitStructure);   
	
}


void Init_LoraIO_DIO1_EXTIoff(void)//PA10//PA12  ���ж�
{
//    NVIC_InitTypeDef NVIC_InitStructure;  
//    EXTI_InitTypeDef EXTI_InitStructure;  
    GPIO_InitTypeDef GPIO_InitStructure;    
    //GPIOA
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOA, ENABLE);					  											 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;                 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);


//	EXTI_ClearITPendingBit(EXTI_Line12);  
//	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource12);//PC12  ΪGPIOA��PIN12  
//	EXTI_InitStructure.EXTI_Line= EXTI_Line12; //PC12��Ϊ��EXTI_Line12	
//	EXTI_InitStructure.EXTI_Mode= EXTI_Mode_Interrupt;	 
//	EXTI_InitStructure.EXTI_Trigger= EXTI_Trigger_Rising;	//�жϷ�ʽΪ�������½���  
//	EXTI_InitStructure.EXTI_LineCmd=DISABLE;  
//	EXTI_Init(&EXTI_InitStructure);  
//		  
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);   //NVIC  
//	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;  
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority= 0;  
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority= 2;		   
//	NVIC_InitStructure.NVIC_IRQChannelCmd=DISABLE;	  
//	NVIC_Init(&NVIC_InitStructure);   
	
}

void Init_LoraIO_DIO3(void)//PA3//PA8
{
	GPIO_InitTypeDef GPIO_InitStructure; //GPIO ����
	EXTI_InitTypeDef EXTI_InitStructure; //�ⲿ�ж϶���
	NVIC_InitTypeDef NVIC_InitStructure; //Ƕ���ж϶���
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOA, ENABLE);					  											 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;                 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

    //��EXTI0ָ��PA3  
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA,EXTI_PinSource3);  
    //EXTI0�ж�������  
//    EXTI_InitTypeDef EXTI_InitStructure;  
    EXTI_InitStructure.EXTI_Line=EXTI_Line3;  
    EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;  
    EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Rising;  //����ָ�ߵ�ƽ
    EXTI_InitStructure.EXTI_LineCmd=ENABLE;  
    EXTI_Init(&EXTI_InitStructure);  

    //EXTI0�ж���������  
//    NVIC_InitTypeDef NVIC_InitStructure;  
    NVIC_InitStructure.NVIC_IRQChannel=EXTI2_3_IRQn;  
    NVIC_InitStructure.NVIC_IRQChannelPriority=0x01;  
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;  
    NVIC_Init(&NVIC_InitStructure);  
}


void Init_LoraIO_DIO3_EXTIoff(void)//PA3//PA8
{
	GPIO_InitTypeDef GPIO_InitStructure; //GPIO ����
	EXTI_InitTypeDef EXTI_InitStructure; //�ⲿ�ж϶���
	NVIC_InitTypeDef NVIC_InitStructure; //Ƕ���ж϶���
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOA, ENABLE);																 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;				  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	//��EXTI0ָ��PA8  
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA,EXTI_PinSource3);  
	//EXTI0�ж�������  
//	  EXTI_InitTypeDef EXTI_InitStructure;	
	EXTI_InitStructure.EXTI_Line=EXTI_Line3;  
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;  
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Rising;  //����ָ�ߵ�ƽ
	EXTI_InitStructure.EXTI_LineCmd=DISABLE;  
	EXTI_Init(&EXTI_InitStructure);  

	//EXTI0�ж���������  
//	  NVIC_InitTypeDef NVIC_InitStructure;	
	NVIC_InitStructure.NVIC_IRQChannel=EXTI2_3_IRQn;  
	NVIC_InitStructure.NVIC_IRQChannelPriority=0x01;  
	NVIC_InitStructure.NVIC_IRQChannelCmd=DISABLE;  
	NVIC_Init(&NVIC_InitStructure);  
}


void Init_LoraIO_DIO0(void)//PA2//PB12  �ж�
{
	GPIO_InitTypeDef GPIO_InitStructure; //GPIO ����
	EXTI_InitTypeDef EXTI_InitStructure; //�ⲿ�ж϶���
	NVIC_InitTypeDef NVIC_InitStructure; //Ƕ���ж϶���
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOA, ENABLE);																 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;				  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	//��EXTI0ָ��PA2 
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA,EXTI_PinSource2);  
	//EXTI0�ж�������  
//	  EXTI_InitTypeDef EXTI_InitStructure;	
	EXTI_InitStructure.EXTI_Line=EXTI_Line2;  
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;  
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Rising;  //����ָ�ߵ�ƽ
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;  
	EXTI_Init(&EXTI_InitStructure);  

	//EXTI0�ж���������  
//	  NVIC_InitTypeDef NVIC_InitStructure;	
	NVIC_InitStructure.NVIC_IRQChannel=EXTI2_3_IRQn;  
	NVIC_InitStructure.NVIC_IRQChannelPriority=0x01;  
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;  
	NVIC_Init(&NVIC_InitStructure);  
}


void Init_LoraIO_DIO0_EXTIoff(void)//PA2//PB12  �ж�
{
	GPIO_InitTypeDef GPIO_InitStructure; //GPIO ����
	EXTI_InitTypeDef EXTI_InitStructure; //�ⲿ�ж϶���
	NVIC_InitTypeDef NVIC_InitStructure; //Ƕ���ж϶���
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOA, ENABLE);																 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;				  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	//��EXTI0ָ��PA8  
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA,EXTI_PinSource3);  
	//EXTI0�ж�������  
//	  EXTI_InitTypeDef EXTI_InitStructure;	
	EXTI_InitStructure.EXTI_Line=EXTI_Line2;  
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;  
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Rising;  //����ָ�ߵ�ƽ
	EXTI_InitStructure.EXTI_LineCmd=DISABLE;  
	EXTI_Init(&EXTI_InitStructure);  

	//EXTI0�ж���������  
//	  NVIC_InitTypeDef NVIC_InitStructure;	
	NVIC_InitStructure.NVIC_IRQChannel=EXTI2_3_IRQn;  
	NVIC_InitStructure.NVIC_IRQChannelPriority=0x01;  
	NVIC_InitStructure.NVIC_IRQChannelCmd=DISABLE;	
	NVIC_Init(&NVIC_InitStructure);  
}

void SX1276InitIo( void )
{
    //PA_TX_DIR = 1;           //PA_TX ��Ϊ���
    //PA_RX_DIR = 1;           //PA_RX ��Ϊ���
    //PA_RX_OUT = 0;           //PA_RX ��ʼ�����Ϊ0
    //PA_TX_OUT = 1;           //PA_TX ��ʼ�����Ϊ1
 //   SXRESET_SET = 1;

    //����Ƭѡ�ŵ�����
//    PB_ODR_ODR2 = 1;    //����ߵ�ƽ
//    PB_DDR_DDR2 = 1;    //���
//    PB_CR1_C12 = 1;     //����
//    PB_CR2_C22 = 0;     //2MHz
//    
//    PB_DDR_DDR0 = 0;        //����
//    PB_CR1_C10 = 1;         //����
//    EXTI_CR1_P0IS = 1;      //�����ش���
//    ITC_SPR3_VECT8SPR = 0;  //EXTI0_vector����һ�����ȼ���Ϊ�˱�֤PC5�ܽ��жϣ���DIO3��DIO1�ж�ͬʱ��������Ҫ��֤DIO1�����ȼ����ߣ�
//  
//    PC_DDR_DDR5 = 0;
//    PC_CR1_C15 = 1;
//    EXTI_CR2_P5IS = 1;
//    
//    PC_DDR_DDR6 = 0;
//    PC_CR1_C16 = 1;
//    EXTI_CR2_P6IS = 1;

	Init_LoraIO_PW();

	Init_LoraIO_CS();
	Init_LoraIO_DIO1();
	Init_LoraIO_DIO3();
	Init_LoraIO_DIO0();

	Init_LoraIO_RST();

	RF_PW_H;
}


////////////////////////////////////////////////////////////////////////////////
// �������� : RF  SPI���ó�ʼ��
// ������� : ��
// ���ز��� : ��
// ˵��     : �˳�ʼ��Ϊ430Ӳ��SPI��ʼ��
////////////////////////////////////////////////////////////////////////////////
void SX1276SPISetup(void)
{
    //SPI_NSS_SET = 1;v1.0
//    SPI_NSS_DIR = 1;
//    SPI_NSS_OUT = 1;         // /CS disable
    //��̬ΪLOW   ��һ���仯�ز���
    RF_CS_H;
}
////////////////////////////////////////////////////////////////////////////////
// �������� : RF   ��λ
// ������� : ��
// ���ز��� : ��
// ˵��     :
////////////////////////////////////////////////////////////////////////////////
void SX1276Reset(void)
{
//    SXRESET_SET = 1;       //Ӳ����λIO�ڷ��������
//    SXRESET_OUT = 1;//0;       //Ӳ����λIO�����0
//    delay_ms(100);           //��ʱ
//    SXRESET_OUT = 0;//1;       //���Ϊ1
//    delay_ms(20);

	RF_RST_L;
	delay_ms(100);  
	RF_RST_H;
	delay_ms(20); 	

}
////////////////////////////////////////////////////////////////////////////////
// �������� : RF  ��Ĵ�����ַ������������
// ������� : uint8_t addr,�Ĵ�����ַ uint8_t *buffer,��������ָ�� uint8_t sizeָ�볤��
// ���ز��� : ��
// ˵��     :
////////////////////////////////////////////////////////////////////////////////
void SX1276WriteBuffer( uint8_t addr, uint8_t *buffer, uint8_t size )
{
    uint8_t i;  

    //SPI_NSS_OUT = 0;
    RF_CS_L;
    
     SPI_SendData(addr | 0x80);
    for( i = 0; i < size; i++ )
        SPI_SendData(buffer[i]);

    //SPI_NSS_OUT = 1;
    delay_us(50);
    RF_CS_H;
}
////////////////////////////////////////////////////////////////////////////////
// �������� : RF  ��Ĵ�����ַ����������
// ������� : uint8_t addr,�Ĵ�����ַ uint8_t *buffer,�洢����ָ�� uint8_t sizeҪ���ĳ���
// ���ز��� : ���ݷ��ص�*buffer��
// ˵��     :
////////////////////////////////////////////////////////////////////////////////
void SX1276ReadBuffer( uint8_t addr, uint8_t *buffer, uint8_t size )
{
    uint8_t i;
    
    //SPI_NSS_OUT = 0;
    RF_CS_L;
    
    SPI_SendData(addr & 0x7F);
    for( i = 0; i < size; i++ )
        buffer[i] = SPI_ReceiveData();

    //SPI_NSS_OUT = 1;
    delay_us(50);
    RF_CS_H;
}
////////////////////////////////////////////////////////////////////////////////
// �������� : RF  ��Ĵ�����ַд1�ֽ�����
// ������� : uint8_t addr,�Ĵ�����ַ uint8_t data����
// ���ز��� : 
// ˵��     :
////////////////////////////////////////////////////////////////////////////////
void SX1276Write( uint8_t addr, uint8_t data )
{
    SX1276WriteBuffer( addr, &data, 1 );
}
////////////////////////////////////////////////////////////////////////////////
// �������� : RF  ��Ĵ�����ַ��1�ֽ�����
// ������� : uint8_t addr,�Ĵ�����ַ uint8_t *data�����ݴ洢��ַ
// ���ز��� : 
// ˵��     :
////////////////////////////////////////////////////////////////////////////////
void SX1276Read( uint8_t addr, uint8_t *data )
{
    SX1276ReadBuffer( addr, data, 1 );
}
////////////////////////////////////////////////////////////////////////////////
// �������� : RF  ��FIFOд����
// ������� : uint8_t *buffer,����ָ�� uint8_t size����
// ���ز��� : 
// ˵��     :
////////////////////////////////////////////////////////////////////////////////
void SX1276WriteFifo( uint8_t *buffer, uint8_t size )
{
    SX1276WriteBuffer( 0, buffer, size );
}
////////////////////////////////////////////////////////////////////////////////
// �������� : RF  ��FIFO������
// ������� : uint8_t *buffer,����ָ�� uint8_t size����
// ���ز��� : uint8_t *buffer �洢��ȡ����
// ˵��     :
////////////////////////////////////////////////////////////////////////////////
void SX1276ReadFifo( uint8_t *buffer, uint8_t size )
{
    SX1276ReadBuffer( 0, buffer, size );
}
////////////////////////////////////////////////////////////////////////////////
// �������� : RF  TX/RX��PA�л�
// ������� :  bool txEnable  �л��߼�
// ���ز��� : ��
// ˵��     :�棺��ΪTX���٣���ΪRX   ΪӲ������PA����IO��
////////////////////////////////////////////////////////////////////////////////
/*void SX1276WriteRxTx( bool txEnable )
{
    if( txEnable != 0 )       //���Ϊ�棬ΪTX
    {
        PA_RX_OUT = 0;        //PA_RXΪ0
        PA_TX_OUT = 1;        //PA_TXΪ1
    }
    else  //Ϊ�٣�ΪRX
    {
        PA_RX_OUT = 1;        //PA_RXΪ1
        PA_TX_OUT = 0;         //PA_TXΪ0
    }
}*/
////////////////////////////////////////////////////////////////////////////////

void SPI_SendData(UINT8 Data)
{
	while(SPI_I2S_GetFlagStatus(SPI2,SPI_I2S_FLAG_TXE)==RESET);
    SPI_SendData8(SPI2,Data);
}
UINT8 SPI_ReceiveData(void)
{
	while(SPI_I2S_GetFlagStatus(SPI2,SPI_I2S_FLAG_TXE)==RESET);
    SPI_SendData8(SPI2,0);
	while(SPI_I2S_GetFlagStatus(SPI2,SPI_I2S_FLAG_RXNE)==RESET);
	return (SPI_ReceiveData8(SPI2));
}



