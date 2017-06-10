
#ifndef _DRV_H_
#define _DRV_H_






void SYS_INIT(void);
void uart_putc(unsigned char c);
void uart_puts(char *s );
void uart_send(unsigned char *sdata,unsigned char len);
void SYS_RST(void);
void USART_lp_INIT(void);
void MCU_SLEEP(void);
void SPIx_Init(void);



#endif 		/* _DRV_H_ */


