/***************************************************************
COPYRIGHT (c)   zehootech
rf.h            V1.0
V1.0    新建
***************************************************************/
////////////////////////////////////////////////////////////////
#ifndef __RF_H__
#define __RF_H__
////////////////////////////////////////////////////////////////
#include "main.h"



////////////////////////////////////////////////////////////////
#define     RF_BUF_SIZE         512
//#define     RF_BUF_SIZE         UART1_RBUFSIZE
#define     RF_PACK_SIZE        64
#define     RF_PACK_START_LEN   4
#define     RF_PACK_DATA_LEN    (RF_PACK_SIZE - RF_PACK_START_LEN)

#define     RF_SLEEP            0x00
#define     RF_CAD              0x01
#define     RF_CADDONE          0x02
#define     RF_CADDETECTED      0x04
#define     RF_ERRWAKE          0x08
#define     RF_WAKEUP           0x10
#define     RF_RECEIVEPACK      0x20
#define     RF_RECEIVED         0x40

#define     RF_WAKE_CODE        0x63
#define     RF_BROADCAST_ADDR   0xff

#define     RF_SLEEPCNT         60*RTC_IRQ_FREQ     //60s

////////////////////////////////////////////////////////////////
typedef struct rf
{
    U8*             buf;
    U8*             packBuf;
    U16             bufsize;
    volatile U16    rcvLen;
    volatile U16    cad_cnt;
    volatile U16    cadOuttime_cnt;
    volatile U16    sleep_cnt;
    volatile U8     flag;           //0表示接收数据已处理可以重新开始接收，1表示开始接收数据，2表示接收数据超时（结束）
    U16             CADCNT;
    U16             CADOUTTIMECNT;
    U16             SLEEPCNT;
} RF_t;


////////////////////////////////////////////////////////////////
extern  RF_t                _rf;

extern UINT8 Lora_Comm_Flag;
extern UINT8 Lora_RcvDat[RF_PACK_SIZE];


////////////////////////////////////////////////////////////////
U8      Init_RF(void);
U16     RF_PackRcv(U8 * packbuf, U8 * rfbuf);
void    RF_Send(U8 * sdata, U16 sdatalen);

UINT8 Lora_Sendtest(UINT8 *sDat,UINT16 sLen);


#endif


