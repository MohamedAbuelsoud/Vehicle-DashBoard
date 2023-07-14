/**
 * @file Speed.c
 * @author G3_DashBoard_Team
 * @brief Program file for Speed service for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "../../00_LIB/STD_Types.h"
#include "../../00_LIB/BIT_Math.h"

#include "../../02_HAL/DATA _FRAME/DATA_FRAME.h"
#include "../../02_HAL/Time/Time.h"
#include"Speed.h"

#define BASE 100       //MilliSeconds

extern uint32 Encoder_Counts;

volatile  uint8 Speed;
volatile    float Speed32;


/**
 * @brief function to get and calculate speed Reading 
 * 
 * @return uint8 speed Reading 
 */
uint8 SPEED_u8GetData(void)
{

	volatile static float64 Current_Time,Previous_Time;
	Current_Time = Get_Time();
	if((Current_Time-Previous_Time)>=BASE)
	{
	    Speed = (Encoder_Counts*(25)); //1250
//	    Speed = (uint8)Speed32;

	    // Add Offsets.
	    Encoder_Counts=0;
	    Previous_Time=Current_Time;
	}
	//Add scale of the speed.
	return Speed;
}
/**
 * @brief Send speed Reading
 * 
 * @param u8BMSCPY speed Reading
 */
void SPEED_voidSendData(uint8 u8SpeedCpy)
{
	DATA_voidSendData(0x23,&u8SpeedCpy,1);
}
