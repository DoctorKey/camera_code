#ifndef __CTRL_H
#define __CTRL_H
#include "include.h"


typedef struct
{
	float kp;
	float ki;
	float kd;
	float error;
	float preerror;
	float prepreerror;
	float integ;
	float integ_max;
	float deriv;
	float output; 
}PID_Typedef;

typedef struct
{
	u16 pitch;
	u16 roll;
	u16 thr;
	u16 yaw;
}Rc_group;

void pid_set(void);
void ctrl_pwm(int16_t CH[CH_NUM]);
void ctrl_throw(u8 command);
void control_duty(void);
void control_throw(void);

extern int16_t CH[];
extern Rc_group Rc;

#endif 
