#include "stm32f10x.h"                  // Device header
#include "PWM.h"


void Motor_Init(void)
{

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef LEDstructure;
	
	LEDstructure.GPIO_Mode=GPIO_Mode_Out_PP;//推挽,可以输出高电平和低电平
	LEDstructure.GPIO_Pin=GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
	LEDstructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&LEDstructure);
	
	LEDstructure.GPIO_Mode=GPIO_Mode_Out_PP;//推挽,可以输出高电平和低电平
	LEDstructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_13|GPIO_Pin_14;
	LEDstructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&LEDstructure);

	PWM_Init();
	
}
void Motor_SetSpeed1(int8_t Speed)
{

	if(Speed>=0)
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_5);
		GPIO_ResetBits(GPIOA,GPIO_Pin_4);
		TIM_SetCompare1(TIM2,Speed);
		
	}
	else {
		GPIO_SetBits(GPIOA,GPIO_Pin_4);
		GPIO_ResetBits(GPIOA,GPIO_Pin_5);
		TIM_SetCompare1(TIM2,-Speed);
		
		
	}

}
void Motor_SetSpeed2(int8_t Speed)
{

	if(Speed>=0)
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_6);
		GPIO_ResetBits(GPIOA,GPIO_Pin_7);
		TIM_SetCompare2(TIM2,Speed);
		
	}
	else {
		GPIO_SetBits(GPIOA,GPIO_Pin_7);
		GPIO_ResetBits(GPIOA,GPIO_Pin_6);
		TIM_SetCompare2(TIM2,-Speed);
		
		
	}

}
void Motor_SetSpeed3(int8_t Speed)
{

	if(Speed>=0)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_0);
		GPIO_ResetBits(GPIOB,GPIO_Pin_1);
		TIM_SetCompare3(TIM2,Speed);
		
	}
	else {
		GPIO_SetBits(GPIOB,GPIO_Pin_1);
		GPIO_ResetBits(GPIOB,GPIO_Pin_0);
		TIM_SetCompare3(TIM2,-Speed);
		
		
	}

}
void Motor_SetSpeed4(int8_t Speed)
{

	if(Speed>=0)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_13);
		GPIO_ResetBits(GPIOA,GPIO_Pin_14);
		TIM_SetCompare4(TIM2,Speed);
		
	}
	else {
		GPIO_SetBits(GPIOA,GPIO_Pin_14);
		GPIO_ResetBits(GPIOA,GPIO_Pin_13);
		TIM_SetCompare4(TIM2,-Speed);
		
		
	}

}
