/**
 * @file DMA.h
 * @author G3_DashBoard_Team
 * @brief Interface file for DMA driver for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef DMA_H
#define DMA_H


#include "../../00_LIB/STD_Types.h"
#include "../../00_LIB/BIT_Math.h"
/**
 * @brief Initialize DMA
 * 
 * @param u8SreamIDCpy Stream ID
 */
void DMA_voidInit(uint8 u8SreamIDCpy );
/**
 * @brief Set Address
 * 
 * @param pu32PeriReg Pripheral Register
 * @param pu32DataReg Data Register
 * @param u32SizeCpy Size
 * @param u8SreamIDCpy Stream ID
 */
void DMA_voidSetAddress(uint32 *pu32PeriReg , uint32 *pu32DataReg , uint32 u32SizeCpy ,uint8 u8SreamIDCpy );
/**
 * @brief Enable Stream
 * 
 * @param u8SreamIDCpy Stream ID
 */
void DMA_voidStreamEnable(uint8 u8SreamIDCpy );

#endif
