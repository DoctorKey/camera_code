#ifndef _OV7670CFG_H
#define _OV7670CFG_H
#include "ov7670.h" 

static	const u8 ov7670_init_reg_tbl[][2]= 
{   
	/*以下为OV7670 QVGA RGB565参数  */
	{0x3a, 0x04},//dummy
	{0x40, 0x10},//565   
	{0x12, 0x14},//QVGA,RGB输出

	//输出窗口设置
	{0x32, 0x80},//HREF control	bit[2:0] HREF start 3 LSB	 bit[5:3] HSTOP HREF end 3LSB
	{0x17, 0x16},//HSTART start high 8-bit MSB         
	{0x18, 0x04},//5 HSTOP end high 8-bit
	{0x19, 0x02},
	{0x1a, 0x7b},//0x7a,
	{0x03, 0x06},//0x0a,帧竖直方向控制

	{0x0c, 0x00},
	{0x15, 0x08},//0x00
	{0x3e, 0x00},//10
	{0x70, 0x3a},//测试图
	{0x71, 0x35},//测试图
	{0x72, 0x11},
	{0x73, 0x00},//

	{0xa2, 0x02},//15
	{0x11, 0x81},//81 时钟分频设置,0,不分频.////////////////////////////
	{0x7a, 0x20},
	{0x7b, 0x1c},
	{0x7c, 0x28},

	{0x7d, 0x3c},//20
	{0x7e, 0x55},
	{0x7f, 0x68},
	{0x80, 0x76},
	{0x81, 0x80},

	{0x82, 0x88},
	{0x83, 0x8f},
	{0x84, 0x96},
	{0x85, 0xa3},
	{0x86, 0xaf},

	{0x87, 0xc4},//30
	{0x88, 0xd7},
	{0x89, 0xe8},
	{0x13, 0xe0},
	{0x00, 0x00},//AGC

	{0x10, 0x00},
	{0x0d, 0x00},//全窗口， 位[5:4]: 01 半窗口，10 1/4窗口，11 1/4窗口 
	{0x14, 0x28},//0x38, limit the max gain
	{0xa5, 0x05},
	{0xab, 0x07},

	{0x24, 0x75},//40
	{0x25, 0x63},
	{0x26, 0xA5},
	{0x9f, 0x78},
	{0xa0, 0x68},

	{0xa1, 0x03},//0x0b,
	{0xa6, 0xdf},//0xd8,
	{0xa7, 0xdf},//0xd8,
	{0xa8, 0xf0},
	{0xa9, 0x90},

	{0xaa, 0x94},//50
	{0x13, 0xe5},
	{0x0e, 0x61},
	{0x0f, 0x4b},
	{0x16, 0x02},

	{0x1e, 0x07},//图像输出镜像控制.0x07
	{0x21, 0x02},
	{0x22, 0x91},
	{0x29, 0x07},
	{0x33, 0x0b},

	{0x35, 0x0b},//60
	{0x37, 0x1d},
	{0x38, 0x71},
	{0x39, 0x2a},
	{0x3c, 0x78},

	{0x4d, 0x40},
	{0x4e, 0x20},
	{0x69, 0x00},
	{0x6b, 0x40},//40 PLL*4=48Mhz//////////////////////////
	{0x74, 0x19},
	{0x8d, 0x4f},

	{0x8e, 0x00},//70
	{0x8f, 0x00},
	{0x90, 0x00},
	{0x91, 0x00},
	{0x92, 0x00},//0x19,//0x66

	{0x96, 0x00},
	{0x9a, 0x80},
	{0xb0, 0x84},
	{0xb1, 0x0c},
	{0xb2, 0x0e},

	{0xb3, 0x82},//80
	{0xb8, 0x0a},
	{0x43, 0x14},
	{0x44, 0xf0},
	{0x45, 0x34},

	{0x46, 0x58},
	{0x47, 0x28},
	{0x48, 0x3a},
	{0x59, 0x88},
	{0x5a, 0x88},

	{0x5b, 0x44},//90
	{0x5c, 0x67},
	{0x5d, 0x49},
	{0x5e, 0x0e},
	{0x64, 0x04},
	{0x65, 0x20},

	{0x66, 0x05},
	{0x94, 0x04},
	{0x95, 0x08},
	{0x6c, 0x0a},
	{0x6d, 0x55},


	{0x4f, 0x80},
	{0x50, 0x80},
	{0x51, 0x00},
	{0x52, 0x22},
	{0x53, 0x5e},
	{0x54, 0x80},

	//{0x54, 0x40},//110


	{0x09, 0x03},//驱动能力最大

	{0x6e, 0x11},//100
	{0x6f, 0x9f},//0x9e for advance AWB
	{0x55, 0x00},//亮度
	{0x56, 0x40},//对比度 0x40
	{0x57, 0x40},//0x40,  change according to Jim's request
///////////////////////////////////////////////////////////////////////
//以下部分代码由开源电子网网友:duanzhang512 提出
//添加此部分代码将可以获得更好的成像效果,但是最下面一行会有蓝色的抖动.
//如不想要,可以屏蔽此部分代码.然后将:OV7670_Window_Set(12,176,240,320);
//改为:OV7670_Window_Set(12,174,240,320);,即可去掉最下一行的蓝色抖动
	{0x6a, 0x40},
	{0x01, 0x40},
	{0x02, 0x40},
	{0x13, 0xe7},
	{0x15, 0x00},  
	
		
	{0x58, 0x9e},
	
	{0x41, 0x08},
	{0x3f, 0x00},
	{0x75, 0x05},
	{0x76, 0xe1},
	{0x4c, 0x00},
	{0x77, 0x01},
	{0x3d, 0xc2},	
	{0x4b, 0x09},
	{0xc9, 0x60},
	{0x41, 0x38},
	
	{0x34, 0x11},
	{0x3b, 0x02}, //////////frame rate

	{0xa4, 0x89},
	{0x96, 0x00},
	{0x97, 0x30},
	{0x98, 0x20},
	{0x99, 0x30},
	{0x9a, 0x84},
	{0x9b, 0x29},
	{0x9c, 0x03},
	{0x9d, 0x4c},
	{0x9e, 0x3f},
	{0x78, 0x04},
	
	{0x79, 0x01},
	{0xc8, 0xf0},
	{0x79, 0x0f},
	{0xc8, 0x00},
	{0x79, 0x10},
	{0xc8, 0x7e},
	{0x79, 0x0a},
	{0xc8, 0x80},
	{0x79, 0x0b},
	{0xc8, 0x01},
	{0x79, 0x0c},
	{0xc8, 0x0f},
	{0x79, 0x0d},
	{0xc8, 0x20},
	{0x79, 0x09},
	{0xc8, 0x80},
	{0x79, 0x02},
	{0xc8, 0xc0},
	{0x79, 0x03},
	{0xc8, 0x40},
	{0x79, 0x05},
	{0xc8, 0x30},
	{0x79, 0x26}, 
//	{0x09, 0x00},
///////////////////////////////////////////////////////////////////////
	{0x13,0xe5},
	{0x01,0x58},
	{0x02,0x60},
	
	{0x4f,0xc0},
	{0x50,0xc0},
	{0x51,0x00},
	{0x52,0x33},
	{0x53,0x8d},
	{0x54,0xc0},
	{0x58,0x9e},
}; 

#endif
