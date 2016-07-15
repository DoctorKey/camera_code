
/* ------------------------------------------������ͷ�ļ�-----------------------------------------------*/
#include "stm32f4xx.h"
#include "init.h"
#include "delay.h"
#include "led.h"
#include "usart.h"
#include "ov7670.h"
#include "ctrl.h"
#include "dgp.h"
#include "data_transfer.h"

/*************************************************************************************
  * �������ƣ�main()
  * ����    ��void
  * ����ֵ  ��void
  * ����    �����������main����
  *************************************************************************************/
int main(void)
{ 
	u16 *jpeg;

	All_Init();

	jpeg=(u16*)jpeg_buf;
	
  	while(1)
	{
//		if(jpeg_data_ok==1)	//�Ѿ��ɼ���һ֡ͼ����
//		{ 			
//			get_info(jpeg,im,&back_target_info);
//			jpeg_data_ok=2;	//���jpeg���ݴ�������,������DMAȥ�ɼ���һ֡��.
//		}	
		LED0(On);
		delay_ms(1000);
		Send_Target(front_target_info.x,front_target_info.y);
		Send_Rc(Rc_send);
		LED0(Off);
		delay_ms(1000);		
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

