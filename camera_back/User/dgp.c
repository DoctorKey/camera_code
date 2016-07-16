#include "dgp.h"
#include "include.h"
#include "ov7670.h"

u8 ov_frame=0;  						//֡��
im_info front_measure_info;
im_info back_measure_info;
//DCMI�жϷ�����
void DCMI_IRQHandler(void)
{
		if(DCMI_GetITStatus(DCMI_IT_FRAME)==SET)//����һ֡ͼ��
		{
				jpeg_data_process(); 	//jpeg���ݴ���	
				DCMI_ClearITPendingBit(DCMI_IT_FRAME);//���֡�ж�
				ov_frame++;	
		}
} 

volatile u32 jpeg_data_len=0; 			//buf�е�JPEG��Ч���ݳ��� 
volatile u8 jpeg_data_ok=0;				//JPEG���ݲɼ���ɱ�־ 
										//0,����û�вɼ���;
										//1,���ݲɼ�����,���ǻ�û����;
										//2,�����Ѿ����������,���Կ�ʼ��һ֡����
										
//����JPEG����
//���ɼ���һ֡JPEG���ݺ�,���ô˺���,�л�JPEG BUF.��ʼ��һ֡�ɼ�.
void jpeg_data_process(void)
{
		if(jpeg_data_ok==0)	//jpeg���ݻ�δ�ɼ���?
		{
			DMA_Cmd(DMA2_Stream1, DISABLE);//ֹͣ��ǰ���� 
			while (DMA_GetCmdStatus(DMA2_Stream1) != DISABLE){}//�ȴ�DMA2_Stream1������  
			jpeg_data_len=jpeg_buf_size-DMA_GetCurrDataCounter(DMA2_Stream1);//�õ��˴����ݴ���ĳ���
				
			jpeg_data_ok=1; 				//���JPEG���ݲɼ��갴��,�ȴ�������������
		}
		if(jpeg_data_ok==2)	//��һ�ε�jpeg�����Ѿ���������
		{
			DMA2_Stream1->NDTR=jpeg_buf_size;	
			DMA_SetCurrDataCounter(DMA2_Stream1,jpeg_buf_size);//���䳤��Ϊjpeg_buf_size*4�ֽ�
			DMA_Cmd(DMA2_Stream1, ENABLE);			//���´���
			jpeg_data_ok=0;						//�������δ�ɼ�
		}
} 


void getH_op1(u16 *jpeg,u8 *H,im_info *info)//ȥ��MAX=B�������ȥ��H<0�����
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
