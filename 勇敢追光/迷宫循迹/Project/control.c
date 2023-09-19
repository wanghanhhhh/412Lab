#include "control.h"

int Balance(float Angle,float Gyro)
{  
	 float Balance_Kp=250,Balance_Kd=1.5;//ֱ����PD����
   float Angle_bias,Gyro_bias;
	 int balance;
	 Angle_bias=3-Angle;                       //���ƽ��ĽǶ���ֵ �ͻ�е���
	 Gyro_bias=0-Gyro;
	 balance=-Balance_Kp*Angle_bias-Gyro_bias*Balance_Kd;   		//����ƽ����Ƶĵ��PWM  PD����   kp��Pϵ�� kd��Dϵ�� 
	 return balance;
}

int Velocity(int encoder_left,int encoder_right)
{  
	  float Velocity_Kp=170,Velocity_Ki=1.0;//�ٶȻ�PI����
    static float velocity,Encoder_Least,Encoder_bias;
	  static float Encoder_Integral;

		Encoder_Least =0-(encoder_left+encoder_right);                    //��ȡ�����ٶ�ƫ��==�����ٶȣ����ұ�����֮�ͣ�-Ŀ���ٶȣ��˴�Ϊ�㣩 
		Encoder_bias *= 0.8;		                                          //һ�׵�ͨ�˲���       
		Encoder_bias += Encoder_Least*0.2;	                              //һ�׵�ͨ�˲���  
																																			//�൱���ϴ�ƫ���0.8 + ����ƫ���0.2�������ٶȲ�ֵ�����ٶ�ֱ���ĸ���  
		Encoder_Integral +=Encoder_bias;                                  //���ֳ�λ�� ����ʱ�䣺10ms
		if(Encoder_Integral>10000)  	Encoder_Integral=10000;             //�����޷�
		if(Encoder_Integral<-10000)	  Encoder_Integral=-10000;            //�����޷�	
		velocity=-Encoder_bias*Velocity_Kp-Encoder_Integral*Velocity_Ki;        //�ٶȿ���	
		if(Flag_Stop==1)   Encoder_Integral=0;   //����رպ��������
	  return velocity;
}
int Turn(u8 Bias,short Gyro)
{
	float Turn_Kp=18,Turn_Kd=0.18;
	float Turn;
	Turn=-Bias*Turn_Kp-Gyro*Turn_Kd;
	return Turn;
}

void Set_Pwm(int left,int right)
{
	if(left>0)
	{
		BIN1=1;
		BIN2=0;
	}else
	{
		BIN1=0;
		BIN2=1;
	}
	if(right>0)
	{
		AIN1=0;
		AIN2=1;
	}else
	{
		AIN1=1;
		AIN2=0;
	}
	PWMB=myabs(left);
	PWMA=myabs(right);
}

int myabs(int a)
{ 		   
	  int temp;
		if(a<0)  temp=-a;  
	  else temp=a;
	  return temp;
}
void MiniBalance_EXTI_Init(void)
{  
		GPIO_InitTypeDef GPIO_InitStructure;
		EXTI_InitTypeDef EXTI_InitStructure;
		NVIC_InitTypeDef NVIC_InitStructure;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);   //�ⲿ�жϣ���Ҫʹ��AFIOʱ��
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //ʹ��GPIO�˿�ʱ��
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;	          //�˿�����
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;         //��������
		GPIO_Init(GPIOA, &GPIO_InitStructure);					      //�����趨������ʼ��GPIO
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource12);
  	EXTI_InitStructure.EXTI_Line=EXTI_Line12;
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;//�½��ش���
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);	 	//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���
		NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;			//ʹ�ܰ������ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//��ռ���ȼ�2�� 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;					//�����ȼ�1
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
  	NVIC_Init(&NVIC_InitStructure); 
}

int PWM_Limit(int IN,int max,int min)
{
	int OUT = IN;
	if(OUT>max) OUT = max;
	if(OUT<min) OUT = min;
	return OUT;
}
void Key(void)
{	
	u8 tmp;
	tmp=click(); 
	if(tmp==1) Flag_Stop=!Flag_Stop;//��������С������ͣ
}

