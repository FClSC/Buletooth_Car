#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void Buzzer_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef structureM;
	structureM.GPIO_Mode= GPIO_Mode_Out_PP;
	structureM.GPIO_Pin=GPIO_Pin_12;
	structureM.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&structureM);
	GPIO_SetBits(GPIOB,GPIO_Pin_12);
	

	
}

void Buzzer_turn(void)
{
	
	if(GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_12)==0)//Ïì×Å
	{	
		GPIO_SetBits(GPIOB,GPIO_Pin_12);//¹ØÉùÒô	
	}
	else GPIO_ResetBits(GPIOB,GPIO_Pin_12);//ÅªÏì
	
}


void Buzzering(void)
{
	
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);
	Delay_ms(500);
	GPIO_SetBits(GPIOB,GPIO_Pin_12);
	Delay_ms(200);
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);
	Delay_ms(500);
	GPIO_SetBits(GPIOB,GPIO_Pin_12);
}







