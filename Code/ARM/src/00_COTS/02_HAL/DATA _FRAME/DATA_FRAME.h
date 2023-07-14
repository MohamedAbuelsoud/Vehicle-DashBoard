/**
 * @file DATA_FRAME.h
 * @author G3_DashBoard_Team
 * @brief Interface file for Data Transmission Layer for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SERVICE_DATA__FRAME_DATA_FRAME_H_
#define SERVICE_DATA__FRAME_DATA_FRAME_H_

/**
 * @brief Initialize Service
 * 
 */
void DATA_voidInit(void);
/**
 * @brief Send Data Frame
 * 
 * @param u8MessageId Message ID
 * @param au8Data Data
 * @param u8DLC Data Length Code
 */
void DATA_voidSendData(uint8 u8MessageId,uint8* au8Data,uint8 u8DLC);


#endif /* SERVICE_DATA__FRAME_DATA_FRAME_H_ */

