/***********************************************
��˾����Ȥ�Ƽ�����ݸ�����޹�˾
Ʒ�ƣ�WHEELTEC
������wheeltec.net
�Ա����̣�shop114407458.taobao.com 
����ͨ: https://minibalance.aliexpress.com/store/4455017
�汾��5.7
�޸�ʱ�䣺2021-04-29

 
Brand: WHEELTEC
Website: wheeltec.net
Taobao shop: shop114407458.taobao.com 
Aliexpress: https://minibalance.aliexpress.com/store/4455017
Version:5.7
Update��2021-04-29

All rights reserved
***********************************************/
#include "key.h"
/**************************************************************************
Function: Key initialization
Input   : none
Output  : none
�������ܣ� ������ʼ��
��ڲ�������	
����  ֵ����
**************************************************************************/
void KEY_Init(void)
{
	RCC->APB2ENR|=1<<2;               //ʹ��PORTAʱ��	   	 
	GPIOA->CRL&=0XFF0FFFFF;           
	GPIOA->CRL|=0X00800000;           
  GPIOA->ODR|=1<<5; 								//��������	
} 
/**************************************************************************
Function: Key scan
Input   : none
Output  : 0��No action��1��click��
�������ܣ�����ɨ��
��ڲ�������	
����  ֵ������״̬ 0���޶��� 1������  
**************************************************************************/
u8 click(void)
{
			static u8 flag_key=1;//�������ɿ���־
			if(flag_key&&KEY==0) //��⵽��������
			{
			flag_key=0;
			return 1;	//��������
			}
			else if(1==KEY)			flag_key=1;
			return 0;//�ް�������
}
