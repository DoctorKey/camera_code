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

void ctrl_pwm(int16_t CH[CH_NUM]);
void PID_Position(PID_Typedef * PID,float target,float measure);
void PID_Incremental(PID_Typedef * PID,float target,float measure);

extern Rc_group Rc_front;
extern Rc_group Rc_back;
extern Rc_group Rc_send;

#endif 
