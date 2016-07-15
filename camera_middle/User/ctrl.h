#ifndef __CTRL_H
#define __CTRL_H
#include "include.h"

#define PITCH_CH 0
#define ROLL_CH  1
#define YAW_CH   2
#define THR_CH   3

typedef struct
{
	double p;
	double i;
	double d;
}pid_group;

typedef struct
{
	u16 pitch;
	u16 roll;
	u16 thr;
	u16 yaw;
}Rc_group;

extern int16_t CH[];
void ctrl_pwm(int16_t CH[CH_NUM]);

extern Rc_group Rc;

#endif 
