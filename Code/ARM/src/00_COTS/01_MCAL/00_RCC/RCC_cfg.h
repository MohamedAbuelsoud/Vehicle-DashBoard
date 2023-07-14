/**
 * @file RCC_cfg.h
 * @author G3_DashBoard_Team
 * @brief Configuration file for RCC driver for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#ifndef RCC_cfg_H
#define RCC_cfg_H

#define RCC_SYSTEM_SOURCE   RCC_HSI
#define RCC_HSE_BYPASS      DISABLE
#define RCC_HSE_CSS         ENABLE

#define RCC_PLLP_VALUE     2
#define RCC_PLLN_VALUE     8         //2..432
#define RCC_PLLM_VALUE     4          //2..63
#define RCC_PLL_SOURCE  RCC_HSE

#define RCC_MCO2_STATUS    RCC_MCO2_SYSCLK
#define RCC_MCO1_STATUS    RCC_MCO1_HSI

#define RCC_MCO2_SPEED    RCC_MCO_No_Prescaller
#define RCC_MCO1_SPEED    RCC_MCO_No_Prescaller

#define RCC_APB1_PRESCALLER     RCC_APB_NO_PRESCALLER
#define RCC_APB2_PRESCALLER     RCC_APB_NO_PRESCALLER
#define RCC_AHB_PRESCALLER      RCC_AHP_NO_PRESCALLER


#endif
