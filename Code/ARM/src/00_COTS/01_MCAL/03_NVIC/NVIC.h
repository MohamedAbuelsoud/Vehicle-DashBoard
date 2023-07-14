/**
 * @file NVIC.h
 * @author G3_DashBoard_Team
 * @brief Interface file for NVIC driver for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef NVIC_H
#define NVIC_H


#define WWDG           0
#define NVIC_EXTI0     6



typedef enum{
    //SCB.
    //-xx
    //x--
    //x-x
    //xx-
    //xxx
    NVIC_GroupMode_g16s0 = 3,
    NVIC_GroupMode_g8s2,
    NVIC_GroupMode_g4s4,
    NVIC_GroupMode_g2s8,
    NVIC_GroupMode_g0s16
}NVIC_GroupMode_t;

/**
 * @brief Enable peripheral Interrupt
 * 
 * @param copy_u8IntNum Interrupt name/ID
 */
void NVIC_voidEnableInterrupt(uint8 copy_u8IntNum);
/**
 * @brief Disable peripheral Interrupt
 * 
 * @param copy_u8IntNum Interrupt name/ID
 */
void NVIC_voidDisableInterrupt(uint8 copy_u8IntNum);

//Trigger Interrupt.
/**
 * @brief Enable Interrupt Pending
 * 
 * @param copy_u8IntNum Interrupt name/ID
 */
void NVIC_voidEnableInterruptPending(uint8 copy_u8IntNum);
/**
 * @brief Disable Interrupt Pending
 * 
 * @param copy_u8IntNum Interrupt name/ID
 */
void NVIC_voidDisableInterruptPinding(uint8 copy_u8IntNum);
//Get Stuts.
/**
 * @brief A function to check weather the pripheral interrupt active or not
 * 
 * @param copy_u8IntNum Interrupt name/ID
 * @return uint8 Interrupt Active Flag
 */
uint8 NVIC_u8IsInterruptActive(uint8 copy_u8IntNum);

/**
 * @brief A function to adjust Interrupt Priority
 * 
 * @param copy_u8IntNum Interrupt name/ID
 * @param copy_GropMode Group Mode
 * @param copy_u8IntGroup Interrupt Group
 * @param copy_u8IntPrio Interrupt Priority
 * @return * void 
 */
void NVIC_voidSetInterruptPriority(uint8 copy_u8IntNum,
                                    NVIC_GroupMode_t copy_GropMode,
                                    uint8 copy_u8IntGroup,
                                    uint8 copy_u8IntPrio);

/**
 * @brief Initialize Interrupt Group
 * 
 * @param copy_GropMode Group mode
 */
void NVIC_voidInitInterruptGroup(NVIC_GroupMode_t copy_GropMode);
/**
 * @brief A function to generate SW Interrupt
 * 
 * @param copy_u8IntNum Interrupt name/ID
 */
void NVIC_voidGenerateSoftwareInterrupt(uint8 copy_u8IntNum);

#endif
