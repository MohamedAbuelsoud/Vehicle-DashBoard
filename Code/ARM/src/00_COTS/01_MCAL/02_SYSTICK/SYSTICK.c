/**
 * @file SYSTICK.c
 * @author G3_DashBoard_Team
 * @brief Program file for systick driver for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "../../00_LIB/STD_Types.h"
#include "../../00_LIB/BIT_Math.h"

#include "SYSTICK.h"
#include "SYSTICK_Cfg.h"
#include "SYSTICK_Priv.h"


pf STK_CallBack = NULL_PTR ;

uint32 Flag=0;

/**
 * @brief Systick ISR
 * 
 */
void SysTick_Handler(void)
{
	STK_CallBack();
Flag=1;
}

/**
 * @brief Systick Initialization function
 * 
 */
void STK_voidInit( void )
{
	// Enable Systick Interrupt  -2nd bit
	//3rd bit =0--> Clock = AHB / 8 - Stop Systic
	STK->CTRL = 0x00000002;
}

/**
 * @brief Systick timer start function
 * 
 * @param Copy_PreloadValue timer preload value
 */
void STK_voidStart( uint32 Copy_PreloadValue )
{
	// AHB = EXT = 8MHZ & CLOCK OF MSTK = AHB / 8 = 8MHZ / 8 = 1MHZ = 1 Micro For Each Count
	//Load Reload Value
	STK->LOAD = Copy_PreloadValue - 1;
	//Clear Val Register
	STK->VAL  = 0 ;
	//Enable Systick
	SET_BIT( STK->CTRL , 0 );
// for (uint32 i =0;i<100000000;i++);
// volatile uint32 hh=STK->VAL;

}

/**
 * @brief Systick Interrupt Enable/Disable function
 * 
 * @param Copy_u8Status Enable/Disable Systick Interrupt
 */
void STK_voidINTStatus( uint8 Copy_u8Status )
{
	 STK->CTRL &= ~( 1 << 1 );
	 STK->CTRL |=  ( Copy_u8Status << 1 );
}

/**
 * @brief function to read Systick flag
 * 
 * @return uint8 Systick flag
 */
uint8 MSTK_u8ReadFlag( void )
{

	return ( GET_BIT( STK->CTRL , 16 ) );

}
/**
 * @brief Set callback function
 * 
 * @param StkCallBack function to be called
 */
void STK_voidSetCallBack( pf StkCallBack )
{

	STK_CallBack = StkCallBack;
}
