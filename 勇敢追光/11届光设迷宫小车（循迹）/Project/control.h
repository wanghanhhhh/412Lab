#ifndef __CONTROL_H
#define __CONTROL_H
#include "sys.h"

void Set_Pwm(int left,int right);
int myabs(int a);
int Balance(float Angle,float Gyro);
void MiniBalance_EXTI_Init(void);
int Velocity(int encoder_left,int encoder_right);
int PWM_Limit(int IN,int max,int min);
void Key(void);
int Turn(u8 Bias,short Gyro);

#endif
