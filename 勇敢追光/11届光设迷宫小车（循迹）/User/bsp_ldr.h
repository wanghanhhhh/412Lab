#ifndef __LDR_H
#define	__LDR_H


#include "stm32f10x.h"
#include "stm32f10x_rcc.h"

//  引脚定义
#define    K1    RCC_APB2Periph_GPIOC
#define    T1    GPIOC		   
#define    N1	   GPIO_Pin_13
#define    K2    RCC_APB2Periph_GPIOC
#define    T2    GPIOC		   
#define    N2		 GPIO_Pin_14
#define    K3    RCC_APB2Periph_GPIOC
#define    T3    GPIOC		   
#define    N3    GPIO_Pin_15
#define    K4    RCC_APB2Periph_GPIOA
#define    T4    GPIOA		   
#define    N4	   GPIO_Pin_15
#define    K5    RCC_APB2Periph_GPIOB
#define    T5    GPIOB		   
#define    N5		 GPIO_Pin_3
#define    K6    RCC_APB2Periph_GPIOB
#define    T6    GPIOB		   
#define    N6		 GPIO_Pin_4
#define    K7    RCC_APB2Periph_GPIOB
#define    T7    GPIOB		   
#define    N7    GPIO_Pin_8
#define    K8    RCC_APB2Periph_GPIOA
#define    T8    GPIOA		   
#define    N8	   GPIO_Pin_7
#define    X1    Test(T1,N1)
#define    X2    Test(T2,N2)
#define    X3    Test(T3,N3)
#define    X4    Test(T4,N4)
#define    X5    Test(T5,N5)
#define    X6    Test(T6,N6)
#define    X7    Test(T7,N7)
#define    X8    Test(T8,N8)

 /** 按键按下标置宏
	*  按键按下为高电平，设置 KEY_ON=1， KEY_OFF=0
	*  若按键按下为低电平，把宏设置成KEY_ON=0 ，KEY_OFF=1 即可
	*/
#define ON	1     // 有光
#define OFF	0     // 无光
uint8_t Test(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);
void Config1(void);

void Config2(void);

void Config3(void);

void Config4(void);
void Config5(void);

void Config6(void);

void Config7(void);

void Config8(void);



#endif /* __LDR_H */

