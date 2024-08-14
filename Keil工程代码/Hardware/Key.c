#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void Key_Init(void)
{
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef structure;
	structure.GPIO_Mode=GPIO_Mode_IPU ;//…œ¿≠ ‰»Î
	structure.GPIO_Pin=GPIO_Pin_12|GPIO_Pin_11;
	structure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&structure);


}
int8_t Key_turn(void)
{
  int num=0;
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_12)==0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_12)==0);
		Delay_ms(20);
		num=1;
		
	}
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_11)==0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_11)==0);
		Delay_ms(20);
		num=2;
		
	}
	
	
	
	
	
	return num;
	
	
	
	
}
