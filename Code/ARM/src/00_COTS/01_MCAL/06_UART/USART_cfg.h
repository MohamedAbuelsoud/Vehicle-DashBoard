/**
 * @file USART_cfg.h
 * @author G3_DashBoard_Team
 * @brief Configuration file for USART driver for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#ifndef USART_cfg_H
#define USART_cfg_H


#define USART1_USE           USART_ENABLE
#define UART1_RECEIVER       USART_ENABLE
#define UART1_TRANSMITTER    USART_ENABLE
#define USART1_IDLE_INT      USART_DISABLE
#define UART1_RX_INT         USART_DISABLE
#define UART1_TX_INT         USART_DISABLE
#define USART1_DATA_SIZE     USART_8_BIT
#define USART1_PARITY        USART_DISABLE
#define USART1_PARITY_TYPE   USART_EEVN_PARITY
#define UART1_OVER_SAMPLING  USART_OVER_SAMPLING_16
#define UART1_STOP_BITS      STOP_1
#define UART1_BUAD_RATE      B_9600
#define UART1_SYNCHRONIZATION USART_ASYNCHRONOUS







#endif

