//LOCK
//20161105

/* Includes ------------------------------------------------------------------*/
#include "main.h"



int main(void)
{

	LOCK_INIT();
	//LOCK_ADMIN_SET();

    gpio_init_rf433m_power();
	hwapi03_rf433m_power_ctrl(1);

	
	SX1276InitIo();
	SPIx_Init();
	__enable_irq();
	Init_RF();
	
	Lora_Sendtest(0,6);
	
	while (1)
	{
	#if 1
	//KEYBD_MAIN();
	//LOCK_MAIN();
	//MCU_SLEEP();
	CARD_MAIN();
	#else

	//test_hwapi03_rf433m_power_ctrl();
	//VOICE_test(0);
	//test_voice_ok_and_error();
	//test_read_card_id();
	#endif
	}
}

 
