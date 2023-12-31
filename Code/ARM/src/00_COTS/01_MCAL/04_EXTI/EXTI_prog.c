/**
 * @file EXTI_prog.c
 * @author G3_DashBoard_Team
 * @brief Program file for Exernal Interrupt driver for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "../../00_LIB/STD_Types.h"
#include "../../00_LIB/BIT_Math.h"

#include "EXTI.h"
#include "EXTI_cfg.h"
#include "EXTI_priv.h"




static void (*EXTI0_CallBack ) (void) =  NULL_PTR ;
static void (*EXTI1_CallBack ) (void) =  NULL_PTR ;

/**
 * @brief Initialze External Interrupt
 * 
 */
void EXTI_voidInit(void)
{
	/***************************	FOR_EXTI_LINE	***************************/
	/* Not Good TO Turn On Line At Initlizaion It is POWER Consumption So  */

#if		EXTI_Line ==	LINE_0
	SET_BIT(EXTI_Ptr->IMR , LINE_0) ;

#elif	EXTI_Line ==LINE_1
	SET_BIT(EXTI_Ptr->IMR , LINE_1) ;

#elif	EXTI_Line ==	LINE_2
	SET_BIT(EXTI_Ptr->IMR , LINE_2) ;

#elif	EXTI_Line ==	LINE_3
	SET_BIT(EXTI_Ptr->IMR , LINE_3) ;

#elif	EXTI_Line ==	LINE_4
	SET_BIT(EXTI_Ptr->IMR , LINE_4) ;

#elif	EXTI_Line ==	LINE_5
	SET_BIT(EXTI_Ptr->IMR , LINE_5) ;

#elif	EXTI_Line ==	LINE_6
	SET_BIT(EXTI_Ptr->IMR , LINE_6) ;

#elif	EXTI_Line ==	LINE_7
	SET_BIT(EXTI_Ptr->IMR , LINE_7) ;

#elif	EXTI_Line ==	LINE_8
	SET_BIT(EXTI_Ptr->IMR , LINE_8) ;

#elif	EXTI_Line ==	LINE_9
	SET_BIT(EXTI_Ptr->IMR , LINE_9) ;

#elif	EXTI_Line ==	LINE_10
	SET_BIT(EXTI_Ptr->IMR , LINE_10) ;

#elif	EXTI_Line ==	LINE_11
	SET_BIT(EXTI_Ptr->IMR , LINE_11) ;

#elif	EXTI_Line ==	LINE_12
	SET_BIT(EXTI_Ptr->IMR , LINE_12) ;

#elif	EXTI_Line ==	LINE_13
	SET_BIT(EXTI_Ptr->IMR , LINE_13) ;

#elif	EXTI_Line ==	LINE_14
	SET_BIT(EXTI_Ptr->IMR , LINE_14) ;

#elif	EXTI_Line ==	LINE_15
	SET_BIT(EXTI_Ptr->IMR , LINE_15) ;

#else

#error "Wrong Mode and Line Choice !!! ";

#endif


	/***************************	FOR_SENSE_MODE	***************************/

#if EXIT_Sense_Mode == Rising_Edage						// Notic In Rising

	SET_BIT( EXTI_Ptr -> RTSR, EXTI_Line );

#elif EXIT_Sense_Mode == FALLING_EDGE						// Notic In Falling

	SET_BIT( EXTI_Ptr -> FTSR, EXTI_Line );

#elif EXIT_Sense_Mode == On_Change						// Any Logical Change

	SET_BIT( EXTI_Ptr -> FTSR, EXTI_Line );
	SET_BIT( EXTI_Ptr -> RTSR, EXTI_Line );

#else
#error "Wrong Mode and Sense Mode Choice !!! ";

#endif
	/* At Init Make Disable */
	// CLR_BIT (EXTI_Ptr ->IMR ,EXTI_Line);   // For Power Consumission

}



/* Give The Function The Line To Enable It IntTERPUT  */
/**
 * @brief Give The Function The Line To Enable It IntTERPUT
 * 
 * @param Copy_u8Line 
 */
void EXIT_voidEnableEXIT(uint8 Copy_u8Line)
{

	SET_BIT (EXTI_Ptr ->IMR ,Copy_u8Line);

}





/* Give The Function The Line To Disable It IntTERPUT  */
/**
 * @brief Give The Function The Line To Disable It IntTERPUT
 * 
 * @param Copy_u8Line 
 */
void EXIT_voidDisableEXIT(uint8 Copy_u8Line)
{

	CLR_BIT (EXTI_Ptr ->IMR ,Copy_u8Line);

}




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
void EXIT_voidSoftwareInterrput(uint8 Copy_u8Line)
{
	SET_BIT(EXTI_Ptr->SWIER , Copy_u8Line);								  // It will Be Clear Alone

}


/* Function To Change Mode And Line At RunTime */
// Signal Latch == Init But Here I can Change The Line And Sense Mode
/**
 * @brief Function To Change Mode And Line At RunTime
 * Signal Latch == Init But Here I can Change The Line And Sense Mode
 * 
 * @param Copy_u8Line 
 * @param Copy_u8EXTISenseMode 
 */
void EXTI_voidSetSignalLatch( uint8 Copy_u8Line,  uint8 Copy_u8EXTISenseMode )
{


	switch(Copy_u8EXTISenseMode)
	{
	case (RISING_EDGE):
		SET_BIT( EXTI_Ptr -> RTSR, EXTI_Line );
		CLR_BIT( EXTI_Ptr -> FTSR, EXTI_Line );
		break;

	case (FALLING_EDGE):	
		SET_BIT( EXTI_Ptr -> FTSR, EXTI_Line );	   
		CLR_BIT( EXTI_Ptr -> RTSR, EXTI_Line );
		break;


	case (ON_CHANGE) :
	SET_BIT( EXTI_Ptr -> FTSR, EXTI_Line );
	SET_BIT( EXTI_Ptr -> RTSR, EXTI_Line );	  break;

	}
	SET_BIT(EXTI_Ptr->IMR ,Copy_u8Line ) ;
}

/**
 * @brief Set CallBack Function for EXTI0
 * 
 * @param ptr Called Function
 */
void EXTI0_voidSetCallBack( void (*ptr) (void))
{

	EXTI0_CallBack =ptr  ;	// Now The Global EXTI0_Call Will Point TO Any Functiom You Will Pass It To Function Only Give Function It's Name

}
/**
 * @brief Set CallBack Function for EXTI1
 * 
 * @param ptr Called Function
 */
void EXTI1_voidSetCallBack( void (*ptr) (void))
{

	EXTI1_CallBack =ptr  ;	// Now The Global EXTI1_Call Will Point TO Any Functiom You Will Pass It To Function Only Give Function It's Name

}
/**
 * @brief A function to configure EXTI port and line
 * 
 * @param Copy_u8ExtiLine 
 * @param Copy_u8GpioPortNum 
 */
void EXTI_voidSetEXTIConfiguration(uint8 Copy_u8ExtiLine , uint8 Copy_u8GpioPortNum )
{

	switch(Copy_u8ExtiLine)
	{
	case LINE_0:
		SYSCFG_EXTICR1 &=  EXTI_CONFG_MASK1;    //0xFFFFFFF0
		SYSCFG_EXTICR1 |=  Copy_u8GpioPortNum;
		break ;
	case LINE_1:
		SYSCFG_EXTICR1 &=  EXTI_CONFG_MASK2;    //0xFFFFFF0F
		SYSCFG_EXTICR1 |=  Copy_u8GpioPortNum<<4;
		break ;

	case LINE_3:
		SYSCFG_EXTICR1 &=  EXTI_CONFG_MASK3;    //0xFFFFF0FF
		SYSCFG_EXTICR1 |=  Copy_u8GpioPortNum<<8;
		break ;

	case LINE_4:
		SYSCFG_EXTICR1 &=  EXTI_CONFG_MASK4;    //0xFFF0FFF
		SYSCFG_EXTICR1 |=  Copy_u8GpioPortNum<<12;
		break ;
	default : /*Do Nothing*/   break ;
	}
}

/**
 * @brief EXTI0 IRQ Handler
 * 
 */
void EXTI0_IRQHandler(void)								// Clear The Pending Bit By Put '1' In PR

{

	EXTI0_CallBack();
	SET_BIT( EXTI_Ptr->PR , 0 );					// With Out That It Will Do INT Alaways

}

/**
 * @brief EXTI1 IRQ Handler
 * 
 */
void EXTI1_IRQHandler(void){

	EXTI1_CallBack();
	SET_BIT( EXTI_Ptr->PR , 0 );					// With Out That It Will Do INT Alaways
}


