#ifndef __CTRL_H
#define __CTRL_H
#include "include.h"
#include "pwm_out.h"

typedef struct
{
	float kp;
	float ki;
	float kd;
	float error;
	float preerror;
	float integ;
	float integ_max;
	float deriv;
	float output; 
}PID_Typedef;


void pid_set(void);

void control_go(void);
void control_back(void);
void control_throw(void);

void set_pid(u16 front_kp,u16 back_kp,u8 choose);

extern Rc_group Rc_out;
extern Rc_group Rc_front;
extern Rc_group Rc_back;
extern u8 middle_ctrl;

#endif 
