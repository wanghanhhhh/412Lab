#include	"stm32f10x.h"
#include	"delay.h"
#include "MPU6050.h"
#include "encoder.h"
#include "sys.h"
#include "OLED.h"
//#include "key.h"
#include "Servo.h"
#include "bsp_ldr.h" 

u8 Flag_Stop=1;  
int Encoder_Left,Encoder_Right;       //左右编码器的脉冲计数
float Angle_Balance,Gyro_Balance; 		//平衡倾角 平衡陀螺仪
void zhixing (void)
{
Set_Pwm(1000,1000);
	
}
void tingzhi (void)
{
	Set_Pwm(2000,2000);Delay_ms(500);
Set_Pwm(0,0);
Delay_s(600);
	
}
void left (void)
{
	Set_Pwm(1000,1000);
	Delay_ms(700);
  Set_Pwm(-2000,2000);
	Delay_ms(450);
		
}
void right (void)
{
	Set_Pwm(1000,1000);
	Delay_ms(700);
	Set_Pwm(2000,-2000);
	Delay_ms(450);
		
}
void turn (void)
{
	//Set_Pwm(1000,1000);
	//Delay_ms(800);
	//Set_Pwm(1000,-1000);
	Set_Pwm(-1200,-1200);
	//Delay_s(3);
	//Delay_ms(200);
		
}

void Key1_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

uint8_t Key_GetNum(void)
{
	uint8_t KeyNum = 0;
	if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_5) == 0)
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_5) == 0);
		Delay_ms(20);
		KeyNum = 1;
	}
	else KeyNum=0;
	
	return KeyNum;}

int main(void)
{int i=0;
	int t=0,t2,m=0;
	int x=0;
	int Rflag=0,Lflag=0;
	MY_NVIC_PriorityGroupConfig(2);	//设置中断分组
	delay_init();			         //初始化OLED
	JTAG_Set(JTAG_SWD_DISABLE);     //关闭JTAG接口
	JTAG_Set(SWD_ENABLE);           //打开SWD接口 可以利用主板的SWD接口调试
	Pwm_Init();
	Servo_Init();
	Key1_Init();	
	Config1();
	Config2();
	Config3();
	Config4();
	Config5();
	Config6();
	Config7();
	Config8();
	
	//while(1)
	//{
		
//	  Set_Pwm(-1000,-1000);
//		//PWM_SetCompare3(1500);
//		 Delay_s(3);
//		Set_Pwm(-7000,7000);
//		Delay_ms(950);
//	 Set_Pwm(-1000,-1000);
//		
//		 Delay_s(3);
//	 Set_Pwm(0,0);
	//}
	
//		  Set_Pwm(1000,1000);
//			Delay_ms(500);
	
	while(1)
	{
		//Set_Pwm(-1000,0);
//		if(X1==1&&X2==1&&X3==1&&X4==0&&X5==0&&X6==0&&X7==0&&X8==0){Rflag=1;right();}
//		else if (X1==0&&X2==0&&X3==0&&X4==0&&X5==0&&X6==1&&X7==1&&X8==1){Lflag=1;left();}
//		else if  (X1==1&&X2==1&&X3==1&&X4==1&&X5==1&&X6==1&&X7==1&&X8==1){Lflag=1;left();}
//		else {Rflag=0;Lflag=0;}
		//if(Key_GetNum()==1)
		
	//{

if(Key_GetNum()==1){	
Set_Pwm(3000,3000);	Delay_ms(500);
	while (1){
	if((X4 == 0)&&(X5 == 0)&&X1==1&&X2==1&&X3==1&&X6==1&&X7==1&&X8==1) // 都是黑色, 加速前进
		{
		  Set_Pwm(3000,3000);
		
		}	
		else if((X4 == 0)&&(X5 ==1)&&X1==1&&X2==1&&X3==1&&X6==1&&X7==1&&X8==1)	//向右
	{Set_Pwm(1500,3000);
		//motor(38,40);
	}
	else if((X4 == 1)&&(X5 == 0)&&X1==1&&X2==1&&X3==1&&X6==1&&X7==1&&X8==1)	//向左   
	{Set_Pwm(3000,1500);
		//motor(40,38);
	}else if((X3 == 1)&&(X4 == 0)&&X1==1&&X2==1&&X3==1&&X6==1&&X7==1&&X8==1)	  
	{
		Set_Pwm(1500,3100);
		//motor(32,40);
	}
	else if((X5 == 0)&&(X6 == 0)&&X1==1&&X2==1&&X3==1&&X4==1&&X7==1&&X8==1)	  
	
	{Set_Pwm(3100,1500);
		//motor(40,32);
	}
	else if((X3 == 0)&&(X4 == 1)&&X1==1&&X2==1&&X5==1&&X6==1&&X7==1&&X8==1)	  
	   
	{
		Set_Pwm(1500,3150);
		//motor(25,40);
	}
	else if((X5== 1)&&(X6 ==0)&&X1==1&&X2==1&&X3==1&&X4==1&&X7==1&&X8==1)	  
  
	{
		//	motor(40,25);
		Set_Pwm(3150,1500);
	}
	else if((X2 == 0)&&(X3 == 0)&&X1==1&&X4==1&&X5==1&&X6==1&&X7==1&&X8==1)	     
	{
		Set_Pwm(1500,3200);
		//motor(20,40);
	}
	else if((X6 == 0)&&(X7 == 0)&&X1==1&&X2==1&&X3==1&&X4==1&&X5==1&&X8==1)	    
	{
		Set_Pwm(3200,1500);
		//motor(40,20);
	}
	else if((X2 == 0)&&(X3 == 1)&&X1==1&&X4==1&&X5==1&&X6==1&&X7==1&&X8==1)	  
    
	{
		Set_Pwm(1500,3250);
		//motor(15,40);
	}
	else if((X6 == 1)&&(X7 ==0)&&X1==1&&X2==1&&X3==1&&X4==1&&X5==1&&X8==1)	  
	{Set_Pwm(3250,1500);
		//motor(40,15);
	}
	else if((X1 ==0)&&(X2 == 0)&&X3==1&&X4==1&&X5==1&&X6==1&&X7==1&&X8==1)	   
	{
		Set_Pwm(1500,3300);
		//motor(10,40);
	}
	else if((X7 == 0)&&(X8 == 0)&&X1==1&&X2==1&&X3==1&&X4==1&&X5==1&&X6==1)	    
	{
		Set_Pwm(3300,1500);
		//motor(40,10);
	}
	else if((X1 == 0)&&(X2 ==1)&&X3==1&&X4==1&&X5==1&&X6==1&&X7==1&&X8==1)	     
	{
		Set_Pwm(1500,3350);
		//motor(0,40);
	}	
	else if((X7 == 1)&&(X8 == 0)&&X1==1&&X2==1&&X3==1&&X4==1&&X5==1&&X6==1)	   
	{
		Set_Pwm(3350,1500);
		//motor(40,0);
	}
		else  if((X1==1&&X2==1&&X3==1&&X4==0&&X5==0&&X6==0&&X7==0&&X8==0)||(X1==1&&X2==1&&X3==1&&X4==1&&X5==0&&X6==0&&X7==0&&X8==0))
			//if((X1==1&&X2==1&&X3==1&&X4==0&&X5==0&&X6==0&&X7==0&&X8==0))
         {
				  x++;Rflag=1;
					 if((x==8)||(x==11)||(x==13))right();
					 else if(x==10)left();
					 else if(x==9){Set_Pwm(2000,2000);Delay_ms(200);}
					 else if(x>19)tingzhi();
					 else right();
				 }
	else  if((X1==0&&X2==0&&X3==0&&X4==0&&X5==0&&X6==1&&X7==1&&X8==1)||(X1==0&&X2==0&&X3==0&&X4==0&&X5==1&&X6==1&&X7==1&&X8==1))
		   //if((X1==0&&X2==0&&X3==0&&X4==0&&X5==0&&X6==1&&X7==1&&X8==1))
         {
				  x++;Lflag=1;
					 if((x==8)||(x==11)||(x==13))right();
					 else if(x==10)left();
					 else if(x==9){Set_Pwm(2000,2000);Delay_ms(200);}
					 else if(x>19)tingzhi();
					 else
					 left();
				 }
  else  if (X1==1&&X2==1&&X3==1&&X4==1&&X5==1&&X6==1&&X7==1&&X8==1)
         {
					 Set_Pwm(0,0);
				  
				 }
	else if(X1==0&&X2==0&&X3==0&&X4==0&&X5==0&&X6==0&&X7==0&&X8==0)
	{ x++;
	         if((x==8)||(x==11)||(x==13))right();
					 else if(x==10)left();
					 else if(x==9){Set_Pwm(2000,2000);Delay_ms(200);}
					 else if(x>19)tingzhi();
					 else
           tingzhi();
	}
				
	
}
}
		}
	
}
