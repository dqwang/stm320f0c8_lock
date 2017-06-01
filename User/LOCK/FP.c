
#include "main.h"


const uint8 FpProtocol_H[7]={0xEF,0x01,0xFF,0xFF,0xFF,0xFF,0x01};// 包头 2
//const uint8 FpProtocol_ChipAddrs[4]={0xFF,0xFF,0xFF,0xFF};//芯片地址4

void GPIO_INIT_Touch(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; //GPIO 定义
	EXTI_InitTypeDef EXTI_InitStructure; //外部中断定义
	NVIC_InitTypeDef NVIC_InitStructure; //嵌套中断定义
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOA, ENABLE);					  											 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;                 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

    //将EXTI0指向PA8  
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA,EXTI_PinSource8);  
    //EXTI0中断线配置  
//    EXTI_InitTypeDef EXTI_InitStructure;  
    EXTI_InitStructure.EXTI_Line=EXTI_Line8;  
    EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;  
    EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Rising;  //有手指高电平
    EXTI_InitStructure.EXTI_LineCmd=ENABLE;  
    EXTI_Init(&EXTI_InitStructure);  

    //EXTI0中断向量配置  
//    NVIC_InitTypeDef NVIC_InitStructure;  
    NVIC_InitStructure.NVIC_IRQChannel=EXTI4_15_IRQn;  
    NVIC_InitStructure.NVIC_IRQChannelPriority=0x01;  
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;  
    NVIC_Init(&NVIC_InitStructure);  
}

void GPIO_INIT_POWER(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOC, ENABLE);					  											 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;                 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; 
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}

void FP_INIT(void)
{
	GPIO_INIT_Touch();
	GPIO_INIT_POWER();
	FP_POWER_OFF();
}
void FP_lp_INIT(void)
{
	GPIO_INIT_Touch();
	GPIO_INIT_POWER();
	FP_POWER_OFF();
}


UINT8 GET_FP_Touch(void)
{
	return(bis(GPIOA,GPIO_Pin_8));//
}

void FP_POWER_ON(void)
{
	(sbi(GPIOC,GPIO_Pin_13));//
	commdelay(0,FPMODULE_POWERON_OUTTIME,flag_RX_finish);//等待模块启动
}
void FP_POWER_OFF(void)
{
	(cbi(GPIOC,GPIO_Pin_13));//
}

uint8 FP_SendCmd_AutoIdentify(uint16 Identify_ID,uint16 Parameter)
{
	uint8 i=0;
	uint16 chksum;

	memcpy(SendBuf,FpProtocol_H,7);
	SendBuf[7+i++]=0x00;//包长度
	SendBuf[7+i++]=0x08;//包长度
	SendBuf[7+i++]=PS_AutoIdentify;//指令
	SendBuf[7+i++]=2;//安全等级 
	SendBuf[7+i++]=(uint8)(Identify_ID>>8);//ID 号 
	SendBuf[7+i++]=(uint8)Identify_ID;//ID 号 
	SendBuf[7+i++]=(uint8)(Parameter>>8);//参数  
	SendBuf[7+i++]=(uint8)(Parameter);//参数  
	chksum = countsum(&SendBuf[6],i+1);
	SendBuf[7+i++]=(uint8)(chksum>>8);//校验  
	SendBuf[7+i++]=(uint8)chksum;//校验

	uart_send(SendBuf,7+i);

	return 0;

}

uint8 FP_SendCmd_AutoEnroll(uint16 Enroll_ID)
{
	uint8 i=0;
	uint16 chksum;

	memcpy(SendBuf,FpProtocol_H,7);
	SendBuf[7+i++]=0x00;//包长度
	SendBuf[7+i++]=0x08;//包长度
	SendBuf[7+i++]=PS_AutoEnroll;//指令
	SendBuf[7+i++]=(uint8)(Enroll_ID>>8);//ID 号 
	SendBuf[7+i++]=(uint8)Enroll_ID;//ID 号 
	SendBuf[7+i++]=2;//录入次数  
	SendBuf[7+i++]=0;//参数  
	SendBuf[7+i++]=0;//参数  
	chksum = countsum(&SendBuf[6],i+1);
	SendBuf[7+i++]=(uint8)(chksum>>8);//校验  
	SendBuf[7+i++]=(uint8)chksum;//校验

	uart_send(SendBuf,7+i);

	return 0;

}

uint8 FP_SendCmd_DeleteChar(uint16 PageID,uint16 PageN)
{
	uint8 i=0;
	uint16 chksum;

	memcpy(SendBuf,FpProtocol_H,7);
	SendBuf[7+i++]=0x00;//包长度
	SendBuf[7+i++]=0x07;//包长度
	SendBuf[7+i++]=PS_DeleteChar;//指令
	SendBuf[7+i++]=(uint8)(PageID>>8);//ID 号 
	SendBuf[7+i++]=(uint8)PageID;//ID 号 
	SendBuf[7+i++]=(uint8)(PageN>>8);//PageN  
	SendBuf[7+i++]=(uint8)(PageN);//  
	chksum = countsum(&SendBuf[6],i+1);
	SendBuf[7+i++]=(uint8)(chksum>>8);//校验  
	SendBuf[7+i++]=(uint8)chksum;//校验

	uart_send(SendBuf,7+i);

	return 0;

}
uint8 FP_SendCmd_Empty(void)
{
	uint8 i=0;
	uint16 chksum;

	memcpy(SendBuf,FpProtocol_H,7);
	SendBuf[7+i++]=0x00;//包长度
	SendBuf[7+i++]=0x03;//包长度
	SendBuf[7+i++]=PS_Empty;//指令
	chksum = countsum(&SendBuf[6],i+1);
	SendBuf[7+i++]=(uint8)(chksum>>8);//校验  
	SendBuf[7+i++]=(uint8)chksum;//校验

	uart_send(SendBuf,7+i);

	return 0;

}


uint8 FP_RcvDeal(uint8 cmd)
{
	uint8 i;
	uint16 uiRcvLen,offset;

	sTimeOut_cnt = FP_OUTTIME;//10s
	while(sTimeOut_cnt)
		{
		if(commdelay(0,COMM_OUTTIME,flag_RX_finish)==1)
			{
			uiRcvLen = uart_RDataLen;//数据长度 
			uart_RDataLen = 0;

			for(i=0;i<uiRcvLen;i++)
				{// 起始符号定位
				if(uart_RBuf[i]==FpProtocol_H[0] && uart_RBuf[i+1]==FpProtocol_H[1])
				break;
				}
			offset = i;
			uiRcvLen = uiRcvLen - offset;//保存数据长度
			if(uiRcvLen>0)//接收到的数据中没有头不处理
				{
				memcpy(RcvBuf,(uart_RBuf+offset),uiRcvLen);
				while(uiRcvLen)
					{
					if(cmd == PS_AutoEnroll)//注册
						{
						if((RcvBuf[9]==0x00)&&(RcvBuf[10]==0x06)&&(RcvBuf[11]==0xF2))//最后一个包
							{
							return 0;//流程结束正常
							}
						else if((RcvBuf[9]==0x00)&&(RcvBuf[10]==0x02)&&(RcvBuf[11]==0x01))//第一幅图采集成功
							{
							VOICE(15,0);//-请再次输入同一枚指纹
							}
						if(uiRcvLen >= 14)//接收包长度14字节
							uiRcvLen -= 14;
						if(uiRcvLen<14)uiRcvLen=0;
						}
					else if(cmd == PS_AutoIdentify)//验证
						{
						if((RcvBuf[10]==0x5))//05包确认搜索成功
							{
							if(RcvBuf[9] == PS_OK)
								return PS_OK;//流程结束正常
							else
								return PS_NOT_SEARCHED;//比对失败
							}		
						else if((RcvBuf[10]==0x1))//01包确认采图成功
							{
							if(RcvBuf[9] == PS_OK)
								VOICE(1,0);//-滴
							else
								return PS_TIME_OUT;//比对失败								
							
							}
						else if((RcvBuf[10]==0x0))
							{
							VOICE(1,0);//-滴							
							}
						if(uiRcvLen >= 17)//接收包长度14字节
							uiRcvLen -= 17;
						if(uiRcvLen<17)uiRcvLen=0;
						}
					else if(cmd == 0)//通用确认码
						if(RcvBuf[9] == PS_OK)
							return 0;//直接成功
					}
				}
			}
//		else
//			{
//			return 2;//超时无返回
//			}
		}
		
		return PS_TIME_OUT;//无数据
}


uint8 CmdAutoEnroll(uint16 UserID)
{
	uint8 ret;
	uint16 Enroll_ID;

	Enroll_ID = FP_Get_Enroll_FPID();
	FP_SendCmd_AutoEnroll(Enroll_ID);
	ret = FP_RcvDeal(PS_AutoEnroll);
	if(ret == 0)//注册成功
		{
		VOICE(2,0);//-操作成功
		
		//更新指纹索引
		FP_UPDATA_FPID(UserID,Enroll_ID);
		//更新用户ID索引
		KeyBD_State_Rst();
		Sys_Task = PS_AutoIdentify;//空闲时为比对
		return 0;
		}
	else
		{	
		VOICE(21,0);//-添加失败
		return ret; 
		
		}
		
		
}
uint8 CmdAutoIdentify(void)
{
	uint8 ret;
//	uint16 Identify_ID;

	FP_SendCmd_AutoIdentify(0xFFFF,0);
	ret = FP_RcvDeal(PS_AutoIdentify);
	if(ret == PS_OK)//搜索成功
		{
		//比对成功 开门语音
		VOICE(2,0);//-锁已开启请按把手//
		MOTO_Forward();
		SETBIT(Sys_State,Bs_DOOR_OPEN);
		return 0;
		}
	else if(ret == PS_NOT_SEARCHED)
		{
		VOICE(20,0);//-你未授权请与管理员联系
		}
	else if(ret == PS_TIME_OUT)
		{
		VOICE(12,0);//-请输入用户指纹
		}
	
	return ret; 

}
uint8 CmdDeleteChar(uint16 UserID)
{
	uint8 ret;

	FP_SendCmd_DeleteChar(UserID,1);
	ret = FP_RcvDeal(0);
	if(ret == 0)
		{
		
		return 0;
		}
		
		
	return ret; 
}
uint8 CmdEmpty(void)
{
	uint8 ret;

	FP_SendCmd_Empty();
	ret = FP_RcvDeal(0);
	if(ret == PS_OK)
		{
		
		return 0;
		}
	else
		{
		VOICE(18,0);//-指纹-删除失败
		return ret; 
		}
		
		

}


void FP_MAIN(void)
{
	//Sys_Task = PS_AutoIdentify;//PS_AutoEnroll;//默认为验证开门
	UINT16 UserID;

	switch(Sys_Task)
		{
		case PS_AutoEnroll://添加指纹
			//GotoSleep_cnt=0;
			if(TESTBIT(Sys_Key,Bk_FP_TOUCH))//指纹
				{
				CLRBIT(Sys_Key,Bk_FP_TOUCH);
				Sys_Channel = Sc_Fp;
				}
			else
				break;//通过状态读取选择通道(卡-密-指纹)
			if((TESTBIT(Sys_Pswd,Bp_ADMINPASSWORD_OK))&&(Sys_Channel == Sc_Fp))
				{
				ClearPassWord();//密码使用后清空
				//CLRBIT(Sys_Pswd,Bp_CHECK_ADMINPASSWORD);//验证管理员完成
				VOICE(12,0);//-请输入用户指纹
				FP_POWER_ON();
				//UserID = LOCK_MENU_KEY();//可以改为键盘输入用户ID
				UserID = 0;
				CmdAutoEnroll(UserID);
				}
			break;
		case PS_AutoIdentify://验证指纹
			if((TESTBIT(Sys_Key,Bk_FP_TOUCH))&&(TESTBIT(Sys_State,Bs_DOOR_OPEN)==0))//指纹
				{//GotoSleep_cnt=0;
				CLRBIT(Sys_Key,Bk_FP_TOUCH);
				if(GET_FP_Touch()==1)//手指还在指纹头上
					{
					FP_POWER_ON();
					CmdAutoIdentify();
					FP_POWER_OFF();
					}
				}		
			break;
		case PS_DeleteChar://删除指纹
			//CmdDeleteChar();
			break;
		case PS_Empty://清空指纹
			//GotoSleep_cnt=0;
			FP_POWER_ON();
			CmdEmpty();
			break;
		default:
			break;	
		}
}




