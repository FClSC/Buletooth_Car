#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Motor.h"




void Move_Front(int Speed)
{
	 
	 Motor_SetSpeed1(Speed);
	 Motor_SetSpeed2(Speed);
	 Motor_SetSpeed3(Speed);
   Motor_SetSpeed4(Speed);
}

void Move_Back(int Speed)
{
	 Motor_SetSpeed1(-Speed);
	 Motor_SetSpeed2(-Speed);
	 Motor_SetSpeed3(-Speed);
   Motor_SetSpeed4(-Speed);
	
	
	
}

void Move_Right(int Speed)
{
	
	 Motor_SetSpeed1(Speed);
	 Motor_SetSpeed2(-Speed);
	 Motor_SetSpeed3(-Speed);
   Motor_SetSpeed4(Speed);
	
}

void Move_Left(int Speed)
{
	
	 Motor_SetSpeed1(-Speed);
	 Motor_SetSpeed2(Speed);
	 Motor_SetSpeed3(Speed);
   Motor_SetSpeed4(-Speed);	
}
void Move_RTwist(int Speed)
{
	
	 Motor_SetSpeed1(Speed);
	 Motor_SetSpeed2(-Speed);
	 Motor_SetSpeed3(Speed);
   Motor_SetSpeed4(-Speed);	
	
	
}
void Move_LTwist(int Speed)
{
	
	 Motor_SetSpeed1(-Speed);
	 Motor_SetSpeed2(Speed);
	 Motor_SetSpeed3(-Speed);
   Motor_SetSpeed4(Speed);	
	
	
}
void Move_Out(void)
{
	 Motor_SetSpeed1(0);
	 Motor_SetSpeed2(0);
	 Motor_SetSpeed3(0);
   Motor_SetSpeed4(0);	
	 
	
}

