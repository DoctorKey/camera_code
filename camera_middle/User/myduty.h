#ifndef _MYDUTY_H_
#define _MYDUTY_H_

#include "stm32f4xx.h"

void middle_duty(void);

void wait_ready(void);
void take_off(void);
void go(void);
void throw_ball(void);
void back(void);
void drop(void);
void set_mode(u8 command);

extern u8 all_ready;
extern u8 mode;

#endif
