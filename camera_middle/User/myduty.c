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

s16 roll_ch_offset=-73;
s16 pit_ch_offset=-26;
s16 yaw_ch_offset=0;
s16 go_pit_offset=140;
s16 back_pit_offset=-100;

u16 go_wait_time=4100;
u16 front_throw_wait_time=300;
u16 back_wait_time=3000;

void middle_duty()
{
	if(mode==0)
	{
		wait_ready();
	}else if(mode==7)
	{
		unlock();
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
	else if(mode==6)
	{
		lock();
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
void unlock()
{
	ctrl_throw(0);
	Rc_out.yaw = 1500 + yaw_ch_offset;
	Rc_out.thr = 1900;
	Rc_out.roll = 1500 + roll_ch_offset;
	Rc_out.pitch = 1500 + pit_ch_offset;
	set_pwm(&Rc_out);
	delay_ms(2000);
	mode = 1;
}
u32 go_start_time;//ms
u32 back_start_time;
u16 go_pit_delter;
u8  wait_count;
u32 front_throw_time;
u8 drop_ok=0;

void take_off()
{
	Rc_out.roll = 1500 + roll_ch_offset;
	Rc_out.pitch = 1500 + pit_ch_offset;
	Rc_out.yaw = 1500 + yaw_ch_offset;
	Rc_out.thr = 1200;
	set_pwm(&Rc_out);
	delay_ms(500);
	mode = 2;
	Rc_out.pitch = 1500 + pit_ch_offset + go_pit_offset;
	go_pit_delter = go_pit_offset*50/go_wait_time;
	Rc_out.thr = 1300;
	set_pwm(&Rc_out);
	go_start_time = GetSysTime_ms();
}
void go()
{
	control_go();//调整roll,输出pwm
	if(front_measure_info.x >115 && GetSysTime_ms() > go_start_time + 1000 )
	{
		wait_count = 1;
		front_throw_time = GetSysTime_ms();
	}
	if(wait_count == 1 && GetSysTime_ms() > front_throw_time + front_throw_wait_time)
	{
		Rc_out.pitch = 1500 + pit_ch_offset;
		Rc_out.thr = 1400;
		set_pwm(&Rc_out);
		mode = 3;
		wait_count = 0;
		printf("前摄像头定时!!!!!!!\r\n");
	}
	if(GetSysTime_ms() > go_start_time + go_wait_time)
	{
		Rc_out.pitch = 1500 + pit_ch_offset;
		Rc_out.thr = 1400;
		set_pwm(&Rc_out);
		mode = 3;
		printf("定时器:%dms投球!!!!!!\r\n",go_wait_time);
	}
	if(middle_measure_info.ratio > THROW_READY)
	{
		Rc_out.pitch = 1500 + pit_ch_offset;
		Rc_out.thr = 1400;
		set_pwm(&Rc_out);
		mode = 3;
		printf("middle投球\r\n");
	}
}
void throw_ball()
{
		ctrl_throw(1);
		Rc_out.pitch = 1500 + pit_ch_offset;
		Rc_out.thr = 1400;
		set_pwm(&Rc_out);
		delay_ms(40);
		mode = 4;

	Rc_out.pitch = 1500 + pit_ch_offset;// + back_pit_offset;
	Rc_out.thr = 1600;
	go_pit_delter = back_pit_offset*100/back_wait_time;
	set_pwm(&Rc_out);
	back_start_time = GetSysTime_ms();
}
void back()
{
	control_back();
	if(GetSysTime_ms() > back_start_time + 2000)
	{
		drop_ok = 1;
	}
	if(GetSysTime_ms() > back_start_time + back_wait_time)
	{
		ctrl_throw(0);
		Rc_out.pitch = 1500 + pit_ch_offset;
		Rc_out.thr = 1700;
		set_pwm(&Rc_out);
		printf("定时器降落!!!!!\r\n");
		mode = 5;
	}
	if(drop_ok==1 && middle_measure_info.ratio > DROP_READY)
	{
		ctrl_throw(0);
		Rc_out.pitch = 1500 + pit_ch_offset;
		Rc_out.thr = 1700;
		set_pwm(&Rc_out);
		printf("middle降落!!!!!\r\n");
		mode = 5;
		drop_ok=0;
	}
}
void drop()
{
	Rc_out.thr = 1700;
	set_pwm(&Rc_out);
	ctrl_throw(0);
	
	wait_count = 0;
	drop_ok=0;
}
void lock()
{
	Rc_out.roll = 1500 + roll_ch_offset;
	Rc_out.pitch = 1500 + pit_ch_offset;
	Rc_out.yaw = 1500 + yaw_ch_offset;
	Rc_out.thr = 1800;
	set_pwm(&Rc_out);
	ctrl_throw(0);
}
void set_mode(u8 command)
{
	mode = command;
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
void set_wait_time(u16 go,u16 throw_wait,u16 back)
{
	go_wait_time = go;
	front_throw_wait_time = throw_wait;
	back_wait_time = back;
}


