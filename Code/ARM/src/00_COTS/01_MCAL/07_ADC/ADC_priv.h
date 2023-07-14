/**
 * @file ADC_priv.h
 * @author G3_DashBoard_Team
 * @brief Private file for ADC driver for stm32f401cc
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ADC_PRIV_H
#define ADC_PRIV_H

#define ADC_BASE_ADDRESS 0x40012000

#define ADC_ENABLE    1
#define ADC_DISABLE   0

#define ADC_RESOLUTION_12BIT   0b00
#define ADC_RESOLUTION_10BIT   0b01
#define ADC_RESOLUTION_8BIT    0b10
#define ADC_RESOLUTION_6BIT    0b11

#define ADC_RIGHT_ALLIGNMENT     0
#define ADC_LEFT_ALLIGNMENT      1

#define ADC_AFTER_REGULAR_CHANNELS    0
#define ADC_AFTER_EACH_CONVERSION     1

#define ADC_DMA_SINGLE_COPY   0
#define ADC_DMA_FREE_RUNNING_COPY   1

#define ADC_SINGLE_SHOT       0
#define ADC_CONTINOUS         1

#define ADC_SAMPLE_3_CYCLES        0b000
#define ADC_SAMPLE_15_CYCLES       0b001
#define ADC_SAMPLE_28_CYCLES       0b010
#define ADC_SAMPLE_56_CYCLES       0b011
#define ADC_SAMPLE_84_CYCLES       0b100
#define ADC_SAMPLE_112_CYCLES      0b101
#define ADC_SAMPLE_144_CYCLES      0b110
#define ADC_SAMPLE_480_CYCLES      0b111

#define ADC_CHANELL_0     0
#define ADC_CHANELL_1     1
#define ADC_CHANELL_2     2
#define ADC_CHANELL_3     3
#define ADC_CHANELL_4     4
#define ADC_CHANELL_5     5
#define ADC_CHANELL_6     6
#define ADC_CHANELL_7     7

typedef struct
{
	volatile uint32 SR;
	volatile uint32 CR1;
	volatile uint32 CR2;
	volatile uint32 SMPR1;
	volatile uint32 SMPR2;
	volatile uint32 JOFR1;
	volatile uint32 JOFR2;
	volatile uint32 JOFR3;
	volatile uint32 JOFR4;
	volatile uint32 HTR;
	volatile uint32 LTR;
	volatile uint32 SQR1;
	volatile uint32 SQR2;
	volatile uint32 SQR3;
	volatile uint32 JSQR;
	volatile uint32 JDR1;
	volatile uint32 JDR2;
	volatile uint32 JDR3;
	volatile uint32 JDR4;
	volatile uint32 DR;
} ADC_MemMap;


typedef struct{
	volatile uint32 CSR;
	volatile uint32 CCR;
	volatile uint32 CDR;
}ADC_Common_reg;


#define ADC ((volatile ADC_MemMap* ) (ADC_BASE_ADDRESS))

#define ADC_COMMON ((volatile ADC_Common_reg* )(ADC_BASE_ADDRESS + 0x300))


#endif
