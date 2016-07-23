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

s16 roll_ch_offset;
s16 pit_ch_offset;
s16 yaw_ch_offset;
s16 go_pit_offset;
s16 back_pit_offset;

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
	ctrl_throw(0);
	if(ready_3 > 0)
	{
		if(ready_2 > 0)
		{
			if(ready_1 > 0)
			{			
				Rc_out.yaw = 1500 + yaw_ch_offset;
				Rc_out.thr = 1100;
				Rc_out.roll = 1500 + roll_ch_offset;
				Rc_out.pitch = 1500 + pit_ch_offset;
				set_pwm(&Rc_out);
				delay_ms(500);
//				mode = 1;
				all_ready=1;
			}
		}
	}	
}
u16 go_time;
void take_off()
{
	Rc_out.roll = 1500 + roll_ch_offset;
	Rc_out.pitch = 1500 + pit_ch_offset;
	Rc_out.yaw = 1500 + yaw_ch_offset;
	Rc_out.thr = 1200;
	set_pwm(&Rc_out);
	delay_ms(500);
	mode = 2;
	go_time=time;
}
u16 throw_count;//定时
u8 wait_count=0;
u16 throw_time;

void go()
{
	control_go();
	if(front_measure_info.x >115)
	{
		wait_count = 1;
	}
	if(wait_count == 1)
	{
		throw_count++;
	}
	if(throw_count > throw_time)
	{
		Rc_out.pitch = 1500 + pit_ch_offset;
		Rc_out.thr = 1400;
		set_pwm(&Rc_out);
		mode = 3;
		wait_count = 0;
		throw_count = 0;
		printf("定时器投球!!!!!!!\r\n");
	}
	if(middle_measure_info.ratio > THROW_READY)
	{
		Rc_out.pitch = 1500 + pit_ch_offset;
		Rc_out.thr = 1400;
		set_pwm(&Rc_out);
		mode = 3;
		printf("middle投球!!!!!!!\r\n");
	}
	if(time > go_time + 4)
	{
		Rc_out.pitch = 1500 + pit_ch_offset;
		Rc_out.thr = 1400;
		set_pwm(&Rc_out);
		mode = 3;
		printf("4s go_time:%d, 投球!!!!!!!\r\n",go_time);
	}
}
u8 back_time;
void throw_ball()
{
//	Rc_out.thr = 1400;
//	Rc_out.yaw = 1500 + yaw_ch_offset;
//	control_throw();
//	if(middle_measure_info.ratio > THROW_BALL)
//	{
		Rc_out.pitch = 1500 + pit_ch_offset;
		Rc_out.thr = 1400;
		set_pwm(&Rc_out);
		ctrl_throw(1);
		delay_ms(40);
		mode = 4;
		back_time = time;
//	}
}
u8 drop_ok;
u8 back_cnt;
void back()
{
	control_back();
	if(middle_measure_info.ratio > DROP_READY && drop_ok==1)
	{
		ctrl_throw(0);
		Rc_out.pitch = 1500 + pit_ch_offset + go_pit_offset;
		Rc_out.thr = 1700;
		set_pwm(&Rc_out);
		drop_ok = 0;
		mode = 5;
	}
	if(time >back_time +3)
	{
		ctrl_throw(0);
		Rc_out.pitch = 1500 + pit_ch_offset + go_pit_offset;
		Rc_out.thr = 1700;
		set_pwm(&Rc_out);
		drop_ok = 0;
		mode = 5;
		printf("3s back_time:%d,飞回降落!!!!!!!\r\n",back_time);
	}
}
void drop()
{
	Rc_out.roll = 1500 + roll_ch_offset;
	Rc_out.pitch = 1500 + pit_ch_offset + go_pit_offset;
	Rc_out.yaw = 1500 + yaw_ch_offset;
	Rc_out.thr = 1700;
	set_pwm(&Rc_out);
	ctrl_throw(0);
	
	throw_count = 0;
	wait_count=0;
	drop_ok=0;
  back_cnt=0;
	
	go_time = 0;
	back_time = 0;
	time = 0;
//	mode = 6;
}
void set_mode(u8 command)
{
	mode = command;
}
void set_time(u16 t)
{
	throw_time = t;
}
void set_offset(u16 roll_offset,u16 pit_offset,u16 yaw_offset)
{
	roll_ch_offset = roll_offset -1500;
	pit_ch_offset = pit_offset -1500;
	yaw_ch_offset = yaw_offset -1500;
}
void set_gopit(u16 go_pit)
{
	go_pit_offset = go_pit - 1500;
}
void set_backpit(u16 back_pit)
{
	back_pit_offset = back_pit - 1500;
}

