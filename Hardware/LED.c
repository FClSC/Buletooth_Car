#include "stm32f10x.h"                  // Device header

void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	
	
	
	GPIO_InitTypeDef structureM;
	structureM.GPIO_Mode= GPIO_Mode_AF_PP;//推挽复用输出
	structureM.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;//四个电机的pwm输出
	structureM.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&structureM);

	
	GPIO_InitTypeDef structureL1;
	structureL1.GPIO_Mode= GPIO_Mode_Out_PP;
	structureL1.GPIO_Pin=GPIO_Pin_15;
	structureL1.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&structureL1);
	GPIO_SetBits(GPIOB,GPIO_Pin_15);//LED1  PB15
	
	GPIO_InitTypeDef structureL2;
	structureL2.GPIO_Mode= GPIO_Mode_Out_PP;
	structureL2.GPIO_Pin=GPIO_Pin_8;
	structureL2.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&structureL2);
	GPIO_SetBits(GPIOA,GPIO_Pin_8);//LED2  PA8
	
}
void LED1_turn()
{
	
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_15)==1)GPIO_ResetBits(GPIOB,GPIO_Pin_15);
	else GPIO_SetBits(GPIOB,GPIO_Pin_15);
}

void LED2_turn()
{
	
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8)==1)GPIO_ResetBits(GPIOA,GPIO_Pin_8);
	else GPIO_SetBits(GPIOA,GPIO_Pin_8);
}
