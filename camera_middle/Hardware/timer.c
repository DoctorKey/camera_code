#include "timer.h"
#include "include.h"
#include "ctrl.h"
#include "dgp.h"

extern u8 ov_frame;
//extern volatile u16 jpeg_data_len;
extern volatile u8 frame_count;
extern volatile u16 over_count;
extern Rc_group Rc;
extern im_info front_target_info;
extern im_info back_target_info;

//通用定时器3中断初始化
//arr：自动重装值。
//psc：时钟预分频数
//定时器溢出时间计算方法:Tout=((arr+1)*(psc+1))/Ft us.
//Ft=定时器工作频率,单位:Mhz
//这里使用的是定时器3!
void TIM3_Int_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);  ///使能TIM3时钟
	
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;  //定时器分频
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
	TIM_TimeBaseInitStructure.TIM_Period=arr;   //自动重装载值
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE); //允许定时器3更新中断
	TIM_Cmd(TIM3,ENABLE); //使能定时器3
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn; //定时器3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=NVIC_TIM3_P; //抢占优先级1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=NVIC_TIM3_S; //子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
}

//定时器3中断服务函数
void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET) //溢出中断
	{
//		printf("frame:%d\r\n",ov_frame);//打印帧率
//		printf("jpeg_data_len:%d\r\n",jpeg_data_len);//打印帧率
//		printf("溢出:%d\r\n",over_count);
		printf("pitch:%d,roll:%d,thr:%d,yaw:%d\r\n",Rc.pitch,Rc.roll,Rc.thr,Rc.yaw);
		printf("front x:%d,y:%d\r\n",front_measure_info.x,front_measure_info.y);
		printf("back x:%d,y:%d\r\n",back_measure_info.x,back_measure_info.y);
		ov_frame=0;
		over_count=0;
	}
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //清除中断标志位
}
