/**
 * @file GPIO.c
 * @author G3_DashBoard_Team
 * @brief Program file for GPIO driver for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include"../../00_LIB/STD_Types.h"
#include"../../00_LIB/BIT_Math.h"

#include "../01_GPIO/GPIO.h"
#include "../01_GPIO/GPIO_cfg.h"
#include "../01_GPIO/GPIO_priv.h"


//void GPIO_voidInit(void);

/**
 * @brief A function to set pin mode 
 * 
 * @param u8PinNumberCpy pin number
 * @param u8PinModeCpy pin mode
 */
void GPIO_voidSetPinMode(uint8 u8PinNumberCpy,uint8 u8PinModeCpy)
{
	if((u8PinNumberCpy >= 0) && (u8PinNumberCpy < 16))
	{
		GPIOA->MODER &= ~(0b11 << (u8PinNumberCpy*2));
		GPIOA->MODER |= (u8PinModeCpy << (u8PinNumberCpy*2));

	}
	else if((u8PinNumberCpy >= 16) && (u8PinNumberCpy < 32))
	{
		GPIOB->MODER &= ~(0b11 << ((u8PinNumberCpy%16)*2));
		GPIOB->MODER |= (u8PinModeCpy << ((u8PinNumberCpy%16)*2));
	}
	else if((u8PinNumberCpy >= 32) && (u8PinNumberCpy < 48))
	{
		GPIOC->MODER &= ~(0b11 << ((u8PinNumberCpy%16)*2));
		GPIOC->MODER |= (u8PinModeCpy << ((u8PinNumberCpy%16)*2));

	}
	else
	{
		//do nothing
	}

}
/**
 * @brief a funtion to set output type
 * 
 * @param u8PinNumberCpy pin number
 * @param u8PinOutputTypeCpy output type
 */
void GPIO_voidSetOutputType(uint8 u8PinNumberCpy,uint8 u8PinOutputTypeCpy)
{
	if((u8PinNumberCpy >= 0) && (u8PinNumberCpy < 16))
	{
		GPIOA->OTYPER &= ~(0b1 << u8PinNumberCpy);
		GPIOA->OTYPER |= (u8PinOutputTypeCpy << u8PinNumberCpy);

	}
	else if((u8PinNumberCpy >= 16) && (u8PinNumberCpy < 32))
	{
		GPIOB->OTYPER &= ~(0b1 << (u8PinNumberCpy%16));
		GPIOB->OTYPER |= (u8PinOutputTypeCpy << (u8PinNumberCpy%16));
	}
	else if((u8PinNumberCpy >= 32) && (u8PinNumberCpy < 48))
	{
		GPIOC->OTYPER &= ~(0b1 << (u8PinNumberCpy%16));
		GPIOC->OTYPER |= (u8PinOutputTypeCpy << (u8PinNumberCpy%16));

	}
	else
	{
		//do nothing
	}
}
/**
 * @brief A function to set output speed
 * 
 * @param u8PinNumberCpy pin number
 * @param u8PinOutputSpeedCpy output speed
 */
void GPIO_voidSetOutoutSpeed(uint8 u8PinNumberCpy,uint8 u8PinOutputSpeedCpy)
{
	if((u8PinNumberCpy >= 0) && (u8PinNumberCpy < 16))
	{
		GPIOA->OSPEEDR &= ~(0b11 << (u8PinNumberCpy*2));
		GPIOA->OSPEEDR |= (u8PinOutputSpeedCpy << (u8PinNumberCpy*2));

	}
	else if((u8PinNumberCpy >= 16) && (u8PinNumberCpy < 32))
	{
		GPIOB->OSPEEDR &= ~(0b11 << ((u8PinNumberCpy%16)*2));
		GPIOB->OSPEEDR |= (u8PinOutputSpeedCpy << ((u8PinNumberCpy%16)*2));
	}
	else if((u8PinNumberCpy >= 32) && (u8PinNumberCpy < 48))
	{
		GPIOC->OSPEEDR &= ~(0b11 << ((u8PinNumberCpy%16)*2));
		GPIOC->OSPEEDR |= (u8PinOutputSpeedCpy << ((u8PinNumberCpy%16)*2));

	}
	else
	{
		//do nothing
	}

}

/**
 * @brief set pull status
 * 
 * @param u8PinNumberCpy pin number
 * @param u8PinStatusCpy pin status
 */
void GPIO_voidSetPullStatus(uint8 u8PinNumberCpy,uint8 u8PinStatusCpy)
{
	if((u8PinNumberCpy >= 0) && (u8PinNumberCpy < 16))
	{
		GPIOA->PUPDR &= ~(0b11 << (u8PinNumberCpy*2));
		GPIOA->PUPDR |= (u8PinStatusCpy << (u8PinNumberCpy*2));

	}
	else if((u8PinNumberCpy >= 16) && (u8PinNumberCpy < 32))
	{
		GPIOB->PUPDR &= ~(0b11 << ((u8PinNumberCpy%16)*2));
		GPIOB->PUPDR |= (u8PinStatusCpy << ((u8PinNumberCpy%16)*2));
	}
	else if((u8PinNumberCpy >= 32) && (u8PinNumberCpy < 48))
	{
		GPIOC->PUPDR &= ~(0b11 << ((u8PinNumberCpy%16)*2));
		GPIOC->PUPDR |= (u8PinStatusCpy << ((u8PinNumberCpy%16)*2));

	}
	else
	{
		//do nothing
	}
}
/**
 * @brief set alternative function
 * 
 * @param u8PinNumberCpy pin number
 * @param u8AltFuncCpy alternative function
 */
void GPIO_voidSetAlternativeFunction(uint8 u8PinNumberCpy, uint8 u8AltFuncCpy)
{
	if((u8PinNumberCpy >= 0) && (u8PinNumberCpy < 8))
	{
		GPIOA->AFRL &= ~(0b1111 << ((u8PinNumberCpy%8)*4));
		GPIOA->AFRL |= (u8AltFuncCpy << ((u8PinNumberCpy%8)*4));
	}
	else if((u8PinNumberCpy >= 8) && (u8PinNumberCpy < 16))
	{
		GPIOA->AFRh &= ~(0b1111 << ((u8PinNumberCpy%8)*4));
		GPIOA->AFRh |= (u8AltFuncCpy << ((u8PinNumberCpy%8)*4));
	}
	if((u8PinNumberCpy >= 16) && (u8PinNumberCpy < 24))
	{
		GPIOB->AFRL &= ~(0b1111 << ((u8PinNumberCpy%8)*4));
		GPIOB->AFRL |= (u8AltFuncCpy << ((u8PinNumberCpy%8)*4));
	}
	else if((u8PinNumberCpy >= 24) && (u8PinNumberCpy < 32))
	{
		GPIOB->AFRh &= ~(0b1111 << ((u8PinNumberCpy%8)*4));
		GPIOB->AFRh |= (u8AltFuncCpy << ((u8PinNumberCpy%8)*4));
	}
	else if((u8PinNumberCpy >= 40) && (u8PinNumberCpy < 48))
	{
		GPIOC->AFRh &= ~(0b1111 << ((u8PinNumberCpy%8)*4));
		GPIOC->AFRh |= (u8AltFuncCpy << ((u8PinNumberCpy%8)*4));
	}

	else
	{
		//do nothing
	}

}
/**
 * @brief write pin output
 * 
 * @param u8PinNumberCpy pin number 
 * @param u8DataCpy pin output 
 */
void GPIO_voidWritePin(uint8 u8PinNumberCpy,uint8 u8DataCpy)
{
	if((u8PinNumberCpy >= 0) && (u8PinNumberCpy < 16))
	{
		GPIOA->ODR &= ~(0b1 << u8PinNumberCpy);
		GPIOA->ODR |= (u8DataCpy << u8PinNumberCpy);

	}
	else if((u8PinNumberCpy >= 16) && (u8PinNumberCpy < 32))
	{
		GPIOB->ODR &= ~(0b1 << (u8PinNumberCpy%16));
		GPIOB->ODR |= (u8DataCpy << (u8PinNumberCpy%16));
	}
	else if((u8PinNumberCpy >= 32) && (u8PinNumberCpy < 48))
	{
		GPIOC->ODR &= ~(0b1 << (u8PinNumberCpy%16));
		GPIOC->ODR |= (u8DataCpy << (u8PinNumberCpy%16));

	}
	else
	{
		//do nothing
	}
}
/**
 * @brief a function to read pin
 * 
 * @param u8PinNumberCpy pin number
 * @param u8DataCpy pin reading value
 */
void GPIO_voidReadPin(uint8 u8PinNumberCpy,uint8* u8DataCpy)
{
	if((u8PinNumberCpy >= 0) && (u8PinNumberCpy < 16))
	{
		*u8DataCpy = GET_BIT(GPIOA->IDR,u8PinNumberCpy);
	}
	else if((u8PinNumberCpy >= 16) && (u8PinNumberCpy < 32))
	{
		*u8DataCpy = GET_BIT(GPIOB->IDR,u8PinNumberCpy%16);
	}
	else if((u8PinNumberCpy >= 32) && (u8PinNumberCpy < 48))
	{
		*u8DataCpy = GET_BIT(GPIOC->IDR,u8PinNumberCpy%16);
	}
	else
	{
		//do nothing
	}
}
