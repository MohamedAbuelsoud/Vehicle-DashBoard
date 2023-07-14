/**
 * @file USART_priv.h
 * @author G3_DashBoard_Team
 * @brief Private file for USART driver for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#ifndef USART_PRIV_H
#define USART_PRIV_H

#define USART_ENABLE     1
#define USART_DISABLE    0

#define USART_8_BIT   0
#define USART_9_BIT   1

#define USART_EEVN_PARITY   0
#define USART_ODD_PARITY    1

#define USART_OVER_SAMPLING_16        0
#define USART_OVER_SAMPLING_8         1

#define STOP_1                0b00
#define STOP_2                0b10

#define USART_SYNCHRONOUS     1
#define USART_ASYNCHRONOUS    0


#define   B_1200    0x44505400
#define   B_2400    0x43d05800
#define   B_9600    0x683
#define   B_19200   0x42504000
#define   B_38400   0x41d08000
#define   B_57600   0x418b0000
#define   B_115200  0x410b0000


#define USART1_BASE_ADDRESS 0x40011000
#define USART2_BASE_ADDRESS 0x40004400
#define USART6_BASE_ADDRESS 0x40011400


typedef struct{
	volatile uint32 SR;
	volatile uint32 DR;
	volatile uint32 BRR;
	volatile uint32 CR1;
	volatile uint32 CR2;
	volatile uint32 CR3;
	volatile uint32 GTPR;
}UART_MR;


#define USART_1   ((volatile UART_MR * ) USART1_BASE_ADDRESS)
#define USART_2   ((volatile UART_MR * ) USART1_BASE_ADDRESS)
#define USART_6   ((volatile UART_MR * ) USART6_BASE_ADDRESS)



#endif

