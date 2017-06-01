
#include "main.h"



uint8 DB_Data[DB_TABLE_MAX_LEN];


/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint32_t EraseCounter = 0x00, Address = 0x00;
uint32_t Data = 0x3210ABCD;
uint32_t NbrOfPage = 0x00;
__IO FLASH_Status FLASHStatus = FLASH_COMPLETE;
__IO TestStatus MemoryProgramStatus = PASSED;

/***************************************************************
FLASH读写
***************************************************************/
void Flash_Erase(UINT32 StartAddr,UINT32 Size)
{
	UINT32 Page=Size/FLASH_PAGE_SIZE;

	FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPERR); 
	FLASHStatus = FLASH_COMPLETE;
	FLASH_Unlock();
	while ((Page--) && FLASHStatus == FLASH_COMPLETE)
		{
		FLASHStatus = FLASH_ErasePage(StartAddr);
		StartAddr+=FLASH_PAGE_SIZE;
		}
	FLASH_Lock();
}


/***************************************************************
读
pos：地址
buf：读出数据缓冲区指针
len：读出数据字节数
***************************************************************/
UINT8 Flash_Read(UINT32 pos, UINT8 * buf, UINT32 len)
{
    UINT32 uc;
    
    for(uc=0;uc<len;uc++)
        //buf[uc] = *(__IO uint32_t *)(pos+uc);	//
        buf[uc] = *(__IO UINT8*)(pos+uc);	//read data(pos+uc);
	return 0;
}    

/***************************************************************
写
pos：地址
buf：写入数据缓冲区指针
len：写入数据字节数
***************************************************************/
UINT8 Flash_Write(UINT32 pos, UINT8 * buf, UINT32 len)
{
	UINT32 i;
	UINT16 buf16;
	UINT16 len16;
	
	len16 = len/2;
	//buf16 = (UINT16)buf;
	//擦除后写入
	Flash_Erase(pos,len);
	if (FLASHStatus!=FLASH_COMPLETE) return 1;//1:擦除错
	FLASH_Unlock();
	for(i=0;i<len16;i++)
		{
		buf16 = ((UINT16)buf[i*2+1]<<8) + buf[i*2];
		FLASHStatus=FLASH_ProgramHalfWord(pos+i*2,buf16);
		if (FLASHStatus!=FLASH_COMPLETE) return 2;//2:写入错
		}
	FLASH_Lock();
return 0;
}    

////////////////////////////////////////////////////////////////////
//系统
////////////////////////////////////////////////////////////////////
uint8 Get_LOCK_State(uint8 *sta)
{	
	Flash_Read(DB_TABLE_LOCKSTATE_ADDRS,DB_Data,DB_TABLE_LOCKSTATE_LEN);

	sta[0]=DB_Data[0];//0x55 锁已设置管理员

	return 0;
}
uint8 Set_LOCK_State(uint8 *sta)
{	
	Flash_Write(DB_TABLE_LOCKSTATE_ADDRS,sta,DB_TABLE_LOCKSTATE_LEN);
	return 0;
}
////////////////////////////////////////////////////////////////////
//密码
////////////////////////////////////////////////////////////////////
uint8 Get_ADMIN_PASSWORD(uint8 *pswd)
{	
	Flash_Read(DB_TABLE_USERID_ADDRS,DB_Data,DB_USERID_LEN);//DB_TABLE_USERID_ADDRS

	if(DB_Data[DB_I_USERID_USED] != DB_TURE)// 锁已设置管理员
		return 1;
	if(DB_Data[DB_I_USERID_PSWD_USED] != DB_TURE)
		return 2;
	memcpy(pswd,&DB_Data[DB_I_USERID_PSWD],PASSWORD_LEN);
	return 0;
}
uint8 Set_ADMIN_PASSWORD(uint8 *pswd)
{	
	DB_Data[DB_I_USERID_USED] = DB_TURE;
	DB_Data[DB_I_USERID_FPNUB] = 0;
	DB_Data[DB_I_USERID_CARDNUB] = 0;
	DB_Data[DB_I_USERID_PSWD_USED] = DB_TURE;
	memcpy(&DB_Data[DB_I_USERID_PSWD],pswd,PASSWORD_LEN);
	Flash_Write(DB_TABLE_USERID_ADDRS,DB_Data,DB_TABLE_USERID_LEN);
	return 0;
}

////////////////////////////////////////////////////////////////////
//指纹
////////////////////////////////////////////////////////////////////
uint16 FP_Get_Enroll_FPID(void)
{
	uint16 i;
	
	Flash_Read(DB_TABLE_FPID_ADDRS,DB_Data,DB_TABLE_FPID_LEN);
	for(i=0;i<DB_FPID_NUB;i++)
		{
		if(DB_Data[DB_FPID_LEN*i]!=DB_TURE)//指纹ID未启用
			{
			return i;
			}
		}
		return 0;
}
uint16 FP_UPDATA_FPID(uint16 UserID,uint16 FpID)
{
	uint8 newData[DB_FPID_LEN];
	
	Flash_Read(DB_TABLE_FPID_ADDRS,DB_Data,DB_TABLE_FPID_LEN);

	newData[DB_I_FPID_USED]=DB_TURE;//启用标识
	newData[DB_I_FPID_FORUSERID]=(uint8)UserID;//

	if(FpID>DB_FPID_NUB)
		return 1;//id超
	memcpy(&DB_Data[DB_FPID_LEN*FpID],newData,DB_FPID_LEN);

	Flash_Write(DB_TABLE_FPID_ADDRS,DB_Data,DB_TABLE_FPID_LEN);

	return 0;

}
////////////////////////////////////////////////////////////////////
//用户
////////////////////////////////////////////////////////////////////
uint16 KEYBD_Get_Enroll_USERID(void)
{
	uint16 i;
	
	Flash_Read(DB_TABLE_USERID_ADDRS,DB_Data,DB_TABLE_USERID_LEN);
	for(i=0;i<DB_USERID_NUB;i++)
		{
		if(DB_Data[DB_FPID_LEN*i]==0)//用户ID未启用
			{
			return i;
			}
		}
		return 0;
}
uint16 USER_Get_Enroll_USERID(void)
{
	uint16 i;
	
	Flash_Read(DB_TABLE_USERID_ADDRS,DB_Data,DB_TABLE_USERID_LEN);
	for(i=0;i<DB_USERID_NUB;i++)
		{
		if(DB_Data[DB_USERID_LEN*i]!=DB_TURE)//卡未启用
			{
			return i;
			}
		}
		return 0;
}

uint16 USER_UPDATA_USERID(uint16 UserID,uint8 * pswd)
{
	uint8 newData[DB_USERID_LEN];

	if(UserID == 0)return RT_FAIL;
	
	Flash_Read(DB_TABLE_USERID_ADDRS,DB_Data,DB_TABLE_USERID_LEN);

	newData[DB_I_USERID_USED]=DB_TURE;//启用标识
	newData[1]=(uint8)UserID;//
	newData[DB_I_USERID_FPNUB]=0;//
	newData[DB_I_USERID_CARDNUB]=0;//创建用户ID时数量为0
	newData[DB_I_USERID_PSWD_USED] = DB_TURE;
	memcpy(&newData[DB_I_USERID_PSWD],pswd,PASSWORD_LEN);
	if(UserID>DB_USERID_NUB)
		return RT_FAIL;//id超
	memcpy(&DB_Data[DB_USERID_LEN*UserID],newData,DB_USERID_LEN);

	Flash_Write(DB_TABLE_USERID_ADDRS,DB_Data,DB_TABLE_USERID_LEN);

	return 0;

}

////////////////////////////////////////////////////////////////////
//卡
////////////////////////////////////////////////////////////////////
uint16 CARD_Get_Enroll_CARDID(void)
{
	uint16 i;
	
	Flash_Read(DB_TABLE_CARDID_ADDRS,DB_Data,DB_TABLE_CARDID_LEN);
	for(i=0;i<DB_CARDID_NUB;i++)
		{
		if(DB_Data[DB_CARDID_LEN*i]!=DB_TURE)//卡未启用
			{
			return i;
			}
		}
		return 0;
}

uint16 CARD_UPDATA_CARDID(uint16 UserID,uint16 CardID,uint8 * pdata)
{
	uint8 newData[DB_CARDID_LEN],i=DB_I_CARDID_DATA;
	
	Flash_Read(DB_TABLE_CARDID_ADDRS,DB_Data,DB_TABLE_CARDID_LEN);

	newData[DB_I_CARDID_USED]=DB_TURE;//启用标识
	newData[DB_I_CARDID_FORUSERID]=(uint8)UserID;//
	newData[i++]=pdata[0];//卡号
	newData[i++]=pdata[1];//
	newData[i++]=pdata[2];//
	newData[i++]=pdata[3];//
	
	if(CardID>DB_CARDID_NUB)
		return 1;//id超
	memcpy(&DB_Data[DB_CARDID_LEN*CardID],newData,DB_CARDID_LEN);

	Flash_Write(DB_TABLE_CARDID_ADDRS,DB_Data,DB_TABLE_CARDID_LEN);

	return 0;

}

uint8 CARD_IDCheck(uint8 * cardid)
{
//	uint8 CardID[4];
	uint8 cardnub,psdi,iderr;
	
	Flash_Read(DB_TABLE_CARDID_ADDRS,DB_Data,DB_TABLE_CARDID_LEN);
	
	for(cardnub=0;cardnub<DB_CARDID_NUB;cardnub++)
		{	
		if(DB_Data[cardnub*DB_CARDID_LEN]==DB_TURE)//启用
			{
			iderr = RT_OK;
			for(psdi=0;psdi<CARDID_LEN;psdi++)
				{
				if(DB_Data[cardnub*DB_CARDID_LEN+DB_I_CARDID_DATA+psdi]!=cardid[psdi])
					{
					iderr = RT_FAIL;//一旦比对不上就退出
					break;
					}
				}
			if(iderr == RT_OK)//密码通过
				return RT_OK;
			}
		}
	return RT_FAIL;		


}






