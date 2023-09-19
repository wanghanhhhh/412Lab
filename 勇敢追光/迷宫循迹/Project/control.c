#include "control.h"

int Balance(float Angle,float Gyro)
{  
	 float Balance_Kp=250,Balance_Kd=1.5;//直立环PD参数
   float Angle_bias,Gyro_bias;
	 int balance;
	 Angle_bias=3-Angle;                       //求出平衡的角度中值 和机械相关
	 Gyro_bias=0-Gyro;
	 balance=-Balance_Kp*Angle_bias-Gyro_bias*Balance_Kd;   		//计算平衡控制的电机PWM  PD控制   kp是P系数 kd是D系数 
	 return balance;
}

int Velocity(int encoder_left,int encoder_right)
{  
	  float Velocity_Kp=170,Velocity_Ki=1.0;//速度环PI参数
    static float velocity,Encoder_Least,Encoder_bias;
	  static float Encoder_Integral;

		Encoder_Least =0-(encoder_left+encoder_right);                    //获取最新速度偏差==测量速度（左右编码器之和）-目标速度（此处为零） 
		Encoder_bias *= 0.8;		                                          //一阶低通滤波器       
		Encoder_bias += Encoder_Least*0.2;	                              //一阶低通滤波器  
																																			//相当于上次偏差的0.8 + 本次偏差的0.2，减缓速度差值，减少对直立的干扰  
		Encoder_Integral +=Encoder_bias;                                  //积分出位移 积分时间：10ms
		if(Encoder_Integral>10000)  	Encoder_Integral=10000;             //积分限幅
		if(Encoder_Integral<-10000)	  Encoder_Integral=-10000;            //积分限幅	
		velocity=-Encoder_bias*Velocity_Kp-Encoder_Integral*Velocity_Ki;        //速度控制	
		if(Flag_Stop==1)   Encoder_Integral=0;   //电机关闭后清除积分
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
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);   //外部中断，需要使能AFIO时钟
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //使能GPIO端口时钟
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;	          //端口配置
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;         //上拉输入
		GPIO_Init(GPIOA, &GPIO_InitStructure);					      //根据设定参数初始化GPIO
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource12);
  	EXTI_InitStructure.EXTI_Line=EXTI_Line12;
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;//下降沿触发
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);	 	//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器
		NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;			//使能按键所在的外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//抢占优先级2， 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;					//子优先级1
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
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
	if(tmp==1) Flag_Stop=!Flag_Stop;//单击控制小车的启停
}

