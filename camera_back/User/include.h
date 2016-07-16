#ifndef _INCLUDE_H_
#define _INCLUDE_H_

#include "stm32f4xx.h"

//================系统===================
#define USE_USART1
//#define USE_USART2


/***************中断优先级******************/
#define NVIC_GROUP NVIC_PriorityGroup_3		//中断分组选择 0~7抢占 0~1响应
#define NVIC_PWMIN_P			4		//接收机采集
#define NVIC_PWMIN_S			0

#define NVIC_TIM3_P       3		//计时中断
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

#define LOW_THRESHOLD 0   //从H中二值化红色的低阈值
#define HIGH_THRESHOLD 25   //从H中二值化红色的高阈值
/***********************************************/

/***************ctrl******************/
#define YAW_OFFSET 0
#define ROLL_OFFSET 0

/***********************************************/

#endif

