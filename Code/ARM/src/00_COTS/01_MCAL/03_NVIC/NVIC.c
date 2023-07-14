/**
 * @file NVIC.c
 * @author G3_DashBoard_Team
 * @brief Program file for NVIC driver for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../../00_LIB/STD_Types.h"
#include "../../00_LIB/BIT_Math.h"

#include "../03_NVIC/NVIC.h"
#include "../03_NVIC/NVIC_Cfg.h"
#include "../03_NVIC/NVIC_Priv.h"



uint8 NVIC_G_u8GroupMode = NVIC_GroupMode_g16s0;

/**
 * @brief Enable peripheral Interrupt
 * 
 * @param copy_u8IntNum Interrupt name/ID
 */
void NVIC_voidEnableInterrupt(uint8 copy_u8IntNum)
{
	NVIC_REG->ISER[copy_u8IntNum / 32] = (1U << copy_u8IntNum % 32);
//	NVIC_REG->ISER[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));

}

/**
 * @brief Disable peripheral Interrupt
 * 
 * @param copy_u8IntNum Interrupt name/ID
 */
void NVIC_voidDisableInterrupt(uint8 copy_u8IntNum)
{
	NVIC_REG->ICER[copy_u8IntNum / 32] = (1U << copy_u8IntNum % 32);
}

/**
 * @brief Enable Interrupt Pending
 * 
 * @param copy_u8IntNum Interrupt name/ID
 */
void NVIC_voidEnableInterruptPending(uint8 copy_u8IntNum)
{
	NVIC_REG->ISPR[copy_u8IntNum / 32] = (1U << copy_u8IntNum % 32);
}
/**
 * @brief Disable Interrupt Pending
 * 
 * @param copy_u8IntNum Interrupt name/ID
 */
void NVIC_voidDisableInterruptPinding(uint8 copy_u8IntNum)
{
	NVIC_REG->ICPR[copy_u8IntNum / 32] = (1U << copy_u8IntNum % 32);
}

/**
 * @brief A function to check weather the pripheral interrupt active or not
 * 
 * @param copy_u8IntNum Interrupt name/ID
 * @return uint8 Interrupt Active Flag
 */
uint8 NVICE_u8IsInterruptActive(uint8 copy_u8IntNum)
{
	return GET_BIT(NVIC_REG->IABR[copy_u8IntNum / 32], copy_u8IntNum);
}

/**
 * @brief Initialize Interrupt Group
 * 
 * @param copy_GropMode Group mode
 */
void NVIC_voidInitInterruptGroup(NVIC_GroupMode_t copy_GropMode)
{
		 //Read  SCB_AIRCR First reset the regester first
	SCB_AIRCR = (VECTKEY | (copy_GropMode << 8));
}

/**
 * @brief A function to adjust Interrupt Priority
 * 
 * @param copy_u8IntNum Interrupt name/ID
 * @param copy_GropMode Group Mode
 * @param copy_u8IntGroup Interrupt Group
 * @param copy_u8IntPrio Interrupt Priority
 * @return * void 
 */
void NVIC_voidSetInterruptPriority(uint8 copy_u8IntNum,NVIC_GroupMode_t copy_GropMode, uint8 copy_u8IntGroup, uint8 copy_u8IntPrio)
{
	// copy_u8IntPrio  ----------> Sub-Group.
	uint8 L_u8PrioValue = 0;
	switch(copy_GropMode){
		//x:Group.
		//o:SubGroup 
		//xxxx---->16,1.
		case NVIC_GroupMode_g16s0 : L_u8PrioValue =  copy_u8IntGroup; break;
		//xxxo
		case NVIC_GroupMode_g8s2  : L_u8PrioValue = (copy_u8IntGroup << 1) | copy_u8IntPrio; break;
		//xxoo---->4,4.
		case NVIC_GroupMode_g4s4  : L_u8PrioValue = (copy_u8IntGroup << 2) | copy_u8IntPrio; break;
		//xooo---->2,8
		case NVIC_GroupMode_g2s8  : L_u8PrioValue = (copy_u8IntGroup << 3) | copy_u8IntPrio; break;
		//oooo---->1,16
		case NVIC_GroupMode_g0s16 : L_u8PrioValue =  copy_u8IntPrio; break;
	}

	NVIC_REG->IPR[copy_u8IntNum] = L_u8PrioValue << 4;
}

/**
 * @brief A function to generate SW Interrupt
 * 
 * @param copy_u8IntNum Interrupt name/ID
 */
void NVIC_voidGenerateSoftwareInterrupt(uint8 copy_u8IntNum)
{
	NVIC_REG->STIR = (copy_u8IntNum << 4);
}
