/**
 * @file ADC.h
 * @author G3_DashBoard_Team
 * @brief Interface file for ADC driver for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ADC_H
#define ADC_H


/**
 * @brief ADC Initialization
 * 
 */
void ADC_voidInit(void);
/**
 * @brief Start ADC Conversion
 * 
 */
void ADC_voidStartConversion(void);
/**
 * @brief Stop ADC Conversion
 * 
 */
void ADC_voidStopConversion(void);
/**
 * @brief Read Converted Signal
 * 
 * @return uint32 
 */
uint32 ADC_u16Read(void);
/**
 * @brief Get Data Address
 * 
 * @return uint32* Data Address
 */
uint32* ADC_u32GetDataAddress(void);
/**
 * @brief Set Callback Function
 * 
 * @param pfADCSetISR Called Function
 */
void ADC_voidSetCallBack(pf pfADCSetISR);
/**
 * @brief ADC IRQ Handler
 * 
 */
void ADC_IRQHandler(void);

#endif
