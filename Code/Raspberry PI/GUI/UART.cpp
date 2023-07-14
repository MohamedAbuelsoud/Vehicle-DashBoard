/**
 * @file UART.cpp
 * @author G3_DashBoard_Team
 * @brief UART Module is for communication with the other ECU through UART. 
 *        It's responsible for receiving data and updating reading values. 
 *        It consists of two functions. First one (UARTvidInit) is a UART initialization function 
 *        to setup the required configuration. 
 *        Second one (UARTvidReceive) is a function that receives data from UART and assign it to reading 
 * @version 0.1
 * @date 2023-02-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <sys/ioctl.h>

uint32 sfd;
extern uint8 u8SpeedValue;
extern uint8 u8TempValue;
extern uint8 u8BatteryValue;
extern uint8 u8FuelValue;
extern uint8 u8AntiLockFlag;
extern uint8 u8SeatBeltFlag;
/**
 * @brief UART initialization function 
 *        to setup the required configuration in Raspberry pi.
 * 
 */
void UARTvidInit(void)
{
    system("sudo systemctl stop serial-getty@ttyAMA0.service");
    sfd = open("/dev/serial0", O_RDWR | O_NOCTTY);
    if (sfd == -1)
    {
        printf("Error no is : %d\n", errno);
        printf("Error description is : %s\n", strerror(errno));
    };
    struct termios options;
    tcgetattr(sfd, &options);

    cfsetspeed(&options, B9600);
    cfmakeraw(&options);
    options.c_cflag &= ~CSTOPB;
    options.c_cflag |= PARENB;
    options.c_cflag |= PARODD;
    options.c_cflag |= CLOCAL;
    options.c_cflag |= CREAD;
    options.c_cc[VTIME]=.01;
    options.c_cc[VMIN]=100;
    tcsetattr(sfd, TCSANOW, &options);
}
/**
 * @brief a Function that receives data from UART and assign it to reading
 * 
 * @return void* 
 */
void* UARTvidReceive(void*)
{
    uint8 DATA[10];
    uint8 CRC;
    uint8 i = 0;
    uint32 count=0;
    while (1)
        {
            uint32 Temp = 0;
            uint32 Fuel = 0;
            uint32 Bms = 0;
            uint32 Speed = 0;
            uint8 ABS = 0;
            uint8 SeatBelt = 0;
            do
            {
                count = read(sfd, &DATA[0] , 1);
            }while(DATA[0]!=0x20 && DATA[0]!=0x21 && DATA[0]!=0x22 && DATA[0]!=0x23 && DATA[0]!=0x24 && DATA[0]!=0x25);

            count = read(sfd, &DATA[1] , 1); 
            count = read(sfd, DATA + 2, DATA[1]+1);
            if (count != 0)
            {
                if (DATA[0] == 0x20)
                {

                    CRC = DATA[1];
                    for (i = 2; i < DATA[1]+2; i++)
                    {
                        Temp = (Temp << 8) | (DATA[i]);
                        CRC ^= DATA[i];
                    }
                    if (CRC == DATA[DATA[1] + 2])
                    {
                        u8TempValue = Temp;
                    }
                }

                else if (DATA[0] == 0x21)
                {

                    CRC = DATA[1];
                    for (i = 2; i < DATA[1] + 2; i++)
                    {
                        Fuel = (Fuel << 8) | (DATA[i]);
                        CRC ^= DATA[i];
                    }
                    if (CRC == DATA[DATA[1] + 2])
                    {
                        u8FuelValue = Fuel;
                    }
                }

                else if (DATA[0] == 0x22)
                {

                    CRC = DATA[1];
                    for (i = 2; i < DATA[1] + 2; i++)
                    {
                        Bms = (Bms << 8) | (DATA[i]);
                        CRC ^= DATA[i];
                    }
                    if (CRC == DATA[DATA[1] + 2])
                    {
                        u8BatteryValue = Bms;
                    }
                }
                else if (DATA[0] == 0x23)
                {

                    CRC = DATA[1];
                    for (i = 2; i < DATA[1] + 2; i++)
                    {
                        Speed = (Speed << 8) | (DATA[i]);
                        CRC ^= DATA[i];
                    }
                    if (CRC == DATA[DATA[1] + 2])
                    {
                        u8SpeedValue = Speed;
                    }
                }
                else if (DATA[0] == 0x24)
                {

                    CRC = DATA[1];
                    for (i = 2; i < DATA[1] + 2; i++)
                    {
                        ABS = (ABS << 8) | (DATA[i]);
                        CRC ^= DATA[i];
                    }
                    if (CRC == DATA[DATA[1] + 2])
                    {
                        u8AntiLockFlag = ABS;
                    }
                }
                else if (DATA[0] == 0x25)
                {

                    CRC = DATA[1];
                    for (i = 2; i < DATA[1] + 2; i++)
                    {
                        SeatBelt = (SeatBelt << 8) | (DATA[i]);
                        CRC ^= DATA[i];
                    }
                    if (CRC == DATA[DATA[1] + 2])
                    {
                        u8SeatBeltFlag = SeatBelt;
                    }
                }
            }
        }
}
