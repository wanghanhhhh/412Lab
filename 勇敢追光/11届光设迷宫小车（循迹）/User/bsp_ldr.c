/**
  ******************************************************************************
  * @file    bsp_photoresistors.c
  * @author  fire
  * @version V1.0
  * @date    2019-xx-xx
  * @brief   ����ģ�����
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� F103-MINI STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
  
#include "bsp_ldr.h" 
//#include "bsp_led.h"

/**
  * @brief  ���ù����õ���I/O��
  * @param  ��
  * @retval ��
  */
void Config1(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*�����˿ڵ�ʱ��*/
	RCC_APB2PeriphClockCmd(K1,ENABLE);
	
	//ѡ�����������
	GPIO_InitStructure.GPIO_Pin = N1; 
	// ���ù������������Ϊ��������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
	GPIO_Init(T1, &GPIO_InitStructure);
}
void Config2(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*�����˿ڵ�ʱ��*/
	RCC_APB2PeriphClockCmd(K2,ENABLE);
	
	//ѡ�����������
	GPIO_InitStructure.GPIO_Pin = N2; 
	// ���ù������������Ϊ��������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
	GPIO_Init(T2, &GPIO_InitStructure);
}
void Config3(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*�����˿ڵ�ʱ��*/
	RCC_APB2PeriphClockCmd(K3,ENABLE);
	
	//ѡ�����������
	GPIO_InitStructure.GPIO_Pin = N3; 
	// ���ù������������Ϊ��������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
	GPIO_Init(T3, &GPIO_InitStructure);
}
void Config4(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*�����˿ڵ�ʱ��*/
	RCC_APB2PeriphClockCmd(K4,ENABLE);
	
	//ѡ�����������
	GPIO_InitStructure.GPIO_Pin = N4; 
	// ���ù������������Ϊ��������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
	GPIO_Init(T4, &GPIO_InitStructure);
}
void Config5(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*�����˿ڵ�ʱ��*/
	RCC_APB2PeriphClockCmd(K5,ENABLE);
	
	//ѡ�����������
	GPIO_InitStructure.GPIO_Pin = N5; 
	// ���ù������������Ϊ��������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
	GPIO_Init(T5, &GPIO_InitStructure);
}
void Config6(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*�����˿ڵ�ʱ��*/
	RCC_APB2PeriphClockCmd(K6,ENABLE);
	
	//ѡ�����������
	GPIO_InitStructure.GPIO_Pin = N6; 
	// ���ù������������Ϊ��������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
	GPIO_Init(T6, &GPIO_InitStructure);
}
void Config7(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*�����˿ڵ�ʱ��*/
	RCC_APB2PeriphClockCmd(K7,ENABLE);
	
	//ѡ�����������
	GPIO_InitStructure.GPIO_Pin = N7; 
	// ���ù������������Ϊ��������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
	GPIO_Init(T7, &GPIO_InitStructure);
}
void Config8(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*�����˿ڵ�ʱ��*/
	RCC_APB2PeriphClockCmd(K8,ENABLE);
	
	//ѡ�����������
	GPIO_InitStructure.GPIO_Pin = N8; 
	// ���ù������������Ϊ��������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
	GPIO_Init(T8, &GPIO_InitStructure);
}







 /*
 * �������������������
 * ����  �������������״̬
 * ����  ��GPIOx��x ������ A��B��C��D���� E
 *		     GPIO_Pin������ȡ�Ķ˿�λ 	
 * ���  ��LDR_ON���й�   LDR_OFF���޹�
 */
uint8_t Test(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{			
	/*����������״̬ */
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == 1 )  
	{	  
		return OFF;    // �޹�
	}
	else
		return ON;    // �й�
}
