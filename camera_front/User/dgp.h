#ifndef _DGP_H_
#define _DGP_H_
#include "stm32f4xx.h"

typedef struct{
	u8 x;
	u8 y;
	float ratio;
}im_info;

void jpeg_data_process(void);
void get_info(u16 *jpeg,u8 *im,im_info *info);

extern volatile u8 jpeg_data_ok;
extern volatile u32 jpeg_data_len;
extern im_info front_measure_info;
extern im_info back_measure_info;

#endif

