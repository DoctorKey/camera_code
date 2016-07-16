#ifndef __CTRL_H
#define __CTRL_H
#include "include.h"


typedef struct
{
	u16 pitch;
	u16 roll;
	u16 thr;
	u16 yaw;
}Rc_group;

void front_duty();
	
extern Rc_group Rc_front;

#endif 
