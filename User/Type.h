/***************************************************************************************************
* File name    :	Type.h
* Function     :	Data type definition
* Author       : 	synochip
* Date         :	2009/03/31
* Version      :    v1.0
* Description  :
* ModifyRecord :
***************************************************************************************************/
#ifndef TYPE_H_
#define TYPE_H_

/* These types must be 16-bit, 32-bit or larger integer */
typedef int				INT;
typedef unsigned int	UINT;

/* These types must be 8-bit integer */
typedef signed char		CHAR;
typedef unsigned char	UCHAR;
typedef unsigned char	BYTE;

/* These types must be 16-bit integer */
typedef short			SHORT;
typedef unsigned short	USHORT;
typedef unsigned short	WORD;
typedef unsigned short	WCHAR;

/* These types must be 32-bit integer */
typedef long			LONG;
typedef unsigned long	ULONG;
typedef unsigned int	DWORD;

//------- BOOL type definition --------------
#ifndef	_BOOL_TYPE_
#define	_BOOL_TYPE_
typedef	unsigned char 	BOOL;
typedef unsigned char   bool;
#define FALSE	0
#define TRUE	1
#define false 	0
#define true  	1
#endif

//------- uint8 type definition --------------
#ifndef	_uint8_TYPE_
#define _uint8_TYPE_
typedef unsigned char  uint8;
#endif

//------- uint16 type definition --------------
#ifndef	_uint16_TYPE_
#define _uint16_TYPE_
typedef unsigned short 	uint16;
#endif

//------- UINT8 type definition --------------
#ifndef	_uint8_t_TYPE_
#define _uint8_t_TYPE_
typedef unsigned char  uint8_t;
#endif

//------- UINT16 type definition --------------
#ifndef	_uint16_t_TYPE_
#define _uint16_t_TYPE_
//typedef unsigned short 	uint16_t;
#endif

//------- UINT32 type definition --------------
//#ifndef	_uint32_t_TYPE_
//#define _uint32_t_TYPE_
//typedef unsigned long  uint32_t;
//#endif

//------- UINT8 type definition --------------
#ifndef	_UINT8_TYPE_
#define _UINT8_TYPE_
typedef unsigned char  UINT8;
#endif

//------- UINT16 type definition --------------
#ifndef	_UINT16_TYPE_
#define _UINT16_TYPE_
typedef unsigned short 	UINT16;
#endif

//------- UINT32 type definition --------------
#ifndef	_UINT32_TYPE_
#define _UINT32_TYPE_
typedef unsigned long  UINT32;
#endif

//------- UINT64 type definition --------------
#ifndef	_UINT64_TYPE_
#define _UINT64_TYPE_
typedef unsigned long long UINT64;
#endif


//-------- INT8 type definition --------------
#ifndef	_INT8_TYPE_
#define _INT8_TYPE_
typedef char  INT8;
#endif

//-------- INT16 type definition --------------
#ifndef	_INT16_TYPE_
#define _INT16_TYPE_
typedef short 	INT16;
#endif

//-------- INT32 type definition --------------
#ifndef	_INT32_TYPE_
#define _INT32_TYPE_
typedef long  INT32;
#endif

//------- INT64 type definition --------------
#ifndef	_INT64_TYPE_
#define _INT64_TYPE_
typedef long long INT64;
#endif

//------- VUINT8 type definition --------------
#ifndef	_VUINT8_TYPE_
#define _VUINT8_TYPE_
typedef volatile unsigned char  VUINT8;
#endif

//------- VUINT16 type definition --------------
#ifndef	_VUINT16_TYPE_
#define _VUINT16_TYPE_
typedef volatile unsigned short 	VUINT16;
#endif

//------- VUINT32 type definition --------------
#ifndef	_VUINT32_TYPE_
#define _VUINT32_TYPE_
typedef volatile unsigned long  VUINT32;
#endif

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef unsigned char U8;
typedef unsigned short U16;
typedef unsigned int U32;



//--------------return code-------------
#define RT_OK            0x00 //success
#define RT_FAIL          0x01  //fail
#define RT_COMMAND_ERR   0x02  //command error
#define RT_PARAM_ERR     0x03  //param error
#define RT_OVERTIME      0x04  //over time
#define RT_ECC_ERR       0x05  //ecc error
#define RT_WRITE_ERR     0x06  //write flash err
#define RT_READ_ERR      0x07  //read  flash err
#define RT_BACK          0x08  //menu back
#define RT_LATE          0x30 //late
#define RT_CARD_ERR      0x11 //ERR CARD
#define RT_EARLY         0x20 //early 
#define RT_LATE          0x30 //late

#define RT_DISTIME       0x10 //Disable User or Group Time
#define RT_ALARM         0x0a //Duress User
#define RT_RTIMEOUT      0x0b //temp time out
#define RT_RTIMEIN       0x0c //temp time in
#define RT_COMBO_S       0x0d //combo goon
#define RT_COMBO_E       0x0e //combo end success
#define RT_ACC_LAST      0x0F //last acc err

#define RT_GOONINPUT     0x1f //set value goon 
#define RT_CHECK_VT      0x2f //check self vt
#define RT_CMOS_ERR      0x31

typedef struct{
      unsigned int bit0 :1;
      unsigned int bit1 :1;
      unsigned int bit2 :1;
      unsigned int bit3 :1;
      unsigned int bit4 :1;
      unsigned int bit5 :1;
      unsigned int bit6 :1;
      unsigned int bit7 :1;
      }tData8bits;
#endif /*TYPE_H_*/
