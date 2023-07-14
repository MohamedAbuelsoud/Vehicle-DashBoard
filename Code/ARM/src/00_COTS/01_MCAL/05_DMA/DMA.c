/**
 * @file DMA.c
 * @author G3_DashBoard_Team
 * @brief Program file for DMA driver for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../../00_LIB/STD_Types.h"
#include "../../00_LIB/BIT_Math.h"

#include "../05_DMA/DMA.h"
#include "../05_DMA/DMA_Cfg.h"
#include "../05_DMA/DMA_Priv.h"

/**
 * @brief Initialize DMA
 * 
 * @param u8SreamIDCpy Stream ID
 */
void DMA_voidInit(uint8 u8SreamIDCpy)
{
	/* 1- Before Any Config The Bit Of EN Must = 0 ,It must Be Disable*/

	/*
	if((DMA_2->CHANNEL[u8SreamIDCpy].CR) == 1 )
	{

		(DMA_2->CHANNEL[u8SreamIDCpy].CR) &=~(1U<<0);
		while((DMA_2->CHANNEL[u8SreamIDCpy].CR) == 1);
	}*/


	/*INTERRUPTS*/
		DMA_2->CHANNEL[u8SreamIDCpy].CR |= (DMA_DIRECT_MODE_INT << 1);
		DMA_2->CHANNEL[u8SreamIDCpy].CR |= (DMA_TANSFERE_ERROR_INT << 2);
		DMA_2->CHANNEL[u8SreamIDCpy].CR |= (DMA_HALF_TANSFERE_COMP_INT << 3);
		DMA_2->CHANNEL[u8SreamIDCpy].CR |= (DMA_TANSFERE_COMP_INT << 4);


		/*DATA TRANSFERE DIRECTION*/
		DMA_2->CHANNEL[u8SreamIDCpy].CR |= (DMA_TRANSFERE_DIRECTION << 6);

		/*CIRCULAR MODE*/
		DMA_2->CHANNEL[u8SreamIDCpy].CR |= (DMA_CIRCULAR_MODE << 8);

		/*INCREMENT CONFIG*/
		DMA_2->CHANNEL[u8SreamIDCpy].CR |= (DMA_PERI_INC_MODE << 9);
		DMA_2->CHANNEL[u8SreamIDCpy].CR |= (DMA_DATA_INC_MODE << 10);

		/*PERI AND MEM DATA SIZE*/

		DMA_2->CHANNEL[u8SreamIDCpy].CR |= (DMA_PERI_DATA_SIZE << 11);
		DMA_2->CHANNEL[u8SreamIDCpy].CR |= (DMA_DATA_DATA_SIZE << 13);

		/* 3-SoftWare Priority  */
		DMA_2->CHANNEL[u8SreamIDCpy].CR |= (DMA_PRIORITY_LEVEL << 16);

		/*CHANELS*/
		DMA_2->CHANNEL[u8SreamIDCpy].CR |= (DMA_CHANNEL << 25);


}
/**
 * @brief Set Address
 * 
 * @param pu32PeriReg Pripheral Register
 * @param pu32DataReg Data Register
 * @param u32SizeCpy Size
 * @param u8SreamIDCpy Stream ID
 */
void DMA_voidSetAddress(uint32 *pu32PeriReg , uint32 *pu32DataReg , uint32 u32SizeCpy ,uint8 u8SreamIDCpy )
{

	DMA_2->CHANNEL[u8SreamIDCpy].PAR= (uint32)pu32PeriReg;
	DMA_2->CHANNEL[u8SreamIDCpy].M0AR=(uint32)pu32DataReg;
	DMA_2->CHANNEL[u8SreamIDCpy].NDTR=u32SizeCpy;

}
/**
 * @brief Enable Stream
 * 
 * @param u8SreamIDCpy Stream ID
 */
void DMA_voidStreamEnable(uint8 u8SreamIDCpy )
{

	SET_BIT( DMA_2->CHANNEL[ u8SreamIDCpy ].CR , 0 );
}

