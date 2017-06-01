

#include "main.h"
#include "stm32f0xx_tim.h"


volatile unsigned char sys_flag;//
volatile unsigned char uart_RDataLen;//
volatile unsigned char uart_cnt;
unsigned char uart_RBuf[UART_RBUF_SIZE];
unsigned char RcvBuf[UART_RBUF_SIZE];
unsigned char SendBuf[UART_RBUF_SIZE];

volatile unsigned int comm_cnt;//
volatile unsigned int sTimeOut_cnt;//
volatile unsigned int ReadCard_cnt;//
volatile unsigned int DoorOpen_cnt;//
volatile unsigned int GotoSleep_cnt;//


//---  微秒级延时-------8M-------------------
void delay_us(unsigned int dlus)
{ 
unsigned int i;	
	while(dlus--)
	{
    for(i=0;i<9;i++)//48M
			__asm("nop");
	}
}
//---- 毫秒级延时程序----8M-------------------
void delay_ms(unsigned int dlms)
{
unsigned int i;
while(dlms--)
	{
    for(i=0;i<6000;i++)//48M
			__asm("nop");
	}
}
/*****************************************************************************
*****************************************************************************/
unsigned char commdelay (unsigned char d,unsigned int x,unsigned char flg)
{
	unsigned char i;
	comm_cnt = x; 
	CLRBIT(sys_flag,flg);
	for(i=0;i<d;i++)
		delay_ms(1);
    while(comm_cnt)
    	{
        if(TESTBIT(sys_flag,flg))
        	{
        	CLRBIT(sys_flag,flg);
        	comm_cnt=0;
        	return 1;
        	}
    	}
	return 0;
}
/*****************************************************************************
*****************************************************************************/
unsigned char statedelay (unsigned char d,unsigned int x,volatile unsigned char *reg,unsigned char flg)
{
	unsigned char i;
	comm_cnt = x;  
	CLRBIT(*reg,flg);
	for(i=0;i<d;i++)
		delay_ms(1);
    while(comm_cnt)
    	{
        if(TESTBIT(*reg,flg))
        	{
        	CLRBIT(*reg,flg);
        	comm_cnt=0;
        	return 1;
        	}
    	}
	return 0;
}

/*****************************************/
//*******************************************/
//int hex_2_ascii(uint8 *data, uint8 *buffer, uint16 len)
//{
//    const uint8 ascTable[17] = {"0123456789ABCDEF"};
//    uint8 *tmp_p = buffer;
//    uint16 i, pos;
//    pos = 0;
//    for(i = 0; i < len; i++)
//    {
//        tmp_p[pos++] = ascTable[data[i] >> 4];
//        tmp_p[pos++] = ascTable[data[i] & 0x0f];
//    }
//    tmp_p[pos] = '\0';
//    return pos;
//}

/*****************************************/
//****************************************/
//uint16 ascii_2_hex(uint8 *O_data, uint8 *N_data, uint16 len)
//{
//    int i,j,tmp_len;
//    uint8 tmpData;
//    uint8 *O_buf = O_data;
//    uint8 *N_buf = N_data;
//    for(i = 0; i < len; i++)
//    {
//        if ((O_buf[i] >= '0') && (O_buf[i] <= '9'))
//        {
//            tmpData = O_buf[i] - '0';
//        }
//        else if ((O_buf[i] >= 'A') && (O_buf[i] <= 'F')) //A....F
//        {
//            tmpData = O_buf[i] - 0x37;
//        }
//        else if((O_buf[i] >= 'a') && (O_buf[i] <= 'f')) //a....f
//        {
//            tmpData = O_buf[i] - 0x57;
//        }
//        else
//        {
//            return 0;
//        }
//        O_buf[i] = tmpData;
//    }
//    for(tmp_len = 0,j = 0; j < i; j+=2)
//    {
//        N_buf[tmp_len++] = (O_buf[j]<<4) | (O_buf[j+1]&0x0F);
//    }
//    return tmp_len;
//}


/*******************************************************
//*******************************************************/
//unsigned char uctobcd(unsigned char uc)
//{
//    unsigned char ucRtn;
//    
//    ucRtn = uc%100;
//    ucRtn = ucRtn/10;
//    ucRtn = ucRtn<<4;
//    ucRtn += uc%10;
//    
//    return ucRtn;
//}
/***************************************/
//***************************************/
//long bcdtol(unsigned char *str, unsigned char len)
//{
//    unsigned char i;
//    long tmp=0;
//    long data=0;
//    unsigned long ten[8] = {1,10,100,1000,10000,100000,1000000,10000000};
//    
//    if(len>4) len = 4;
//    for(i=0;i<len;i++)
//    {
//        tmp = (str[i]>>4)&0x0f;
//        data += tmp*ten[i*2+1];
//        tmp = str[i]&0x0f;
//        data += tmp*ten[i*2];
//    }
//    return data;
//}

/***************************************************************
计算校验和
***************************************************************/
UINT16 countsum(UINT8 *p, UINT16 len)
{
    UINT16 sum = 0;
    UINT16 i;
    for(i = 0; i < len; i++)
    {
	    sum += p[i];
    }
    //sum = 0xff - sum;
    return sum;
}


/********************************************************
//获取CRC16校验码
********************************************************/
unsigned int Get_CRC(unsigned char * pBuf, unsigned int num)
{
   unsigned char j;
   unsigned int i,uiCRC=0xffff;
   for(i=0;i<num;i++)
   {
       uiCRC^=(unsigned int)(pBuf[i]);
       for(j=0;j<8;j++)
       {
           if(uiCRC&1)
           {
               uiCRC>>=1;
               uiCRC^=0xA001;
           }
           else
           {
               uiCRC>>=1;
           }
       }
   }
   return uiCRC;
}






