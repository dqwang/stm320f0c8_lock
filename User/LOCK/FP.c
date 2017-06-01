
#include "main.h"


const uint8 FpProtocol_H[7]={0xEF,0x01,0xFF,0xFF,0xFF,0xFF,0x01};// ��ͷ 2
//const uint8 FpProtocol_ChipAddrs[4]={0xFF,0xFF,0xFF,0xFF};//оƬ��ַ4

void GPIO_INIT_Touch(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; //GPIO ����
	EXTI_InitTypeDef EXTI_InitStructure; //�ⲿ�ж϶���
	NVIC_InitTypeDef NVIC_InitStructure; //Ƕ���ж϶���
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOA, ENABLE);					  											 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;                 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

    //��EXTI0ָ��PA8  
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA,EXTI_PinSource8);  
    //EXTI0�ж�������  
//    EXTI_InitTypeDef EXTI_InitStructure;  
    EXTI_InitStructure.EXTI_Line=EXTI_Line8;  
    EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;  
    EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Rising;  //����ָ�ߵ�ƽ
    EXTI_InitStructure.EXTI_LineCmd=ENABLE;  
    EXTI_Init(&EXTI_InitStructure);  

    //EXTI0�ж���������  
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
	commdelay(0,FPMODULE_POWERON_OUTTIME,flag_RX_finish);//�ȴ�ģ������
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
	SendBuf[7+i++]=0x00;//������
	SendBuf[7+i++]=0x08;//������
	SendBuf[7+i++]=PS_AutoIdentify;//ָ��
	SendBuf[7+i++]=2;//��ȫ�ȼ� 
	SendBuf[7+i++]=(uint8)(Identify_ID>>8);//ID �� 
	SendBuf[7+i++]=(uint8)Identify_ID;//ID �� 
	SendBuf[7+i++]=(uint8)(Parameter>>8);//����  
	SendBuf[7+i++]=(uint8)(Parameter);//����  
	chksum = countsum(&SendBuf[6],i+1);
	SendBuf[7+i++]=(uint8)(chksum>>8);//У��  
	SendBuf[7+i++]=(uint8)chksum;//У��

	uart_send(SendBuf,7+i);

	return 0;

}

uint8 FP_SendCmd_AutoEnroll(uint16 Enroll_ID)
{
	uint8 i=0;
	uint16 chksum;

	memcpy(SendBuf,FpProtocol_H,7);
	SendBuf[7+i++]=0x00;//������
	SendBuf[7+i++]=0x08;//������
	SendBuf[7+i++]=PS_AutoEnroll;//ָ��
	SendBuf[7+i++]=(uint8)(Enroll_ID>>8);//ID �� 
	SendBuf[7+i++]=(uint8)Enroll_ID;//ID �� 
	SendBuf[7+i++]=2;//¼�����  
	SendBuf[7+i++]=0;//����  
	SendBuf[7+i++]=0;//����  
	chksum = countsum(&SendBuf[6],i+1);
	SendBuf[7+i++]=(uint8)(chksum>>8);//У��  
	SendBuf[7+i++]=(uint8)chksum;//У��

	uart_send(SendBuf,7+i);

	return 0;

}

uint8 FP_SendCmd_DeleteChar(uint16 PageID,uint16 PageN)
{
	uint8 i=0;
	uint16 chksum;

	memcpy(SendBuf,FpProtocol_H,7);
	SendBuf[7+i++]=0x00;//������
	SendBuf[7+i++]=0x07;//������
	SendBuf[7+i++]=PS_DeleteChar;//ָ��
	SendBuf[7+i++]=(uint8)(PageID>>8);//ID �� 
	SendBuf[7+i++]=(uint8)PageID;//ID �� 
	SendBuf[7+i++]=(uint8)(PageN>>8);//PageN  
	SendBuf[7+i++]=(uint8)(PageN);//  
	chksum = countsum(&SendBuf[6],i+1);
	SendBuf[7+i++]=(uint8)(chksum>>8);//У��  
	SendBuf[7+i++]=(uint8)chksum;//У��

	uart_send(SendBuf,7+i);

	return 0;

}
uint8 FP_SendCmd_Empty(void)
{
	uint8 i=0;
	uint16 chksum;

	memcpy(SendBuf,FpProtocol_H,7);
	SendBuf[7+i++]=0x00;//������
	SendBuf[7+i++]=0x03;//������
	SendBuf[7+i++]=PS_Empty;//ָ��
	chksum = countsum(&SendBuf[6],i+1);
	SendBuf[7+i++]=(uint8)(chksum>>8);//У��  
	SendBuf[7+i++]=(uint8)chksum;//У��

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
			uiRcvLen = uart_RDataLen;//���ݳ��� 
			uart_RDataLen = 0;

			for(i=0;i<uiRcvLen;i++)
				{// ��ʼ���Ŷ�λ
				if(uart_RBuf[i]==FpProtocol_H[0] && uart_RBuf[i+1]==FpProtocol_H[1])
				break;
				}
			offset = i;
			uiRcvLen = uiRcvLen - offset;//�������ݳ���
			if(uiRcvLen>0)//���յ���������û��ͷ������
				{
				memcpy(RcvBuf,(uart_RBuf+offset),uiRcvLen);
				while(uiRcvLen)
					{
					if(cmd == PS_AutoEnroll)//ע��
						{
						if((RcvBuf[9]==0x00)&&(RcvBuf[10]==0x06)&&(RcvBuf[11]==0xF2))//���һ����
							{
							return 0;//���̽�������
							}
						else if((RcvBuf[9]==0x00)&&(RcvBuf[10]==0x02)&&(RcvBuf[11]==0x01))//��һ��ͼ�ɼ��ɹ�
							{
							VOICE(15,0);//-���ٴ�����ͬһöָ��
							}
						if(uiRcvLen >= 14)//���հ�����14�ֽ�
							uiRcvLen -= 14;
						if(uiRcvLen<14)uiRcvLen=0;
						}
					else if(cmd == PS_AutoIdentify)//��֤
						{
						if((RcvBuf[10]==0x5))//05��ȷ�������ɹ�
							{
							if(RcvBuf[9] == PS_OK)
								return PS_OK;//���̽�������
							else
								return PS_NOT_SEARCHED;//�ȶ�ʧ��
							}		
						else if((RcvBuf[10]==0x1))//01��ȷ�ϲ�ͼ�ɹ�
							{
							if(RcvBuf[9] == PS_OK)
								VOICE(1,0);//-��
							else
								return PS_TIME_OUT;//�ȶ�ʧ��								
							
							}
						else if((RcvBuf[10]==0x0))
							{
							VOICE(1,0);//-��							
							}
						if(uiRcvLen >= 17)//���հ�����14�ֽ�
							uiRcvLen -= 17;
						if(uiRcvLen<17)uiRcvLen=0;
						}
					else if(cmd == 0)//ͨ��ȷ����
						if(RcvBuf[9] == PS_OK)
							return 0;//ֱ�ӳɹ�
					}
				}
			}
//		else
//			{
//			return 2;//��ʱ�޷���
//			}
		}
		
		return PS_TIME_OUT;//������
}


uint8 CmdAutoEnroll(uint16 UserID)
{
	uint8 ret;
	uint16 Enroll_ID;

	Enroll_ID = FP_Get_Enroll_FPID();
	FP_SendCmd_AutoEnroll(Enroll_ID);
	ret = FP_RcvDeal(PS_AutoEnroll);
	if(ret == 0)//ע��ɹ�
		{
		VOICE(2,0);//-�����ɹ�
		
		//����ָ������
		FP_UPDATA_FPID(UserID,Enroll_ID);
		//�����û�ID����
		KeyBD_State_Rst();
		Sys_Task = PS_AutoIdentify;//����ʱΪ�ȶ�
		return 0;
		}
	else
		{	
		VOICE(21,0);//-���ʧ��
		return ret; 
		
		}
		
		
}
uint8 CmdAutoIdentify(void)
{
	uint8 ret;
//	uint16 Identify_ID;

	FP_SendCmd_AutoIdentify(0xFFFF,0);
	ret = FP_RcvDeal(PS_AutoIdentify);
	if(ret == PS_OK)//�����ɹ�
		{
		//�ȶԳɹ� ��������
		VOICE(2,0);//-���ѿ����밴����//
		MOTO_Forward();
		SETBIT(Sys_State,Bs_DOOR_OPEN);
		return 0;
		}
	else if(ret == PS_NOT_SEARCHED)
		{
		VOICE(20,0);//-��δ��Ȩ�������Ա��ϵ
		}
	else if(ret == PS_TIME_OUT)
		{
		VOICE(12,0);//-�������û�ָ��
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
		VOICE(18,0);//-ָ��-ɾ��ʧ��
		return ret; 
		}
		
		

}


void FP_MAIN(void)
{
	//Sys_Task = PS_AutoIdentify;//PS_AutoEnroll;//Ĭ��Ϊ��֤����
	UINT16 UserID;

	switch(Sys_Task)
		{
		case PS_AutoEnroll://���ָ��
			//GotoSleep_cnt=0;
			if(TESTBIT(Sys_Key,Bk_FP_TOUCH))//ָ��
				{
				CLRBIT(Sys_Key,Bk_FP_TOUCH);
				Sys_Channel = Sc_Fp;
				}
			else
				break;//ͨ��״̬��ȡѡ��ͨ��(��-��-ָ��)
			if((TESTBIT(Sys_Pswd,Bp_ADMINPASSWORD_OK))&&(Sys_Channel == Sc_Fp))
				{
				ClearPassWord();//����ʹ�ú����
				//CLRBIT(Sys_Pswd,Bp_CHECK_ADMINPASSWORD);//��֤����Ա���
				VOICE(12,0);//-�������û�ָ��
				FP_POWER_ON();
				//UserID = LOCK_MENU_KEY();//���Ը�Ϊ���������û�ID
				UserID = 0;
				CmdAutoEnroll(UserID);
				}
			break;
		case PS_AutoIdentify://��ָ֤��
			if((TESTBIT(Sys_Key,Bk_FP_TOUCH))&&(TESTBIT(Sys_State,Bs_DOOR_OPEN)==0))//ָ��
				{//GotoSleep_cnt=0;
				CLRBIT(Sys_Key,Bk_FP_TOUCH);
				if(GET_FP_Touch()==1)//��ָ����ָ��ͷ��
					{
					FP_POWER_ON();
					CmdAutoIdentify();
					FP_POWER_OFF();
					}
				}		
			break;
		case PS_DeleteChar://ɾ��ָ��
			//CmdDeleteChar();
			break;
		case PS_Empty://���ָ��
			//GotoSleep_cnt=0;
			FP_POWER_ON();
			CmdEmpty();
			break;
		default:
			break;	
		}
}




