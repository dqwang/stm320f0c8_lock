
#include "main.h"


void GPIO_INIT(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOC, ENABLE);					  											 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;                 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; 
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}
void TIM3_INIT(unsigned int arr,unsigned int psc)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//	NVIC_InitTypeDef NVIC_InitStructure;
 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //时钟使能
	
	//定时器TIM3初始化
	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //位
 
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE ); //

	TIM_Cmd(TIM3, ENABLE);  //使能TIMx	


}
void USART_INIT(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef 	NVIC_InitStructure;

	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE );						
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_1);
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_1);     											 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10;                 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; 
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);   

	USART_InitStructure.USART_BaudRate = 57600;//9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART1, &USART_InitStructure);
	
	USART_Cmd(USART1, ENABLE);
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
}

void USART_lp_INIT(void)
{
	USART_Cmd(USART1, DISABLE);

}
void SYSTICK_INIT(void)
{
		//SysTick_Config(SystemCoreClock / 1000);	//Set SysTick Timer for 1ms interrupts
		//SysTick_Config(SystemCoreClock / 200);	//Set SysTick Timer for 5ms interrupts
		SysTick_Config(SystemCoreClock / 100);	//Set SysTick Timer for 10ms interrupts
		//SysTick_Config(SystemCoreClock / 10);	//Set SysTick Timer for 100ms interrupts     
}

void SYS_INIT(void)
{
	SystemInit();//RCC_SYSCLKConfig(RCC_SYSCLKSource_HSI);
	SYSTICK_INIT();
	//GPIO_INIT();
	USART_INIT();   
}

//串口
//字符
void uart_putc(unsigned char c)
{
	while(!((USART1->ISR)&(1<<7)));
	USART1->TDR=c;	
}
//字符串
void uart_puts(char *s )
{
	while (*s)
	uart_putc(*s++);
}
void uart_send(unsigned char *sdata,unsigned char len)
{
	unsigned char i,lTmp;
    lTmp = len;
    if(len>UART_SBUF_SIZE) 
		lTmp = UART_SBUF_SIZE;
    for(i=0;i<lTmp;i++)
    	{ 
		uart_putc(sdata[i]);             
    	}    
}

void SYS_RST(void)
{
	//NVIC_SystemReset();


}

void Init_GPIO_LP(void)
{
//	USART_lp_INIT();
	KEYBD_lp_INIT();
//	MOTO_lp_INIT();
//	FP_lp_INIT();
//	TSM12_lp_Init();
//	VOICE_lp_INIT();
//	CARD_lp_INIT();

	//EXTI_ClearITPendingBit(0xFFFFFFFF);
}



void MCU_SLEEP(void)
{

	if(GotoSleep_cnt>=GOTOSLEEP_OUTTIME)//进休眠
		{
		
		Init_GPIO_LP();

		RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE); 	
	
		PWR_EnterSTOPMode(PWR_Regulator_LowPower, PWR_STOPEntry_WFI);
		
		LOCK_INIT();
		GotoSleep_cnt=0;

		
		}



  
}

void SPIx_Init(void)//SPI2-PB13-14-15
{
	SPI_InitTypeDef  SPI_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
//	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);
	
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource13, GPIO_AF_0);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource14, GPIO_AF_0);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource15, GPIO_AF_0);
	
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Level_3;
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
//	GPIO_Init(GPIOB, &GPIO_InitStructure);
//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_14;
//	GPIO_Init(GPIOB, &GPIO_InitStructure);
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
//	GPIO_Init(GPIOB, &GPIO_InitStructure);
	/* Configure SPI2 pins: NSS, SCK, MISO and MOSI */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_Init(GPIOB, &GPIO_InitStructure); 

	
	SPI_InitStructure.SPI_BaudRatePrescaler 			   = SPI_BaudRatePrescaler_64;
	SPI_InitStructure.SPI_CPHA								  = SPI_CPHA_1Edge;
	SPI_InitStructure.SPI_CPOL								  = SPI_CPOL_Low;
	SPI_InitStructure.SPI_CRCPolynomial 					   = 7;
	SPI_InitStructure.SPI_DataSize						  = SPI_DataSize_8b;
	SPI_InitStructure.SPI_Direction 					   = SPI_Direction_2Lines_FullDuplex;
	SPI_InitStructure.SPI_FirstBit								  = SPI_FirstBit_MSB;
	SPI_InitStructure.SPI_Mode								  = SPI_Mode_Master;
	SPI_InitStructure.SPI_NSS								 = SPI_NSS_Soft;
	SPI_Init(SPI2, &SPI_InitStructure);
	
//	NVIC_InitStructure.NVIC_IRQChannel = SPI2_IRQn;
//	NVIC_InitStructure.NVIC_IRQChannelPriority = 1;
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(&NVIC_InitStructure);
//	
//	SPI_RxFIFOThresholdConfig(SPI2, SPI_RxFIFOThreshold_QF);
//	SPI_I2S_ITConfig(SPI2, SPI_I2S_IT_RXNE, ENABLE);
//	SPI_I2S_ITConfig(SPI2, SPI_I2S_IT_ERR, ENABLE);
	SPI_Cmd(SPI2, ENABLE);

}



