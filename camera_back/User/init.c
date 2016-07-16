#include "init.h"
#include "include.h"

void All_Init()
{
	NVIC_PriorityGroupConfig(NVIC_GROUP);		//�ж����ȼ��������
	
  SystemInit();			                      //��ʼ��ϵͳʱ�ӣ�����ʱ��Ϊ168Mhz
	
  LED_GPIO_Conf();												//��ʼ��LED��GPIO����
	
  SysTick_Init();
		
	Usart1_Init(115200);
	
	Usart2_Init(115200);
	
	TIM3_Int_Init(10000-1,8400-1);//10Khz����,1�����ж�һ��
	
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
