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
void set_pwm(Rc_group *Rc);
void ctrl_throw(u8 command);// 0 �ض����1 �����
void control_go(void);
void control_back(void);
void control_throw(void);

extern Rc_group Rc_out;
extern Rc_group Rc_front;
extern Rc_group Rc_back;

#endif 
