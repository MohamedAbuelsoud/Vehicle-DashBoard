/**
 * @file EXTI_priv.h
 * @author G3_DashBoard_Team
 * @brief Private file for EXTI driver for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef EXIT_PRIV_H
#define EXIT_PRIV_H

 
#define Base_Adress_EXTI				      0x40013C00
 
 
#define  SYSCFG_EXTICR1                  (*(volatile uint32*)(0x40013808))

 
#define   EXTI_CONFG_MASK1                0xFFFFFFF0UL
#define   EXTI_CONFG_MASK2                0xFFFFFF0FUL
#define   EXTI_CONFG_MASK3                0xFFFFF0FFUL
#define   EXTI_CONFG_MASK4                0xFFFF0FFFUL



typedef struct
{
	/*  	Must be arranged like register map		*/

	volatile  uint32   IMR		;
	volatile  uint32   EMR		;
	volatile  uint32   RTSR	;
	volatile  uint32   FTSR	;
	volatile  uint32   SWIER   ;
	volatile  uint32   PR		;
}EXTI_t;



#define EXTI_Ptr 		 (( volatile  EXTI_t * ) Base_Adress_EXTI )			


#endif //EXIT_PRIVATE_H
