/**
 * @file USART.c
 * @author G3_DashBoard_Team
 * @brief Program file for USART driver for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "../../00_LIB/STD_Types.h"
#include "../../00_LIB/BIT_Math.h"

#include"USART.h"
#include"USART_cfg.h"
#include"USART_priv.h"

/**
 * @brief USART Initialization
 * 
 */
void USART_voidInit(void)
{

	USART_1->BRR = UART1_BUAD_RATE;
	USART_1->CR1 |= (UART1_RECEIVER << 2);
	USART_1->CR1 |= (UART1_TRANSMITTER << 3);
	USART_1->CR1 |= (USART1_IDLE_INT << 4);
	USART_1->CR1 |= (UART1_RX_INT << 5);
	USART_1->CR1 |= (UART1_TX_INT << 6);
	USART_1->CR1 |= (USART1_PARITY_TYPE << 9);
	USART_1->CR1 |= (USART1_PARITY << 10);
	USART_1->CR1 |= (USART1_DATA_SIZE << 12);
	USART_1->CR1 |= (UART1_OVER_SAMPLING << 15);
	USART_1->CR2 |= (UART1_SYNCHRONIZATION << 11);
	USART_1->CR2 |= (UART1_STOP_BITS << 12);


}
/**
 * @brief Receive byte from USART
 * 
 * @param u8IndexCPY USART ID
 * @param pu16DataCpy Received DATA
 */
void USART_enuGetDataByte(uint8 u8IndexCPY, uint8* pu16DataCpy)
{
	switch (u8IndexCPY)
		{
		case 1:
			while (GET_BIT(USART_1->SR, 5) == 0);
			*pu16DataCpy = USART_1->DR;
			break;
		case 2:
			while (GET_BIT(USART_2->SR, 5) == 0);
			*pu16DataCpy = USART_2->DR;
			break;
		case 6:
			while (GET_BIT(USART_6->SR, 5) == 0);
			*pu16DataCpy = USART_6->DR;
			break;
		}

}
/**
 * @brief Send byte through USART
 * 
 * @param u8IndexCPY USART ID
 * @param u16DataCpy DATA to be sent
 */
void USART_voidSendDataByte(uint8 u8IndexCPY, uint8 u16DataCpy)
{
	switch (u8IndexCPY)
			{
			case 1:
				while (GET_BIT(USART_1->SR, 7)==0);
				USART_1->DR = u16DataCpy;
				while (GET_BIT(USART_1->SR, 6)==0);
				break;
			case 2:
				USART_2->DR = u16DataCpy;
				while (!GET_BIT(USART_2->SR, 6));
				break;
			case 6:
				USART_6->DR = u16DataCpy;
				while (!GET_BIT(USART_6->SR, 6));
				break;
			}

}
/**
 * @brief Receive string from USART
 * 
 * @param u8IndexCPY USART ID
 * @param pu16DataCpy Received DATA
 * @param u8Size string size
 */
void USART_enuGetDataString(uint8 u8IndexCPY, uint16* pu16DataCpy ,uint8 u8Size)
{
	uint8 u8Counter;
	switch (u8IndexCPY)
		{
		case 1:
			for(u8Counter=0;u8Counter<u8Size;u8Counter++)
			{
				while (GET_BIT(USART_1->SR, 5) == 0);
				pu16DataCpy[u8Counter] = USART_1->DR;
			}
			break;
		case 2:
			for(u8Counter=0;u8Counter<u8Size;u8Counter++)
			{
				while (GET_BIT(USART_2->SR, 5) == 0);
				pu16DataCpy[u8Counter] = USART_2->DR;
			}
			break;
		case 6:
			for(u8Counter=0;u8Counter<u8Size;u8Counter++)
			{
				while (GET_BIT(USART_6->SR, 5) == 0);
				pu16DataCpy[u8Counter] = USART_6->DR;
			}
			break;
		}
}
/**
 * @brief send string through USART
 * 
 * @param u8IndexCPY USART ID
 * @param u16DataCpy DATA to be sent
 * @param u8Size string size
 */
void USART_voidSendDataString(uint8 u8IndexCPY, uint8* u16DataCpy, uint8 u8Size)
{
	uint8 u8Counter;

		switch (u8IndexCPY)
		{
		case 1:
			for (u8Counter = 0; u8Counter < u8Size; u8Counter++)
			{
				USART_1->DR = u16DataCpy[u8Counter];
				while (!GET_BIT(USART_1->SR, 6));
			}
			break;
		case 2:
			for (u8Counter = 0; u8Counter < u8Size; u8Counter++)
			{
				USART_2->DR = u16DataCpy[u8Counter];
				while (!GET_BIT(USART_2->SR, 6));
			}
			break;
		case 6:
			for (u8Counter = 0; u8Counter < u8Size; u8Counter++)
			{
				USART_6->DR = u16DataCpy[u8Counter];
				while (!GET_BIT(USART_6->SR, 6));
			}
			break;
		}
}

/**
 * @brief Enable USART Peripheral
 * 
 * @param u8IndexCPY USART ID
 */
void USART_voidEnable(uint8 u8IndexCPY)
{
	switch (u8IndexCPY)
	{
	case 1:
		SET_BIT(USART_1->CR1, 13);
		break;
	case 2:
		SET_BIT(USART_2->CR1, 13);
		break;
	case 3:
		SET_BIT(USART_6->CR1, 13);
		break;
	}
}
/**
 * @brief Disable USART Peripheral
 * 
 * @param u8IndexCPY USART ID
 */
void USART_voidDisable(uint8 u8IndexCPY)
{
	switch (u8IndexCPY)
	{
	case 1:
		CLR_BIT(USART_1->CR1, 13);
		break;
	case 2:
		CLR_BIT(USART_2->CR1, 13);
		break;
	case 3:
		CLR_BIT(USART_6->CR1, 13);
		break;
	}
}
