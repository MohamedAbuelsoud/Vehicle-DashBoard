/**
 * @file RCC_priv.h
 * @author G3_DashBoard_Team
 * @brief private file for RCC driver for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef RCC_PRIV_H
#define RCC_PRIV_H

#define RCC_HSI  0
#define RCC_HSE  1
#define RCC_PLL  2

#define RCC_MCO2_SYSCLK  0
#define RCC_MCO2_PLLI2S  1
#define RCC_MCO2_HSE     2
#define RCC_MCO2_PLL     3

#define RCC_MCO1_HSI     0
#define RCC_MCO1_LSE     1
#define RCC_MCO1_HSE     2
#define RCC_MCO1_PLL     3

#define RCC_MCO_No_Prescaller    0
#define RCC_MCO_Prescaller2      4
#define RCC_MCO_Prescaller3      5
#define RCC_MCO_Prescaller4      6
#define RCC_MCO_Prescaller5      7

#define RCC_APB_NO_PRESCALLER      0
#define RCC_APB_PRESCALLER2        4
#define RCC_APB_PRESCALLER4        5
#define RCC_APB_PRESCALLER8        6
#define RCC_APB_PRESCALLER16       7

#define RCC_AHP_NO_PRESCALLER     0
#define RCC_AHP_PRESCALLER_2      8
#define RCC_AHP_PRESCALLER_4      9
#define RCC_AHP_PRESCALLER_8      10
#define RCC_AHP_PRESCALLER_16     11
#define RCC_AHP_PRESCALLER_64     12
#define RCC_AHP_PRESCALLER_128    13
#define RCC_AHP_PRESCALLER_256    14
#define RCC_AHP_PRESCALLER_512    15

#define RCC_BASE_ADDRESS     0x40023800

#define RCC_CR   			*((volatile uint32*)(RCC_BASE_ADDRESS + 0x00 ))
#define RCC_PLLCFGR			*((volatile uint32*)(RCC_BASE_ADDRESS + 0x04 ))
#define RCC_CFGR			*((volatile uint32*)(RCC_BASE_ADDRESS + 0x08 ))
#define RCC_AHB1ENR			*((volatile uint32*)(RCC_BASE_ADDRESS + 0x30 ))
#define RCC_AHB2ENR			*((volatile uint32*)(RCC_BASE_ADDRESS + 0x34 ))
#define RCC_APB1ENR			*((volatile uint32*)(RCC_BASE_ADDRESS + 0x40 ))
#define RCC_APB2ENR			*((volatile uint32*)(RCC_BASE_ADDRESS + 0x44 ))


#endif
