
#ifndef _DISP_H_
#define _DISP_H_


#define 				D595_OUT_CLK_L  cbi(GPIOB,GPIO_Pin_13)
#define 				D595_DAT_CLK_H  sbi(GPIOB,GPIO_Pin_12)
#define 				D595_DAT_CLK_L  cbi(GPIOB,GPIO_Pin_12)

//RESET
#define OLED_ReSet() 		sbi(GPIOF,GPIO_Pin_6)
#define OLED_ReReSet() 		cbi(GPIOF,GPIO_Pin_6)
//CS
#define OLED_CS_EN()  		cbi(GPIOF,GPIO_Pin_7)// 0
#define OLED_CS_DIS()  		sbi(GPIOF,GPIO_Pin_7)// 1
//DC
#define OLED_DC_D()  		sbi(GPIOA,GPIO_Pin_13)
#define OLED_DC_C()  		cbi(GPIOA,GPIO_Pin_13)
//ERD
#define OLED_SCLK_H()  	    sbi(GPIOA,GPIO_Pin_12)
#define OLED_SCLK_L()  	    cbi(GPIOA,GPIO_Pin_12)
//RW
#define OLED_SDIO_H()  	    sbi(GPIOA,GPIO_Pin_11)
#define OLED_SDIO_L()  	    cbi(GPIOA,GPIO_Pin_11)









#endif 		/* _DISP_H_ */


