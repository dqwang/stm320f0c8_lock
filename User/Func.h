
#ifndef _FUNC_H_
#define _FUNC_H_
#include <Type.h>

#define GOTOSLEEP_OUTTIME 1000//10s

#define UART_RBUF_SIZE 100
#define UART_SBUF_SIZE 100
#define UART_OUTTIME 2//20ms
#define COMM_OUTTIME 200// 2s
#define READCARD_OUTTIME 100//1s
#define READCARD_OUTTIME_OFF 0xFFFF//1s


#define FP_OUTTIME 1000// 10s
#define CARD_OUTTIME 1000// 10s
#define PASSWORD_OUTTIME 1000// 10s

#define DOOROPEN_OUTTIME 500//5s

#define FPMODULE_POWERON_OUTTIME 40// 400ms


//sys_flag_bit.x
#define flag_RX_start 		0
#define flag_RX_finish 		1
#define flag_Sleep 			2






extern volatile unsigned char sys_flag;//
extern volatile unsigned char uart_RDataLen;//接收的数据长度
extern volatile unsigned char uart_cnt;
extern unsigned char uart_RBuf[UART_RBUF_SIZE];
extern unsigned char RcvBuf[UART_RBUF_SIZE];
extern unsigned char SendBuf[UART_RBUF_SIZE];
extern volatile unsigned int comm_cnt;
extern volatile unsigned int sTimeOut_cnt;
extern volatile unsigned int ReadCard_cnt;//读卡周期超时时间
extern volatile unsigned int DoorOpen_cnt;//开门超时时间
extern volatile unsigned int GotoSleep_cnt;//进入休眠超时时间

void delay_us(unsigned int dlus);
void delay_ms(unsigned int dlms);
UINT16 countsum(UINT8 *p, UINT16 len);
unsigned char commdelay (unsigned char d,unsigned int x,unsigned char flg);
unsigned char statedelay (unsigned char d,unsigned int x,volatile unsigned char *reg,unsigned char flg);


#endif 		/* _FUNC_H_ */


