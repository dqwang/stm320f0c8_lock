////////////////////////////////////////////////////////////////////////////////
// 版权:     利尔达科技集团股份有限公司
// 文件名:   
// 版本：    v1.0
// 工作环境: IAR  v5.30
// 作者:     佟亚波、于海波
// 生成日期: 2013.12
// 功能:      硬件接口定义
// 相关文件: 
// 修改日志：
////////////////////////////////////////////////////////////////////////////////
#ifndef __SX1276_HAL_H__
#define __SX1276_HAL_H__

#include "main.h"

//===================================RF硬件IO口定义===================================================

//RF_PW
#define RF_PW_H  		GPIO_SetBits(GPIOC,GPIO_Pin_13)
#define RF_PW_L  		GPIO_ResetBits(GPIOC,GPIO_Pin_13)

//RF_CS
#define RF_CS_H  		GPIO_SetBits(GPIOF,GPIO_Pin_6)
#define RF_CS_L  		GPIO_ResetBits(GPIOF,GPIO_Pin_6)

#define RF_RST_H  		GPIO_SetBits(GPIOA,GPIO_Pin_9)
#define RF_RST_L  		GPIO_ResetBits(GPIOA,GPIO_Pin_9)

//	//SX1276 DIO pins  I/O definitions
//	//DIO0为PC6口
//#define SX_DIO0_DIR         PC_DDR_DDR6         //DIO0 方向寄存器   
//#define DIO0_IFG            EXTI_SR1_P6F        //DIO0 中断标志位寄存器
//#define DIO0_IFG_CLR        EXTI_SR1_P6F = 1    //DIO0 清中断标记
//	//#define DIO0_IES            P2IES_bit.P4      //DIO0 触发方式寄存器，上升沿或下降沿
//#define DIO0_IES_UP         EXTI_CR2_P6IS = 1   //DIO0 上升沿触发
//#define DIO0_IE             PC_CR2_C26          //DIO0 中断使能寄存器
//#define DIO0_IN             PC_IDR_IDR6         //DIO0 输入寄存器

//	//DIO1为PC5口
//#define SX_DIO1_DIR         PC_DDR_DDR5         //DIO1 方向寄存器   
//#define DIO1_IFG            EXTI_SR1_P5F        //DIO1 中断标志位寄存器
//#define DIO1_IFG_CLR        EXTI_SR1_P5F = 1    //DIO1 清中断标记
//	//#define DIO1_IES            P2IES_bit.P3      //DIO1 触发方式寄存器，上升沿或下降沿
//#define DIO1_IES_UP         EXTI_CR2_P5IS = 1   //DIO1 上升沿触发
//#define DIO1_IE             PC_CR2_C25          //DIO1 中断使能寄存器
//#define DIO1_IN             PC_IDR_IDR5         //DIO1 输入寄存器

//	//DIO3为PB0口
//#define SX_DIO3_DIR         PB_DDR_DDR0         //DIO3 方向寄存器   
//#define DIO3_IFG            EXTI_SR1_P0F        //DIO3 中断标志位寄存器
//#define DIO3_IFG_CLR        EXTI_SR1_P0F = 1    //DIO3 清中断标记
//	//#define DIO3_IES            P2IES_bit.P2      //DIO3 触发方式寄存器，上升沿或下降沿
//#define DIO3_IES_UP         EXTI_CR1_P0IS = 1   //DIO3 上升沿触发
//#define DIO3_IE             PB_CR2_C20          //DIO3 中断使能寄存器
//#define DIO3_IN             PB_IDR_IDR0         //DIO3 输入寄存器

/*
//DIO3为PC5口
#define SX_DIO3_DIR         PC_DDR_DDR5         //DIO1 方向寄存器   
#define DIO3_IFG            EXTI_SR1_P5F        //DIO1 中断标志位寄存器
#define DIO3_IFG_CLR        EXTI_SR1_P5F = 1    //DIO1 清中断标记
//#define DIO1_IES            P2IES_bit.P3      //DIO1 触发方式寄存器，上升沿或下降沿
#define DIO3_IES_UP         EXTI_CR2_P5IS = 1   //DIO1 上升沿触发
#define DIO3_IE             PC_CR2_C25          //DIO1 中断使能寄存器
#define DIO3_IN             PC_IDR_IDR5         //DIO1 输入寄存器

//DIO1为PB0口
#define SX_DIO1_DIR         PB_DDR_DDR0         //DIO3 方向寄存器   
#define DIO1_IFG            EXTI_SR1_P0F        //DIO3 中断标志位寄存器
#define DIO1_IFG_CLR        EXTI_SR1_P0F = 1    //DIO3 清中断标记
//#define DIO3_IES            P2IES_bit.P2      //DIO3 触发方式寄存器，上升沿或下降沿
#define DIO1_IES_UP         EXTI_CR1_P0IS = 1   //DIO3 上升沿触发
#define DIO1_IE             PB_CR2_C20          //DIO3 中断使能寄存器
#define DIO1_IN             PB_IDR_IDR0         //DIO3 输入寄存器
*/
//SX1276 SPI I/O definitions
//	//片选为PB2
//#define  SPI_NSS_DIR        PB_DDR_DDR2
//#define  SPI_NSS_OUT        PB_ODR_ODR2

//#define  SPI_SOMI_BIT_R     PB_IDR_IDR7

//	//SX1276 RESET I/O definitions（POWER I/O）
//	//供电脚为PA0
//#define  SXRESET_SET        uIO//PA_DDR_DDR0
//#define  SXRESET_OUT        uIO//PA_ODR_ODR0

/*
//PA I/O definitions
#define PA_TX_DIR           P6DIR_bit.P3
#define PA_TX_OUT           P6OUT_bit.P3
#define PA_RX_DIR           P5DIR_bit.P1
#define PA_RX_OUT           P5OUT_bit.P1

//KEY OF MCU  I/O definitions
//Key1
#define SX_Key1_DIR         P1DIR_bit.P7     //key 方向寄存器
#define Key1_IFG            P1IFG_bit.P7     //key 中断标志位寄存器
#define Key1_IES            P1IES_bit.P7     //key 触发方式寄存器，上升沿或下降沿
#define Key1_IE             P1IE_bit.P7      //key 中断使能寄存器
#define Key1_IN             P1IN_bit.P7      //key 输入寄存器

//Key2
#define SX_Key2_DIR         P1DIR_bit.P6     //key 方向寄存器
#define Key2_IFG            P1IFG_bit.P6     //key 中断标志位寄存器
#define Key2_IES            P1IES_bit.P6     //key 触发方式寄存器，上升沿或下降沿
#define Key2_IE             P1IE_bit.P6      //key 中断使能寄存器
#define Key2_IN             P1IN_bit.P6      //key 输入寄存器

//Key3
#define SX_Key3_DIR         P1DIR_bit.P5     //key 方向寄存器
#define Key3_IFG            P1IFG_bit.P5     //key 中断标志位寄存器
#define Key3_IES            P1IES_bit.P5     //key 触发方式寄存器，上升沿或下降沿
#define Key3_IE             P1IE_bit.P5      //key 中断使能寄存器
#define Key3_IN             P1IN_bit.P5      //key 输入寄存器

//Key4
#define SX_Key4_DIR         P1DIR_bit.P4     //key 方向寄存器
#define Key4_IFG            P1IFG_bit.P4     //key 中断标志位寄存器
#define Key4_IES            P1IES_bit.P4     //key 触发方式寄存器，上升沿或下降沿
#define Key4_IE             P1IE_bit.P4      //key 中断使能寄存器
#define Key4_IN             P1IN_bit.P4      //key 输入寄存器

//key5 
#define SX_key5_DIR         P1DIR_bit.P3     //key 方向寄存器
#define key5_IFG            P1IFG_bit.P3     //key 中断标志位寄存器
#define key5_IES            P1IES_bit.P3     //key 触发方式寄存器，上升沿或下降沿
#define key5_IE             P1IE_bit.P3      //key 中断使能寄存器
#define key5_IN             P1IN_bit.P3      //key 输入寄存器
*/
//===================================宏定义===================================================
// RXTX pin control see errata note
//#define RXTX( txEnable )                            SX1276WriteRxTx( txEnable );
/*!
 * DIO state read functions mapping
 */
//#define DIO0                                        SX1276ReadDio0( )
//#define DIO1                                        SX1276ReadDio1( )
//#define DIO2                                        SX1276ReadDio2( )
//#define DIO3                                        SX1276ReadDio3( )
//#define DIO4                                        SX1276ReadDio4( )
//#define DIO5                                        SX1276ReadDio5( )

#define RF_R_DIO0  		GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_2)//GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)
#define RF_R_DIO1  		GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_10)//GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_12)
//#define RF_R_DIO2  		GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_)
#define RF_R_DIO3  		GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_3)//GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8)

//0,1,3 needed

//#define SX1276ReadDio0( )   DIO0_IN
//#define SX1276ReadDio1( )   DIO1_IN
//#define SX1276ReadDio2( )   1         //未使用
//#define SX1276ReadDio3( )   DIO3_IN
//#define SX1276ReadDio4( )   1         //未使用

typedef enum
{
    RADIO_RESET_OFF,
    RADIO_RESET_ON,
}tRadioResetState;

//===================================SPI函数声明===================================================
void SX1276InitIo( void );
void SX1276SPISetup(void);
void SX1276WriteBuffer( uint8_t addr, uint8_t *buffer, uint8_t size );
void SX1276ReadBuffer( uint8_t addr, uint8_t *buffer, uint8_t size );
void SX1276Write( uint8_t addr, uint8_t data );
void SX1276Read( uint8_t addr, uint8_t *data );
void SX1276WriteFifo( uint8_t *buffer, uint8_t size );
void SX1276ReadFifo( uint8_t *buffer, uint8_t size );
void SX1276Reset(void);
//void SX1276WriteRxTx( bool txEnable );

void Init_LoraIO_DIO0(void);
void Init_LoraIO_DIO1(void);
void Init_LoraIO_DIO3(void);
void Init_LoraIO_DIO0_EXTIoff(void);
void Init_LoraIO_DIO1_EXTIoff(void);
void Init_LoraIO_DIO3_EXTIoff(void);

void Init_LoraIO_LP(void);//
void Init_LoraIO_PW(void);


#endif 
