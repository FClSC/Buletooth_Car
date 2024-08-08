#include "stm32f10x.h"                  // Device header

void PWM_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	//GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2,ENABLE);
	//配置引脚重映射
	
	TIM_InternalClockConfig(TIM2);
	//配置时基单元
	TIM_TimeBaseInitTypeDef structure;
	structure.TIM_ClockDivision=TIM_CKD_DIV1;
	structure.TIM_CounterMode=TIM_CounterMode_Up;
	structure.TIM_Period=100-1;//ARR
	structure.TIM_Prescaler=36-1;//PSC
	structure.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM2,&structure);
	//配置输出比较模块
	TIM_OCInitTypeDef OCStructure;
	TIM_OCStructInit(&OCStructure);//给结构体赋初值，防止内部有些是未知值的
	
	OCStructure.TIM_OCMode=TIM_OCMode_PWM1;            //输出比较模式
	OCStructure.TIM_OCPolarity=TIM_OCPolarity_High;        //输出比较极性,REF为高电平
	OCStructure.TIM_OutputState=TIM_OutputState_Enable;       //输出比较状态使能
	OCStructure.TIM_Pulse=0;            //指定捕获比较寄存器的脉冲值也就是CCR
	
	TIM_OC1Init(TIM2,&OCStructure);
	TIM_OC2Init(TIM2,&OCStructure);
	TIM_OC3Init(TIM2,&OCStructure);
	TIM_OC4Init(TIM2,&OCStructure);
	//上述为初始化外设TIM1,2,3,4
	TIM_Cmd(TIM2,ENABLE);//使能计数器
	
	
	
	
	
	
	
	
	
	
	
	
}
