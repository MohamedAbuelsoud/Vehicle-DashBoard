/*
 * MIL.c
 *
 *  Created on: Feb 19, 2023
 *      Author: AA
 */

#include "../../00_LIB/STD_Types.h"
#include "../../00_LIB/BIT_Math.h"

#include "../../02_HAL/DATA _FRAME/DATA_FRAME.h"
#include "../../01_MCAL/01_GPIO/GPIO.h"
#include "MIL.h"

void MIL_voidInit(void)
{
	GPIO_voidSetPinMode(GPIOB_PIN_NUM_01,GPIO_DIGITAL_INPUT);
	GPIO_voidSetPullStatus(GPIOB_PIN_NUM_01,GPIO_PULL_UP);
	GPIO_voidSetPinMode(GPIOB_PIN_NUM_00,GPIO_DIGITAL_INPUT);
	GPIO_voidSetPullStatus(GPIOB_PIN_NUM_00,GPIO_PULL_UP);

}

uint8 ABS_u8GetData(void)
{
	uint8 u8ABS=0;
	GPIO_voidReadPin(GPIOB_PIN_NUM_01,&u8ABS);
	return u8ABS;

}

void ABS_voidSendData(uint8 u8ABSCpy)
{
	DATA_voidSendData(0x24,&u8ABSCpy,1);
}

uint8 SEATBELT_u8GetData(void)
{
	uint8 u8SeatBelt=0;
	GPIO_voidReadPin(GPIOB_PIN_NUM_00,&u8SeatBelt);
	return u8SeatBelt;
}
void SEATBELT_voidSendData(uint8 u8SeatBeltCpy)
{
	DATA_voidSendData(0x25,&u8SeatBeltCpy,1);
}
