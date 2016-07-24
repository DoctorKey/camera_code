#include "ctrl.h"
#include "dgp.h"
#include "data_transfer.h"
#include "init.h"

Rc_group Rc_front;
Rc_group Rc_back;
Rc_group Rc_send;

u8 back_ctrl_finish;

void back_duty()
{
//	Send_ready(2,ready_2);
	Send_Back_Target(back_measure_info);
//	control_back_output(front_measure_info,back_measure_info);
	ready_2++;
}




