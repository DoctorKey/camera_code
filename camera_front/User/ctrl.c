#include "ctrl.h"
#include "dgp.h"
#include "data_transfer.h"
#include "init.h"

Rc_group Rc_front;

u8 ctrl_finish;//0 ������ƣ�������µ�ͼ������
							 //1 ��ɿ��ƣ��ȴ����ͼ������

void front_duty()
{
//	Send_ready(1,ready_1);
	Send_Front_Measure(front_measure_info);
	ready_1++;
}

