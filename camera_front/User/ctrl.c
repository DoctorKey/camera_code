#include "ctrl.h"
#include "dgp.h"
#include "data_transfer.h"
#include "init.h"

Rc_group Rc_front;

void front_duty()
{
	
//	delay_ms(1000);
//	Send_Front_Measure(front_measure_info);
//	Send_Rc(Rc_front);
	Send_Front_Measure(front_measure_info);
	Send_ready(1,ready_1);
}

