#include "stm32f10x.h"                  // Device header

void PWM_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	//GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2,ENABLE);
	//����������ӳ��
	
	TIM_InternalClockConfig(TIM2);
	//����ʱ����Ԫ
	TIM_TimeBaseInitTypeDef structure;
	structure.TIM_ClockDivision=TIM_CKD_DIV1;
	structure.TIM_CounterMode=TIM_CounterMode_Up;
	structure.TIM_Period=100-1;//ARR
	structure.TIM_Prescaler=36-1;//PSC
	structure.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM2,&structure);
	//��������Ƚ�ģ��
	TIM_OCInitTypeDef OCStructure;
	TIM_OCStructInit(&OCStructure);//���ṹ�帳��ֵ����ֹ�ڲ���Щ��δֵ֪��
	
	OCStructure.TIM_OCMode=TIM_OCMode_PWM1;            //����Ƚ�ģʽ
	OCStructure.TIM_OCPolarity=TIM_OCPolarity_High;        //����Ƚϼ���,REFΪ�ߵ�ƽ
	OCStructure.TIM_OutputState=TIM_OutputState_Enable;       //����Ƚ�״̬ʹ��
	OCStructure.TIM_Pulse=0;            //ָ������ȽϼĴ���������ֵҲ����CCR
	
	TIM_OC1Init(TIM2,&OCStructure);
	TIM_OC2Init(TIM2,&OCStructure);
	TIM_OC3Init(TIM2,&OCStructure);
	TIM_OC4Init(TIM2,&OCStructure);
	//����Ϊ��ʼ������TIM1,2,3,4
	TIM_Cmd(TIM2,ENABLE);//ʹ�ܼ�����
	
	
	
	
	
	
	
	
	
	
	
	
}
