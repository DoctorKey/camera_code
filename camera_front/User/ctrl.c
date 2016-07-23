#include "ctrl.h"
#include "dgp.h"
#include "data_transfer.h"
#include "init.h"

Rc_group Rc_front;

u8 ctrl_finish;//0 允许控制，获得了新的图像数据
							 //1 完成控制，等待获得图像数据

void front_duty()
{
//	Send_ready(1,ready_1);
	Send_Front_Measure(front_measure_info);
	ready_1++;
}

