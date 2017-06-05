////////////////////////////////////////////////////////////////////////////////
// 版权:     利尔达科技集团股份有限公司
// 文件名:   
// 版本：    v1.0
// 工作环境: IAR  v5.30
// 作者:     于海波
// 生成日期: 2013.12
// 功能:       SPI
// 相关文件: 
// 修改日志：
////////////////////////////////////////////////////////////////////////////////
#include "main.h"

#include "SX1276_Hal.h"

////////////////////////////////////////////////////////////////////////////////
// 功能描述 : RF初始化IO口
// 输入参数 : 无
// 返回参数 : 无
// 说明     : 
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
//void Init_LoraIO_DIO1_LP(void)//PA12  中断
//{

//    GPIO_InitTypeDef GPIO_InitStructure;    
//    //GPIOA
//    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE);

//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;	
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;       
//    GPIO_Init(GPIOA, &GPIO_InitStructure);
//}
//void Init_LoraIO_DIO2_LP(void)//PA12  中断
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

//void Init_LoraIO_DIO0_LP(void)//PB12  中断
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

void Init_LoraIO_DIO1(void)//PA10//PA12  中断
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
//	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource12);//PC12  为GPIOA的PIN12  
//	EXTI_InitStructure.EXTI_Line= EXTI_Line12; //PC12，为：EXTI_Line12	
//	EXTI_InitStructure.EXTI_Mode= EXTI_Mode_Interrupt;	 
//	EXTI_InitStructure.EXTI_Trigger= EXTI_Trigger_Rising;	//中断方式为上升与下降沿  
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


void Init_LoraIO_DIO1_EXTIoff(void)//PA10//PA12  关中断
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
//	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource12);//PC12  为GPIOA的PIN12  
//	EXTI_InitStructure.EXTI_Line= EXTI_Line12; //PC12，为：EXTI_Line12	
//	EXTI_InitStructure.EXTI_Mode= EXTI_Mode_Interrupt;	 
//	EXTI_InitStructure.EXTI_Trigger= EXTI_Trigger_Rising;	//中断方式为上升与下降沿  
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
	GPIO_InitTypeDef GPIO_InitStructure; //GPIO 定义
	EXTI_InitTypeDef EXTI_InitStructure; //外部中断定义
	NVIC_InitTypeDef NVIC_InitStructure; //嵌套中断定义
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOA, ENABLE);					  											 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;                 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

    //将EXTI0指向PA3  
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA,EXTI_PinSource3);  
    //EXTI0中断线配置  
//    EXTI_InitTypeDef EXTI_InitStructure;  
    EXTI_InitStructure.EXTI_Line=EXTI_Line3;  
    EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;  
    EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Rising;  //有手指高电平
    EXTI_InitStructure.EXTI_LineCmd=ENABLE;  
    EXTI_Init(&EXTI_InitStructure);  

    //EXTI0中断向量配置  
//    NVIC_InitTypeDef NVIC_InitStructure;  
    NVIC_InitStructure.NVIC_IRQChannel=EXTI2_3_IRQn;  
    NVIC_InitStructure.NVIC_IRQChannelPriority=0x01;  
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;  
    NVIC_Init(&NVIC_InitStructure);  
}


void Init_LoraIO_DIO3_EXTIoff(void)//PA3//PA8
{
	GPIO_InitTypeDef GPIO_InitStructure; //GPIO 定义
	EXTI_InitTypeDef EXTI_InitStructure; //外部中断定义
	NVIC_InitTypeDef NVIC_InitStructure; //嵌套中断定义
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOA, ENABLE);																 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;				  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	//将EXTI0指向PA8  
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA,EXTI_PinSource3);  
	//EXTI0中断线配置  
//	  EXTI_InitTypeDef EXTI_InitStructure;	
	EXTI_InitStructure.EXTI_Line=EXTI_Line3;  
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;  
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Rising;  //有手指高电平
	EXTI_InitStructure.EXTI_LineCmd=DISABLE;  
	EXTI_Init(&EXTI_InitStructure);  

	//EXTI0中断向量配置  
//	  NVIC_InitTypeDef NVIC_InitStructure;	
	NVIC_InitStructure.NVIC_IRQChannel=EXTI2_3_IRQn;  
	NVIC_InitStructure.NVIC_IRQChannelPriority=0x01;  
	NVIC_InitStructure.NVIC_IRQChannelCmd=DISABLE;  
	NVIC_Init(&NVIC_InitStructure);  
}


void Init_LoraIO_DIO0(void)//PA2//PB12  中断
{
	GPIO_InitTypeDef GPIO_InitStructure; //GPIO 定义
	EXTI_InitTypeDef EXTI_InitStructure; //外部中断定义
	NVIC_InitTypeDef NVIC_InitStructure; //嵌套中断定义
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOA, ENABLE);																 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;				  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	//将EXTI0指向PA2 
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA,EXTI_PinSource2);  
	//EXTI0中断线配置  
//	  EXTI_InitTypeDef EXTI_InitStructure;	
	EXTI_InitStructure.EXTI_Line=EXTI_Line2;  
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;  
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Rising;  //有手指高电平
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;  
	EXTI_Init(&EXTI_InitStructure);  

	//EXTI0中断向量配置  
//	  NVIC_InitTypeDef NVIC_InitStructure;	
	NVIC_InitStructure.NVIC_IRQChannel=EXTI2_3_IRQn;  
	NVIC_InitStructure.NVIC_IRQChannelPriority=0x01;  
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;  
	NVIC_Init(&NVIC_InitStructure);  
}


void Init_LoraIO_DIO0_EXTIoff(void)//PA2//PB12  中断
{
	GPIO_InitTypeDef GPIO_InitStructure; //GPIO 定义
	EXTI_InitTypeDef EXTI_InitStructure; //外部中断定义
	NVIC_InitTypeDef NVIC_InitStructure; //嵌套中断定义
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOA, ENABLE);																 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;				  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	//将EXTI0指向PA8  
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA,EXTI_PinSource3);  
	//EXTI0中断线配置  
//	  EXTI_InitTypeDef EXTI_InitStructure;	
	EXTI_InitStructure.EXTI_Line=EXTI_Line2;  
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;  
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Rising;  //有手指高电平
	EXTI_InitStructure.EXTI_LineCmd=DISABLE;  
	EXTI_Init(&EXTI_InitStructure);  

	//EXTI0中断向量配置  
//	  NVIC_InitTypeDef NVIC_InitStructure;	
	NVIC_InitStructure.NVIC_IRQChannel=EXTI2_3_IRQn;  
	NVIC_InitStructure.NVIC_IRQChannelPriority=0x01;  
	NVIC_InitStructure.NVIC_IRQChannelCmd=DISABLE;	
	NVIC_Init(&NVIC_InitStructure);  
}

void SX1276InitIo( void )
{
    //PA_TX_DIR = 1;           //PA_TX 作为输出
    //PA_RX_DIR = 1;           //PA_RX 作为输出
    //PA_RX_OUT = 0;           //PA_RX 初始化输出为0
    //PA_TX_OUT = 1;           //PA_TX 初始化输出为1
 //   SXRESET_SET = 1;

    //无线片选脚的配置
//    PB_ODR_ODR2 = 1;    //输出高电平
//    PB_DDR_DDR2 = 1;    //输出
//    PB_CR1_C12 = 1;     //推挽
//    PB_CR2_C22 = 0;     //2MHz
//    
//    PB_DDR_DDR0 = 0;        //输入
//    PB_CR1_C10 = 1;         //上拉
//    EXTI_CR1_P0IS = 1;      //上升沿触发
//    ITC_SPR3_VECT8SPR = 0;  //EXTI0_vector降低一级优先级（为了保证PC5能进中断）（DIO3和DIO1中断同时发生，需要保证DIO1的优先级更高）
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
// 功能描述 : RF  SPI设置初始化
// 输入参数 : 无
// 返回参数 : 无
// 说明     : 此初始化为430硬件SPI初始化
////////////////////////////////////////////////////////////////////////////////
void SX1276SPISetup(void)
{
    //SPI_NSS_SET = 1;v1.0
//    SPI_NSS_DIR = 1;
//    SPI_NSS_OUT = 1;         // /CS disable
    //常态为LOW   第一个变化沿采样
    RF_CS_H;
}
////////////////////////////////////////////////////////////////////////////////
// 功能描述 : RF   复位
// 输入参数 : 无
// 返回参数 : 无
// 说明     :
////////////////////////////////////////////////////////////////////////////////
void SX1276Reset(void)
{
//    SXRESET_SET = 1;       //硬件复位IO口方向做输出
//    SXRESET_OUT = 1;//0;       //硬件复位IO口输出0
//    delay_ms(100);           //延时
//    SXRESET_OUT = 0;//1;       //输出为1
//    delay_ms(20);

	RF_RST_L;
	delay_ms(100);  
	RF_RST_H;
	delay_ms(20); 	

}
////////////////////////////////////////////////////////////////////////////////
// 功能描述 : RF  向寄存器地址连续发送数据
// 输入参数 : uint8_t addr,寄存器地址 uint8_t *buffer,发送数组指针 uint8_t size指针长度
// 返回参数 : 无
// 说明     :
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
// 功能描述 : RF  向寄存器地址连续读数据
// 输入参数 : uint8_t addr,寄存器地址 uint8_t *buffer,存储数组指针 uint8_t size要读的长度
// 返回参数 : 数据返回到*buffer中
// 说明     :
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
// 功能描述 : RF  向寄存器地址写1字节数据
// 输入参数 : uint8_t addr,寄存器地址 uint8_t data数据
// 返回参数 : 
// 说明     :
////////////////////////////////////////////////////////////////////////////////
void SX1276Write( uint8_t addr, uint8_t data )
{
    SX1276WriteBuffer( addr, &data, 1 );
}
////////////////////////////////////////////////////////////////////////////////
// 功能描述 : RF  向寄存器地址读1字节数据
// 输入参数 : uint8_t addr,寄存器地址 uint8_t *data读数据存储地址
// 返回参数 : 
// 说明     :
////////////////////////////////////////////////////////////////////////////////
void SX1276Read( uint8_t addr, uint8_t *data )
{
    SX1276ReadBuffer( addr, data, 1 );
}
////////////////////////////////////////////////////////////////////////////////
// 功能描述 : RF  向FIFO写数据
// 输入参数 : uint8_t *buffer,数组指针 uint8_t size长度
// 返回参数 : 
// 说明     :
////////////////////////////////////////////////////////////////////////////////
void SX1276WriteFifo( uint8_t *buffer, uint8_t size )
{
    SX1276WriteBuffer( 0, buffer, size );
}
////////////////////////////////////////////////////////////////////////////////
// 功能描述 : RF  向FIFO读数据
// 输入参数 : uint8_t *buffer,数组指针 uint8_t size长度
// 返回参数 : uint8_t *buffer 存储读取内容
// 说明     :
////////////////////////////////////////////////////////////////////////////////
void SX1276ReadFifo( uint8_t *buffer, uint8_t size )
{
    SX1276ReadBuffer( 0, buffer, size );
}
////////////////////////////////////////////////////////////////////////////////
// 功能描述 : RF  TX/RX的PA切换
// 输入参数 :  bool txEnable  切换逻辑
// 返回参数 : 无
// 说明     :真：作为TX。假：作为RX   为硬件两个PA控制IO口
////////////////////////////////////////////////////////////////////////////////
/*void SX1276WriteRxTx( bool txEnable )
{
    if( txEnable != 0 )       //如果为真，为TX
    {
        PA_RX_OUT = 0;        //PA_RX为0
        PA_TX_OUT = 1;        //PA_TX为1
    }
    else  //为假，为RX
    {
        PA_RX_OUT = 1;        //PA_RX为1
        PA_TX_OUT = 0;         //PA_TX为0
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



