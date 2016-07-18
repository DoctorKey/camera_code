#include "ctrl.h"
#include "dgp.h"
#include "data_transfer.h"
#include "init.h"

PID_Typedef roll_pid;
PID_Typedef yaw_pid;

Rc_group Rc_front;
Rc_group Rc_send;

void pid_set()
{
	roll_pid.kp=1;
	roll_pid.ki=0;
	roll_pid.kd=0;
	
	yaw_pid.kp=1;
	yaw_pid.ki=0;
	yaw_pid.kd=0;
}
void back_duty()
{
	Send_ready(1,ready_1);
	Send_ready(2,ready_2);
	Send_Front_Target(front_measure_info);
	Send_Back_Target(back_measure_info);
	control_pwm(front_measure_info,back_measure_info);
	ready_2++;
}
void control_yaw(PID_Typedef * PID,im_info front_info,im_info back_info)
{
	float target,measure;
	target = 0;
	measure = front_info.y - back_info.y;
	PID_Position(PID,target,measure);
}
void control_roll(PID_Typedef * PID,im_info front_info,im_info back_info)
{
	float target,measure;
	target = 0;
	measure = (front_info.y + back_info.y)/2 - PIC_COL;
	PID_Position(PID,target,measure);
}
void control_pwm(im_info front_info,im_info back_info)
{
	control_yaw(&yaw_pid,front_info,back_info);
	control_roll(&roll_pid,front_info,back_info);
	
	Rc_send.yaw = 1500 + YAW_OFFSET + yaw_pid.output;
	Rc_send.roll = 1500 + ROLL_OFFSET + roll_pid.output;
	
	Send_Rc(Rc_send);
}

//-----------Î»ÖÃPID-----------
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

//-----------ÔöÁ¿PID-----------
void PID_Incremental(PID_Typedef * PID,float target,float measure)
{
	PID->error = target - measure;

	PID->output = PID->kp * (PID->error - PID->preerror) + PID->ki * PID->error + PID->kd * (PID->error - 2 * PID->preerror + PID->prepreerror);

	PID->preerror = PID->error;
	PID->prepreerror = PID->preerror;
}

