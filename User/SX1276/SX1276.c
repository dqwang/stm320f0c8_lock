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
#include "SX1276.h"


//===================================�������===================================================

const unsigned char  Freq_Cal_Tab[]=
{
    0x75,0x80,0x00,//470MHz
    0x75,0xC0,0x00,//471MHz
    0x76,0x00,0x00,//472MHz
    0x76,0x40,0x00,//473MHz
    0x76,0x80,0x00,//474MHz
    0x76,0xC0,0x00,//475MHz
    0x77,0x00,0x00,//476MHz
    0x77,0x40,0x00,//477MHz
    0x77,0x80,0x00,//478MHz
    0x77,0xC0,0x00,//479MHz
    0x78,0x00,0x00,//480MHz
    0x78,0x40,0x00,//481MHz
    0x78,0x80,0x00,//482MHz
    0x78,0xC0,0x00,//483MHz
    0x79,0x00,0x00,//484MHz
    0x79,0x40,0x00,//485MHz
    0x79,0x80,0x00,//486MHz
    0x79,0xC0,0x00,//487MHz
    0x7A,0x00,0x00,//488MHz
    0x7A,0x40,0x00,//489MHz
    0x7A,0x80,0x00,//490MHz
    0x7A,0xC0,0x00,//491MHz
    0x7B,0x00,0x00,//492MHz
    0x7B,0x40,0x00,//493MHz
    0x7B,0x80,0x00,//494MHz
    0x7B,0xC0,0x00,//495MHz
    0x7C,0x00,0x00,//496MHz
    0x7C,0x40,0x00,//497MHz
    0x7C,0x80,0x00,//498MHz
    0x7C,0xC0,0x00,//499MHz
    0x7D,0x00,0x00,//500MHz
    0x7D,0x40,0x00,//501MHz
    0x7D,0x80,0x00,//502MHz
    0x7D,0xC0,0x00,//503MHz
    0x7E,0x00,0x00,//504MHz
    0x7E,0x40,0x00,//505MHz
    0x7E,0x80,0x00,//506MHz
    0x7E,0xC0,0x00,//507MHz
    0x7F,0x00,0x00,//508MHz
    0x7F,0x40,0x00,//509MHz
    0x7F,0x80,0x00,//510MHz
};
//===================================�Ӻ���===================================================
////////////////////////////////////////////////////////////////////////////////
// �������� : RF��ʼ��
// ������� : tSX127xInitPara initPara  ��������Init_LoRa_0_8K, Init_LoRa_4_8K , Init_LoRa_10k,
// ���ز��� : tSX127xError              ����ö������
// ˵��     :  ��ʼ��ʱ���ŵ���ʼ��Ĭ��Ϊ0�ŵ�
////////////////////////////////////////////////////////////////////////////////
tSX127xError SX127x_init(tSX127xInitPara initPara)
{
    uint8_t test = 0;
    if(initPara>Init_LoRa_10k)   //��������������
    {
        return PARAMETER_INVALID;  //��������
    }
    SX1276InitIo();                // PAIO�ڳ�ʼ��           
    SX1276Reset();                 //��λRF
    SX1276SPISetup();              //SPI��ʼ��

test=0x55;
    SX1276Read( REG_LR_VERSION, &test );            
	test++;
    //init Regs
    SX1276Write( REG_LR_OPMODE, RFLR_OPMODE_SLEEP );            
    SX1276Write( REG_LR_OPMODE, 0x80|RFLR_OPMODE_SLEEP );       
    SX1276Write( REG_LR_OPMODE, 0x80|RFLR_OPMODE_STANDBY );      
    SX1276Write( REG_LR_PACONFIG, 0xff );                      
    SX1276Write( REG_LR_PADAC, RFLR_PADAC_20DBM_ON );           
    SX1276Write( REG_LR_PARAMP,RFLR_PARAMP_1000_US);            
    SX1276Write( REG_LR_OCP,0x20|RFLR_OCP_TRIM_240_MA);         
    SX1276Write( REG_LR_PAYLOADLENGTH,2);                       
    //SX1276Write( REG_LR_MODEMCONFIG3,RFLR_MODEMCONFIG3_LOWDATARATEOPTIMIZE_ON|RFLR_MODEMCONFIG3_AGCAUTO_ON);      
	SX1276Write( REG_LR_MODEMCONFIG3,RFLR_MODEMCONFIG3_LOWDATARATEOPTIMIZE_OFF | RFLR_MODEMCONFIG3_AGCAUTO_ON); 
   // �����������Ż� 0-�ر� 1-���������ų��ȳ��� 16msʱ����� ����ȱʡ�ر�
   
    //BW,SF,CR,Header,CRC
//    SX1276Write( REG_LR_MODEMCONFIG2,0xFF);                       
//    SX1276Write( REG_LR_SYMBTIMEOUTLSB,0xFF);                       
    switch(initPara){
    case Init_LoRa_0_8K:
//        SX1276Write( REG_LR_MODEMCONFIG3,\
//            RFLR_MODEMCONFIG3_LOWDATARATEOPTIMIZE_ON|
//                RFLR_MODEMCONFIG3_AGCAUTO_ON);      
        
        SX1276Write( REG_LR_MODEMCONFIG1,\
            RFLR_MODEMCONFIG1_BW_125_KHZ+RFLR_MODEMCONFIG1_CODINGRATE_4_8+\
                RFLR_MODEMCONFIG1_IMPLICITHEADER_OFF); 
        SX1276Write( REG_LR_MODEMCONFIG2,\
            RFLR_MODEMCONFIG2_SF_9|RFLR_MODEMCONFIG2_RXPAYLOADCRC_ON);     
        SX1276Write( REG_LR_PREAMBLELSB,12);
        break;
    case Init_LoRa_4_8K:
//        SX1276Write( REG_LR_MODEMCONFIG3,\
//            RFLR_MODEMCONFIG3_LOWDATARATEOPTIMIZE_OFF|
//                RFLR_MODEMCONFIG3_AGCAUTO_OFF);      
        
        SX1276Write( REG_LR_MODEMCONFIG1,\
            RFLR_MODEMCONFIG1_BW_500_KHZ+RFLR_MODEMCONFIG1_CODINGRATE_4_8+\
                RFLR_MODEMCONFIG1_IMPLICITHEADER_OFF);
        SX1276Write( REG_LR_MODEMCONFIG2,\
            RFLR_MODEMCONFIG2_SF_8|RFLR_MODEMCONFIG2_RXPAYLOADCRC_ON);     
//        SX1276Write( REG_LR_PREAMBLEMSB,1);
        SX1276Write( REG_LR_PREAMBLELSB,12);
        break;
    case Init_LoRa_10k:
        SX1276Read( 0x31,&test);
        SX1276Write(  0x31,(test& 0xF8)|0x05);
        SX1276Write(  0x37,0x0C);       
//        SX1276Write( REG_LR_MODEMCONFIG3,\
//            RFLR_MODEMCONFIG3_LOWDATARATEOPTIMIZE_OFF|
//                RFLR_MODEMCONFIG3_AGCAUTO_ON);      
        
        SX1276Write( REG_LR_MODEMCONFIG1,\
            RFLR_MODEMCONFIG1_BW_500_KHZ+RFLR_MODEMCONFIG1_CODINGRATE_4_8+\
                RFLR_MODEMCONFIG1_IMPLICITHEADER_ON); 
        SX1276Write( REG_LR_MODEMCONFIG2,\
            RFLR_MODEMCONFIG2_SF_6|RFLR_MODEMCONFIG2_RXPAYLOADCRC_ON);     
//        SX1276Write( REG_LR_PREAMBLEMSB,4);
        SX1276Write( REG_LR_PREAMBLELSB,12);
        break;
    default:
        break;
    }
    if(!RF_FreqSet(0))    //����Ϊ0�ŵ�
      return SPI_READCHECK_WRONG;
    
    return NORMAL;
}
////////////////////////////////////////////////////////////////////////////////
// �������� : RF�������ݰ�
// ������� : uint8_t*data����������ָ�룬uint8_t size�������ݳ���
// ���ز��� : ��
// ˵��     : ����Ϊ�����ǣ� preamble�Ļ�Ĭ��ֵ
////////////////////////////////////////////////////////////////////////////////
void SX1276_TxPacket(uint8_t*data,uint8_t size)
{
    
    SX1276Write( REG_LR_OPMODE, 0x80|RFLR_OPMODE_STANDBY );      
    SX1276Write( REG_LR_PREAMBLEMSB,0);//set preamble length
    SX1276Write( REG_LR_PREAMBLELSB,12);//set preamble length
    SX1276Write( REG_LR_PAYLOADLENGTH,size);                    
    //SX1276WriteRxTx(true);                                      
    SX1276Write( REG_LR_FIFOADDRPTR,0x80);                      
    SX1276WriteBuffer(REG_LR_FIFO,data,size);                   
    SX1276Write(REG_LR_IRQFLAGS,0xff);                          
    SX1276Write( REG_LR_IRQFLAGSMASK, ~(RFLR_IRQFLAGS_TXDONE));
    SX1276Write( REG_LR_DIOMAPPING1, RFLR_DIOMAPPING1_DIO0_01 );
    SX1276Write( REG_LR_OPMODE, 0x80|RFLR_OPMODE_TRANSMITTER );  
}
////////////////////////////////////////////////////////////////////////////////
// �������� : RF�������״̬
// ������� : uint8_t clen �ɱ����ݰ��´�ֵ��Ч���̶����ݰ�Ϊ����ֵ
// ���ز��� : ��
// ˵��     : ������պ�preamble���û�Ĭ��ֵΪ
////////////////////////////////////////////////////////////////////////////////
void Rx_mode(uint8_t clen)
{
    SX1276Write( REG_LR_OPMODE, 0x80|RFLR_OPMODE_STANDBY );      
    SX1276Write( REG_LR_PREAMBLEMSB,0);
    SX1276Write( REG_LR_PREAMBLELSB,12);
    SX1276Write( REG_LR_PAYLOADLENGTH,clen);                    
    SX1276Write( REG_LR_IRQFLAGSMASK, ~(RFLR_IRQFLAGS_RXDONE)); 
    SX1276Write( REG_LR_DIOMAPPING1, RFLR_DIOMAPPING1_DIO0_00 );
    //SX1276WriteRxTx(false);                                     
    SX1276Write( REG_LR_FIFOADDRPTR,0x00);                      
    SX1276Write(REG_LR_IRQFLAGS,0xff);                          
    SX1276Write( REG_LR_OPMODE, 0x80|RFLR_OPMODE_RECEIVER );       
}
////////////////////////////////////////////////////////////////////////////////
// �������� : RF���տɱ����ݰ�
// ������� : uint8_t*cbuf��������ָ��,uint8_t *csize���س���ָ��
// ���ز��� : ��
// ˵��     : 
////////////////////////////////////////////////////////////////////////////////
void RF_RxVariPacket(uint8_t*cbuf,uint8_t *csize)
{
    SX1276Read(REG_LR_NBRXBYTES,csize);
    SX1276Write( REG_LR_FIFOADDRPTR,0x00);  
    SX1276ReadFifo(cbuf,*csize);              
    SX1276Write(REG_LR_IRQFLAGS,0xff);        
}
////////////////////////////////////////////////////////////////////////////////
// �������� : RF���չ̶����ݰ�
// ������� : uint8_t*cbuf��������ָ��,uint8_t csize���չ̶�����
// ���ز��� : ��
// ˵��     : ������10kʱֻ�ܲ��ù̶����ݰ�����
////////////////////////////////////////////////////////////////////////////////
void RF_RxFixiPacket(uint8_t*cbuf,uint8_t csize)
{
    SX1276Write( REG_LR_FIFOADDRPTR,0x00);  
    SX1276ReadFifo(cbuf,csize);              
    SX1276Write(REG_LR_IRQFLAGS,0xff);      
}
////////////////////////////////////////////////////////////////////////////////
// �������� : RF����SLEEP״̬
// ������� : ��
// ���ز��� : ��
// ˵��     : 
////////////////////////////////////////////////////////////////////////////////
void LSD_RF_SleepMode(void)
{
    SX1276Write( REG_LR_OPMODE, 0x80|RFLR_OPMODE_STANDBY );     
    SX1276Write( REG_LR_OPMODE, 0x80|RFLR_OPMODE_SLEEP );     
}
////////////////////////////////////////////////////////////////////////////////
// �������� : RF����standby״̬
// ������� : ��
// ���ز��� : ��
// ˵��     : 
////////////////////////////////////////////////////////////////////////////////
void LSD_RF_StandbyMode(void)
{
    SX1276Write( REG_LR_OPMODE, 0x80|RFLR_OPMODE_STANDBY );       
}
////////////////////////////////////////////////////////////////////////////////
// �������� : RF���벻ͬ�ŵ�
// ������� : uint8_t ch  ��Χ0-40
// ���ز��� : ��
// ˵��     : 
////////////////////////////////////////////////////////////////////////////////
uint8_t RF_FreqSet(uint8_t ch)
{         
    uint8_t test_FRFMSB = 0,test_FRFMID=0,test_FRFLSB=0;
    LSD_RF_StandbyMode();
    SX1276Write( REG_LR_FRFMSB,Freq_Cal_Tab[3*ch]);   //set frequency 
    SX1276Write( REG_LR_FRFMID,Freq_Cal_Tab[3*ch+1]);   
    SX1276Write( REG_LR_FRFLSB,Freq_Cal_Tab[3*ch+2]);
     
    SX1276Read(REG_LR_FRFMSB,&test_FRFMSB);
    SX1276Read(REG_LR_FRFMID,&test_FRFMID);
    SX1276Read(REG_LR_FRFLSB,&test_FRFLSB);
    
    if(test_FRFMSB !=Freq_Cal_Tab[3*ch])
      return 0;
    if(test_FRFMID !=Freq_Cal_Tab[3*ch+1])
      return 0;
    if(test_FRFLSB !=Freq_Cal_Tab[3*ch+2])
      return 0;
    return 1;
}

 
     
    
    
    
    
    
    
    
