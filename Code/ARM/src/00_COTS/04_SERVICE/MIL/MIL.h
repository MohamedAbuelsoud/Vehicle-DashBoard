/*
 * MIL.h
 *
 *  Created on: Feb 19, 2023
 *      Author: AA
 */

#ifndef MIL_H
#define MIL_H

void MIL_voidInit(void);

uint8 ABS_u8GetData(void);
void ABS_voidSendData(uint8 u8ABSCpy);

uint8 SEATBELT_u8GetData(void);
void SEATBELT_voidSendData(uint8 u8SeatBeltCpy);

#endif /* 00_COTS_04_SERVICE_MIL_MIL_H_ */
