/**
 * @file NVIC_Priv.h
 * @author G3_DashBoard_Team
 * @brief Private file for NVIC driver for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef NVIC_PRIV_H
#define NVIC_PRIV_H


#define NVIC_BASE_ADDRESS    0xE000E100


/** NVIC register map type. */
typedef struct
{
	uint32 ISER[8];              /**< Interrupt Set Enable Registers */
	uint32 RESERVED0[24];        /**< Reserved */
	uint32 ICER[8];              /**< Interrupt Clear Enable Registers */
	uint32 RSERVED1[24];         /**< Reserved */
	uint32 ISPR[8];              /**< Interrupt Set Pending Registers */
	uint32 RESERVED2[24];        /**< Reserved */
	uint32 ICPR[8];              /**< Interrupt Clear Pending Registers */
	uint32 RESERVED3[24];        /**< Reserved */
	uint32 IABR[8];              /**< Interrupt Active bit Registers */
	uint32 RESERVED4[56];        /**< Reserved */
	uint8  IPR[240];             /**< Interrupt Priority Registers */
	uint32 RESERVED5[580];       /**< Reserved */
	uint32 STIR;                 /**< Software Trigger Interrupt Registers */
} NVIC_t;


/*******************************************************************************************************/
/*                                   Struct Macros Base Address Of NVIC                                */
/*******************************************************************************************************/

#define     NVIC_REG    ((volatile NVIC_t*)(NVIC_BASE_ADDRESS))

#define     SCB_AIRCR   (*(volatile uint32*) 0xE000ED0C)

#define     VECTKEY     0x05FA0000

#endif
