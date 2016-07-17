#ifndef _INCLUDE_H_
#define _INCLUDE_H_

#include "stm32f4xx.h"
#include "led.h"
#include "usart.h"

//================ϵͳ===================
//#define USE_USART1
#define USE_USART2

/***************�ж����ȼ�******************/
#define NVIC_GROUP NVIC_PriorityGroup_3		//�жϷ���ѡ�� 0~7��ռ 0~1��Ӧ
#define NVIC_PWMIN_P			4		//���ջ��ɼ�
#define NVIC_PWMIN_S			0

#define NVIC_TIM3_P       3		//��δʹ��
#define NVIC_TIM3_S       0

#define NVIC_DCMI_P       2		//DCMI�ж�
#define NVIC_DCMI_S       0

#define NVIC_UART1_P			1		//����1�ж�
#define NVIC_UART1_S			1

#define NVIC_UART2_P			1		//����2�ж�
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

