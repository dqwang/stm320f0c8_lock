
#ifndef _LOCK_H_
#define _LOCK_H_


//Sys_Channel
#define Sc_Non 			0//
#define Sc_Card 		1//
#define Sc_Fp 			2//
#define Sc_Pswd 		3//

//Sys_State.x
#define Bs_DOOR_OPEN 		0//
#define Bs_ADMIN_SET		1//
#define Bs_CARD_ON			2//


//Sys_Key.x
#define Bk_KEY_CON 			0//
#define Bk_KEY_ADD 			1//
#define Bk_KEY_DEL 			2//
#define Bk_FP_TOUCH 		3//
#define Bk_CARD_INT 		4//
#define Bk_KEYBD_INT 		5
#define Bk_KEY_RST 			6//
#define Bk_KEY_LOGO 		7//

//Sys_Pswd.x
#define Bp_PASSWORD_OK				1//
#define Bp_ADMINPASSWORD_OK			2//
#define Bp_PASSWORD_IN				3//
#define Bp_CHECK_ADMINPASSWORD		4//


#define PASSWORD_LEN 6
#define PASSWORD_BUF_LEN 20

#define CARDID_LEN 4


extern UINT8 PassWord_Admin[PASSWORD_LEN];//
extern UINT8 PassWord_Buf[PASSWORD_BUF_LEN];//
extern UINT8 PassWord_Buf_i;//
extern UINT8 Key_value;//

extern UINT8 Menu_1L,Menu_2L;
extern volatile UINT8 Sys_Task;//
extern volatile UINT8 Sys_Channel;//
extern volatile UINT8 Sys_State;//
extern volatile UINT8 Sys_Key;//
extern volatile UINT8 Sys_Pswd;//


void LOCK_INIT(void);
void LOCK_MAIN(void);
void LOCK_ADMIN_SET(void);
UINT16 LOCK_MENU_KEY(void);
void KeyBD_State_Rst(void);
void ClearPassWord(void);

#endif 		/* _LOCK_H_ */


