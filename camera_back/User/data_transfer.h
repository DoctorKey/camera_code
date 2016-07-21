#ifndef _DATA_TRANSFER_H
#define	_DATA_TRANSFER_H

#include "stm32f4xx.h"
#include "ctrl.h"
#include "dgp.h"

void Data_Receive_Prepare_1(u8 data);
void Data_Receive_Prepare_2(u8 data);
void Data_Receive_deal(u8 *data_buf,u8 num);

void Send_Front_Target(im_info info);
void Send_Back_Target(im_info info);
void Send_Front_Rc(Rc_group rc);
void Send_Back_Rc(Rc_group rc);
void Send_ready(u8 camera_num,u8 ready);

extern u8 front_data_ok;

#endif

