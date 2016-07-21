#include "ctrl.h"
#include "dgp.h"
#include "data_transfer.h"
#include "init.h"

PID_Typedef roll_pid;
PID_Typedef yaw_pid;

Rc_group Rc_front;
Rc_group Rc_back;
Rc_group Rc_send;

u8 front_info_y_last;
u8 back_info_y_last;

u8 back_ctrl_finish;

void pid_set()
{
	roll_pid.kp=0.8;
	roll_pid.ki=0;
	roll_pid.kd=0;
	
	yaw_pid.kp=1;
	yaw_pid.ki=0;
	yaw_pid.kd=0;
}
void front_duty()
{
	Send_ready(1,ready_1);
	Send_Front_Target(front_measure_info);
	control_go_output(front_measure_info,back_measure_info);
}
void back_duty()
{
//	Send_ready(2,ready_2);
	Send_Back_Target(back_measure_info);
	control_back_output(front_measure_info,back_measure_info);
	ready_2++;
}
void control_yaw(PID_Typedef * PID,im_info front_info,im_info back_info)
{
	float target,measure;
	target = 0;
	measure = front_info.y - back_info.y;
	PID_Position(PID,target,measure);
}

//-----------位置PID-----------
void PID_Position(PID_Typedef * PID,float target,float measure)
{
		
	PID->error = target - measure;
	
	PID->deriv = PID->error - PID->preerror;
	
	PID->integ = PID->integ + PID->error;     
	
	if(PID->integ > PID->integ_max)
		PID->integ = PID->integ_max;   
	else if(PID->integ < - PID->integ_max)
		PID->integ = - PID->integ_max;
			
	PID->output = (PID->kp * PID->error) + (PID->ki * PID->integ) + (PID->kd * PID->deriv);
	
	PID->preerror = PID->error;
	
}

//-------------------前进时控制---------------
void control_go_roll(PID_Typedef * PID,im_info front_info,im_info back_info)
{
	float target,measure;
	target = 0;
//	measure = (front_info.y + back_info.y)/2 - PIC_COL;
	if(front_info.y == 0)
	{
		measure = 0;
	}
	else
	{
		measure = PIC_COL/2 - front_info.y;
	}
//	if(front_info.y > 40 && front_info.y < 120)
//	{
//		PID->output = 0;
//	}else if(front_info.y < 40 && front_info.y > 10)
//	{
//		PID->output = -15;
//	}else if(front_info.y >120 && front_info.y <155)
//	{
//		PID->output = 15;
//	}else
//	{
//		front_info.y = front_info_y_last;
//	}
	if(front_info.y < 5 || front_info.y > 155)
	{
		front_info.y = front_info_y_last;
	}
	PID_Position(PID,target,measure);
	front_info_y_last = front_info.y;
}
void control_go_output(im_info front_info,im_info back_info)
{
//	control_yaw(&yaw_pid,front_info,back_info);
	control_go_roll(&roll_pid,front_info,back_info);
	
	Rc_front.yaw = 1500 + yaw_pid.output;
	Rc_front.roll = 1500 + roll_pid.output;
	
	Send_Front_Rc(Rc_front);
}

//-------------------后退时控制---------------
void control_back_roll(PID_Typedef * PID,im_info front_info,im_info back_info)
{
	float target,measure;
	target = 0;
//	measure = (front_info.y + back_info.y)/2 - PIC_COL;
	if(back_info.y == 0)
	{
		measure = 0;
	}
	else
	{
		measure = PIC_COL/2 - back_info.y;
	}
//	if(front_info.y > 40 && front_info.y < 120)
//	{
//		PID->output = 0;
//	}else if(front_info.y < 40 && front_info.y > 10)
//	{
//		PID->output = -15;
//	}else if(front_info.y >120 && front_info.y <155)
//	{
//		PID->output = 15;
//	}else
//	{
//		front_info.y = front_info_y_last;
//	}
	if(back_info.y < 5 || back_info.y > 155)
	{
		back_info.y = back_info_y_last;
	}
	PID_Position(PID,target,measure);
	front_info_y_last = front_info.y;
}
void control_back_output(im_info front_info,im_info back_info)
{
//	control_yaw(&yaw_pid,front_info,back_info);
	control_go_roll(&roll_pid,front_info,back_info);
	
	Rc_back.yaw = 1500 + yaw_pid.output;
	Rc_back.roll = 1500 + roll_pid.output;
	
	Send_Front_Rc(Rc_back);
}


