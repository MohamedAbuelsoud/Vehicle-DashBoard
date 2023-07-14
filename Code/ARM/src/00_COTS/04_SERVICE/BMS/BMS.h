/**
 * @file BMS.h
 * @author G3_DashBoard_Team
 * @brief Interface file for BMS service for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef BMS_H
#define BMS_H
/**
 * @brief function to get and calculate Battery Reading 
 * 
 * @return uint8 Battery Reading 
 */
uint8 BMS_u8GetData(void);
/**
 * @brief Send Battery Reading
 * 
 * @param u8BMSCPY Battery Reading
 */
void BMS_voidSendData(uint8 u8BMSCPY);

#endif
