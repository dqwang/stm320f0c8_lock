/***************************************************************
COPYRIGHT (c)   zehootech
rf.c            V1.0
V1.0    新建
***************************************************************/
////////////////////////////////////////////////////////////////
#include "main.h"

#include "rf.h"

UINT8 Lora_Comm_Flag=0;
UINT8 Lora_RcvDat[RF_PACK_SIZE];

#define RTC_SRC_CLK     64                      
#define RTC_INTERVAL    16                    
#define RTC_IRQ_FREQ    1//RTC_SRC_CLK/RTC_INTERVAL

////////////////////////////////////////////////////////////////
UINT8 				RfBuf[RF_BUF_SIZE];
UINT8               RfPackBuf[RF_PACK_SIZE];

RF_t                _rf;

////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////
//无线初始化
////////////////////////////////////////////////////////////////
UINT8 Init_RF(void)
{
    //U8  rtn=0;
    
    _rf.buf = RfBuf;
    _rf.packBuf = RfPackBuf;
    _rf.bufsize = RF_BUF_SIZE;
    _rf.rcvLen = 0;
    _rf.flag = RF_SLEEP;
    _rf.cad_cnt = 0;
    _rf.CADCNT = 10*RTC_IRQ_FREQ;           
    _rf.cadOuttime_cnt = 0;
    _rf.CADOUTTIMECNT = 20*RTC_IRQ_FREQ;    
    _rf.sleep_cnt = 0;
    _rf.SLEEPCNT = RF_SLEEPCNT;            

    if(SX127x_init(Init_LoRa_0_8K)==NORMAL)
    {
        RF_FreqSet(0);            
        //RF_FreqSet(24);            
        RF_RXmode(RF_PACK_SIZE);  
        //RF_WORInit();
        //RF_Sleepmode();
        return 1;//rtn = 1;
    }
    //else
    //    RST_APP;
    
    return 0;
}


////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
void RF_Send(UINT8 * sdata, UINT16 sdatalen)
{



        __disable_irq();//_DINT();
        RF_SendPacket(sdata,sdatalen);
        __enable_irq();//_EINT();
        delay_ms(1);
	
    RF_RXmode(RF_PACK_SIZE);
}

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
UINT16  RF_PackRcv(UINT8 * packbuf, UINT8 * rfbuf)
{
    UINT16 rDataLen=0;
    UINT16 packDataLen,pos;
    UINT8  packNum,packNo;

    packDataLen = packbuf[0]-RF_PACK_START_LEN;
    if(packDataLen > RF_PACK_DATA_LEN)
        return 0;
    packNum = packbuf[2];
    if(packNum < 1)
        return 0;
    packNo = packbuf[3];
    if(packNo < 1)
        return 0;
        
    pos = RF_PACK_DATA_LEN*(packNo-1);
    if((pos+packDataLen) > RF_BUF_SIZE)
        return 0;
    memcpy(rfbuf+pos,packbuf+RF_PACK_START_LEN, packDataLen);
    if(packNo == packNum)
        rDataLen = pos+packDataLen;

    return rDataLen;
}

UINT8 Lora_Sendtest(UINT8 *sDat,UINT16 sLen)
{
	UINT8 sbuf[20]={0x0D,0xFF,0x01,0x00,0x01,0x09,0x08,0x07,0x06,0x05,0x04,0x17,0x55};
	UINT16 crc;

//	sbuf[3] = (UINT8)(Lora_Mod_ADRS>>8);
//	sbuf[4] = (UINT8)(Lora_Mod_ADRS);
//	memcpy(&sbuf[5],sDat,sLen);
//	CalCRC(sbuf,sLen+5,&crc);
//	sbuf[5+sLen] = (UINT8)crc;
//	sbuf[5+sLen+1] = (UINT8)(crc>>8);
	RF_Send(sbuf,sLen+7);

  return 0;
}


////////////////////////////////////////////////////////////////
//无线中断处理
////////////////////////////////////////////////////////////////
 void port2_isr(void)
{  
    if(DIO3_IFG && DIO3_IE)     //CadDone中断，表示没有发生CADDetected
    {
        DIO3_IFG = 0;           //清除中断标志位
        RF_Sleepmode();
        _rf.flag = RF_SLEEP;
        _rf.cad_cnt = 0;
    }
    
    if(DIO1_IFG && DIO1_IE)     //CadDetected中断
    {
        DIO1_IFG = 0;
        RF_WOR_Exit(RF_PACK_SIZE);  //退出WOR进入接收模式
        LED1_ON;
        _rf.flag = RF_CADDETECTED;  //开启一个超时计数标记，没有收到有效数据则重新进入WOR
        _rf.cadOuttime_cnt = 0;
    }

    if(DIO0_IFG && DIO0_IE)     //RxDone中断
    {
        DIO0_IFG = 0;
        if(_rf.flag == RF_CADDETECTED)
        {
            RF_RxFixiPacket(_rf.packBuf, 2);
            if(_rf.packBuf[0] == RF_WAKE_CODE && (_rf.packBuf[1] == EQUinfo.LOCALNUM[3] || _rf.packBuf[1] == RF_BROADCAST_ADDR))
            {
                _rf.flag = RF_WAKEUP;
                LED2_ON;
                LPM4_EXIT;
                _NOP();
                //_sysSleepFlag = 0;
            }
            else
            {
                RF_WORInit();
                RF_Sleepmode();
                LED1_OFF;
                _rf.flag = RF_SLEEP;
                _rf.cad_cnt = 0;
            }
        }
        if(_rf.flag == RF_WAKEUP && _rf.rcvLen == 0)
        {
            RF_RxFixiPacket(_rf.packBuf, 2);                     //接收数据包首两字节（包长度、目的地址）
            if((_rf.packBuf[0] > RF_PACK_START_LEN) && (_rf.packBuf[0] <= RF_PACK_SIZE) && (_rf.packBuf[1] == EQUinfo.LOCALNUM[3] || _rf.packBuf[1] == RF_BROADCAST_ADDR))
            {   //长度满足要求并且为广播地址（后期可加入本机地址）
                LED2_ON;
                _rf.sleep_cnt=0;
                //_sysSleepCnt=0;
                RF_RxFixiPacket(_rf.packBuf, _rf.packBuf[0]);      //接收数据包
                _rf.rcvLen = RF_PackRcv(_rf.packBuf, _rf.buf);
                LED2_OFF;
                if(_rf.rcvLen > 0)
                {
                    LPM4_EXIT;
                    _NOP();
                }
                
            }
            delay_us(5);    
            RF_RXmode(RF_PACK_SIZE);
        }
    }
    P2IFG=0;
}
