#include "myduty.h"
#include "init.h"
#include "ctrl.h"
#include "include.h"
#include "dgp.h"

u8 all_ready=0;
u8 mode=0;
//wait ready 0
//take off 1
//go 2
//throw ball 3
//back 4
//drop 5

void middle_duty()
{
	if(mode==0)
	{
		wait_ready();
	}else if(mode==1)
	{
		take_off();
	}else if(mode==2)
	{
		go();
	}else if(mode==3)
	{
		throw_ball();
	}else if(mode==4)
	{
		back();
	}else if(mode==5)
	{
		drop();
	}
	ready_3++;
}
void wait_ready()
{
	if(ready_3 > 0)
	{
		if(ready_2 > 0)
		{
			if(ready_1 > 0)
			{			
//				Rc_out.yaw = 1100;
//				Rc_out.thr = 1100;
//				Rc_out.roll = 1900;
//				Rc_out.pitch = 1900;
//				set_pwm(&Rc_out);
//				delay_ms(1500);
				Rc_out.yaw = 1500 + YAW_CH_OFFSET;
				Rc_out.thr = 1100;
				Rc_out.roll = 1500 + ROLL_CH_OFFSET;
				Rc_out.pitch = 1500 + PIT_CH_OFFSET;
				set_pwm(&Rc_out);
				delay_ms(500);
//				mode = 1;
				all_ready=1;
			}
		}
	}	
}
void take_off()
{
	Rc_out.roll = 1500 + ROLL_CH_OFFSET;
	Rc_out.pitch = 1500 + PIT_CH_OFFSET;
	Rc_out.yaw = 1500 + YAW_CH_OFFSET;
	Rc_out.thr = 1200;
	set_pwm(&Rc_out);
//	mode = 2;
}
void go()
{
	Rc_out.pitch = 1500 + PIT_CH_OFFSET + GO_PIT;
	Rc_out.thr = 1300;
	control_duty();
	if(middle_measure_info.ratio > THROW_READY)
	{
		Rc_out.pitch = 1500 + PIT_CH_OFFSET;
		Rc_out.thr = 1400;
		set_pwm(&Rc_out);
//		mode = 3;
	}
}
void throw_ball()
{
	Rc_out.thr = 1400;
	Rc_out.yaw = 1500 + YAW_CH_OFFSET;
	control_throw();
	if(middle_measure_info.ratio > THROW_BALL)
	{
		ctrl_throw(1);
		Rc_out.pitch = 1500 + PIT_CH_OFFSET;
		Rc_out.thr = 1400;
		set_pwm(&Rc_out);
//		mode = 4;
	}
}
void back()
{
	Rc_out.pitch = 1500 + PIT_CH_OFFSET + BACK_PIT;
	Rc_out.thr = 1500;
	control_duty();
	if(middle_measure_info.ratio > DROP_READY)
	{
		ctrl_throw(0);
		Rc_out.pitch = 1500 + PIT_CH_OFFSET;
		Rc_out.thr = 1600;
		set_pwm(&Rc_out);
//		mode = 5;
	}
}
void drop()
{
	Rc_out.roll = 1500 + ROLL_CH_OFFSET;
	Rc_out.pitch = 1500 + PIT_CH_OFFSET;
	Rc_out.yaw = 1500 + YAW_CH_OFFSET;
	Rc_out.thr = 1600;
	set_pwm(&Rc_out);
//	mode = 6;
}
void set_mode(u8 command)
{
	mode = command;
}
