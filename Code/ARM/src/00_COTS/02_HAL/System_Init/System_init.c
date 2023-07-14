/**
 * @file System_init.c
 * @author G3_DashBoard_Team
 * @brief Program file for System Initialization for stm32f401cc
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
#include "../ADC_conversion/ADC_conv.h"
#include "../DATA _FRAME/DATA_FRAME.h"
#include "../ENCODER/Encoder.h"
#include "../Time/Time.h"


/**
 * @brief System Initialization
 * 
 */
void SYS_voidInit(void)
{
	RCC_voidInit();
	RCC_voidEnablePeriphralClock(RCC_GPIOA);
	RCC_voidEnablePeriphralClock(RCC_GPIOB);
	RCC_voidEnablePeriphralClock(RCC_SYSCFG);
	MIL_voidInit();
	ADC_CONV_VoidInit();
	DATA_voidInit();
	Time_Init();
	Encoder_Init();

}
