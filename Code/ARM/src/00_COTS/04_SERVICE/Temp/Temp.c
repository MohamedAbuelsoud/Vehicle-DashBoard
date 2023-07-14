/**
 * @file Temp.c
 * @author G3_DashBoard_Team
 * @brief Program file for temperature service for stm32f401cc
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

#include "Temp.h"

/**
 * @brief function to get and calculate temperature Reading 
 * 
 * @return uint8 temperature Reading 
 */
uint8 TEMP_u8GetData(void)
{
	uint32 u32Data=0;
	uint8 u8Temp=0;
	u32Data = ADC_CONV_u32GetFirstChanelData();
	u8Temp = (u32Data*250)/1023;
	return u8Temp;
}
/**
 * @brief Send temperature Reading
 * 
 * @param u8BMSCPY temperature Reading
 */
void TEMP_voidSendData(uint8 u8TempCPY)
{
	DATA_voidSendData(0x20,&u8TempCPY,1);
}
