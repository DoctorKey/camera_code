#include "ctrl.h"
#include "dgp.h"
#include "myduty.h"
#include "data_transfer.h"
#include "mymath.h"

u8 middle_ctrl;

//中间摄像头的两组pid参数
PID_Typedef pitch_pid;
PID_Typedef roll_pid;

PID_Typedef front_pid;
PID_Typedef back_pid;

Rc_group Rc_out;
Rc_group Rc_front;
Rc_group Rc_back;


void pid_set()
{
	front_pid.kp = 0.4;
	front_pid.kd = 0;
	front_pid.ki = 0;
	
	back_pid.kp = 0.4;
	back_pid.kd = 0;
	back_pid.ki = 0;
	
	pitch_pid.kp = 1;
	pitch_pid.kd = 0;
	pitch_pid.ki = 0;
	
	roll_pid.kp = 0.4;//寻迹p
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
	if(middle_info.line_y == 0)
	{
		measure = PIC_COL/2;
	}
	else
	{
		measure = middle_info.line_y;
	}
	PID_Position(PID,measure,target);//measure - target
}
void control_throw()
{
	control_pitch(&pitch_pid,middle_measure_info);
	control_roll(&roll_pid,middle_measure_info);
	Rc_out.pitch = 1500 + pit_ch_offset + pitch_pid.output;
	Rc_out.roll = 1500 + roll_ch_offset + roll_pid.output;
	
	set_pwm(&Rc_out);
}


u8 front_info_y_last;
u8 back_info_y_last;

//前摄像头调整roll
void control_front_roll(PID_Typedef * PID,im_info front_info,im_info back_info)
{
	float target,measure;
	target = PIC_COL/2;
	
	if(front_info.y == 0)
	{
		measure = PIC_COL/2;
	}
	else
	{
		measure = front_info.y;
	}
	if(front_info.y < 5 || front_info.y > 155)
	{
		front_info.y = front_info_y_last;
	}
	PID_Position(PID,measure,target);//error=measure-target
	front_info_y_last = front_info.y;
}
//后摄像头调整roll
void control_back_roll(PID_Typedef * PID,im_info front_info,im_info back_info)
{
	float target,measure;
	target = PIC_COL/2;

	if(back_info.y == 0)
	{
		measure = PIC_COL/2;
	}
	else
	{
		measure = back_info.y;
	}
	if(back_info.y < 5 || back_info.y > 155)
	{
		back_info.y = back_info_y_last;
	}
	PID_Position(PID,target,measure);
	front_info_y_last = front_info.y;
}


/////////////////////////////////////////////////
u8 roll_ctrl=0;
//-------------------前进时控制---------------
void control_go()
{
	if(front_info_ok==1)//大概50ms一次
	{
		control_front_roll(&front_pid,front_measure_info,back_measure_info);
		printf("--f--y:%d,x:%d,",front_measure_info.y,front_measure_info.x);
		Rc_out.pitch -= go_pit_delter;
		front_info_ok = 0;
		roll_ctrl = 1;
	}
	if(back_info_ok==1)//大概50ms一次
	{		
		control_back_roll(&back_pid,front_measure_info,back_measure_info);
		printf("--b--y:%d,x:%d,",back_measure_info.y,back_measure_info.x);
		back_info_ok = 0;
		roll_ctrl = 1;
	}
	if(roll_ctrl == 1)
	{
		Rc_out.roll = 1500 + roll_ch_offset + front_pid.output + back_pid.output;
		set_pwm(&Rc_out);
		printf("roll:%d\r\n",Rc_out.roll);
		roll_ctrl = 0;
	}
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////


//-------------------后退时控制---------------
void control_back()
{
	if(front_info_ok==1)
	{
		control_front_roll(&front_pid,front_measure_info,back_measure_info);
		printf("--f--y:%d,x:%d,",front_measure_info.y,front_measure_info.x);
		front_info_ok = 0;
		roll_ctrl = 1;
	}
	if(back_info_ok==1)
	{		
		control_back_roll(&back_pid,front_measure_info,back_measure_info);
		printf("--b--y:%d,x:%d,",back_measure_info.y,back_measure_info.x);
		Rc_out.pitch -= go_pit_delter;
		back_info_ok = 0;
		roll_ctrl = 1;
	}
	if(roll_ctrl == 1)
	{
		Rc_out.roll = 1500 + roll_ch_offset + front_pid.output + back_pid.output;
		set_pwm(&Rc_out);
		printf("roll:%d\r\n",Rc_out.roll);
		roll_ctrl = 0;
	}
}



