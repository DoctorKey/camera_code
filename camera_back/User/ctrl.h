#ifndef __CTRL_H
#define __CTRL_H
#include "include.h"
#include "dgp.h"

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
void front_duty(void);
void back_duty(void);
void control_go_output(im_info front_info,im_info back_info);
void PID_Position(PID_Typedef * PID,float target,float measure);
void control_back_output(im_info front_info,im_info back_info);

extern Rc_group Rc_front;
extern Rc_group Rc_back;

extern u8 back_ctrl_finish;

#endif 
