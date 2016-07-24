#include "stm32f4xx.h"
#include "init.h"
#include "led.h"
#include "dgp.h"
#include "myduty.h"

int main(void)
{ 
	u16 *jpeg;
	
	ready_3 = All_Init();
	
	jpeg=(u16*)jpeg_buf;
	
	#ifdef TEST
	while(1)
	{
		if(jpeg_data_ok==1)	//已经采集完一帧图像了
		{ 
			LED0(On);
			test(jpeg_buf,im);
			jpeg_data_ok=2;	//标记jpeg数据处理完了,可以让DMA去采集下一帧了.
		}	
		LED0(Off);
	}
	#endif
	#ifdef TEST_Y
	while(1)
	{
		if(jpeg_data_ok==1)	//已经采集完一帧图像了
		{ 
			LED0(On);
			test_Y(jpeg_buf,im);
			jpeg_data_ok=2;	//标记jpeg数据处理完了,可以让DMA去采集下一帧了.
		}	
		LED0(Off);
	}
	#endif
	#ifdef TEST_LINE
	while(1)
	{
		if(jpeg_data_ok==1)	//已经采集完一帧图像了
		{ 
			LED0(On);
			test_line(jpeg_buf,im);
			jpeg_data_ok=2;	//标记jpeg数据处理完了,可以让DMA去采集下一帧了.
		}	
		LED0(Off);
	}
	#endif
  while(1)
	{
		if(jpeg_data_ok==1)	//已经采集完一帧图像了
		{ 
			LED0(On);
			get_target2(jpeg,im,&middle_measure_info);
			jpeg_data_ok=2;	//标记jpeg数据处理完了,可以让DMA去采集下一帧了.
			middle_ctrl = 1;//可以执行一次middle控制
		}	
		LED0(Off);
		middle_duty();	
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

