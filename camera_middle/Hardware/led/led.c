#include "led.h"

void LED_GPIO_Conf(void)
{
   GPIO_InitTypeDef GPIO_InitStructure;		                            //����GPIO��ʼ���ṹ��
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);			  			//ʹ��GPIOB��AHP1ʱ��
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;										  //���ó�ʼ��ģʽΪ���ģʽ
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;										  //�����������Ϊ�������
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;									  //��������ٶ�Ϊ100Mhz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;										  
   GPIO_InitStructure.GPIO_Pin=(GPIO_Pin_9);								  //�����ʼ���Ĺܽ�ΪPin9
   GPIO_Init(GPIOB, &GPIO_InitStructure);												  //��ʼ��GPIOB��Pin_9�ܽ�
   GPIO_SetBits(GPIOB,GPIO_Pin_9);														  //ʹGPIOB��Pin_9����ߵ�ƽ
}
void LED_SET(u8 mode)
{
	if(mode)
		LED0(0);
	else
		LED0(1);
}