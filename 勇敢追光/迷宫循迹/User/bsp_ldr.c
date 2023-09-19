/**
  ******************************************************************************
  * @file    bsp_photoresistors.c
  * @author  fire
  * @version V1.0
  * @date    2019-xx-xx
  * @brief   光敏模块测试
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 F103-MINI STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
  
#include "bsp_ldr.h" 
//#include "bsp_led.h"

/**
  * @brief  配置光敏用到的I/O口
  * @param  无
  * @retval 无
  */
void Config1(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*开启端口的时钟*/
	RCC_APB2PeriphClockCmd(K1,ENABLE);
	
	//选择输入的引脚
	GPIO_InitStructure.GPIO_Pin = N1; 
	// 设置光敏输入的引脚为下拉输入
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
	GPIO_Init(T1, &GPIO_InitStructure);
}
void Config2(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*开启端口的时钟*/
	RCC_APB2PeriphClockCmd(K2,ENABLE);
	
	//选择输入的引脚
	GPIO_InitStructure.GPIO_Pin = N2; 
	// 设置光敏输入的引脚为下拉输入
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
	GPIO_Init(T2, &GPIO_InitStructure);
}
void Config3(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*开启端口的时钟*/
	RCC_APB2PeriphClockCmd(K3,ENABLE);
	
	//选择输入的引脚
	GPIO_InitStructure.GPIO_Pin = N3; 
	// 设置光敏输入的引脚为下拉输入
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
	GPIO_Init(T3, &GPIO_InitStructure);
}
void Config4(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*开启端口的时钟*/
	RCC_APB2PeriphClockCmd(K4,ENABLE);
	
	//选择输入的引脚
	GPIO_InitStructure.GPIO_Pin = N4; 
	// 设置光敏输入的引脚为下拉输入
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
	GPIO_Init(T4, &GPIO_InitStructure);
}
void Config5(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*开启端口的时钟*/
	RCC_APB2PeriphClockCmd(K5,ENABLE);
	
	//选择输入的引脚
	GPIO_InitStructure.GPIO_Pin = N5; 
	// 设置光敏输入的引脚为下拉输入
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
	GPIO_Init(T5, &GPIO_InitStructure);
}
void Config6(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*开启端口的时钟*/
	RCC_APB2PeriphClockCmd(K6,ENABLE);
	
	//选择输入的引脚
	GPIO_InitStructure.GPIO_Pin = N6; 
	// 设置光敏输入的引脚为下拉输入
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
	GPIO_Init(T6, &GPIO_InitStructure);
}
void Config7(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*开启端口的时钟*/
	RCC_APB2PeriphClockCmd(K7,ENABLE);
	
	//选择输入的引脚
	GPIO_InitStructure.GPIO_Pin = N7; 
	// 设置光敏输入的引脚为下拉输入
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
	GPIO_Init(T7, &GPIO_InitStructure);
}
void Config8(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*开启端口的时钟*/
	RCC_APB2PeriphClockCmd(K8,ENABLE);
	
	//选择输入的引脚
	GPIO_InitStructure.GPIO_Pin = N8; 
	// 设置光敏输入的引脚为下拉输入
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
	GPIO_Init(T8, &GPIO_InitStructure);
}







 /*
 * 函数名：光敏电阻测试
 * 描述  ：检测光敏电阻的状态
 * 输入  ：GPIOx：x 可以是 A，B，C，D或者 E
 *		     GPIO_Pin：待读取的端口位 	
 * 输出  ：LDR_ON：有光   LDR_OFF：无光
 */
uint8_t Test(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{			
	/*检测光敏输入状态 */
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == 1 )  
	{	  
		return OFF;    // 无光
	}
	else
		return ON;    // 有光
}
