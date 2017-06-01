
#ifndef _KEYBD_H_
#define _KEYBD_H_



#define 				KBLED_H 		sbi(GPIOA,GPIO_Pin_15)
#define 				KBLED_L 		cbi(GPIOA,GPIO_Pin_15)


//¼üÅÌ¼üÖµ
#define  KEYBD_1 	1
#define  KEYBD_2 	2
#define  KEYBD_3 	3
#define  KEYBD_4 	4
#define  KEYBD_5 	5
#define  KEYBD_6 	6
#define  KEYBD_7 	7
#define  KEYBD_8 	8
#define  KEYBD_9 	9
#define  KEYBD_0 	10
#define  KEYBD_x 	12
#define  KEYBD_c 	11


#define 				TSM12_I2C_uEN 		sbi(GPIOB,GPIO_Pin_8)
#define 				TSM12_I2C_EN 		cbi(GPIOB,GPIO_Pin_8)


void KEYBD_INIT(void);
void KEYBD_lp_INIT(void);
void TSM12_lp_Init(void);
UINT8 GET_ButtonADD(void);
UINT8 GET_ButtonDEL(void);
void Disp_KBD(unsigned int dat16);
void Disp_KBD_Rst(void);
void TSM12_Init(void);
void KEYBD_MAIN(void);
UINT8 TSM12_Reading_Start(void);
uint8 Check_PassWord(uint8 * pswd,uint8 * pswd_in);
void PASSWORD_MAIN(void);

void Exit_sleep_mode(void);
void Go_sleep_mode(void);

#endif 		/* _KEYBD_H_ */


