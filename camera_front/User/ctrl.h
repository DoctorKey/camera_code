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

extern Rc_group Rc_front;

#endif 
