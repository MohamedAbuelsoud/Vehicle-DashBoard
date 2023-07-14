/**
 * @file SYSTICK_Priv.h
 * @author G3_DashBoard_Team
 * @brief Private file for systick driver for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef SYSTICK_PRIV_H
#define SYSTICK_PRIV_H


#define    STK_BASE_ADRESS        0xE000E010


typedef struct{

	volatile uint32 CTRL ;
	volatile uint32 LOAD ;
	volatile uint32 VAL  ;
	volatile uint32 CALIB;

}SYSTICK;

#define STK ((volatile SYSTICK*) STK_BASE_ADRESS)

#endif
