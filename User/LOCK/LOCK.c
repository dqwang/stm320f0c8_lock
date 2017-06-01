
#include "main.h"


UINT8 Menu_1L,Menu_2L;
volatile UINT8 Sys_Task=PS_AutoIdentify;//
volatile UINT8 Sys_Channel;//
volatile UINT8 Sys_State;//
volatile UINT8 Sys_Key;//
volatile UINT8 Sys_Pswd;//

UINT8 PassWord_Admin[PASSWORD_LEN] = {1,2,3,4,5,6};//
UINT8 PassWord_Buf[PASSWORD_BUF_LEN];//
UINT8 PassWord_Buf_i;//

UINT8 Key_value;//键值





#define M1_USER_MANAGEMENT 	11
#define M1_SYSTEM_SETTING 	12
#define M1_INFORMATION_VIEW 13


void LOCK_MENU_1L(void)
{
	switch(Menu_1L)//一级目录
		{
		case M1_USER_MANAGEMENT: //用户管理
			break;
		case M1_SYSTEM_SETTING: //系统设置
			break;
		case M1_INFORMATION_VIEW: //信息查看
			break;
		default:
			break;
		}
}
void LOCK_MENU_2L(void)
{
	switch(Menu_2L)//二级目录
		{
		case M1_USER_MANAGEMENT: //用户管理
			break;
		case M1_SYSTEM_SETTING: //系统设置
			break;
		case M1_INFORMATION_VIEW: //信息查看
			break;
		default:
			break;
		}
}


void LOCK_MAIN(void)
{
	
	FP_MAIN();
	CARD_MAIN();
	PASSWORD_MAIN();

}
void LOCK_ADMIN_SET(void)
{
uint8 rtn,keybuf,pswd_chk=0;

rtn = Get_ADMIN_PASSWORD(PassWord_Admin);
if(rtn == 0)//
	{
	SETBIT(Sys_State,Bs_ADMIN_SET);
	VOICE(1,0);//-叮叮叮-叮
	}
else
	{
	CLRBIT(Sys_State,Bs_ADMIN_SET);
	VOICE(13,0);//-请先添加-管理员
	while(1)
		{
		if(TESTBIT(Sys_Key,Bk_KEYBD_INT))//键盘
			{
			CLRBIT(Sys_Key,Bk_KEYBD_INT);
			keybuf = Key_value;//TSM12_Reading_Start();
			if(keybuf == KEYBD_x)
				{
				KeyBD_State_Rst();
				return;
				}
			else if(keybuf == KEYBD_c)
				{
				if(PassWord_Buf_i != PASSWORD_LEN)
					{
					VOICE(8,0);//-密码位数输入错误
					KeyBD_State_Rst();
					}
				else
					{
					if(pswd_chk == 1)//校验密码
						{
						if(0 == Check_PassWord(PassWord_Admin,PassWord_Buf))//密码通过
							{
							VOICE(2,0);//-操作成功
							Set_ADMIN_PASSWORD(PassWord_Admin);
							delay_ms(2000);
							SW_RESET();
							}
						else
							{
							VOICE(20,0);//-验证失败-请重新输入
							KeyBD_State_Rst();
							}
						ClearPassWord();//
						}
					else
						{
						VOICE(15,0);//-请重新输入-密码
						memcpy(PassWord_Admin,PassWord_Buf,PASSWORD_LEN);
						KeyBD_State_Rst();						
						pswd_chk = 1;
						}
					}

				}
			}
		}
	}
}
void LOCK_INIT(void)
{
	SYS_INIT();
	MOTO_INIT();
	KEYBD_INIT();
	FP_INIT();
	TSM12_Init();
	VOICE_INIT();
	CARD_INIT();

}
void KeyBD_State_Rst(void)
{
	Sys_Key = 0;
	//Sys_Task = PS_AutoIdentify;//空闲时为比对
	PassWord_Buf_i=0;
	memset(PassWord_Buf,0xFF,PASSWORD_BUF_LEN);
}
void ClearPassWord(void)
{
	PassWord_Buf_i=0;
	memset(PassWord_Buf,0xFF,PASSWORD_BUF_LEN);
}


