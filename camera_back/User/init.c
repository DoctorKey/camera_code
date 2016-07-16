#include "init.h"
#include "include.h"

void All_Init()
{
	NVIC_PriorityGroupConfig(NVIC_GROUP);		//中断优先级组别设置
	
  SystemInit();			                      //初始化系统时钟，设置时钟为168Mhz
	
  LED_GPIO_Conf();												//初始化LED的GPIO配置
	
  SysTick_Init();
		
	Usart1_Init(115200);
	
	Usart2_Init(115200);
	
	TIM3_Int_Init(10000-1,8400-1);//10Khz计数,1秒钟中断一次
	
	if(OV7670_Init())
	{
		while(1)
		{
			LED0(On);
			delay_ms(300);
			LED0(Off);
			delay_ms(300);	
			USART_SendData(USART2,00);			
		}
	}

	delay_ms(1000);
	
	DCMI_Start();
	
	pid_set();
}
