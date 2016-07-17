#include "myduty.h"
#include "init.h"
#include "ctrl.h"
#include "include.h"
#include "dgp.h"

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
}
void wait_ready()
{
	if(ready_3==1)
	{
		if(ready_2==1)
		{
			if(ready_1==1)
			{
				CH[YAW_CH] = 1100;
				CH[THR_CH] = 1100;
				CH[ROLL_CH] = 1900;
				CH[PIT_CH] = 1900;
				ctrl_pwm(CH);
				delay_ms(1500);
				CH[YAW_CH] = 1500;
				CH[THR_CH] = 1100;
				CH[ROLL_CH] = 1500;
				CH[PIT_CH] = 1500;
				ctrl_pwm(CH);
				delay_ms(500);
				mode = 1;
			}
		}
	}	
}
void take_off()
{
	CH[ROLL_CH] = 1500 + ROLL_CH_OFFSET;
	CH[PIT_CH] = 1500 + PIT_CH_OFFSET;
	CH[YAW_CH] = 1500 + YAW_CH_OFFSET;
	CH[THR_CH] = 1200;
	ctrl_pwm(CH);
	mode = 2;
}
void go()
{
	CH[PIT_CH] = 1500 + PIT_CH_OFFSET + GO_PIT;
	CH[THR_CH] = 1300;
	control_duty();
	if(middle_measure_info.ratio > THROW_READY)
	{
		CH[PIT_CH] = 1500 + PIT_CH_OFFSET;
		CH[THR_CH] = 1400;
		ctrl_pwm(CH);
		mode = 3;
	}
}
void throw_ball()
{
	CH[THR_CH] = 1400;
	CH[YAW_CH] = 1500 + YAW_CH_OFFSET;
	control_throw();
	if(middle_measure_info.ratio > THROW_BALL)
	{
		ctrl_throw(1);
		CH[PIT_CH] = 1500 + PIT_CH_OFFSET;
		CH[THR_CH] = 1400;
		ctrl_pwm(CH);
		mode = 4;
	}
}
void back()
{
	CH[PIT_CH] = 1500 + PIT_CH_OFFSET + BACK_PIT;
	CH[THR_CH] = 1500;
	control_duty();
	if(middle_measure_info.ratio > DROP_READY)
	{
		ctrl_throw(0);
		CH[PIT_CH] = 1500 + PIT_CH_OFFSET;
		CH[THR_CH] = 1600;
		ctrl_pwm(CH);
		mode = 5;
	}
}
void drop()
{
	CH[ROLL_CH] = 1500 + ROLL_CH_OFFSET;
	CH[PIT_CH] = 1500 + PIT_CH_OFFSET;
	CH[YAW_CH] = 1500 + YAW_CH_OFFSET;
	CH[THR_CH] = 1600;
	ctrl_pwm(CH);
	mode = 6;
}
