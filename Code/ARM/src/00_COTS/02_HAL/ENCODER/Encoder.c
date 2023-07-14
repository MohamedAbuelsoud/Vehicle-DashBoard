/**
 * @file Encoder.c
 * @author G3_DashBoard_Team
 * @brief Program file for Encoder Layer for stm32f401cc
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
#include "../../01_MCAL/03_NVIC/NVIC.h"
#include "../../01_MCAL/04_EXTI/EXTI.h"

#include"Encoder.h"

volatile uint32 Encoder_Counts;
/**
 * @brief Update Count
 * 
 */
void UpdateEncoderCounts()
{
	Encoder_Counts++;
}

NVIC_GroupMode_t Group_SubGroup =NVIC_GroupMode_g16s0;

/**
 * @brief Initialization Function
 * 
 */
void Encoder_Init()
{

	NVIC_voidInitInterruptGroup(Group_SubGroup);

	NVIC_voidEnableInterrupt(7);
	NVIC_voidSetInterruptPriority(7,Group_SubGroup,2,0);

	GPIO_voidSetPinMode(GPIOA_PIN_NUM_01,GPIO_DIGITAL_INPUT);
	GPIO_voidSetPullStatus(GPIOA_PIN_NUM_01,GPIO_PULL_UP);


	EXTI_voidSetEXTIConfiguration(LINE_1 , GPIOA_PORT);
	EXTI_voidSetSignalLatch(LINE_1 ,FALLING_EDGE)  ;
	EXIT_voidEnableEXIT(LINE_1);

	//End here.
	// Just make Setcall back at init and call them at
	EXTI1_voidSetCallBack(UpdateEncoderCounts);

}	
