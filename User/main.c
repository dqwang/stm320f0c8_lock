//LOCK
//20161105

/* Includes ------------------------------------------------------------------*/
#include "main.h"



int main(void)
{

	LOCK_INIT();
	LOCK_ADMIN_SET();


	while (1)
	{

	KEYBD_MAIN();
	LOCK_MAIN();
	MCU_SLEEP();

	}
}

 
