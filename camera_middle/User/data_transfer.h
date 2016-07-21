#ifndef _DATA_TRANSFER_H
#define	_DATA_TRANSFER_H

#include "stm32f4xx.h"
#include "dgp.h"
#include "ctrl.h"

void Data_Receive_Prepare_1(u8 data);
void Data_Receive_Prepare_2(u8 data);
void Data_Receive_deal(u8 *data_buf,u8 num);

void Send_Front_Measure(im_info info);
void Send_Back_Measure(im_info info);
void Send_Rc(Rc_group rc);

extern u8 front_rc_ok;
extern u8 back_rc_ok;

#endif
