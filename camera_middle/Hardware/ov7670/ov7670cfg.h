#ifndef _OV7670CFG_H
#define _OV7670CFG_H
#include "ov7670.h" 

static const u8 OV7670_reg[][2]=
{	 
	{0x3a, 0x0C}, 
	{0x40, 0xd0}, //COM15
	{0x12, 0x14}, //COM7 
	{0x32, 0x80}, 
	{0x17, 0x16}, 
	{0x18, 0x04}, 
	{0x19, 0x02}, 
	{0x1a, 0x7a},//0x7a, 
	{0x03, 0x05},//VREF 		
	{0x0c, 0x00},//COM3
	{0x3e, 0x00},//COM14
	{0x70, 0xba},//测试图像 3a
	{0x71, 0x35},//测试图像 
	{0x72, 0x11}, 
	{0x73, 0x00},// 
	{0xa2, 0x02}, 
	{0x11, 0x81},//CLKRC 
	{0x7a, 0x20},//SLOP 
	{0x7b, 0x1c}, 
	{0x7c, 0x28}, 
	{0x7d, 0x3c}, 
	{0x7e, 0x55}, 
	{0x7f, 0x68}, 
	{0x80, 0x76}, 
	{0x81, 0x80}, 
	{0x82, 0x88}, 
	{0x83, 0x8f}, 
	{0x84, 0x96}, 
	{0x85, 0xa3}, 
	{0x86, 0xaf}, 
	{0x87, 0xc4}, 
	{0x88, 0xd7}, 
	{0x89, 0xe8}, 
	{0x13, 0xe0},//COM8 
	{0x00, 0x00},//AGC 
	{0x10, 0x00}, 
	{0x0d, 0x00},//COM4 
	{0x42, 0x00},//COM17
	{0x14, 0x28},//COM9,0x38, limit the max gain 
	{0xa5, 0x05}, 
	{0xab, 0x07}, 
	{0x24, 0x75}, 
	{0x25, 0x63}, 
	{0x26, 0xA5}, 
	{0x9f, 0x78}, 
	{0xa0, 0x68}, //{0xa1, 0x03},//0x0b,
	{0xa6, 0xdf},//0xd8, 
	{0xa7, 0xdf},//0xd8, 
	{0xa8, 0xf0}, 
	{0xa9, 0x90}, 
	{0xaa, 0x94},//AEC selection
	{0x13, 0xe5},//COM8 
	{0x0e, 0x61}, 
	{0x0f, 0x43},//COM6 {0x16, 0x02},reserved	 
	{0x1e, 0x05},//0x07, 
	{0x21, 0x02}, 
	{0x22, 0x01},
	{0x23, 0x00},	//{0x29, 0x07},	 
	{0x33, 0x0b},//{0x35, 0x0b}, 	 
	{0x37, 0x1d}, 
	{0x38, 0x71}, 
	{0x39, 0x2a}, 
	{0x3c, 0x68},//COM12 {0x4d, 0x40}, {0x4e, 0x20},	 
	{0x69, 0x55}, 
	{0x6b, 0x0A},//PLL 重要参数 
	{0x74, 0x11}, //{0x8d, 0x4f}, {0x8e, 0x00}, {0x8f, 0x00}, {0x90, 0x00}, {0x91, 0x00}, 	
	{0x92, 0x00},//0x19,//0x66 
	{0x93, 0x00},//{0x96, 0x00}, 	{0x9a, 0x80},	 {0xb0, 0x84},
	{0xb1, 0x04}, //{0xb2, 0x0e},	 
	{0xb3, 0x82}, //	{0xb8, 0x0a},
	{0x43, 0x14}, 
	{0x44, 0xf0}, 
	{0x45, 0x45}, 
	{0x46, 0x61}, 
	{0x47, 0x51}, 
	{0x48, 0x79}, //{0x59, 0x88},{0x5a, 0x88}, {0x5b, 0x44}, {0x5c, 0x67},{0x5d, 0x49}, {0x5e, 0x0e}, 	
	{0x64, 0x04}, 
	{0x65, 0x20}, 
	{0x66, 0x05}, 
	{0x94, 0x04}, 
	{0x95, 0x08}, 
	{0x6c, 0x0a}, 
	{0x6d, 0x55}, 
	{0x6e, 0x11}, 
	{0x6f, 0x9f},//0x9e for advance AWB 
	{0x6a, 0x40}, 
	{0x01, 0x40}, 
	{0x02, 0x40}, 
	{0x13, 0xe7}, 
	{0x15, 0x00}, //重要参数 
	{0x4f, 0x80}, 
	{0x50, 0x80}, 
	{0x51, 0x00}, 
	{0x52, 0x22}, 
	{0x53, 0x5e}, 
	{0x54, 0x80}, 
	{0x55, 0x0A},//亮度 
	{0x56, 0x4f},//对比度 
	{0x58, 0x9e},	
	{0x41, 0x08},//COM16 
	{0x3f, 0x05},//边缘增强调整 
	{0x75, 0x05}, 
	{0x76, 0xc1}, 
	{0x4c, 0x0F},//噪声抑制强度 
	{0x77, 0x0a}, 
	{0x3d, 0xc2},//0xc0, 
	{0x4b, 0x01}, 
	{0xc9, 0x60}, 
	{0x41, 0x38}, 
	{0x34, 0x11}, 
	{0x3b, 0x02},//COM11//0x00,//0x02, 
	{0xa4, 0x89},//0x88, {0x96, 0x00},{0x97, 0x30},{0x98, 0x20},{0x99, 0x30}, {0x9a, 0x84}, {0x9b, 0x29},{0x9c, 0x03},	 
	{0x9d, 0x4c}, 
	{0x9e, 0x3f}, //{0x78, 0x04},	{0x79, 0x01},	{0xc8, 0xf0},  {0x79, 0x0f},
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
	{0x09, 0x02}, 
	{0x3b, 0x42},//0x82,//0xc0,//0xc2,	//night mode 
};

static const uint8_t OV7670_Reg_new[][2]= {    
//Frame Rate Adjustment for 24Mhz input clock   
//30fps PCLK=24MHz    
{0x11, 0x80},//
//???????????0x80,??????0x00    
{0x6b, 0x1a},//PLL??,???????????0x0a,??????0x40,?PLL??????????    
{0x2a, 0x00},   
{0x2b, 0x00},   
{0x92, 0x00}, 
{0x93, 0x00},   
{0x3b, 0x0a},     

//Output format    
{0x12, 0x16},//QVGA(320*240)?RGB  com7
	{0x70, 0xba},//测试图像 3a
	{0x71, 0x35},//测试图像 
//RGB555/565 option(must set COM7[2] = 1 and COM7[0] = 0)   
{0x40, 0x90},//RGB565,effective only when RGB444[1] is low   
{0x8c, 0x00}, 

  //Special effects - ??    //normal   
  {0x3a, 0x04},   
  {0x67, 0xc0}, 
  {0x68, 0x80},

  //Mirror/VFlip Enable - ????/??????   
  {0x1e, 0x37},
//???????????????????     

  //Banding Filter Setting for 24Mhz Input Clock - ?????   
  //30fps for 60Hz light frequency   
  //{0x13, 0xe7},//banding filer enable   
  //{0x9d, 0x98},//50Hz banding filer   
  //{0x9e, 0x7f},//60Hz banding filer   
  //{0xa5, 0x02},//3 step for 50Hz   
  //{0xab, 0x03},//4 step for 60Hz    
  //{0x3b, 0x02},//select 60Hz banding filer     

  //Simple White Balance - ???    
  //{0x13, 0xe7},//AWB?AGC?AGC Enable and ...   
  //{0x6f, 0x9f},//simple AWB     

  //AWBC - ???????(Automatic white balance control)  
  //{0x43, 0x14},//????????????????(Reserved),???????   
  //{0x44, 0xf0},   
  //{0x45, 0x34},           
  //{0x46, 0x58},   
  //{0x47, 0x28},   
  //{0x48, 0x3a},  

  //AWB Control    
  //{0x59, 0x88},//????????????,???????   
  //{0x5a, 0x88},           
  //{0x5b, 0x44},   
  //{0x5c, 0x67},   
  //{0x5d, 0x49},   
  //{0x5e, 0x0e}, 

  //AWB Control   
  //{0x6c, 0x0a},   
  //{0x6d, 0x55},          
  //{0x6e, 0x11},   
  //{0x6f, 0x9f},       

  //AGC/AEC - Automatic Gain Control??????/Automatic exposure Control??????   //{0x00, 0x00},   
  //{0x14, 0x20},   
  //{0x24, 0x75},   
  //{0x25, 0x63},   
  //{0x26, 0xA5},     

  //AEC algorithm selection - AEC????     
  //{0xaa, 0x94},
  //??????AEC??Average-based AEC algorithm/??????AEC??
  //Histogra-based AEC algorithm  

    //??????AGC/AEC???   
    //{0x9f, 0x78},   
    //{0xa0, 0x68},          
    //{0xa6, 0xdf},   
    //{0xa7, 0xdf},   
    //{0xa8, 0xf0},   
    //{0xa9, 0x90},     

    //Fix Gain Control - ??????        
    //{0x69, 0x5d},//Fix gain for Gr channel/for Gb channel/for R channel/for B channel     
    //Color saturation ????? + 0 

  //{0x4f, 0x80},   
  //{0x50, 0x80},   
  //{0x51, 0x00}, 
  //{0x52, 0x22},  
  //{0x53, 0x5e},   
  //{0x54, 0x80},   
  //{0x58, 0x9e}, 

  //Brightness - ?? + 0   
  //{0x55, 0x00},     
  //Contrast - ??? + 0   
  //{0x56, 0x40},  

  //Gamma Curve - ????   
  //{0x7a, 0x20},   
  //{0x7b, 0x1c},   
  //{0x7c, 0x28},           
  //{0x7d, 0x3c},   
  //{0x7e, 0x55},   
  //{0x7f, 0x68},   
  //{0x80, 0x76},   
  //{0x81, 0x80},  
         
  //{0x82, 0x88},   
  //{0x83, 0x8f},   
  //{0x84, 0x96},   
  //{0x85, 0xa3},
  //{0x86, 0xaf},           
  //{0x87, 0xc4},   
  //{0x88, 0xd7},   
  //{0x89, 0xe8},     

  //Matrix Coefficient - ??????               
  //{0x4f, 0x80},   
  //{0x50, 0x80},   
  //{0x51, 0x00},   
  //{0x52, 0x22},   
  //{0x53, 0x5e},   
  //{0x54, 0x80},     

  //Lens Correction Option - ??????   
  //{0x62, 0x00},          
  //{0x63, 0x00},   
  //{0x64, 0x04}, 
  //{0x65, 0x20},           
  //{0x66, 0x05},    
  //{0x94, 0x04},//effective only when LCC5[2] is high   
  //{0x95, 0x08},//effective only when LCC5[2] is high   


  //????????,?????,?????,?????????????????   
  {0x17, 0x16},//??Horizontal Frame?????(????HREF[2:0])          
  {0x18, 0x04},//??Horizontal Frame?????(????HREF[5:3])   
  {0x19, 0x02},//??Vertical Frame?????(????VREF[1:0])   
  {0x1a, 0x7b},//??Vertical Frame?????(????VREF[3:2])   
  {0x32, 0x80},//HREF   
  {0x03, 0x06},//VREF     

  //????????,??????
 //   {0x15, 0x02},//??PCLK?HREF?VSYNC??     
	{0x15, 0x00}, //重要参数 
    //Automatic black Level Compensation - ???????    
    {0xb0, 0x84},//??????????,????????,?????,?????,
    //?????????????RSVD   
    //{0xb1, 0x0c},   
    //{0xb2, 0x0e},         
    //{0xb3, 0x82},   
    //{0xb8, 0x0a},     

    //SCALING_xx???   
    //{0x70, 0x00}, 
  //{0x71, 0x00},   
  //{0x72, 0x11},   
  //{0x73, 0x08},   
  //{0x3e, 0x00},    

  //ADC    
  //{0x37, 0x1d},//ADC??ADC Control    
  //{0x38, 0x71},//ADC???????ADC and Analog Common Mode Control   
  //{0x39, 0x2a},//ADC????ADC Offset Control     

  //??????    
  //{0x92, 0x00},//?????Dummy Line low 8 bits   
  //{0xa2, 0x02},//??????   
  //{0x0c, 0x0c},   
  //{0x10, 0x00},   
  //{0x0d, 0x01},   
  //{0x0f, 0x4b}, 
  //{0x3c, 0x78},   
  //{0x74, 0x19}, 

  //???????????????RSVD   
  //{0x0e, 0x61},   
  //{0x16, 0x02},   
  //{0x21, 0x02},   
  //{0x22, 0x91},   
  //{0x29, 0x07},   
  //{0x33, 0x0b},   
  //{0x35, 0x0b},   
  //{0x4d, 0x40},   
  //{0x4e, 0x20},   
  //{0x8d, 0x4f},           
  //{0x8e, 0x00},   
  //{0x8f, 0x00},   
  //{0x90, 0x00},   
  //{0x91, 0x00},   
  //{0x96, 0x00},    
  //{0x9a, 0x80},                               
}; 

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

	{0x1e, 0x27},//图像输出镜像控制.0x07
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
	
}; 
//static const uint8_t OV7670_Reg_2[][2]= {  
//   {0x3a, 0x04},
//        {0x40, 0xD0},//D0
//        {0x12, 0x14},
//        {0x32, 0x80},
//        {0x17, 0x16},
//        {0x18, 0x04},
//        {0x19, 0x02},
//        {0x1a, 0x7b},//0x7a,
//        {0x03, 0x06},//0x0a,
//        {0x0c, 0x00},
//        {0x3e, 0x00},//
//        {0x70, 0x00},//00
//        {0x71, 0x00},//0x85??
//        {0x72, 0x11},
//        {0x73, 0x00},//
//        {0xa2, 0x02},
//        {0x11, 0x02},
//        {0x7a, 0x20},
//        {0x7b, 0x1c},
//        {0x7c, 0x28},
//        {0x7d, 0x3c},
//        {0x7e, 0x55},
//        {0x7f, 0x68},
//        {0x80, 0x76},
//        {0x81, 0x80},
//        {0x82, 0x88},
//        {0x83, 0x8f},
//        {0x84, 0x96},
//        {0x85, 0xa3},
//        {0x86, 0xaf},
//        {0x87, 0xc4},
//        {0x88, 0xd7},
//        {0x89, 0xe8},
//        {0x13, 0xe0},
//        {0x00, 0x00},//AGC
//        {0x10, 0x00},
//        {0x0d, 0x00},
//        {0x14, 0x20},//0x38, limit the max gain
//        {0xa5, 0x05},
//        {0xab, 0x07},
//        {0x24, 0x75},
//        {0x25, 0x63},
//        {0x26, 0xA5},
//        {0x9f, 0x78},
//        {0xa0, 0x68},
//        {0xa1, 0x03},//0x0b,
//        {0xa6, 0xdf},//0xd8,
//        {0xa7, 0xdf},//0xd8,
//        {0xa8, 0xf0},
//        {0xa9, 0x90},
//        {0xaa, 0x94},
//        {0x13, 0xe5},
//        {0x0e, 0x61},
//        {0x0f, 0x4b},
//        {0x16, 0x02},
//        {0x1e, 0x37},//0x07,
//        {0x21, 0x02},
//        {0x22, 0x91},
//        {0x29, 0x07},
//        {0x33, 0x0b},
//        {0x35, 0x0b},
//        {0x37, 0x1d},
//        {0x38, 0x71},
//        {0x39, 0x2a},//
//        {0x3c, 0x78},
//        {0x4d, 0x40},
//        {0x4e, 0x20},
//        {0x69, 0x0c},///////////////////////
//        {0x6b, 0x80},//PLL
//        {0x74, 0x19},
//        {0x8d, 0x4f},
//        {0x8e, 0x00},
//        {0x8f, 0x00},
//        {0x90, 0x00},
//        {0x91, 0x00},
//        {0x92, 0x00},//0x19,//0x66
//        {0x96, 0x00},
//        {0x9a, 0x80},
//        {0xb0, 0x84},
//        {0xb1, 0x0c},
//        {0xb2, 0x0e},
//        {0xb3, 0x82},
//        {0xb8, 0x0a},
//        {0x43, 0x14},
//        {0x44, 0xf0},
//        {0x45, 0x34},
//        {0x46, 0x58},
//        {0x47, 0x28},
//        {0x48, 0x3a},
//        {0x59, 0x88},
//        {0x5a, 0x88},
//        {0x5b, 0x44},
//        {0x5c, 0x67},
//        {0x5d, 0x49},
//        {0x5e, 0x0e},
//        {0x64, 0x04},
//        {0x65, 0x20},
//        {0x66, 0x05},
//        {0x94, 0x04},
//        {0x95, 0x08},
//        {0x6c, 0x0a},
//        {0x6d, 0x55},
//        {0x6e, 0x11},
//        {0x6f, 0x9f},//0x9e for advance AWB
//        {0x6a, 0x00},
//        {0x01, 0x80},
//        {0x02, 0x80},
//        {0x13, 0xe7},
//        {0x15, 0x00},
//        {0x4f, 0x80},
//        {0x50, 0x80},
//        {0x51, 0x00},
//        {0x52, 0x22},
//        {0x53, 0x5e},
//        {0x54, 0x80},
//        {0x58, 0x9e},        
//        {0x41, 0x08},
//        {0x3f, 0x00},
//        {0x75, 0x05},
//        {0x76, 0xe1},
//        {0x4c, 0x00},
//        {0x77, 0x01},
//        {0x3d, 0xc2},        //0xc0,
//        {0x4b, 0x09},
//        {0xc9, 0x60},
//        {0x41, 0x38},
//        {0x56, 0x40},//0x40,  change according to Jim's request        
//        {0x34, 0x11},
//        {0x3b, 0x02},//0x00,//0x02,
//        {0xa4, 0x89},//0x88,
//        {0x96, 0x00},
//        {0x97, 0x30},
//        {0x98, 0x20},
//        {0x99, 0x30},
//        {0x9a, 0x84},
//        {0x9b, 0x29},
//        {0x9c, 0x03},
//        {0x9d, 0x4c},
//        {0x9e, 0x3f},
//        {0x78, 0x04},        
//        {0x79, 0x01},
//        {0xc8, 0xf0},
//        {0x79, 0x0f},
//        {0xc8, 0x00},
//        {0x79, 0x10},
//        {0xc8, 0x7e},
//        {0x79, 0x0a},
//        {0xc8, 0x80},
//        {0x79, 0x0b},
//        {0xc8, 0x01},
//        {0x79, 0x0c},
//        {0xc8, 0x0f},
//        {0x79, 0x0d},
//        {0xc8, 0x20},
//        {0x79, 0x09},
//        {0xc8, 0x80},
//        {0x79, 0x02},
//        {0xc8, 0xc0},
//        {0x79, 0x03},
//        {0xc8, 0x40},
//        {0x79, 0x05},
//        {0xc8, 0x30},
//        {0x79, 0x26},
//        {0x09, 0x03},
//        {0x55, 0x00},
//        {0x56, 0x40},        
//        {0x3b, 0xC2},//0x82,//0xc0,//0xc2,        //night mode

//};
#endif
