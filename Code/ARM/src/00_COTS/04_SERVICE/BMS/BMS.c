/**
 * @file BMS.c
 * @author G3_DashBoard_Team
 * @brief Program file for BMS service for stm32f401cc
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
#include "../../02_HAL/Time/Time.h"

#include "BMS.h"



#define MAX_CHARGE    1
#define OFFSIT        0
#define GAIN          1

/**
 * @brief function to get and calculate Battery Reading 
 * 
 * @return uint8 Battery Reading 
 */
uint8 BMS_u8GetData(void)
{

	uint32 ADC_value_32;

	static uint8 Adc_Value_8;//,Samples=0,sensor;
//	static float64 Current_Time , Previous_Time;

//	Current_Time=Get_Time();

	ADC_value_32 = ADC_CONV_u32GetThirdChanelData();
//	ADC_value_32=55;
	Adc_Value_8=(ADC_value_32*100)/1023;
//	sensor=(Adc_Value_8 - OFFSIT) * GAIN;

//	Samples += sensor * (Current_Time-Previous_Time);

//	Previous_Time =Current_Time;

return Adc_Value_8;//Samples/MAX_CHARGE;

}


/**
 * @brief Send Battery Reading
 * 
 * @param u8BMSCPY Battery Reading
 */
void BMS_voidSendData(uint8 u8BMSCPY)
{
	DATA_voidSendData(0x22,&u8BMSCPY,1);
}
