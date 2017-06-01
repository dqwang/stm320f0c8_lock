
#ifndef _DATABASE_H_
#define _DATABASE_H_


#define DB_TABLE_LOCKSTATE_ADDRS 	FLASH_USER_START_ADDR+0// 
#define DB_TABLE_USERID_ADDRS 		DB_TABLE_LOCKSTATE_ADDRS+0x100// 
#define DB_TABLE_FPID_ADDRS 		DB_TABLE_USERID_ADDRS+0x800//
#define DB_TABLE_CARDID_ADDRS 		DB_TABLE_FPID_ADDRS+0x800// 

#define DB_USERID_NUB 	100//
#define DB_FPID_NUB 	300
#define DB_CARDID_NUB 	30// 

#define DB_USERID_LEN 	16// 
#define DB_FPID_LEN 	4//
#define DB_CARDID_LEN 	32//


#define DB_TABLE_LOCKSTATE_LEN 	FLASH_PAGE_SIZE*1 // 
#define DB_TABLE_USERID_LEN 	FLASH_PAGE_SIZE*2//
#define DB_TABLE_FPID_LEN 		FLASH_PAGE_SIZE*2//
#define DB_TABLE_CARDID_LEN 	FLASH_PAGE_SIZE*2//
#define DB_TABLE_MAX_LEN 		FLASH_PAGE_SIZE*2//


#define DB_TURE 				0x55


#define DB_I_USERID_USED 		0
#define DB_I_USERID_FPNUB 		1
#define DB_I_USERID_CARDNUB 	2
#define DB_I_USERID_PSWD_USED 	3
#define DB_I_USERID_PSWD 		4


#define DB_I_FPID_USED 			0
#define DB_I_FPID_FORUSERID 	1


#define DB_I_CARDID_USED 		0
#define DB_I_CARDID_FORUSERID 	1
#define DB_I_CARDID_DATA 		2

/* Private typedef -----------------------------------------------------------*/
typedef enum {FAILED = 0, PASSED = !FAILED} TestStatus;
/* Private define ------------------------------------------------------------*/
#define FLASH_PAGE_SIZE         ((uint32_t)0x00000400)   /* FLASH Page Size */
#define FLASH_USER_START_ADDR   ((uint32_t)0x08006000)   /* Start @ of user Flash area */
#define FLASH_USER_END_ADDR     ((uint32_t)0x08007000)   /* End @ of user Flash area */
#define DATA_32                 ((uint32_t)0x12345678)



extern uint8 DB_Data[DB_TABLE_MAX_LEN];



UINT8 Flash_Read(UINT32 pos, UINT8 * buf, UINT32 len);
UINT8 Flash_Write(UINT32 pos, UINT8 * buf, UINT32 len);
uint8 Get_ADMIN_PASSWORD(uint8 *pswd);
uint8 Set_ADMIN_PASSWORD(uint8 *pswd);

uint16 FP_Get_Enroll_FPID(void);
uint16 FP_UPDATA_FPID(uint16 UserID,uint16 FpID);
uint16 KEYBD_Get_Enroll_USERID(void);
uint16 USER_Get_Enroll_USERID(void);
uint16 USER_UPDATA_USERID(uint16 UserID,uint8 * pswd);

uint16 CARD_Get_Enroll_CARDID(void);
uint16 CARD_UPDATA_CARDID(uint16 UserID,uint16 CardID,uint8 * pdata);
uint8 CARD_IDCheck(uint8 * cardid);


#endif 		/* _DATABASE_H_ */


