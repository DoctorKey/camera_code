#include "test.h"
#include "dgp.h"
#include "ctrl.h"

void set_Rc(u16 pitch,u16 roll,u16 thr,u16 yaw)
{
	Rc_front.pitch = pitch;
	Rc_front.roll = roll;
	Rc_front.thr = thr;
	Rc_front.yaw = yaw;
}
void set_Front_Target(u8 x,u8 y)
{
	front_target_info.x = x;
	front_target_info.y = y;
}
void set_Back_Target(u8 x,u8 y)
{
	back_target_info.x = x;
	back_target_info.y = y;
}

