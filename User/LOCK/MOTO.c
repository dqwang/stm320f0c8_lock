
#include "main.h"



void GPIO_INIT_MOTO(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOB, ENABLE);					  											 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13;                 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; 
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}


void MOTO_Standby(void)
{
	(cbi(GPIOB,GPIO_Pin_12));//
	(cbi(GPIOB,GPIO_Pin_13));//
}

void MOTO_Stop(void)
{
	(sbi(GPIOB,GPIO_Pin_12));//
	(sbi(GPIOB,GPIO_Pin_13));//
}

void MOTO_Forward(void)
{
	(cbi(GPIOB,GPIO_Pin_12));//
	(sbi(GPIOB,GPIO_Pin_13));//
	delay_ms(150);
	MOTO_Stop();
	delay_ms(20);
	MOTO_Standby();
}

void MOTO_Back(void)
{
	(sbi(GPIOB,GPIO_Pin_12));//
	(cbi(GPIOB,GPIO_Pin_13));//
	delay_ms(150);
	MOTO_Stop();
	delay_ms(20);
	MOTO_Standby();
}



void MOTO_INIT(void)
{
	GPIO_INIT_MOTO();
	MOTO_Standby();

}
void MOTO_lp_INIT(void)
{
	GPIO_INIT_MOTO();
	MOTO_Standby();

}


