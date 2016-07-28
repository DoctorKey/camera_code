#include "usmart.h"
#include "usmart_str.h"
////////////////////////////�û�������///////////////////////////////////////////////
//������Ҫ�������õ��ĺ�����������ͷ�ļ�(�û��Լ����) 
#include "delay.h"		
#include "sys.h"
#include "led.h"		
#include "ov7670.h"
#include "myduty.h"
#include "ctrl.h"

//extern void led_set(u8 sta);
//extern void test_fun(void(*ledset)(u8),u8 sta);
//�������б��ʼ��(�û��Լ����)
//�û�ֱ������������Ҫִ�еĺ�����������Ҵ�
struct _m_usmart_nametab usmart_nametab[]=
{
#if USMART_USE_WRFUNS==1 	//���ʹ���˶�д����
	(void*)read_addr,"u32 read_addr(u32 addr)",
	(void*)write_addr,"void write_addr(u32 addr,u32 val)",	 
#endif		   
	(void*)delay_ms,"void delay_ms(u16 nms)",
 	(void*)delay_us,"void delay_us(u32 nus)",	 
	(void*)LED_SET,"void LED_SET(u8 mode)",
	(void*)set_mode,"void set_mode(u8 command)",
	(void*)set_offset,"void set_offset(u16 roll_offset,u16 pit_offset,u16 yaw_offset)",
	(void*)set_gopit,"void set_gopit(u16 go_pit)",
	(void*)set_backpit,"void set_backpit(u16 back_pit)",
  (void*)set_wait_time,"void set_wait_time(u16 go,u16 throw_wait,u16 back)",	
	(void*)set_pid,"void set_pid(u16 front_kp,u16 back_kp,u8 choose)",		
};						  
///////////////////////////////////END///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
//�������ƹ�������ʼ��
//�õ������ܿغ���������
//�õ�����������
struct _m_usmart_dev usmart_dev=
{
	usmart_nametab,
	usmart_init,
	usmart_cmd_rec,
	usmart_exe,
	usmart_scan,
	sizeof(usmart_nametab)/sizeof(struct _m_usmart_nametab),//��������
	0,	  	//��������
	0,	 	//����ID
	1,		//������ʾ����,0,10����;1,16����
	0,		//��������.bitx:,0,����;1,�ַ���	    
	0,	  	//ÿ�������ĳ����ݴ��,��ҪMAX_PARM��0��ʼ��
	0,		//�����Ĳ���,��ҪPARM_LEN��0��ʼ��
};   

