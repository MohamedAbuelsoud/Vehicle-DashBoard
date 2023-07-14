/**
 * @file GPIO_priv.h
 * @author G3_DashBoard_Team
 * @brief Configuration file for GPIO driver for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef GPIO_PRIV_H
#define GPIO_PRIV_H


#define GBIO_A_BASE_ADDRESS      0x40020000
#define GBIO_B_BASE_ADDRESS      0x40020400
#define GBIO_C_BASE_ADDRESS      0x40020800


typedef struct
{
	volatile uint32 MODER;
	volatile uint32 OTYPER;
	volatile uint32 OSPEEDR;
	volatile uint32 PUPDR;
	volatile uint32 IDR;
	volatile uint32 ODR;
	volatile uint32 BSRR;
	volatile uint32 LCKR;
	volatile uint32 AFRL;
	volatile uint32 AFRh;

}GPIO_MemMaP;

#define GPIOA    ((volatile GPIO_MemMaP *) GBIO_A_BASE_ADDRESS)
#define GPIOB    ((volatile GPIO_MemMaP *) GBIO_B_BASE_ADDRESS)
#define GPIOC    ((volatile GPIO_MemMaP *) GBIO_C_BASE_ADDRESS)

#endif
