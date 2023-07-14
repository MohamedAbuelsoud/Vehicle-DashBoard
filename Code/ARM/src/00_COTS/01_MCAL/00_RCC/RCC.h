/**
 * @file RCC.h
 * @author G3_DashBoard_Team
 * @brief Interface file for RCC driver for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#ifndef RCC_H
#define RCC_H

#define ENABLE    0
#define DISABLE   1

#define RCC_GPIOA      0
#define RCC_GPIOB      1
#define RCC_GPIOC      2
#define RCC_GPIOD      3
#define RCC_GPIOE      4
#define RCC_GPIOH      7
#define RCC_CRC        12
#define RCC_DMA1       21
#define RCC_DMA2       22

#define RCC_OTGFS     (32+7)

#define RCC_TIM2      (64+0)
#define RCC_TIM3      (64+1)
#define RCC_TIM4      (64+2)
#define RCC_TIM5      (64+3)
#define RCC_WWDG      (64+11)
#define RCC_SPI2      (64+14)
#define RCC_SPI3      (64+15)
#define RCC_USART2    (64+17)
#define RCC_I2C1      (64+21)
#define RCC_I2C2      (64+22)
#define RCC_I2C3      (64+23)
#define RCC_PWR	      (64+28)

#define RCC_TIM1     (96+0)
#define RCC_USART1	 (96+4)
#define RCC_USART6	 (96+5)
#define RCC_ADC1	 (96+8)
#define RCC_SDIO	 (96+11)
#define RCC_SP11	 (96+12)
#define RCC_SP14	 (96+13)
#define RCC_SYSCFG	 (96+14)
#define RCC_TIM9	 (96+16)
#define RCC_TIM10	 (96+17)
#define RCC_TIM11	 (96+18)

/**
 * @brief RCC Initialization Function
 * 
 */
void RCC_voidInit(void);
/**
 * @brief A function to check the current clock source
 * 
 * @return uint8 clock source
 */
uint8 RCC_u8CheckClkSource(void);
/**
 * @brief A function to enable peripheral clock
 * 
 * @param u32PrephiralNameCpy peripheral name/ID 
 */
void RCC_voidEnablePeriphralClock(uint32 u32PrephiralNameCpy);
/**
 * @brief A function to disable peripheral clock
 * 
 * @param u32PrephiralNameCpy peripheral name/ID 
 */
void RCC_voidDisablePeriphralClock(uint8 u32PrephiralNameCpy);
/**
 * @brief Enable Internal clock
 * 
 */
void RCC_HSIEnable(void);
/**
 * @brief disable Internal clock
 * 
 */
void RCC_HSIDisable(void);
/**
 * @brief Enable External clock
 * 
 * @param u8CssStatus CSS
 * @param u8HsebyoStatus HSE bypass
 */
void RCC_HSEEnable(uint8 u8CssStatus, uint8 u8HsebyoStatus);
/**
 * @brief Disable external clock
 * 
 */
void RCC_HSEDisable(void);
/**
 * @brief enable PLL clock
 * 
 */
void RCC_PLLEnable(void);
/**
 * @brief disable PLL clock
 * 
 */
void RCC_PLLDisable(void);
/**
 * @brief choose system clock
 * 
 * @param u8ChangeSystemClock system clock name/ID
 */
void RCC_voidSetSystemClock(uint8 u8ChangeSystemClock);


#endif
