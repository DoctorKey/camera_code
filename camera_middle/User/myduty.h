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
void set_offset(u16 roll_offset,u16 pit_offset,u16 yaw_offset);
void set_gopit(u16 go_pit);

extern u8 all_ready;
extern u8 mode;
extern s16 roll_ch_offset;
extern s16 pit_ch_offset;
extern s16 yaw_ch_offset;

#endif
