/**
 * @file GPIO.h
 * @author G3_DashBoard_Team
 * @brief Interface file for GPIO driver for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#ifndef GPIO_H
#define GPIO_H

#define GPIOA_PIN_NUM_00      0
#define GPIOA_PIN_NUM_01      1
#define GPIOA_PIN_NUM_02      2
#define GPIOA_PIN_NUM_03      3
#define GPIOA_PIN_NUM_04      4
#define GPIOA_PIN_NUM_05      5
#define GPIOA_PIN_NUM_06      6
#define GPIOA_PIN_NUM_07      7
#define GPIOA_PIN_NUM_08      8
#define GPIOA_PIN_NUM_09      9
#define GPIOA_PIN_NUM_10      10
#define GPIOA_PIN_NUM_11      11
#define GPIOA_PIN_NUM_12      12
#define GPIOA_PIN_NUM_13      13
#define GPIOA_PIN_NUM_14      14
#define GPIOA_PIN_NUM_15      15

#define GPIOB_PIN_NUM_00      (16+0)
#define GPIOB_PIN_NUM_01      (16+1)
#define GPIOB_PIN_NUM_02      (16+2)
#define GPIOB_PIN_NUM_03      (16+3)
#define GPIOB_PIN_NUM_04      (16+4)
#define GPIOB_PIN_NUM_05      (16+5)
#define GPIOB_PIN_NUM_06      (16+6)
#define GPIOB_PIN_NUM_07      (16+7)
#define GPIOB_PIN_NUM_08      (16+8)
#define GPIOB_PIN_NUM_09      (16+9)
#define GPIOB_PIN_NUM_10      (16+10)
#define GPIOB_PIN_NUM_11      (16+11)
#define GPIOB_PIN_NUM_12      (16+12)
#define GPIOB_PIN_NUM_13      (16+13)
#define GPIOB_PIN_NUM_14      (16+14)
#define GPIOB_PIN_NUM_15      (16+15)


#define GPIOC_PIN_NUM_13      (32+13)
#define GPIOC_PIN_NUM_14      (32+14)
#define GPIOC_PIN_NUM_15      (32+15)



#define GPIO_DIGITAL_INPUT     0
#define GPIO_DIGITAL_OUTPUT    1
#define GPIO_ALTERNATE_FUNC    2
#define GPIO_ANALOG            3

#define GPIO_PUSHPULL_TYPE     0
#define GPIO_OPEN_DRAIN_TYPE   1

#define GPIO_LOW_SPEED         0
#define GPIO_MEDIUM_SPEED      1
#define GPIO_HIGH_SPEED        2
#define GPIO_VERY_HIGH_SPEED   3

#define GPIO_FLOATING         0
#define GPIO_PULL_UP          1
#define GPIO_PULL_DOWN        2

#define GPIO_ALT_FUNC_AF00     0
#define GPIO_ALT_FUNC_AF01     1
#define GPIO_ALT_FUNC_AF02     2
#define GPIO_ALT_FUNC_AF03     3
#define GPIO_ALT_FUNC_AF04     4
#define GPIO_ALT_FUNC_AF05     5
#define GPIO_ALT_FUNC_AF06     6
#define GPIO_ALT_FUNC_AF07     7
#define GPIO_ALT_FUNC_AF08     8
#define GPIO_ALT_FUNC_AF09     9
#define GPIO_ALT_FUNC_AF10     10
#define GPIO_ALT_FUNC_AF11     11
#define GPIO_ALT_FUNC_AF12     12
#define GPIO_ALT_FUNC_AF13     13
#define GPIO_ALT_FUNC_AF14     14
#define GPIO_ALT_FUNC_AF15     15



#define HIGH    1
#define LOW     0




//void GPIO_voidInit(void);

/**
 * @brief A function to set pin mode 
 * 
 * @param u8PinNumberCpy pin number
 * @param u8PinModeCpy pin mode
 */
void GPIO_voidSetPinMode(uint8 u8PinNumberCpy,uint8 u8PinModeCpy);
/**
 * @brief a funtion to set output type
 * 
 * @param u8PinNumberCpy pin number
 * @param u8PinOutputTypeCpy output type
 */
void GPIO_voidSetOutputType(uint8 u8PinNumberCpy,uint8 u8PinOutputTypeCpy);
/**
 * @brief A function to set output speed
 * 
 * @param u8PinNumberCpy pin number
 * @param u8PinOutputSpeedCpy output speed
 */
void GPIO_voidSetOutoutSpeed(uint8 u8PinNumberCpy,uint8 u8PinOutputSpeedCpy);
/**
 * @brief set pull status
 * 
 * @param u8PinNumberCpy pin number
 * @param u8PinStatusCpy pin status
 */
void GPIO_voidSetPullStatus(uint8 u8PinNumberCpy,uint8 u8PinStatusCpy);
/**
 * @brief set alternative function
 * 
 * @param u8PinNumberCpy pin number
 * @param u8AltFuncCpy alternative function
 */
void GPIO_voidSetAlternativeFunction(uint8 u8PinNumberCpy, uint8 u8AltFuncCpy);
/**
 * @brief write pin output
 * 
 * @param u8PinNumberCpy pin number 
 * @param u8DataCpy pin output 
 */
void GPIO_voidWritePin(uint8 u8PinNumberCpy,uint8 u8DataCpy);
/**
 * @brief a function to read pin
 * 
 * @param u8PinNumberCpy pin number
 * @param u8DataCpy pin reading value
 */
void GPIO_voidReadPin(uint8 u8PinNumberCpy,uint8* u8DataCpy);





#endif
