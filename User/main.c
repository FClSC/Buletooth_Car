#include "stm32f10x.h"
#include "OLED.h"
#include "Delay.h"
#include "LED.h"
#include "PWM.h"
#include "Motor.h"
#include "Key.h"
#include "HC05.h"
#include "string.h"
#include "Buzzer.h"
#include "GPS.h"
#include "usart.h"

uint8_t RxSTA = 1;

char RxData[100] = "None";
char LastRxData[100] = "None"; 

int is_utf8_chinese(const char *str) ;

float Lo=0;//当前纬度
float La=0;//当前经度

double Speed=0;



int main(void)
{
    OLED_Init();
    LED_Init();
    HC05_Init();
    Motor_Init();
    Key_Init();
	  Buzzer_Init();
    int8_t SL = 0;
	



   OLED_ShowChinese(0,0,"你好");
	 OLED_Update();


			
			
			while(1) {
			
       HC05_GetData(RxData);
       OLED_Clear();
			
       OLED_ShowString(0, 0, "Speed:", 8);
       OLED_ShowString(0, 16, "Receive:", 8);
       if (RxSTA == 0)//如果接受了新数据的标志位为0
       {
				 
				 if(RxData[0]!='\0')//如果新传过来字符串非空	 
		     {
					 
				 	if (RxData[0] == 'A') //加速
				  {
              SL += 10;
              if (SL > 100) SL = 100;
          } 		
				  if (RxData[0] == 'B')//减速
				  {
              SL -= 10;
              if (SL < -100) SL = -100;
          }
					if (RxData[0] == 'I')//停止
					{
						SL=0;
					}
					if (RxData[0] == 'E')//点灯
					{
						Buzzer_turn();
						//LED1_turn();
						//LED2_turn();

						
					}					
				
			    strcpy(LastRxData, RxData); //把其更新
		 
	       }

				if(is_utf8_chinese(LastRxData)==1)OLED_ShowChinese(0,32,LastRxData);
        else OLED_ShowString(0, 32, LastRxData, 8);
				 
        OLED_ShowSignedNum(48, 0, SL, 3, 8);
	      memset(RxData,0,sizeof(RxData));//清空新的
				OLED_Update();
        Motor_SetSpeed1(SL);
            
	      RxSTA = 1;//标志位更新
				 
      }		
			 
			 
			

    } 
 

}




int is_utf8_chinese(const char *str) {
    // 检查一个UTF-8编码字符的字节序列是否符合中文字符的规则
    // UTF-8中，中文字符的字节序列范围：
    // 单字节编码：0x00 - 0x7F
    // 多字节编码：0xE0 - 0xEF 开头的三字节序列
    //           0xF0 - 0xF7 开头的四字节序列
    if ((str[0] & 0xE0) == 0xC0) {
        // 两字节编码的第一个字节范围是 0xC0 - 0xDF
        if ((str[1] & 0xC0) == 0x80) {
            return 1;
        }
    } else if ((str[0] & 0xF0) == 0xE0) {
        // 三字节编码的第一个字节范围是 0xE0 - 0xEF
        if ((str[1] & 0xC0) == 0x80 &&
            (str[2] & 0xC0) == 0x80) {
            return 1;
        }
    } else if ((str[0] & 0xF8) == 0xF0) {
        // 四字节编码的第一个字节范围是 0xF0 - 0xF7
        if ((str[1] & 0xC0) == 0x80 &&
            (str[2] & 0xC0) == 0x80 &&
            (str[3] & 0xC0) == 0x80) {
            return 1;
        }
    }
    
		
		
		
		
		
		
		
    return 0;
}
