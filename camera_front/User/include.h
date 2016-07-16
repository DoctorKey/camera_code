#ifndef _INCLUDE_H_
#define _INCLUDE_H_

#include "stm32f4xx.h"
#include "led.h"
#include "usart.h"

//================系统===================
//#define USE_USART1
#define USE_USART2

/***************中断优先级******************/
#define NVIC_GROUP NVIC_PriorityGroup_3		//中断分组选择 0~7抢占 0~1响应
#define NVIC_PWMIN_P			1		//接收机采集
#define NVIC_PWMIN_S			1

#define NVIC_TIM3_P       1		//暂未使用
#define NVIC_TIM3_S       3

#define NVIC_DCMI_P       1		//DCMI中断
#define NVIC_DCMI_S       2

#define NVIC_UART1_P			7		//串口1中断
#define NVIC_UART1_S			1

#define NVIC_UART2_P			2		//串口2中断
#define NVIC_UART2_S			0
/***********************************************/

/***************picture******************/
#define PIC_ROW 120
#define PIC_COL 160
#define jpeg_buf_size (PIC_ROW*PIC_COL/2)
/***********************************************/

/***************ctrl******************/

/***********************************************/

#endif

