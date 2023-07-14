/**
 * @file DATA_FRAME.c
 * @author G3_DashBoard_Team
 * @brief Program file for Data Transmission Layer for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../../00_LIB/STD_Types.h"
#include "../../00_LIB/BIT_Math.h"

#include "../../01_MCAL/00_RCC/RCC.h"
#include "../../01_MCAL/01_GPIO/GPIO.h"
#include "../../01_MCAL/06_UART/USART.h"
#include "DATA_FRAME.h"

uint8 CalculateCRCHelper(uint8* au8Data,uint8 u8DLC);

/**
 * @brief Initialize Service
 * 
 */
void DATA_voidInit(void)
{
	RCC_voidEnablePeriphralClock(RCC_USART1);
	USART_voidInit();
	USART_voidEnable(1);

	GPIO_voidSetPinMode(GPIOA_PIN_NUM_09,GPIO_ALTERNATE_FUNC);
	GPIO_voidSetAlternativeFunction(GPIOA_PIN_NUM_09,GPIO_ALT_FUNC_AF07);

	GPIO_voidSetPinMode(GPIOA_PIN_NUM_10,GPIO_ALTERNATE_FUNC);
	GPIO_voidSetAlternativeFunction(GPIOA_PIN_NUM_10,GPIO_ALT_FUNC_AF07);
}
/**
 * @brief Send Data Frame
 * 
 * @param u8MessageId Message ID
 * @param au8Data Data
 * @param u8DLC Data Length Code
 */
void DATA_voidSendData(uint8 u8MessageId,uint8* au8Data,uint8 u8DLC)
{
	uint8 u8CRC;
	uint8 u8Counter;

	USART_voidSendDataByte(1,u8MessageId);
	USART_voidSendDataByte(1,u8DLC);
	for ( u8Counter = 0 ; u8Counter < u8DLC ; u8Counter++ )
	{
		USART_voidSendDataByte(1,au8Data[u8Counter]);
	}
	u8CRC=CalculateCRCHelper(au8Data,u8DLC);
	USART_voidSendDataByte(1,u8CRC);

}



uint8 CalculateCRCHelper(uint8* au8Data,uint8 u8DLC)
{
	uint8 u8Counter;
	uint8 u8CRC=u8DLC;
	for ( u8Counter = 0 ; u8Counter < u8DLC ; u8Counter++ )
	{
		u8CRC ^= au8Data[u8Counter];
	}

	return u8CRC;

}
