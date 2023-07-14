/**
 * @file ADC.c
 * @author G3_DashBoard_Team
 * @brief Program file for ADC driver for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include"../../00_LIB/BIT_MATH.h"
#include"../../00_LIB/STD_TYPES.h"

#include "../07_ADC/ADC.h"
#include "../07_ADC/ADC_priv.h"
#include "../07_ADC/ADC_cfg.h"


static pf ADC_CallBack;


/**
 * @brief ADC Initialization
 * 
 */
void ADC_voidInit(void)
{

	/*configre resolution*/
	ADC->CR1 |= (ADC_RESOLUTION <<24);

	/*scan mode enable*/
	ADC->CR1 |= (ADC_SCAN_MODE << 8);

	/* Select data alignment */
	ADC->CR2 |= (ADC_DATAD_ALLIGNMENT << 11);

	/*enable EOC*/
	ADC->CR2 |= (ADC_EOC_SELECTION << 10);

	/*DMA*/
	ADC->CR2 |= (ADC_DMA_MODE <<8);
	ADC->CR2 |= (ADC_DMA_SELSCTION << 9);

	/*conversion mode*/
	ADC->CR2 |= (ADC_CONVERSION_MODE << 1);

	/* SAMPLING TIME */
	ADC->SMPR2 |= ADC_CHANELL_0_SAMPLE_TIME;
	ADC->SMPR2 |= (ADC_CHANELL_1_SAMPLE_TIME << 3);
	ADC->SMPR2 |= (ADC_CHANELL_2_SAMPLE_TIME << 6);
	ADC->SMPR2 |= (ADC_CHANELL_3_SAMPLE_TIME << 9);
	ADC->SMPR2 |= (ADC_CHANELL_4_SAMPLE_TIME << 12);
	ADC->SMPR2 |= (ADC_CHANELL_5_SAMPLE_TIME << 15);
	ADC->SMPR2 |= (ADC_CHANELL_6_SAMPLE_TIME << 18);
	ADC->SMPR2 |= (ADC_CHANELL_7_SAMPLE_TIME << 21);


	/*       no of channels   */
	ADC->SQR1 |= ((ADC_REGULAR_SEG_CHANNELS_LENGHT-1) << 20);



	/* Selecting regular sequence */
	ADC->SQR3 |= (ADC_REGULAR_SEQ_1 << 0);
	ADC->SQR3 |= (ADC_REGULAR_SEQ_2 << 5);
	ADC->SQR3 |= (ADC_REGULAR_SEQ_3 << 10);
	ADC->SQR3 |= (ADC_REGULAR_SEQ_4 << 15);
	ADC->SQR3 |= (ADC_REGULAR_SEQ_5 << 20);
	ADC->SQR3 |= (ADC_REGULAR_SEQ_5 << 25);
	ADC->SQR2 |= (ADC_REGULAR_SEQ_7 << 0);



	/*disable all interrupt*/
	ADC->CR1 |= (ADC_EOC_INT << 5);

	/* ADC Prescalar = div by 2 */
	CLR_BIT(ADC_COMMON -> CCR, 16);
	CLR_BIT(ADC_COMMON -> CCR, 17);


	/*    enable ADC     */
	ADC->CR2 |= (ADC_CONVERSION << 0);


}
/**
 * @brief Start ADC Conversion
 * 
 */
void ADC_voidStartConversion(void)
{
	/* Start conversion of regular channels */
	SET_BIT(ADC->CR2,30);
}
/**
 * @brief Stop ADC Conversion
 * 
 */
void ADC_voidStopConversion(void)
{
	/* Start conversion of regular channels */
	CLR_BIT(ADC->CR2,30);
}

/**
 * @brief Read Converted Signal
 * 
 * @return uint32 
 */
uint32 ADC_u16Read(void)
{
	/* Wait for the end of conversion flag */
	while( GET_BIT(ADC->SR,1) == 0 );
	return (ADC->DR);
}
/**
 * @brief Get Data Address
 * 
 * @return uint32* Data Address
 */
uint32* ADC_u32GetDataAddress(void)
{
	return &(ADC->DR);
}
/**
 * @brief Set Callback Function
 * 
 * @param pfADCSetISR Called Function
 */
void ADC_voidSetCallBack(pf pfADCSetISR)
{
	ADC_CallBack = pfADCSetISR ;
}
/**
 * @brief ADC IRQ Handler
 * 
 */
void ADC_IRQHandler(void)
{
	ADC_CallBack();
}
