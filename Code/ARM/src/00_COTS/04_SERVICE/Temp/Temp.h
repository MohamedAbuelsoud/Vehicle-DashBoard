/**
 * @file Temp.h
 * @author G3_DashBoard_Team
 * @brief Program file for temperature service for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef TEMP_H
#define TEMP_H
/**
 * @brief function to get and calculate temperature Reading 
 * 
 * @return uint8 temperature Reading 
 */
uint8 TEMP_u8GetData(void);
/**
 * @brief Send temperature Reading
 * 
 * @param u8BMSCPY temperature Reading
 */
void TEMP_voidSendData(uint8 u8TempCPY);

#endif
