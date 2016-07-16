#include "dgp.h"
#include "include.h"
#include "ov7670.h"

u8 ov_frame=0;  						//帧率
im_info front_measure_info;
im_info back_measure_info;
//DCMI中断服务函数
void DCMI_IRQHandler(void)
{
		if(DCMI_GetITStatus(DCMI_IT_FRAME)==SET)//捕获到一帧图像
		{
				jpeg_data_process(); 	//jpeg数据处理	
				DCMI_ClearITPendingBit(DCMI_IT_FRAME);//清除帧中断
				ov_frame++;	
		}
} 

volatile u32 jpeg_data_len=0; 			//buf中的JPEG有效数据长度 
volatile u8 jpeg_data_ok=0;				//JPEG数据采集完成标志 
										//0,数据没有采集完;
										//1,数据采集完了,但是还没处理;
										//2,数据已经处理完成了,可以开始下一帧接收
										
//处理JPEG数据
//当采集完一帧JPEG数据后,调用此函数,切换JPEG BUF.开始下一帧采集.
void jpeg_data_process(void)
{
		if(jpeg_data_ok==0)	//jpeg数据还未采集完?
		{
			DMA_Cmd(DMA2_Stream1, DISABLE);//停止当前传输 
			while (DMA_GetCmdStatus(DMA2_Stream1) != DISABLE){}//等待DMA2_Stream1可配置  
			jpeg_data_len=jpeg_buf_size-DMA_GetCurrDataCounter(DMA2_Stream1);//得到此次数据传输的长度
				
			jpeg_data_ok=1; 				//标记JPEG数据采集完按成,等待其他函数处理
		}
		if(jpeg_data_ok==2)	//上一次的jpeg数据已经被处理了
		{
			DMA2_Stream1->NDTR=jpeg_buf_size;	
			DMA_SetCurrDataCounter(DMA2_Stream1,jpeg_buf_size);//传输长度为jpeg_buf_size*4字节
			DMA_Cmd(DMA2_Stream1, ENABLE);			//重新传输
			jpeg_data_ok=0;						//标记数据未采集
		}
} 


void getH_op1(u16 *jpeg,u8 *H,im_info *info)//去掉MAX=B的情况，去掉H<0的情况
{
	u8 R,G,B;
	float h_tmp;
	u16 i,j,count_x=0,count_y=0;
	u32 x=0,y=0;
	for(i=0;i<PIC_ROW;i++)
	{
		for(j=0;j<PIC_COL;j++)
		{
			R=((*(jpeg+i*PIC_COL+j))&0x1f)<<3;//R
			G=((*(jpeg+i*PIC_COL+j))&0x7e0)>>3;//G
			B=((*(jpeg+i*PIC_COL+j))&0xf800)>>8;//B
					
			h_tmp=TWO_PI;
			if		 (R>B&&B>G){
				h_tmp=((G-B)/(R-G))*PI_3_40;
			}
			else if(R>G&&G>B){
				h_tmp=((G-B)/(R-B))*PI_3_40;
			}
			else if(G>B&&B>R){
				h_tmp=((B-R)/(G-R)+2)*PI_3_40;
			}
			else if(G>R&&R>B){
				h_tmp=((B-R)/(G-B)+2)*PI_3_40;
			}
			
			if(h_tmp<HIGH_THRESHOLD&&h_tmp>LOW_THRESHOLD)
			{
				x+=i; //row
				count_x++;
				y+=j; //col
				count_y++;
			}
			*(H+i*PIC_COL+j)=h_tmp;
		}
	}
	
	info->x = x/count_x;
	info->y = y/count_y;
	info->ratio = count_x/(PIC_ROW*PIC_COL);
	
	for(i=(info->x-2);i<(info->x+3);i++)
	{
		for(j=0;j<PIC_COL;j++)
		{
			*(H+i*PIC_COL+j)=255;
		}
	}
	for(i=0;i<PIC_ROW;i++)
	{
		for(j=(info->y-2);j<(info->y+3);j++)
		{
			*(H+i*PIC_COL+j)=255;
		}
	}
}
void get_info(u16 *jpeg,u8 *H,im_info *info)
{
	
}
