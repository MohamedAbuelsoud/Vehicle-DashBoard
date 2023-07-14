/**
 * @file Time.h
 * @author G3_DashBoard_Team
 * @brief Program file for Time Layer for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef TIME_H
#define TIME_H



/**
 * @brief Initialization Function
 * 
 */
void Time_Init(void);
/**
 * @brief Get time
 * 
 * @return float64 calculated time  
 */
float64 Get_Time(void);


#endif 
