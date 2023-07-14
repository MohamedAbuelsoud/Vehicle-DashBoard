/**
 * @file ARM_main.c
 * @author G3_DashBoard_Team
 * @brief this main function is the entry point of the ARM code
 * @version 0.1
 * @date 2023-02-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "00_LIB/STD_Types.h"
#include "00_LIB/BIT_Math.h"

#include "02_HAL/System_Init/System_init.h"
#include "04_SERVICE/Temp/Temp.h"
#include "04_SERVICE/BMS/BMS.h"
#include "04_SERVICE/Fuel/Fuel.h"
#include "04_SERVICE/Speed/Speed.h"


/**
 * @brief Temperature Reading
 * 
 */
uint8 Temp=0;
/**
 * @brief Fuel Reading
 * 
 */
uint8 Fuel=0;
/**
 * @brief Battery Reading
 * 
 */
uint8 Bms=0;
/**
 * @brief Speed Reading
 * 
 */
uint8 Speed=0;
/**
 * @brief ABS Reading
 * 
 */


uint8 ABS=0;
/**
 * @brief Seat Belt Reading
 * 
 */
uint8 SeatBelt=0;


/**
 * @brief this main function is the entry point of the ARM code
 * 
 */



void main (void)
{

	SYS_voidInit();

	while(1)
	{
		/**
		 * @brief Get Temperature Reading
		 * 
		 */
		Temp=TEMP_u8GetData();
		/**
		 * @brief Send Temperature Reading through UART
		 * 
		 */
		TEMP_voidSendData(Temp);
		/**
		 * @brief Get Fuel Reading
		 * 
		 */
		Fuel=FUEL_u8GetData();
		/**
		 * @brief Send Fuel Reading through UART
		 * 
		 */
		FUEL_voidSendData(Fuel);
		/**
		 * @brief Get Battery Reading
		 * 
		 */
		Bms=BMS_u8GetData();
		/**
		 * @brief Send Battery Reading through UART
		 * 
		 */		
		BMS_voidSendData(Bms);
		/**
		 * @brief Get Speed Reading
		 * 
		 */
		Speed=SPEED_u8GetData();
		/**
		 * @brief Send Speed Reading through UART
		 * 
		 */				
		SPEED_voidSendData(Speed);
		/**
		 * @brief  Get ABS READING
		 * 
		 * 
		 */				


		ABS = !ABS_u8GetData();
		/**
		 * @brief Send ABS Reading through UART
		 * 
		 */				

		ABS_voidSendData(ABS);
		/**
		 * @brief Get SeatBelt Reading
		 * 
		 */				

		SeatBelt = !SEATBELT_u8GetData();
		/**
		 * @brief Send Seatbelt Reading through UART
		 * 
		 */				

		SEATBELT_voidSendData(SeatBelt);



	}
}
