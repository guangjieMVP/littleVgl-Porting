#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "lcd.h"
#include "demo.h"
#include "timer.h"
#include "lv_app.h"
#include "touch.h"



int main(void)
{

	HAL_Init();                     //初始化HAL库   
	Stm32_Clock_Init(360,25,2,8);   //设置时钟,180Mhz
	delay_init(180);                //初始化延时函数
	uart_init(115200);              //初始化USART
	LED_Init();                     //初始化LED 
	LCD_Init();	                    //初始化LCD 
	tp_dev.init();
	TIM3_Init(100-1,9000-1);       //定时10ms//定时500ms / 50 = 10ms   5000/50 = 100    定时10ms
	
	lv_init(); 
	     
	my_lv_display_init();
	my_lv_touchpad_init();
	
	   
	
	demo_create();
	
	
	while(1)
	{
		lv_task_handler();
//		printf("ababab\n");
		tp_dev.scan(0);
//		delay_ms(10);
	}
}
