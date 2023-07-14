/**
 * @file SYSTICK.h
 * @author G3_DashBoard_Team
 * @brief Interface file for systick driver for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SYSTICK_H
#define SYSTICK_H


#define STK_INT_EN   1
#define STK_INT_DIS  0

/**
 * @brief Systick Initialization function
 * 
 */
void STK_voidInit( void );
/**
 * @brief Systick timer start function
 * 
 * @param Copy_PreloadValue timer preload value
 */
void STK_voidStart( uint32 Copy_PreloadValue );
/**
 * @brief Systick Interrupt Enable/Disable function
 * 
 * @param Copy_u8Status Enable/Disable Systick Interrupt
 */
void STK_voidINTStatus( uint8 Copy_u8Status );
/**
 * @brief function to read Systick flag
 * 
 * @return uint8 Systick flag
 */
uint8 STK_u8ReadFlag( void );
/**
 * @brief Set callback function
 * 
 * @param StkCallBack function to be called
 */
void STK_voidSetCallBack( pf StkCallBack );

#endif
