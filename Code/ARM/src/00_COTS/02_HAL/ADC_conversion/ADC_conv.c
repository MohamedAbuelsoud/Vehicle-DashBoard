/**
 * @file ADC_conv.c
 * @author G3_DashBoard_Team
 * @brief Program file for ADC Service Layer for stm32f401cc
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
#include "../../01_MCAL/07_ADC/ADC.h"
#include "../../01_MCAL/05_DMA/DMA.h"

#include "ADC_conv.h"

/**
 * @brief Array to Receive ADC Readings from 3 channels
 * 
 */
uint32 ADC_data[3]={0,0,0};
/**
 * @brief Initialize ADC Service
 * 
 */
void ADC_CONV_VoidInit(void)
{
	RCC_voidEnablePeriphralClock(RCC_ADC1);
	RCC_voidEnablePeriphralClock(RCC_DMA2);

	GPIO_voidSetPinMode(GPIOA_PIN_NUM_00,GPIO_ANALOG);
	GPIO_voidSetPinMode(GPIOA_PIN_NUM_04,GPIO_ANALOG);
	GPIO_voidSetPinMode(GPIOA_PIN_NUM_03,GPIO_ANALOG);

	DMA_voidSetAddress(ADC_u32GetDataAddress(),ADC_data,3,0);

	ADC_voidInit();
	DMA_voidInit(0);

	ADC_voidStartConversion();
	DMA_voidStreamEnable(0);
}
/**
 * @brief Get first channel data
 * 
 * @return uint32 data
 */
uint32 ADC_CONV_u32GetFirstChanelData(void)
{
	return ADC_data[0];
}
/**
 * @brief Get second channel data
 * 
 * @return uint32 data
 */
uint32 ADC_CONV_u32GetSecondChanelData(void)
{
	return ADC_data[1];
}
/**
 * @brief Get third channel data
 * 
 * @return uint32 data
 */
uint32 ADC_CONV_u32GetThirdChanelData(void)
{
	return ADC_data[2];
}
