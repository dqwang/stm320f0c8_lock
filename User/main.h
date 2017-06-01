
#ifndef __MAIN_H
#define __MAIN_H

#include "stm32f0xx.h"
#include "core_cm0.h"


#include <string.h>
#include <Drv.h>
#include <Func.h>
#include <Type.h>

#include <LOCK.h>
#include <FP.h>
#include <KEYBD.h>
#include <DATABASE.h>
#include <VOICE.h>
#include <CARD.h>
#include <DISP.h>
#include <MOTO.h>
#define  SW_RESET()	       NVIC_SystemReset()

#define sbi(ADDRESS,BIT) 	((ADDRESS->BSRR = BIT))	// Set bit
#define cbi(ADDRESS,BIT) 	((ADDRESS->BRR = BIT))	// Clear bit
#define	bis(ADDRESS,BIT)	(GPIO_ReadInputDataBit(ADDRESS,BIT))	// Is bit set?
#define	bic(ADDRESS,BIT)	(!GPIO_ReadInputDataBit(ADDRESS,BIT))	// Is bit clear
#define	toggle(ADDRESS,BIT)	(GPIO_WriteBit(ADDRESS,BIT,(BitAction)((1-GPIO_ReadOutputDataBit(ADDRESS,BIT)))))	// Toggle bit

#define SETBIT(x,y) (x |= (1<<y))       // Set bit y in byte x 
#define CLRBIT(x,y) (x &= (~(1<<y)))    // Clear bit y in byte x 
#define TESTBIT(x,y) (x & (1<<y))       // Check bit y in byte x 

#define PLL_SOURCE_HSI        // HSI (~8MHz) used to clock the PLL, and the PLL is used as system clock source
//#define PLL_SOURCE_HSE        // HSE (8MHz) used to clock the PLL, and the PLL is used as system clock source
//#define PLL_SOURCE_HSE_BYPASS // HSE bypassed with an external clock (8MHz, coming from ST-Link) used to clock

#endif /* __MAIN_H */


