/**
 * @file DMA_Cfg.h
 * @author G3_DashBoard_Team
 * @brief Configuration file for DMA driver for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef DMA_CFG_H
#define DMA_CFG_H



#define DMA_DIRECT_MODE_INT          DMA_DISABLE
#define DMA_TANSFERE_ERROR_INT       DMA_DISABLE
#define DMA_HALF_TANSFERE_COMP_INT   DMA_DISABLE
#define DMA_TANSFERE_COMP_INT        DMA_DISABLE
#define DMA_TRANSFERE_DIRECTION      PREI_TO_MEM
#define DMA_CIRCULAR_MODE            DMA_ENABLE
#define DMA_PERI_INC_MODE            DMA_DISABLE
#define DMA_DATA_INC_MODE            DMA_ENABLE
#define DMA_PERI_DATA_SIZE           WORD
#define DMA_DATA_DATA_SIZE			 WORD
#define DMA_PRIORITY_LEVEL           DMA_VERY_HIGH
#define DMA_CHANNEL                  DMA_CHANNEL_0

#endif
