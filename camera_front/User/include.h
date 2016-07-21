#ifndef _INCLUDE_H_
#define _INCLUDE_H_

#include "stm32f4xx.h"
#include "led.h"
#include "usart.h"

#if __FPU_USED==1
#define SCORE_FPU_MODE                  //\"FPU On\" 
#else
#define SCORE_FPU_MODE                  //\"FPU Off\" 
#endif

//================系统===================
//#define TEST //找红点
//#define TEST_Y //只测试图像
#define DUTY

//#define USE_USART1
#define USE_USART2

/***************中断优先级******************/
#define NVIC_GROUP NVIC_PriorityGroup_3		//中断分组选择 0~7抢占 0~1响应
#define NVIC_PWMIN_P			4		//接收机采集
#define NVIC_PWMIN_S			0

#define NVIC_TIM3_P       3		//暂未使用
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
#define R_threshold 60
#define G_threshold 60
#define B_threshold 100

/***********************************************/

#endif

