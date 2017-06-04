////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// ��Ȩ:     ������Ƽ����Źɷ����޹�˾
// �ļ���:   
// �汾��    v1.0
// ��������: IAR  v5.30
// ����:     �ں���
// ��������: 2013.12
// ����:      API
// ����ļ�: 
// �޸���־��
////////////////////////////////////////////////////////////////////////////////
#include "SX1276_App.h"

////////////////////////////////////////////////////////////////////////////////
// �������� : RF�������ݰ�
// ������� : uint8_t*data����������ָ�룬uint8_t size�������ݳ���
// ���ز��� : ��
// ˵��     : ���ݷ�����ɺ�DIO0�ӵ͵�ƽ��ɸߵ�ƽ��ÿ�ε��ô˺��������Զ��Ƚ�DIO0��Ϊ�ͣ��ȴ��ߵ�ƽ
////////////////////////////////////////////////////////////////////////////////
void RF_SendPacket(uint8_t*cbuf,uint8_t csize)
{
    unsigned long int j=8000000;//16777215;                   //��ʱ�ã��û���Ҫ����ʵ�����������
//    SX_DIO0_DIR=0;                                  //����Ϊ����
//    DIO0_IFG_CLR;//DIO0_IFG = 0;                                   //���DIO0��־λ
//    DIO0_IES_UP;//DIO0_IES = 0;                                   //����DIO0�����ش�����ʽ 
//    DIO0_IE = 0;                                    //��ֹDIO0�ж�
	Init_LoraIO_DIO0_EXTIoff();

    SX1276_TxPacket(cbuf,csize);                    //��������
    //while((!DIO0_IFG)&&j)j--;                               //�ȴ�GDIO0��ƽΪ��
//    while((!DIO0_IN)&&j)j--;
//    DIO0_IFG_CLR;//DIO0_IFG = 0;                                   //����жϱ�־λ

	  while((!RF_R_DIO0)&&j)j--;


}
////////////////////////////////////////////////////////////////////////////////
// �������� : RF�������״̬
// ������� : uint8_t cclen  �ɱ����ݰ���Ч���̶����ݰ�ʱΪ����ֵ
// ���ز��� : ��
// ˵��     : ����������ɺ�DIO0�ӵ͵�ƽ��ɸߵ�ƽ��
////////////////////////////////////////////////////////////////////////////////
void RF_RXmode(uint8_t cclen)
{
    Rx_mode(cclen);                      //RF���ջ��л���RXģʽ
//    SX_DIO0_DIR = 0;                     //������
//    DIO0_IFG_CLR;//DIO0_IFG = 0;                        //���DIO0�жϱ�־λ
//    DIO0_IES_UP;//DIO0_IES = 0;                        //����DIO0�����ش�����ʽ
//    DIO0_IE = 1;                         //ʹ��DIO0�ж�
	Init_LoraIO_DIO0();
}

////////////////////////////////////////////////////////////////////////////////
// �������� : RF����Sleep״̬
// ������� : ��
// ���ز��� : ��
// ˵��     : ��
////////////////////////////////////////////////////////////////////////////////
void RF_Sleepmode(void)
{
    SX1276Write( REG_LR_OPMODE, 0x80|RFLR_OPMODE_STANDBY );     
    SX1276Write(REG_LR_IRQFLAGS,0xff);                           
    SX1276Write( REG_LR_OPMODE, 0x80|RFLR_OPMODE_SLEEP );       
    //PA_RX_OUT = 0;           //PA_RX ��ʼ�����Ϊ0
    //PA_TX_OUT = 0;           //PA_TX ��ʼ�����Ϊ0   Ŀ���ǽ��ʹ�������
}
////////////////////////////////////////////////////////////////////////////////
// �������� : RF  CAD��ʼ��
// ������� : ��
// ���ز��� : ��
// ˵��     : DIO1--CADDetected    DIO3---CADDone
////////////////////////////////////////////////////////////////////////////////
void RF_CADinit(void)
{
    SX1276Write( REG_LR_OPMODE, 0x80|RFLR_OPMODE_STANDBY );   
    SX1276Write( REG_LR_PREAMBLEMSB,0xf0);
    SX1276Write( REG_LR_PREAMBLELSB,0xff);
    SX1276Write( REG_LR_IRQFLAGSMASK,\
	~(RFLR_IRQFLAGS_CADDONE|RFLR_IRQFLAGS_CADDETECTED));
    //
    SX1276Write( REG_LR_DIOMAPPING1,\
	RFLR_DIOMAPPING1_DIO3_00 | RFLR_DIOMAPPING1_DIO1_10);
    //SX1276WriteRxTx(false);     //set RF switch to RX path
    SX1276Write(REG_LR_IRQFLAGS,0xff);     
}
////////////////////////////////////////////////////////////////////////////////
// �������� : RF����CAD�������ŵ����һ��
// ������� : ��
// ���ز��� : ��
// ˵��     :   ����ʱ��ԼΪ(2^SF+32)/BW
////////////////////////////////////////////////////////////////////////////////
void RF_CAD_Sample(void)
{
    //SX1276WriteRxTx(false);     //set RF switch to RX path
    SX1276Write( REG_LR_OPMODE, 0x80|RFLR_OPMODE_STANDBY );   
    SX1276Write( REG_LR_OPMODE, 0x80|RFLR_OPMODE_CAD ); 
}
////////////////////////////////////////////////////////////////////////////////
// �������� : WOR��ʼ��
// ������� : ��
// ���ز��� : ��
// ˵��     :   DIO1 :�����ж�   DIO3��CAD��ʱ�жϣ�Ҳ������Ϊ�ǽ��ռ���жϣ�
////////////////////////////////////////////////////////////////////////////////
void RF_WORInit(void)
{
//    RF_CADinit();        //CAD���ܳ�ʼ��
//    //CADDoneʹ��
//    SX_DIO3_DIR=0;                       //������
//    DIO3_IFG_CLR;//DIO3_IFG = 0;                        //����жϱ�־λ
//    DIO3_IES_UP;//DIO3_IES = 0;                        //���������ش�����ʽ
//    DIO3_IE = 1;                         //ʹ��DIO3�ж�
//    //CADDetectedʹ��
//    SX_DIO1_DIR=0;                       //������
//    DIO1_IFG_CLR;//DIO1_IFG = 0;                        //����жϱ�־λ
//    DIO1_IES_UP;//DIO1_IES = 0;                        //���������ش�����ʽ
//    DIO1_IE = 1;                         //ʹ��DIO1�ж�
//    //�ر�DIO0�����ж�ʹ��
//    DIO0_IE = 0;                         //�ر�DIO0�ж�
}
////////////////////////////////////////////////////////////////////////////////
// �������� : ִ��WOR����
// ������� : uint8_t cclen  0������˯�ߡ�1������CAD���ģʽ
// ���ز��� : ��
// ˵��     :   
////////////////////////////////////////////////////////////////////////////////
/*void RF_WOR_Execute(uint8_t cclen)
{
    switch(cclen)
    {
        case 0:   //����˯��
                  LSD_RF_Sleepmode();      
                  ON_Sleep_Timerout();     //����˯�߳�ʱ��ʱ��
                  break;
        case 1:   //����CAD���ģʽ
                  OFF_Sleep_Timerout();    //�ر�˯�߳�ʱ��ʱ��
                  LSD_RF_CAD_Sample();     //����CADһ�� 
                  
                  break;
        default:  break;
    }
}*/
////////////////////////////////////////////////////////////////////////////////
// �������� : WOR��RX
// ������� : ��
// ���ز��� : ��
// ˵��     : �˳�WOR������RXģʽ��ǰ��preamble��Ȼ�����������ֵ��
////////////////////////////////////////////////////////////////////////////////
void RF_WOR_Exit(uint8_t cclen)
{
    //OFF_Sleep_Timerout();
    SX1276Write( REG_LR_OPMODE, 0x80|RFLR_OPMODE_STANDBY );    
    SX1276Write( REG_LR_PAYLOADLENGTH,cclen);                    
    SX1276Write( REG_LR_IRQFLAGSMASK, ~(RFLR_IRQFLAGS_RXDONE)); 
    SX1276Write( REG_LR_DIOMAPPING1, RFLR_DIOMAPPING1_DIO0_00 );
    //SX1276WriteRxTx(false);                                     
    SX1276Write( REG_LR_FIFOADDRPTR,0x00);                      
    SX1276Write(REG_LR_IRQFLAGS,0xff);                          
    SX1276Write( REG_LR_OPMODE, 0x80|RFLR_OPMODE_RECEIVER );    
//    SX_DIO0_DIR = 0;                     //������
//    DIO0_IFG_CLR;//DIO0_IFG = 0;                        //���DIO0�жϱ�־λ
//    DIO0_IES_UP;//DIO0_IES = 0;                        //����DIO0�����ش�����ʽ
//    DIO0_IE = 1;                         //ʹ��DIO0�ж�
	Init_LoraIO_DIO0();

//    DIO1_IE = 0;                         //��ֹDIO1
//    DIO3_IE = 0;                         //��ֹDIO3
    Init_LoraIO_DIO1_EXTIoff();
	Init_LoraIO_DIO3_EXTIoff();
}

////////////////////////////////////////////////////////////////////////////////
// �������� : RF���ͻ��Ѱ�
// ������� : uint8_t*data����������ָ�룬uint8_t size�������ݳ���
// ���ز��� : ��
// ˵��     : 
////////////////////////////////////////////////////////////////////////////////
void RF_Awake(uint8_t*cbuf,uint8_t csize)
{
//    SX_DIO0_DIR = 0;
//    DIO0_IFG_CLR;//DIO0_IFG = 0;                                   //���DIO0��־λ
//    DIO0_IES_UP;//DIO0_IES = 0;                                   //����DIO0�����ش�����ʽ 
//    DIO0_IE = 0;                                    //��ֹDIO0�ж�
	Init_LoraIO_DIO0_EXTIoff();

    SX1276Write( REG_LR_OPMODE, 0x80|RFLR_OPMODE_STANDBY );      
    SX1276Write( REG_LR_PAYLOADLENGTH,csize);                    
    //SX1276WriteRxTx(true);                                      
    SX1276Write( REG_LR_FIFOADDRPTR,0x80);                      
    SX1276WriteBuffer(REG_LR_FIFO,cbuf,csize);                   
    SX1276Write(REG_LR_IRQFLAGS,0xff);                          
    SX1276Write( REG_LR_IRQFLAGSMASK, ~(RFLR_IRQFLAGS_TXDONE));  
    SX1276Write( REG_LR_DIOMAPPING1, RFLR_DIOMAPPING1_DIO0_01 );
    SX1276Write( REG_LR_PREAMBLEMSB,0x03);//set preamble length
    SX1276Write( REG_LR_PREAMBLELSB,0xEC);//set preamble length
    SX1276Write( REG_LR_OPMODE, 0x80|RFLR_OPMODE_TRANSMITTER );  
    //while((!DIO0_IFG));                                         //�ȴ�GDIO0��ƽΪ��
    //while((!DIO0_IN));
 	while((!RF_R_DIO0));
    //DIO0_IFG_CLR;//DIO0_IFG = 0;                                               //����жϱ�־λ
    //�����껽�����ݰ��󣬽�ǰ��ʱ��Ļ�����Ĭ��ֵ��
    SX1276Write( REG_LR_OPMODE, 0x80|RFLR_OPMODE_STANDBY );     
    SX1276Write( REG_LR_PREAMBLEMSB,0);//set preamble length
    SX1276Write( REG_LR_PREAMBLELSB,12);//set preamble length
    
}
//******************************************************************************************
