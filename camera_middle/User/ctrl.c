#include "ctrl.h"
#include "pwm_out.h"
#include "dgp.h"
#include "myduty.h"
#include "data_transfer.h"
#include "mymath.h"

//中间摄像头的两组pid参数
PID_Typedef pitch_pid;
PID_Typedef roll_pid;

Rc_group Rc_out;
Rc_group Rc_front;
Rc_group Rc_back;


void pid_set()
{
	pitch_pid.kp = 1;
	pitch_pid.kd = 0;
	pitch_pid.ki = 0;
	
	roll_pid.kp = 1;
	roll_pid.kd = 0;
	roll_pid.ki = 0;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

void PID_Position(PID_Typedef * PID,float target,float measure)
{
		
	PID->error = target - measure;
	
	PID->deriv = PID->error - PID->preerror;
	
	PID->integ = PID->integ + PID->error;     
	
	PID->integ = LIMIT(PID->integ,-PID->integ_max,PID->integ_max);
			
	PID->output = (PID->kp * PID->error) + (PID->ki * PID->integ) + (PID->kd * PID->deriv);
	
	PID->preerror = PID->error;
	
}
void control_pitch(PID_Typedef * PID,im_info middle_info)
{
	float target,measure;
	target = PIC_ROW/2;
	measure = middle_info.x;
	PID_Position(PID,target,measure);
}
void control_roll(PID_Typedef * PID,im_info middle_info)
{
	float target,measure;
	target = PIC_COL/2;
	measure = middle_info.y;
	PID_Position(PID,target,measure);
}
void control_throw()
{
	control_pitch(&pitch_pid,middle_measure_info);
	control_roll(&roll_pid,middle_measure_info);
	Rc_out.pitch = 1500 + pit_ch_offset + pitch_pid.output;
	Rc_out.roll = 1500 + roll_ch_offset + roll_pid.output;
	
	set_pwm(&Rc_out);
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

void control_go()
{
	if(front_rc_ok==1)
	{
		Rc_out.roll = Rc_front.roll + roll_ch_offset;
	//	Rc_out.yaw = Back_Rc.yaw;
	//	Rc_out.roll = 1500 + roll_ch_offset;
		Rc_out.yaw = 1500 + yaw_ch_offset;
		set_pwm(&Rc_out);
		printf("-----roll:%d,y:%d,x:%d\r\n",Rc_out.roll,front_measure_info.y,front_measure_info.x);
		front_rc_ok = 0;
	}
}
void control_back()
{
	if(back_rc_ok==1)
	{
		Rc_out.roll = Rc_back.roll + roll_ch_offset;
	//	Rc_out.yaw = Back_Rc.yaw;
	//	Rc_out.roll = 1500 + roll_ch_offset;
		Rc_out.yaw = 1500 + yaw_ch_offset;
		set_pwm(&Rc_out);
		back_rc_ok = 0;
	}
}



int16_t pwm[4]={0,0,0,0};//0~500
void set_pwm(Rc_group *Rc)
{
	pwm[0]=(Rc->roll-1000)/2;
	pwm[1]=(Rc->pitch-1000)/2;
	pwm[2]=(Rc->thr-1000)/2;
	pwm[3]=(Rc->yaw-1000)/2;
	SetPwm_1(pwm,PWM_MIN,PWM_MAX);
}

int16_t pwm_throw[2]={0,0};
void ctrl_throw(u8 command)
{
	if(command==1)//throw
	{
		pwm_throw[0]=250;
		pwm_throw[1]=250;
		SetPwm_5(pwm_throw[0],pwm_throw[1],PWM_MIN,PWM_MAX);
	}else if(command==0)//close
	{
		pwm_throw[0]=0;
		pwm_throw[1]=0;
		SetPwm_5(pwm_throw[0],pwm_throw[1],PWM_MIN,PWM_MAX);
	}
}

