#ifndef __CTRL_H
#define __CTRL_H
#include "include.h"
#include "dgp.h"

typedef struct
{
	u16 pitch;
	u16 roll;
	u16 thr;
	u16 yaw;
}Rc_group;

void back_duty(void);

extern Rc_group Rc_front;
extern Rc_group Rc_back;

extern u8 back_ctrl_finish;

#endif 
