/**
 * @file UART.h
 * @author G3_DashBoard_Team
 * @brief UART functions prototypes
 *        UART Module is for communication with the other ECU through UART. 
 *        It's responsible for receiving data and updating reading values. 
 *        It consists of two functions. First one (UARTvidInit) is a UART initialization function 
 *        to setup the required configuration. 
 *        Second one (UARTvidReceive) is a function that receives data from UART and assign it to reading 
 * @version 0.1
 * @date 2023-02-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef UART_H
#define UART_H
/**
 * @brief UART initialization function 
 *        to setup the required configuration in Raspberry pi.
 * 
 */
void UARTvidInit(void);
/**
 * @brief a Function that receives data from UART and assign it to reading
 * 
 * @return void* 
 */
void* UARTvidReceive(void*);

#endif // UART_H
