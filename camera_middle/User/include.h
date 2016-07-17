#ifndef _INCLUDE_H_
#define _INCLUDE_H_

#include "stm32f4xx.h"
#include "led.h"
#include "usart.h"
#include "pwm_out.h"

/***************中断优先级******************/
#define NVIC_GROUP NVIC_PriorityGroup_3		//中断分组选择 0~7抢占 0~1响应
#define NVIC_PWMIN_P			4		//接收机采集
#define NVIC_PWMIN_S			0

#define NVIC_TIM3_P       3		//计时器
#define NVIC_TIM3_S       0

#define NVIC_DCMI_P       2		//DCMI中断
#define NVIC_DCMI_S       0

#define NVIC_UART1_P			1		//串口1中断
#define NVIC_UART1_S			1

#define NVIC_UART2_P			1		//串口2中断
#define NVIC_UART2_S			0
/***********************************************/

/***************picture******************/
#define PIC_ROW 120
#define PIC_COL 160
#define jpeg_buf_size (PIC_ROW*PIC_COL/2)
/***********************************************/

/***************ctrl******************/
#define CH_NUM 4

#define ROLL_CH 0
#define PIT_CH 1
#define THR_CH 2
#define YAW_CH 3

#define ROLL_CH_OFFSET 0
#define PIT_CH_OFFSET 0
#define YAW_CH_OFFSET 0

#define PWM_MIN 0
#define PWM_MAX 500

#define GO_PIT   (50)
#define BACK_PIT (-50)

#define THROW_READY 0.2 //中间摄像头准备投球的阈值
#define THROW_BALL 0.4 //中间摄像头决定投球的阈值
#define DROP_READY 0.3 //准备降落
/***********************************************/

#endif

