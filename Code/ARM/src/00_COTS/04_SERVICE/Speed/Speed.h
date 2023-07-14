/**
 * @file Speed.h
 * @author G3_DashBoard_Team
 * @brief Interface file for Speed service for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef SPEED_H

#define SPEED_H


#include "../../00_LIB/STD_Types.h"
#include "../../00_LIB/BIT_Math.h"
#include "../../02_HAL/ENCODER/Encoder.h"





//This Function called at System Init.

/**
 * @brief function to get and calculate speed Reading 
 * 
 * @return uint8 speed Reading 
 */
uint8 SPEED_u8GetData(void);
/**
 * @brief Send speed Reading
 * 
 * @param u8BMSCPY speed Reading
 */
void SPEED_voidSendData(uint8 u8SpeedCpy);




#endif
