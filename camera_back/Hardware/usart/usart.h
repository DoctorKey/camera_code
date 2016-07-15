#ifndef __USART_H
#define __USART_H

#include "stm32f4xx.h"

void Usart1_Init(u32 br_num);
void Usart1_IRQ(void);
void Usart1_Send(unsigned char *DataToSend ,u8 data_num);

void Usart2_Init(u32 br_num);
void Usart2_IRQ(void);
void Usart2_Send(unsigned char *DataToSend ,u8 data_num);

#endif
