#ifndef _PWM_OUT_H_
#define _PWM_OUT_H_

#include "stm32f4xx.h"

typedef struct
{
	u16 pitch;
	u16 roll;
	u16 thr;
	u16 yaw;
}Rc_group;

u8 PWM_Out_Init(uint16_t hz);
void SetPwm_1(int16_t pwm[],s16 min,s16 max);
void SetPwm_5(int16_t pwm_3,int16_t pwm_4,s16 min,s16 max);

void set_pwm(Rc_group *Rc);
void ctrl_throw(u8 command);// 0 关舵机，1 开舵机

#endif

