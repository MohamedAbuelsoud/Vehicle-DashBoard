/**
 * @file DMA_Priv.h
 * @author G3_DashBoard_Team
 * @brief Private file for DMA driver for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef DMA_PRIV_H
#define DMA_PRIV_H

#define DMA_DISABLE 0
#define DMA_ENABLE  1


//DMA CHANNELS
#define DMA_CHANNEL_0  (0b000)
#define DMA_CHANNEL_1  (0b001)
#define DMA_CHANNEL_2  (0b010)
#define DMA_CHANNEL_3  (0b011)
#define DMA_CHANNEL_4  (0b100)
#define DMA_CHANNEL_5  (0b101)
#define DMA_CHANNEL_6  (0b110)
#define DMA_CHANNEL_7  (0b111)



//DMA Configuration
//Direction
#define PREI_TO_MEM  0b00
#define MEM_TO_PERI  0b01
#define MEM_TO_MEM   0b10

//Size
#define BYTE       0b00
#define HALF_WORD  0b01
#define WORD       0b10

//Channel Priority
#define DMA_LOW         0b00
#define DMA_MEDIUM      0b01
#define DMA_HIGH        0b10
#define DMA_VERY_HIGH   0b11

#define BASE_ADRESS_DMA_1            0x40026000
#define BASE_ADRESS_DMA_2            0x40026400


typedef struct
{
	volatile uint32 CR;
	volatile uint32 NDTR;
	volatile uint32 PAR;
	volatile uint32 M0AR;
	volatile uint32 M1AR;
	volatile uint32 FCR;

}DMA_CHANNELS;


typedef struct
{
	volatile uint32 LISR;
	volatile uint32 HISR;
	volatile uint32 LIFCR;
	volatile uint32 HIFCR;
	volatile DMA_CHANNELS CHANNEL[8];

}DMA;


#define DMA_1 ( ( volatile DMA * ) BASE_ADRESS_DMA_1 )

#define DMA_2 ( ( volatile DMA * ) BASE_ADRESS_DMA_2 )

#endif
