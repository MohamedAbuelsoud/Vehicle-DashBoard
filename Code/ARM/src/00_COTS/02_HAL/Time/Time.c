/**
 * @file Time.c
 * @author G3_DashBoard_Team
 * @brief Program file for Time Layer for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../../00_LIB/STD_Types.h"
#include "../../00_LIB/BIT_Math.h"
#include "../../01_MCAL/02_SYSTICK/SYSTICK.h"

#include"Time.h"

float64 Ticks_Count;
/**
 * @brief Update Time
 * 
 */
void Update_Time()
{
	Ticks_Count++;
	STK_voidStart(2000);
}
/**
 * @brief Initialization Function
 * 
 */
void Time_Init(void)
{
    STK_voidInit();
    STK_voidSetCallBack(Update_Time);
    STK_voidStart(2000);
}


/*                 Called at   BMS and SPEED.      */
/**
 * @brief Get time
 * 
 * @return float64 calculated time  
 */
float64 Get_Time(void)
{
    return Ticks_Count;
}
