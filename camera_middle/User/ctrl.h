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
void pwm_test(u16 p1,u16 p2,u16 p3,u16 p4);
void ctrl_throw(u8 command);
void control_duty(void);
void control_throw(void);

extern int16_t CH[];
extern Rc_group Rc_out;
extern Rc_group Back_Rc;

#endif 
