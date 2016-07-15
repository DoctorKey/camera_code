#ifndef _TEST_H_
#define _TEST_H_
#include "stm32f4xx.h"

void set_Rc(u16 pitch,u16 roll,u16 thr,u16 yaw);
void set_Front_Target(u8 x,u8 y);
void set_Back_Target(u8 x,u8 y);

#endif
