#include "data_transfer.h"
#include "stm32f4xx.h"
#include "ctrl.h"
#include "dgp.h"
#include "init.h"

/////////////////////////////////////////////////////////////////////////////////////
//数据拆分宏定义，在发送大于1字节的数据类型时，比如int16、float等，需要把数据拆分成单独字节进行发送
#define BYTE0(dwTemp)       ( *( (char *)(&dwTemp)		) )
#define BYTE1(dwTemp)       ( *( (char *)(&dwTemp) + 1) )
#define BYTE2(dwTemp)       ( *( (char *)(&dwTemp) + 2) )
#define BYTE3(dwTemp)       ( *( (char *)(&dwTemp) + 3) )

u8 data_to_send[20];	//发送数据缓存

/////////////////////////////////////////////////////////////////////////////////////
//Data_Receive_Prepare函数是协议预解析，根据协议的格式，将收到的数据进行一次格式性解析，格式正确的话再进行数据解析
//移植时，此函数应由用户根据自身使用的通信方式自行调用，比如串口每收到一字节数据，则调用此函数一次
//此函数解析出符合格式的数据帧后，会自行调用数据解析函数
void Data_Receive_Prepare_1(u8 data)//usart1
{
	static u8 RxBuffer[50];
	static u8 _data_len = 0,_data_cnt = 0;
	static u8 state = 0;
	
	if(state==0&&data==0xAA)
	{
		state=1;
		RxBuffer[0]=data;
	}
	else if(state==1&&data==0xAF)
	{
		state=2;
		RxBuffer[1]=data;
	}
	else if(state==2&&data<0XF1)
	{
		state=3;
		RxBuffer[2]=data;
	}
	else if(state==3&&data<50)
	{
		state = 4;
		RxBuffer[3]=data;
		_data_len = data;
		_data_cnt = 0;
	}
	else if(state==4&&_data_len>0)
	{
		_data_len--;
		RxBuffer[4+_data_cnt++]=data;
		if(_data_len==0)
			state = 5;
	}
	else if(state==5)
	{
		state = 0;
		RxBuffer[4+_data_cnt]=data;
		Data_Receive_deal(RxBuffer,_data_cnt+5);
	}
	else
		state = 0;
}
void Data_Receive_Prepare_2(u8 data)//usart2
{
	static u8 RxBuffer[50];
	static u8 _data_len = 0,_data_cnt = 0;
	static u8 state = 0;
	
	if(state==0&&data==0xAA)
	{
		state=1;
		RxBuffer[0]=data;
	}
	else if(state==1&&data==0xAF)
	{
		state=2;
		RxBuffer[1]=data;
	}
	else if(state==2&&data<0XF1)
	{
		state=3;
		RxBuffer[2]=data;
	}
	else if(state==3&&data<50)
	{
		state = 4;
		RxBuffer[3]=data;
		_data_len = data;
		_data_cnt = 0;
	}
	else if(state==4&&_data_len>0)
	{
		_data_len--;
		RxBuffer[4+_data_cnt++]=data;
		if(_data_len==0)
			state = 5;
	}
	else if(state==5)
	{
		state = 0;
		RxBuffer[4+_data_cnt]=data;
		Data_Receive_deal(RxBuffer,_data_cnt+5);
	}
	else
		state = 0;
}
u8 front_info_ok=0;
u8 back_info_ok=0;
u8 front_rc_ok=0;
u8 back_rc_ok=0;
void Data_Receive_deal(u8 *data_buf,u8 num)
{
	u8 sum = 0,i;
	for(i=0;i<(num-1);i++)
		sum += *(data_buf+i);
	if(!(sum==*(data_buf+num-1)))		return;		//判断sum
	if(!(*(data_buf)==0xAA && *(data_buf+1)==0xAF))		return;		//判断帧头
	
	if(*(data_buf+2)==0X01)
	{
		front_measure_info.x = *(data_buf+4);
		front_measure_info.y = *(data_buf+5);
		front_info_ok=1;
	}
	if(*(data_buf+2)==0X02)
	{
		back_measure_info.x = *(data_buf+4);
		back_measure_info.y = *(data_buf+5);
		back_info_ok=1;
	}
	if(*(data_buf+2)==0X03)
	{
		Rc_front.pitch=(u16)(*(data_buf+4)<<8)|*(data_buf+5);
		Rc_front.roll =(u16)(*(data_buf+6)<<8)|*(data_buf+7);
		Rc_front.thr  =(u16)(*(data_buf+8)<<8)|*(data_buf+9);
		Rc_front.yaw  =(u16)(*(data_buf+10)<<8)|*(data_buf+11);
		front_rc_ok = 1;
	}
	if(*(data_buf+2)==0X06)
	{
		Rc_back.pitch=(u16)(*(data_buf+4)<<8)|*(data_buf+5);
		Rc_back.roll =(u16)(*(data_buf+6)<<8)|*(data_buf+7);
		Rc_back.thr  =(u16)(*(data_buf+8)<<8)|*(data_buf+9);
		Rc_back.yaw  =(u16)(*(data_buf+10)<<8)|*(data_buf+11);
		back_rc_ok = 1;
	}
	if(*(data_buf+2)==0X04)
	{
		if(*(data_buf+4)==0x01)
		{
			ready_1 = *(data_buf+5);
		}
		if(*(data_buf+4)==0x02)
		{
			ready_2 = *(data_buf+5);
		}
	}
}
void Send_Data(u8 *dataToSend , u8 length)
{
#ifdef USE_USART2
	Usart2_Send(data_to_send, length);
#endif
#ifdef USE_USART1
	Usart1_Send(data_to_send, length);
#endif
}
void Send_Front_Measure(im_info info)
{
	u8 _cnt=0;
	vs16 _temp;
	u8 sum = 0;
	u8 i = 0;
	
	data_to_send[_cnt++]=0xAA;
	data_to_send[_cnt++]=0xAF;
	data_to_send[_cnt++]=0x01;
	data_to_send[_cnt++]=0;
	
	data_to_send[_cnt++] = info.x;
	data_to_send[_cnt++] = info.y;
	
	
	data_to_send[3] = _cnt-4;
	
	
	for(i=0;i<_cnt;i++)
		sum += data_to_send[i];
	data_to_send[_cnt++]=sum;
	
	Send_Data(data_to_send, _cnt);
}
void Send_Back_Measure(im_info info)
{
	u8 _cnt=0;
	vs16 _temp;
	u8 sum = 0;
	u8 i = 0;
	
	data_to_send[_cnt++]=0xAA;
	data_to_send[_cnt++]=0xAF;
	data_to_send[_cnt++]=0x02;
	data_to_send[_cnt++]=0;
	
	data_to_send[_cnt++] = info.x;
	data_to_send[_cnt++] = info.y;
	
	
	data_to_send[3] = _cnt-4;
	
	
	for(i=0;i<_cnt;i++)
		sum += data_to_send[i];
	data_to_send[_cnt++]=sum;
	
	Send_Data(data_to_send, _cnt);
}
void Send_Rc(Rc_group rc)
{
	u8 _cnt=0;
	vs16 _temp;
	u8 sum = 0;
	u8 i = 0;
	data_to_send[_cnt++]=0xAA;
	data_to_send[_cnt++]=0xAF;
	data_to_send[_cnt++]=0x03;
	data_to_send[_cnt++]=0;
	
	data_to_send[_cnt++]=BYTE1(rc.pitch);
	data_to_send[_cnt++]=BYTE0(rc.pitch);
	data_to_send[_cnt++]=BYTE1(rc.roll);
	data_to_send[_cnt++]=BYTE0(rc.roll);
	data_to_send[_cnt++]=BYTE1(rc.thr);
	data_to_send[_cnt++]=BYTE0(rc.thr);
	data_to_send[_cnt++]=BYTE1(rc.yaw);
	data_to_send[_cnt++]=BYTE0(rc.yaw);
	
	data_to_send[3] = _cnt-4;
	
	
	for(i=0;i<_cnt;i++)
		sum += data_to_send[i];
	data_to_send[_cnt++]=sum;
	
	Send_Data(data_to_send, _cnt);
}

