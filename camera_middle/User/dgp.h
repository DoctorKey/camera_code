#ifndef _DGP_H_
#define _DGP_H_
#include "stm32f4xx.h"

#define PI_3 1.0472
#define TWO_PI 6.2832
#define PI_3_40 41.888 //  pi/3*40

typedef struct{
	u8 x;
	u8 y;
	float ratio;
	u8 line_x;
	u8 line_y;
	float line_ratio;
}im_info;

void jpeg_data_process(void);
void get_info(u16 *jpeg,u8 *H,im_info *info);
void test(u32* jpeg_buf,u8* im);
void test_Y(u32* jpeg_buf,u8* im);
void test_line(u32* jpeg_buf,u8* im);
void get_target2(u16 *jpeg,u8 *H,im_info *info);
void get_line(u16 *jpeg,u8 *H,im_info *info);	

extern volatile u8 jpeg_data_ok;
extern volatile u32 jpeg_data_len;
extern im_info front_measure_info;
extern im_info back_measure_info;
extern im_info middle_measure_info;

#endif

