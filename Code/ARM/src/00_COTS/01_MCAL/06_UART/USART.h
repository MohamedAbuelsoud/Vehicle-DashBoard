/**
 * @file USART.h
 * @author G3_DashBoard_Team
 * @brief Interface file for USART driver for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#ifndef USART_H
#define USART_H


/**
 * @brief USART Initialization
 * 
 */
void USART_voidInit(void);
/**
 * @brief Receive byte from USART
 * 
 * @param u8IndexCPY USART ID
 * @param pu16DataCpy Received DATA
 */
void USART_enuGetDataByte(uint8 u8IndexCPY, uint8* pu16DataCpy);
/**
 * @brief Send byte through USART
 * 
 * @param u8IndexCPY USART ID
 * @param u16DataCpy DATA to be sent
 */
void USART_voidSendDataByte(uint8 u8IndexCPY, uint8 u16DataCpy);
/**
 * @brief Receive string from USART
 * 
 * @param u8IndexCPY USART ID
 * @param pu16DataCpy Received DATA
 * @param u8Size string size
 */
void USART_enuGetDataString(uint8 u8IndexCPY, uint16* pu16DataCpy ,uint8 u8Size);
/**
 * @brief send string through USART
 * 
 * @param u8IndexCPY USART ID
 * @param u16DataCpy DATA to be sent
 * @param u8Size string size
 */
void USART_voidSendDataString(uint8 u8IndexCPY, uint8* u16DataCpy, uint8 u8Size);
/**
 * @brief Enable USART Peripheral
 * 
 * @param u8IndexCPY USART ID
 */
void USART_voidEnable(uint8 u8IndexCPY);
/**
 * @brief Disable USART Peripheral
 * 
 * @param u8IndexCPY USART ID
 */
void USART_voidDisable(uint8 u8IndexCPY);


/*
void USART_voidEnableRXCompInt(void);
void USART_voidDisableRXCompInt(void);


void USART_voidEnableTXCompInt(void);
void USART_voidDisableTXCompInt(void);

void USART_voidEnableDataRegFreeInt(void);
void USART_voidDisableDataRegFreeInt(void);

void USART_voidTxCompSetCallBack(pf pfTxCompCpy);
void USART_voidRxCompSetCallBack(pfU16 pfRxCompCpy);
void USART_voidTxEmptySetCallBack(pfU16 pfTxEmptyCpy);

*/

#endif

