
#ifndef _FP_H_
#define _FP_H_

//指纹头指令
#define PS_GetImage				0x01			
#define PS_GenChar				0x02
#define PS_Match				0x03
#define PS_Search				0x04
#define PS_RegModel				0x05
#define PS_StoreChar			0x06
#define PS_LoadChar				0x07
#define PS_UpChar				0x08
#define PS_DownChar				0x09
#define PS_UpImage				0x0a
#define	PS_DownImage			0x0b
#define PS_DeleteChar			0x0c
#define PS_Empty				0x0d
#define	PS_WriteReg				0x0e
#define PS_ReadSysPara			0x0f
#define PS_Enroll				0x10
#define PS_Identify				0x11
#define PS_SetPwd				0x12
#define PS_VfyPwd				0x13
#define PS_GetRandomCode		0x14
#define PS_SetChipAddr			0x15
#define PS_ReadINFpage			0x16
#define PS_Port_Control			0x17
#define PS_WriteNotepad			0x18
#define PS_ReadNotepad			0x19
#define PS_BurnCode				0x1a
#define PS_HighSpeedSearch		0x1b
#define PS_GenBinImage			0x1c
#define PS_ValidTempleteNum		0x1d
#define PS_UserCommand			0x1e// 这里实际上是灯控制函数
#define PS_ReadIndexTable       0x1f//读取模版索引表 

// 这些命令用于获取原始图像和调试传感器参数，使用SynoDemo V2.9 
#define PS_GetRawImg            0x20 
#define PS_SetCmosPara          0x21
#define PS_GetCmosPara          0x22

#define PS_UpLumCommand         0x24 // Chris add for plbk 20090604
#define PS_GetTestImage         0x25 // Chris add for plbk 20090604
#define PS_UpTestImage          0x26 // Chris add for plbk 20090604
#define PS_GetImagDirect        0x27 // Chris add for plbk 20090604
//#define PS_ISP                  0x28 // Chris add for ADEL 20091110
#define PS_GetEnrollImage       0x29 //add for enroll getimage

#define PS_Cancle       		0x30//取消命令
#define PS_AutoEnroll       	0x31//自动注册模板
#define PS_AutoIdentify       	0x32//自动验证指纹
#define PS_Sleep		       	0x33//睡眠
#define PS_GetChipSN			0x34//获取芯片唯一序列号
#define PS_HandShake		    0x35//握手指令
#define PS_CheckSensor		    0x36//校验传感器


/*General Return Code */
#define RT_OK            0x00 //success
#define RT_FAIL          0x01  //fail
#define RT_COMMAND_ERR   0x02  //command error
#define RT_PARAM_ERR     0x03  //param error
#define RT_OVERTIME      0x04  //over time
#define RT_ECC_ERR       0x05  //ecc error
#define RT_WRITE_ERR     0x06  //write flash err
#define RT_READ_ERR      0x07  //read flash err

//错误返回码
#define PS_OK                	0x00
#define PS_COMM_ERR          	0x01
#define PS_NO_FINGER         	0x02
#define PS_GET_IMG_ERR       	0x03
#define PS_FP_TOO_DRY        	0x04
#define PS_FP_TOO_WET       	0x05
#define PS_FP_DISORDER       	0x06
#define PS_LITTLE_FEATURE    	0x07
#define PS_NOT_MATCH         	0x08
#define PS_NOT_SEARCHED      	0x09
#define PS_MERGE_ERR         	0x0a
#define PS_ADDRESS_OVER      	0x0b
#define PS_READ_ERR          	0x0c
#define PS_UP_TEMP_ERR       	0x0d
#define PS_RECV_ERR          	0x0e
#define PS_UP_IMG_ERR        	0x0f
#define PS_DEL_TEMP_ERR      	0x10
#define PS_CLEAR_TEMP_ERR    	0x11
#define PS_SLEEP_ERR         	0x12
#define PS_INVALID_PASSWORD  	0x13
#define PS_RESET_ERR         	0x14
#define PS_INVALID_IMAGE     	0x15
#define PS_HANGOVER_UNREMOVE 	0X17
#define PS_FLASH_ERR         	0x18
#define PS_TRNG_ERR         	0x19
#define PS_INVALID_REG       	0x1a
#define PS_ENROLL_ERR        	0x1e
#define PS_LIB_FULL_ERR      	0x1f
#define PS_DEVICE_ADDR_ERR   	0x20
#define PS_MUST_VERIFY_PWD   	0x21

#define PS_TMPL_NOT_EMPTY    	0x22
#define PS_TMPL_EMPTY    	 	0x23
#define PS_LIB_EMPTY_ERR      	0x24
#define PS_TMPL_NUM_ERR		 	0x25
#define PS_TIME_OUT			 	0x26
#define PS_FP_DUPLICATION	 	0x27
#define PS_RELATE         		0x28
#define PS_SENSOR_ERR         	0x29


#define PS_NEED_FP_TIMES	 0x30







void FP_INIT(void);
void FP_lp_INIT(void);
UINT8 GET_FP_Touch(void);
void FP_POWER_ON(void);
void FP_POWER_OFF(void);
void FP_MAIN(void);
uint8 CmdEmpty(void);

#endif 		/* _FP_H_ */


