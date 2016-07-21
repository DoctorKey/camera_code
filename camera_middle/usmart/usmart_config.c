#include "usmart.h"
#include "usmart_str.h"
////////////////////////////用户配置区///////////////////////////////////////////////
//这下面要包含所用到的函数所申明的头文件(用户自己添加) 
#include "delay.h"		
#include "sys.h"
#include "led.h"		
#include "ov7670.h"
#include "myduty.h"
#include "ctrl.h"

//extern void led_set(u8 sta);
//extern void test_fun(void(*ledset)(u8),u8 sta);
//函数名列表初始化(用户自己添加)
//用户直接在这里输入要执行的函数名及其查找串
struct _m_usmart_nametab usmart_nametab[]=
{
#if USMART_USE_WRFUNS==1 	//如果使能了读写操作
	(void*)read_addr,"u32 read_addr(u32 addr)",
	(void*)write_addr,"void write_addr(u32 addr,u32 val)",	 
#endif		   
	(void*)delay_ms,"void delay_ms(u16 nms)",
 	(void*)delay_us,"void delay_us(u32 nus)",	 
	(void*)LED_SET,"void LED_SET(u8 mode)",
	(void*)OV_WriteReg,"u8 OV_WriteReg(u8 regID, u8 regDat)",
	(void*)set_mode,"void set_mode(u8 command)",
	(void*)pwm_test,"void pwm_test(u16 p1,u16 p2,u16 p3,u16 p4)",
	(void*)set_offset,"void set_offset(u16 roll_offset,u16 pit_offset,u16 yaw_offset)",
	(void*)set_gopit,"void set_gopit(u16 go_pit)",
//	(void*)led_set,"void led_set(u8 sta)",
//	(void*)test_fun,"void test_fun(void(*ledset)(u8),u8 sta)",				  	    
};						  
///////////////////////////////////END///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
//函数控制管理器初始化
//得到各个受控函数的名字
//得到函数总数量
struct _m_usmart_dev usmart_dev=
{
	usmart_nametab,
	usmart_init,
	usmart_cmd_rec,
	usmart_exe,
	usmart_scan,
	sizeof(usmart_nametab)/sizeof(struct _m_usmart_nametab),//函数数量
	0,	  	//参数数量
	0,	 	//函数ID
	1,		//参数显示类型,0,10进制;1,16进制
	0,		//参数类型.bitx:,0,数字;1,字符串	    
	0,	  	//每个参数的长度暂存表,需要MAX_PARM个0初始化
	0,		//函数的参数,需要PARM_LEN个0初始化
};   

