#ifndef __SX1276_APP_H__
#define __SX1276_APP_H__


#include "SX1276.h"



void RF_SendPacket(uint8_t*cbuf,uint8_t csize);
void RF_RXmode(uint8_t cclen);
void RF_Sleepmode(void);
void RF_CADinit(void);
void RF_CAD_Sample(void);
void RF_WORInit(void);
void RF_WOR_Execute(uint8_t cclen);
void RF_WOR_Exit(uint8_t cclen);
void RF_Awake(uint8_t*cbuf,uint8_t csize);
#endif
