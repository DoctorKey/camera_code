#include "dgp.h"
#include "include.h"
#include "ov7670.h"

u8 ov_frame=0;  						//֡��

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
im_info front_measure_info;
im_info back_measure_info;
void get_info(u16 *jpeg,u8 *H,im_info *info)
{
	u8 R,G,B;
	float h_tmp;
	u16 i,j,count_x=0;
	u32 x=0,y=0;
	for(i=0;i<PIC_ROW;i++)
	{
		for(j=0;j<PIC_COL;j++)
		{
			R=((*(jpeg+i*PIC_COL+j))&0x1f)<<3;//R
			G=((*(jpeg+i*PIC_COL+j))&0x7e0)>>3;//G
			B=((*(jpeg+i*PIC_COL+j))&0xf800)>>8;//B
			
			if		 (R>B&&B>G){
				h_tmp=(float)((G-B)/(R-G))*PI_3_40;
			}
			else if(R>G&&G>B){
				h_tmp=(float)((G-B)/(R-B))*PI_3_40;
			}
			else if(G>R&&R>B){
				h_tmp=(float)((B-R)/(G-B)+2)*PI_3_40;
			}
			else if(G>B&&B>R){
				h_tmp=(float)((B-R)/(G-R)+2)*PI_3_40;
			}
			else if(B>R&&R>G){
				h_tmp=(float)((R-G)/(B-G)+4)*PI_3_40;
			}
			else if(B>G&&G>R){
				h_tmp=(float)((R-G)/(B-R)+4)*PI_3_40;
			}
					
			if(h_tmp<0)
			{
				h_tmp += TWO_PI*40;
			}
			
			if(h_tmp>166)
			{
				x+=i; //row
				count_x++;
				y+=(j+158)%PIC_COL; //col
			}
			
			#ifdef TEST
			*(H+i*PIC_COL+(j+158)%PIC_COL)=h_tmp;
			#endif
		}
	}
	
	info->x = x/count_x;
	info->y = y/count_x;
//	info->ratio = (float)count_x/(PIC_ROW*PIC_COL);
	
	#ifdef TEST
	j=info->y;
	for(i=info->x-3;i<info->x+4;i++)
	{
		*(H+i*PIC_COL+j)=254;
	}

	i=info->x;
	for(j=info->y-3;j<info->y+4;j++)
	{
		*(H+i*PIC_COL+j)=254;
	}
	#endif
}
void test(u32* jpeg_buf,u8* im)
{
	u32 i;
	u16 *jpeg;
	i=PIC_COL*PIC_ROW;
	jpeg=(u16*)jpeg_buf;
	get_info(jpeg,im,&front_measure_info);
	LED0(On);
	USART_SendString_bysize(USART2,im,i);
	USART_SendData(USART2,255);
	LED0(Off);
}
void get_Y(u16 *jpeg,u8 *Y)
{
	u8 R,G,B;
	u16 i,j,count_x=0;
	u32 x=0,y=0,y_tmp;
	for(i=0;i<PIC_ROW;i++)
	{
		for(j=0;j<PIC_COL;j++)
		{
			R=((*(jpeg+i*PIC_COL+j))&0x1f)<<3;//R
			G=((*(jpeg+i*PIC_COL+j))&0x7e0)>>3;//G
			B=((*(jpeg+i*PIC_COL+j))&0xf800)>>8;//B
			
			y_tmp = 1224*R + 2404*G + 467*B;
			y_tmp = y_tmp>>12;
			
			*(Y+i*PIC_COL+(j+158)%PIC_COL)=y_tmp;
		}
	}
}
void test_Y(u32* jpeg_buf,u8* im)
{
	u32 i;
	u16 *jpeg;
	i=PIC_COL*PIC_ROW;
	jpeg=(u16*)jpeg_buf;
	get_Y(jpeg,im);
	LED0(On);
	USART_SendString_bysize(USART2,im,i);
	USART_SendData(USART2,255);
	LED0(Off);
}


