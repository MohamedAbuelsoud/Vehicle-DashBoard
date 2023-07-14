/**
 * @file ADC_conv.h
 * @author G3_DashBoard_Team
 * @brief Interface file for ADC Service Layer for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ADC_CONV_H_
#define ADC_CONV_H_

/**
 * @brief Initialize ADC Service
 * 
 */
void ADC_CONV_VoidInit(void);
/**
 * @brief Get first channel data
 * 
 * @return uint32 data
 */
uint32 ADC_CONV_u32GetFirstChanelData(void);
/**
 * @brief Get second channel data
 * 
 * @return uint32 data
 */
uint32 ADC_CONV_u32GetSecondChanelData(void);
/**
 * @brief Get third channel data
 * 
 * @return uint32 data
 */
uint32 ADC_CONV_u32GetThirdChanelData(void);



#endif /* 00_COTS_02_HAL_ADC_CONVERSION_ADC_CONV_H_ */
