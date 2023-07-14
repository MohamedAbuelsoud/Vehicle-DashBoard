/**
 * @file STD_Types.h
 * @author G3_DashBoard_Team
 * @brief typedef for datatpes
 * @version 0.1
 * @date 2023-02-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef  STD_TYPES_H
#define  STD_TYPES_H

typedef   unsigned char      uint8  ;
typedef   unsigned short int uint16 ;
typedef   unsigned long  int uint32 ;
typedef   signed char        sint8  ;
typedef   signed short int   sint16 ;
typedef   signed long  int   sint32 ;
typedef   float              float32 ;
typedef   double             float64 ;
typedef   long double        float128 ;


typedef void(*pf)(void);

typedef void (*pfU16) (uint16*);

typedef void (*pf2xU16) (uint8*,uint8*);

typedef void (*pf2xF32)(float32*, float32*);

typedef enum 
{
	EOK  ,
	ENOK  ,
	PARAM_OUT_RANGE,
	PARAM_NULL_PTR 
}tenuErrorStatus;


typedef enum {
	PROCESS_OK,
	PROCESS_NOT_OK,
	ARBITRATION_LOST,
	START_ERROR,
	DID_NOT_ACK,
	TIME_OUT
}teni2CErrorStatus;


#define NULL_PTR (void *) 0

#endif


