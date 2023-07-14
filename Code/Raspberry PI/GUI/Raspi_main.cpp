/**
 * @file Raspi_main.cpp
 * @author G3_DashBoard_Team
 * @brief this main function is the entry point of the Raspberry pi code
 * @version 0.1
 * @date 2023-02-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "widget.h"
#include <pthread.h>
#include <QApplication>
#include "UART.h"
/**
 * @brief thread1 to run UART function on other thread
 * 
 */
pthread_t thread1;
/**
 * @brief this main function is the entry point of the Raspberry pi code
 * 
 * @param argc how many input parameters from terminal call
 * @param argv the input parameters
 * @return int 0 if no error and -1 if there's error
 */
int main(int argc, char *argv[])
{
    /**
     * @brief The QApplication class manages the GUI application's
     * control flow and main settings.
     * QApplication contains the main event loop,
     * where all events from the window system and other sources are processed and dispatched.
     * It also handles the application's initialization, finalization,
     * and provides session management. In addition,
     * QApplication handles most of the system-wide and application-wide settings.
     * For any GUI application using Qt, there is precisely one QApplication object,
     *  no matter whether the application has 0, 1, 2 or more windows at any given time.
     * @return QApplication
     *
     * Widgets are the primary elements for creating user interfaces in Qt.
     * Widgets can display data and status information, receive user input,
     * and provide a container for other widgets that should be grouped together.
     * A widget that is not embedded in a parent widget is called a window.
     */
    QApplication a(argc, argv);
    /**
     * @brief to mask the cursor on screen
     * 
     * @return QCursor 
     */
    QCursor Cursor(Qt::BlankCursor);
    QApplication::setOverrideCursor(Cursor);
    QApplication::changeOverrideCursor(Cursor);
    Widget w;

    UARTvidInit();
    /**
     * @brief Creating another thread to receive UART data
     * 
     */
    pthread_create( &thread1, NULL, UARTvidReceive,NULL);
    /**
     * @brief to show widget at full screen
     * 
     */
    w.showFullScreen();

    return a.exec();
}


