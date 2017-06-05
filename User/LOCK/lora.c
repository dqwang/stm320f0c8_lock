/*wdq*/

#include "main.h"

void gpio_init_rf433m_power(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOC, ENABLE);					  											 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;                 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; 
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}


void hwapi03_rf433m_power_ctrl(u8 on_off)
{
	if (on_off > 0){
		(sbi(GPIOC,GPIO_Pin_13));
	}else{
		(cbi(GPIOC,GPIO_Pin_13));
	}
}


void test_hwapi03_rf433m_power_ctrl(void)
{
	hwapi03_rf433m_power_ctrl(1);
	delay_ms(1000);
	hwapi03_rf433m_power_ctrl(0);
	delay_ms(1000);
}


#define SPI_DUMMY_BYTE 0xFF


//SPI1 Init
//SCK-->PB13
//MISO->PB14
//MOSI->PB15






