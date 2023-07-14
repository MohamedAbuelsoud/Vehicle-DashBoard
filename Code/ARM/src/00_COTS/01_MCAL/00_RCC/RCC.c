	/**
 * @file RCC.c
 * @author G3_DashBoard_Team
 * @brief Program file for RCC driver for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include"../../00_LIB/STD_Types.h"
#include"../../00_LIB/BIT_Math.h"


#include "../00_RCC/RCC.h"
#include "../00_RCC/RCC_cfg.h"
#include "../00_RCC/RCC_priv.h"




/**
 * @brief RCC Initialization Function
 * 
 */
void RCC_voidInit(void)
{
#if RCC_SYSTEM_SOURCE == RCC_HSE
	SET_BIT(RCC_CR, 16);

	#if RCC_HSE_CSS == DISABLE
		CLR_BIT(RCC_CR, 19);
	#else
		SET_BIT(RCC_CR, 19);
	#endif

	#if RCC_HSE_BYPASS == DISABLE
		CLR_BIT(RCC_CR, 18);
	#else
		SET_BIT(RCC_CR, 18);
	#endif
		/* 3- CLK SYS --> HSE */
		SET_BIT(MRCC->CFGR, 0U);
		CLR_BIT(MRCC->CFGR, 1U);

#elif RCC_SYSTEM_SOURCE == RCC_PLL
	SET_BIT(RCC_CR, 24);
	/* 4- System Clk  PLL */
	CLR_BIT(MRCC->CFGR,0U);
	SET_BIT(MRCC->CFGR,1U);

#else
	SET_BIT(RCC_CR, 0);
	/* 2- CLK SYS --> HSI */
	CLR_BIT(RCC_CFGR, 0U);
	CLR_BIT(RCC_CFGR, 1U);

#endif


	RCC_PLLCFGR |= RCC_PLL_SOURCE << 22;
	RCC_PLLCFGR |= RCC_PLLP_VALUE << 16;
	RCC_PLLCFGR |= RCC_PLLN_VALUE << 06;
	RCC_PLLCFGR |= RCC_PLLM_VALUE ;


	RCC_CFGR |= RCC_AHB_PRESCALLER << 4;
	RCC_CFGR |= RCC_APB1_PRESCALLER << 10;
	RCC_CFGR |= RCC_APB2_PRESCALLER << 13;
	RCC_CFGR |= RCC_MCO1_STATUS << 21;
	RCC_CFGR |= RCC_MCO1_STATUS << 24;
	RCC_CFGR |= RCC_MCO2_SPEED << 27;
	RCC_CFGR |= RCC_MCO2_STATUS << 30;

}
/**
 * @brief A function to check the current clock source
 * 
 * @return uint8 clock source
 */
uint8 RCC_u8CheckClkSource(void)
{
	uint8 u8ClockSourceLoc=0;
	u8ClockSourceLoc = GET_BIT(RCC_CFGR, 2);
	u8ClockSourceLoc |= GET_BIT(RCC_CFGR, 3) << 1;

	return u8ClockSourceLoc;
}

/**
 * @brief A function to enable peripheral clock
 * 
 * @param u32PrephiralNameCpy peripheral name/ID 
 */
void RCC_voidEnablePeriphralClock(uint32 u32PrephiralNameCpy)
{
	if ((u32PrephiralNameCpy >= 0) && (u32PrephiralNameCpy < 32))
	{
		SET_BIT(RCC_AHB1ENR, u32PrephiralNameCpy);
	}
	else if ((u32PrephiralNameCpy >= 32) && (u32PrephiralNameCpy < 64))
	{
		SET_BIT(RCC_AHB2ENR, u32PrephiralNameCpy % 32);
	}
	else if ((u32PrephiralNameCpy >= 64) && (u32PrephiralNameCpy < 96))
	{
		SET_BIT(RCC_APB1ENR, u32PrephiralNameCpy % 32);
	}
	else if ((u32PrephiralNameCpy >= 96) && (u32PrephiralNameCpy < 128 ))
	{
		SET_BIT(RCC_APB2ENR, u32PrephiralNameCpy % 32);
	}

}
/**
 * @brief A function to disable peripheral clock
 * 
 * @param u32PrephiralNameCpy peripheral name/ID 
 */
void RCC_voidDisablePeriphralClock(uint8 u32PrephiralNameCpy)
{
	if ((u32PrephiralNameCpy >= 0) && (u32PrephiralNameCpy < 32))
	{
		CLR_BIT(RCC_AHB1ENR, u32PrephiralNameCpy);
	}
	else if ((u32PrephiralNameCpy >= 32) && (u32PrephiralNameCpy < 64))
	{
		CLR_BIT(RCC_AHB2ENR, u32PrephiralNameCpy % 32);
	}
	else if ((u32PrephiralNameCpy >= 64) && (u32PrephiralNameCpy < 96))
	{
		CLR_BIT(RCC_APB1ENR, u32PrephiralNameCpy % 32);
	}
	else if ((u32PrephiralNameCpy >= 96) && (u32PrephiralNameCpy < 128))
	{
		CLR_BIT(RCC_APB2ENR, u32PrephiralNameCpy % 32);
	}

}
/**
 * @brief Enable Internal clock
 * 
 */
void RCC_HSIEnable(void)
{
	SET_BIT(RCC_CR, 0);
}
/**
 * @brief disable Internal clock
 * 
 */
void RCC_HSIDisable(void)
{
	CLR_BIT(RCC_CR, 0);
}
/**
 * @brief Enable External clock
 * 
 * @param u8CssStatus CSS
 * @param u8HsebyoStatus HSE bypass
 */
void RCC_HSEEnable(uint8 u8CssStatus, uint8 u8HsebyoStatus)
{
	SET_BIT(RCC_CR, 16);

    if (u8CssStatus == DISABLE)
	{
    	CLR_BIT(RCC_CR, 19);
	}
    else
	{
    	SET_BIT(RCC_CR, 19);
	}

    if(u8HsebyoStatus == DISABLE)
	{
    	CLR_BIT(RCC_CR, 18);
	}
    else
	{
    	SET_BIT(RCC_CR, 18);
	}
}
/**
 * @brief Disable external clock
 * 
 */
void RCC_HSEDisable(void)
{
	CLR_BIT(RCC_CR, 16);
}
/**
 * @brief enable PLL clock
 * 
 */
void RCC_PLLEnable(void)
{
	SET_BIT(RCC_CR, 24);
}
/**
 * @brief disable PLL clock
 * 
 */
void RCC_PLLDisable(void)
{
	CLR_BIT(RCC_CR, 24);
}
/**
 * @brief choose system clock
 * 
 * @param u8ChangeSystemClock system clock name/ID
 */
void RCC_voidSetSystemClock(uint8 u8ChangeSystemClock)
{
	RCC_CFGR |= u8ChangeSystemClock & 0x3;
}
