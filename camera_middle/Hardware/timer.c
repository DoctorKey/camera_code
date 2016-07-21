#include "timer.h"
#include "include.h"
#include "ctrl.h"
#include "dgp.h"

extern u8 ov_frame;
//extern volatile u16 jpeg_data_len;
extern volatile u8 frame_count;
extern volatile u16 over_count;
extern Rc_group Rc_out;
extern im_info front_target_info;
extern im_info back_target_info;
extern im_info middle_measure_info;
extern u8 all_ready;
extern u8 mode;
extern u8 ready_3;
extern u8 ready_1;
extern u8 ready_2;
extern s16 go_pit_offset;

//ͨ�ö�ʱ��3�жϳ�ʼ��
//arr���Զ���װֵ��
//psc��ʱ��Ԥ��Ƶ��
//��ʱ�����ʱ����㷽��:Tout=((arr+1)*(psc+1))/Ft us.
//Ft=��ʱ������Ƶ��,��λ:Mhz
//����ʹ�õ��Ƕ�ʱ��3!
void TIM3_Int_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);  ///ʹ��TIM3ʱ��
	
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;  //��ʱ����Ƶ
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
	TIM_TimeBaseInitStructure.TIM_Period=arr;   //�Զ���װ��ֵ
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE); //����ʱ��3�����ж�
	TIM_Cmd(TIM3,ENABLE); //ʹ�ܶ�ʱ��3
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn; //��ʱ��3�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=NVIC_TIM3_P; //��ռ���ȼ�1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=NVIC_TIM3_S; //�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
}

//��ʱ��3�жϷ�����
void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET) //����ж�
	{
		printf("--------------------------------\r\n");
		printf("roll:%d,pitch:%d,thr:%d,yaw:%d\r\n",Rc_out.roll,Rc_out.pitch,Rc_out.thr,Rc_out.yaw);
		printf("go_pit_offset:%d\r\n",go_pit_offset);
		printf("front x:%d,y:%d,ratio:%f\r\n",front_measure_info.x,front_measure_info.y,front_measure_info.ratio);
		printf("back x:%d,y:%d,ratio:%f\r\n",back_measure_info.x,back_measure_info.y,back_measure_info.ratio);
		printf("middle x:%d,y:%d,ratio:%f\r\n",middle_measure_info.x,middle_measure_info.y,middle_measure_info.ratio);
		printf("ready_1:%d,ready_2:%d,ready_3:%d,ov_frame:%d\r\n",ready_1,ready_2,ready_3,ov_frame);
		printf("mode :%d\r\n",mode);
//		if(all_ready==1)
//		{
//			if(ready_1==0)
//			{
//				mode=5;
//			}
//			else if(ready_2==0)
//			{
//				mode=5;
//			}
//			else if(ready_3==0)
//			{
//				mode=5;
//			}
//		}
//		ready_1=0;
//		ready_2=0;
		ready_3=0;
		ov_frame=0;
	}
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //����жϱ�־λ
}
