/**
 * @file Fuel.h
 * @author G3_DashBoard_Team
 * @brief Interface file for Fuel service for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef FUEL_H
#define FUEL_H

/**
 * @brief function to get and calculate Fuel Reading 
 * 
 * @return uint8 Fuel Reading 
 */
uint8 FUEL_u8GetData(void);
/**
 * @brief Send Fuel Reading
 * 
 * @param u8BMSCPY Fuel Reading
 */
void FUEL_voidSendData(uint8 u8FuelCPY);


#endif
