/**
  ******************************************************************************
  * @file    Project/STM32F0xx_StdPeriph_Templates/stm32f0xx_it.c 
  * @author  MCD Application Team
  * @version V1.2.0
  * @date    22-November-2013
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_it.h"

#define sbi(ADDRESS,BIT) 	((ADDRESS->BSRR = BIT))	// Set bit
#define cbi(ADDRESS,BIT) 	((ADDRESS->BRR = BIT))	// Clear bit
#define	bis(ADDRESS,BIT)	(GPIO_ReadInputDataBit(ADDRESS,BIT))	// Is bit set?
#define	bic(ADDRESS,BIT)	(!GPIO_ReadInputDataBit(ADDRESS,BIT))	// Is bit clear
#define	toggle(ADDRESS,BIT)	(GPIO_WriteBit(ADDRESS,BIT,(BitAction)((1-GPIO_ReadOutputDataBit(ADDRESS,BIT)))))	// Toggle bit


/** @addtogroup STM32F0xx_StdPeriph_Templates
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M0 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{	
	// 10ms
	//ͨѶ��ʱʱ��
	if(comm_cnt>0)
		comm_cnt--;
	//�����ڳ�ʱʱ��
	if(sTimeOut_cnt>0)
		sTimeOut_cnt--;	
	//����0�������ݳ�ʱ����
	if(TESTBIT(sys_flag,flag_RX_start))
		{
		if(uart_cnt < UART_OUTTIME)  
			uart_cnt++;
		else	//�����ʱ������Ϊһ�����ݽ���
			{
			SETBIT(sys_flag,flag_RX_finish);//�����ݸ��±���
			CLRBIT(sys_flag,flag_RX_start);//���ݽ��ս���
			}
		}
	//����Ѱ��
	if(ReadCard_cnt != READCARD_OUTTIME_OFF)
		ReadCard_cnt++;
	if(ReadCard_cnt > READCARD_OUTTIME)
		{//Ѱ��
		ReadCard_cnt=0;
		if (PcdRequest(PICC_REQALL, Card_pTagType) == MI_OK)
			{   //��⵽�п�����
			//if (PcdAnticoll(g_ucTempbuf) == MI_OK)
			SETBIT(Sys_State,Bs_CARD_ON);//�п�
			}
		else
			CLRBIT(Sys_State,Bs_CARD_ON);
		}
	//���ž�Ĭ
	if(TESTBIT(Sys_State,Bs_DOOR_OPEN))
		{
		DoorOpen_cnt++;
		if(DoorOpen_cnt > DOOROPEN_OUTTIME)
			{
			MOTO_Back();
			CLRBIT(Sys_State,Bs_DOOR_OPEN);	
			DoorOpen_cnt=0;
			}

		}
	//��ʱ����
	if(GotoSleep_cnt<GOTOSLEEP_OUTTIME)
		{
		GotoSleep_cnt++;			
		}
}

/**
  * @brief  This function handles USART1 global interrupt request.
  * @param  None
  * @retval None
  */
void USART1_IRQHandler(void)
{
  if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
  {

  SETBIT(sys_flag,flag_RX_start);		  //��ʾ��ʼ��������
  if(uart_cnt >= UART_OUTTIME)	//�����ʱ������Ϊһ�����ݽ���
	  {
	  uart_RDataLen=0;
	  CLRBIT(sys_flag,flag_RX_finish);	//�����ݸ��±��	  
	  }
  uart_cnt = 0; 
  if(uart_RDataLen >= UART_RBUF_SIZE)
	  uart_RDataLen = 0;
  uart_RBuf[uart_RDataLen++] = USART_ReceiveData(USART1);

  }
}

//��ʱ��3�жϷ������
void TIM3_IRQHandler(void)   //TIM3�ж�
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //���TIM3�����жϷ������
		{
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);  //���TIMx�����жϱ�־ 
		
		}
}


void EXTI0_1_IRQHandler(void)
{  

}
void EXTI4_15_IRQHandler(void)
{  

    if((EXTI_GetITStatus(EXTI_Line7)!=RESET)&&((TESTBIT(Sys_State,Bs_CARD_ON)==0)))
    {  
		ReadCard_cnt=0;
		if (PcdRequest(PICC_REQALL, Card_pTagType) == MI_OK)
			{  
			SETBIT(Sys_State,Bs_CARD_ON);//�п�
			}
		else 
			{
	        SETBIT(Sys_Key,Bk_KEYBD_INT);
			Key_value = TSM12_Reading_Start();
			if(Key_value)
				{
				GotoSleep_cnt=0;
				VOICE(0,0);//-��
				while(TSM12_Reading_Start());
				Disp_KBD_Rst();
				if(Key_value == KEYBD_x)//ȡ��
					{
					memset(PassWord_Buf,0xFF,PASSWORD_BUF_LEN);
					PassWord_Buf_i=0;
					}
				else if(Key_value == KEYBD_c)//ȷ��
					{
					SETBIT(Sys_Pswd,Bp_PASSWORD_IN);
					}
				else 
					{
					PassWord_Buf[PassWord_Buf_i++] = Key_value;		
					if(PassWord_Buf_i>=PASSWORD_BUF_LEN)PassWord_Buf_i=PASSWORD_BUF_LEN-1;
					}
				}			
			}
    }  
    EXTI_ClearFlag(EXTI_Line7);  	

    if(EXTI_GetITStatus(EXTI_Line8)!=RESET)  
    {GotoSleep_cnt=0; 
        SETBIT(Sys_Key,Bk_FP_TOUCH);
    }  
    EXTI_ClearFlag(EXTI_Line8);  	//�˳��ж�ʱע�������־λ  

    if(EXTI_GetITStatus(EXTI_Line9)!=RESET)  
    {GotoSleep_cnt=0;   
        SETBIT(Sys_Key,Bk_KEY_LOGO);
    }  
    EXTI_ClearFlag(EXTI_Line9); 

    if(EXTI_GetITStatus(EXTI_Line14)!=RESET)  
    {GotoSleep_cnt=0;   
        SETBIT(Sys_Key,Bk_KEY_RST);
    }  
    EXTI_ClearFlag(EXTI_Line14); 

}

/******************************************************************************/
/*                 STM32F0xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f0xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
