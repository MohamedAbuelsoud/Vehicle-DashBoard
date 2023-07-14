/**
 * @file EXTI.h
 * @author G3_DashBoard_Team
 * @brief Interface file for Exernal Interrupt driver for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#ifndef EXTI_H
#define EXTI_H


#define EXTI0     0
#define EXTI1     1

#define   RISING_EDGE     0

#define   FALLING_EDGE   1

#define    ON_CHANGE       2

#define LINE_0			0
#define LINE_1			1
#define LINE_2			2
#define LINE_3			3
#define LINE_4			4
#define LINE_5			5
#define LINE_6			6
#define LINE_7			7
#define LINE_8			8
#define LINE_9			9
#define LINE_10			10
#define LINE_11			11
#define LINE_12			12
#define LINE_13			13
#define LINE_14			14
#define LINE_15			15

#define GPIOA_PORT   		   0b0000
#define GPIOB_PORT   		   0b0001
#define GPIOC_PORT   		   0b0010
#define GPIOD_PORT   		   0b0011



/**
 * @brief Initialze External Interrupt
 * 
 */
void EXTI_voidInit(void);
/* Function To Change Mode And Line At RunTime */
// Signal Latch == Init But Here I can Change The Line And Sense Mode
/**
 * @brief Function To Change Mode And Line At RunTime
 * Signal Latch == Init But Here I can Change The Line And Sense Mode
 * 
 * @param Copy_u8Line 
 * @param Copy_u8EXTISenseMode 
 */
void EXTI_voidSetSignalLatch(uint8 Copy_Exti_Line ,uint8 Copy_EXTI_Sense_Mode )  ;
/* Give The Function The Line To Enable It IntTERPUT  */
/**
 * @brief Give The Function The Line To Enable It IntTERPUT
 * 
 * @param Copy_u8Line 
 */
void EXIT_voidEnableEXIT(uint8 Copy_u8Line) ;
/* Give The Function The Line To Disable It IntTERPUT  */
/**
 * @brief Give The Function The Line To Disable It IntTERPUT
 * 
 * @param Copy_u8Line 
 */
void EXTI_voidDisableEXTI(uint8 Copy_u8Line);
/* Function Make SoftWare INT at Any Line */
// If Interrput Enable (PIE) ON This Line And EXTI_IMR Line Writing By '1' , When it is Set To '0' Set Corresponding Pending
/* IMR = 1 And PR =0 FOR 0:15 Now You Will Have Software Trigger & And It Clear By Put 1 At PR */
/**
 * @brief Function Make SoftWare INT at Any Line
 * If Interrput Enable (PIE) ON This Line And EXTI_IMR Line Writing By '1', 
 * When it is Set To '0' Set Corresponding Pending
 * IMR = 1 And PR =0 FOR 0:15 Now You Will Have Software Trigger & And It Clear By Put 1 At PR
 * 
 * @param Copy_u8Line 
 */
void EXIT_voidSoftwareInterrput(uint8 Copy_u8Line);
/**
 * @brief Set CallBack Function for EXTI0
 * 
 * @param ptr Called Function
 */
void EXTI0_voidSetCallBack( void (*ptr) (void));
/**
 * @brief Set CallBack Function for EXTI1
 * 
 * @param ptr Called Function
 */
void EXTI1_voidSetCallBack( void (*ptr) (void));
/**
 * @brief A function to configure EXTI port and line
 * 
 * @param Copy_u8ExtiLine 
 * @param Copy_u8GpioPortNum 
 */
void EXTI_voidSetEXTIConfiguration(uint8 Copy_u8ExtiLine , uint8 Copy_u8GpioPortNum );

#endif  
