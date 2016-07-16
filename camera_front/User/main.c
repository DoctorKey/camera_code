#include "stm32f4xx.h"
#include "init.h"
#include "delay.h"
#include "led.h"
#include "usart.h"
#include "ctrl.h"
#include "usmart.h"
#include "dgp.h"

int main(void)
{ 
	u16 *jpeg;

	All_Init();

	jpeg=(u16*)jpeg_buf;
	
  	while(1)
	{
		if(jpeg_data_ok==1)	//已经采集完一帧图像了
		{ 			
			LED0(On);
			get_info(jpeg,im,&front_measure_info);
////			i=jpeg_data_len*4;
//			i=jpeg_buf_size*4;
//			p=(u8*)jpeg_buf;
//			LED0(On);
//			USART_SendString_bysize(USART2,p,i);
////			USART_SendData(USART2,255);
//			delay_ms(300);
//			LED0(Off);
			jpeg_data_ok=2;	//标记jpeg数据处理完了,可以让DMA去采集下一帧了.
		}		
		LED0(Off);
		front_duty();	
	}
}


#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

