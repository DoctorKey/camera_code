#ifndef _DATA_TRANSFER_H
#define	_DATA_TRANSFER_H

#include "stm32f4xx.h"

#define PITCH_CH 2
#define ROLL_CH 3
#define THR_CH 4
#define YAW_CH 5

void Data_Receive_Prepare_1(u8 data);
void Data_Receive_Prepare_2(u8 data);
void Data_Receive_deal(u8 *data_buf,u8 num);

#endif