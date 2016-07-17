#ifndef _INIT_H_
#define _INIT_H_

#include "stm32f4xx.h"
#include "ov7670.h"
#include "delay.h"
#include "timer.h"
#include "ctrl.h"
#include "usart.h"
#include "led.h"

u8 All_Init(void);

extern u8 ready_3;
extern u8 ready_1;
extern u8 ready_2;

#endif
