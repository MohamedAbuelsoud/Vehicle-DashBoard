/**
 * @file Fuel.c
 * @author G3_DashBoard_Team
 * @brief Program file for Fuel service for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../../00_LIB/STD_Types.h"
#include "../../00_LIB/BIT_Math.h"

#include "../../02_HAL/DATA _FRAME/DATA_FRAME.h"
#include "../../02_HAL/ADC_conversion/ADC_conv.h"
#include "Fuel.h"

/**
 * @brief function to get and calculate Fuel Reading 
 * 
 * @return uint8 Fuel Reading 
 */
uint8 FUEL_u8GetData(void)
{
	uint32 u32Data=0;
	uint8 u8Fuel=0;
	u32Data = ADC_CONV_u32GetSecondChanelData();
	u8Fuel = (u32Data*255)/1024;
	return u8Fuel;
}
/**
 * @brief Send Fuel Reading
 * 
 * @param u8BMSCPY Fuel Reading
 */
void FUEL_voidSendData(uint8 u8FuelCPY)
{
	DATA_voidSendData(0x21,&u8FuelCPY,1);
}
