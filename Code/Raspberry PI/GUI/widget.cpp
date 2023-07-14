/**
 * @file widget.cpp
 * @author G3_DashBoard_Team
 * @brief module is responsible for data visualization. It uses QT frame work.
 *        First we designed the GUI structure and appearance and added the required objects 
 *        then we added a timer as a signal to call a slot regularly. 
 *        The slot is (WidgetvidUpdateValues) a function that 
 *        updates data in GUI according to reading variables updated from UART module.
 * @version 0.1
 * @date 2023-02-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
#include <QTimer>
#include <QString>
#include <QPainter>
#include <pthread.h>

extern pthread_t thread1;
/**
 * @brief Variable resembles speed
 * 
 */
uint8 u8SpeedValue=0;
/**
 * @brief Variable resembles temperature
 * 
 */
uint8 u8TempValue=0;
/**
 * @brief Variable resembles battery
 * 
 */
uint8 u8BatteryValue=0;
/**
 * @brief Variable resembles fuel
 * 
 */
uint8 u8FuelValue=0;
/**
 * @brief Variable resembles antilock flag
 * 
 */
uint8 u8AntiLockFlag=0;
/**
 * @brief Variable resembles seatbelt flag
 * 
 */
uint8 u8SeatBeltFlag=0;


/**
 * @brief Construct a new Widget:: Widget object
 *        Setting up UI and its objects
 * 
 * @param parent 
 */
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("Dash Board");
//    resize(1000,600);

    SetBackground();

    BatteryInit ();
    SeatbeltInit ();
    AntiLockBrakeInit ();
    SpeedInit ();
    TempInit ();
    FuelInit ();

    /*Timer to update call WidgetvidUpdateValues() regularly*/
    QTimer *Timer= new QTimer(this);
    connect(Timer, SIGNAL(timeout()),this, SLOT(WidgetvidUpdateValues()));
    Timer->start(50);
}
/**
 * @brief Destroy the Widget:: Widget object, here we join the two threads at the end of the program
 * 
 */
Widget::~Widget()
{
    pthread_join( thread1, NULL);
    pthread_exit(NULL);
    delete ui;
}
/**
 * @brief WidgetvidUpdateValues is a function to update the sensor readings in GUI
 * 
 */
void Widget::WidgetvidUpdateValues()
{
    TempUpdate ();
    BatteryUpdate ();
    SpeedUpdate ();
    FuelUpdate ();
    AntiLockBrakeUpdate ();
    SeatbeltUpdate ();
}
/**
 * @brief A function to set the background of the GUI
 * 
 */
void Widget::SetBackground (void)
{
    BackGround= new QLabel(this);
    BackGround->setPixmap(QPixmap(":/Images/bg.png"));
}
/**
 * @brief A function to Initailize speed objects and labels
 * 
 */
void Widget::SpeedInit (void)
{
    SpeedScale= new QLabel(this);
    SpeedScale->setPixmap(QPixmap(":/Images/speed.png"));
    SpeedScale->setGeometry(350,100,300,300);

    SpeedScalepix=QPixmap(":/Images/pointer2.png");
    QPixmap SpeedrotatedPixmap(SpeedScalepix.size());
    SpeedrotatedPixmap.fill(QColor::fromRgb(0, 0, 0, 0));
    QPainter* Speedpainter = new QPainter(&SpeedrotatedPixmap);
    QSize Speedsize = SpeedScalepix.size();
    Speedpainter->translate(Speedsize.height()/2,Speedsize.height()/2);
    Speedpainter->rotate(0);  //max is
    Speedpainter->translate(-Speedsize.height()/2,-Speedsize.height()/2);
    Speedpainter->drawPixmap(0, 0, SpeedScalepix);
    Speedpainter->end();
    delete Speedpainter;
    SpeedPointer= new QLabel(this);
    SpeedPointer->setGeometry(388,126,300,300);
    SpeedPointer->setPixmap(SpeedrotatedPixmap);
}
/**
 * @brief A function to Initailize temperature objects and labels
 * 
 */
void Widget::TempInit (void)
{
    EngineTemp= new QLabel(this);
    EngineTemp->setText(QString::number(0)+" °C");
    EngineTemp->setFont(QFont("Times", 30));
    EngineTemp->setStyleSheet("color:white");
    EngineTemp->setGeometry(150,400,200,50);

    TempScale= new QLabel(this);
    TempScale->setPixmap(QPixmap(":/Images/temp1.png"));
    TempScale->setGeometry(60,200,300,300);

    TempScalepix=QPixmap(":/Images/pointer2.png");
    QPixmap TemprotatedPixmap(TempScalepix.size());
    TemprotatedPixmap.fill(QColor::fromRgb(0, 0, 0, 0));
    QPainter* Temppainter = new QPainter(&TemprotatedPixmap);
    QSize Tempsize = TempScalepix.size();
    Temppainter->translate(Tempsize.height()/2,Tempsize.height()/2);
    Temppainter->rotate(0);  //max is
    Temppainter->translate(-Tempsize.height()/2,-Tempsize.height()/2);
    Temppainter->drawPixmap(0, 0, TempScalepix);
    Temppainter->end();
    delete Temppainter;
    TempPointer= new QLabel(this);
    TempPointer->setGeometry(70,205,300,300);
    TempPointer->setPixmap(TemprotatedPixmap);

    TempWarning= new QLabel(this);
    TempWarning->setPixmap(QPixmap(""));
    TempWarning->setGeometry(50,520,150,150);
}
/**
 * @brief A function to Initailize fuel objects and labels
 * 
 */
void Widget::FuelInit (void)
{
    FuelScale= new QLabel(this);
    FuelScale->setPixmap(QPixmap(":/Images/fuelscale.png"));
    FuelScale->setGeometry(680,220,300,200);


    FuelScalepix=QPixmap(":/Images/pointer2.png");
    QPixmap FuelrotatedPixmap(FuelScalepix.size());
    FuelrotatedPixmap.fill(QColor::fromRgb(0, 0, 0, 0));
    QPainter* FuelPainter = new QPainter(&FuelrotatedPixmap);
    QSize Fuelsize = FuelScalepix.size();
    FuelPainter->translate(Fuelsize.height()/2,Fuelsize.height()/2);
    FuelPainter->rotate(0);  //max is 180
    FuelPainter->translate(-Fuelsize.height()/2,-Fuelsize.height()/2);
    FuelPainter->drawPixmap(0, 0, FuelScalepix);
    FuelPainter->end();
    delete FuelPainter;
    FuelPointer= new QLabel(this);
    FuelPointer->setGeometry(685,210,300,300);
    FuelPointer->setPixmap(FuelrotatedPixmap);

    FuelWarning= new QLabel(this);
    FuelWarning->setPixmap(QPixmap(""));
    FuelWarning->setGeometry(610,520,150,150);
}
/**
 * @brief A function to Initailize battery objects and labels
 * 
 */
void Widget::BatteryInit (void)
{
    Battery= new QLabel(this);
    Battery->setPixmap(QPixmap(":/Images/bat.png"));
    Battery->setGeometry(825,500,200,200);

    BatteryPercentage= new QLabel(this);
    BatteryPercentage->setText("100%");
    BatteryPercentage->setFont(QFont("Times", 20));
    BatteryPercentage->setGeometry(870,540,200,200);
}
/**
 * @brief A function to Initailize seatbelt objects and labels
 * 
 */
void Widget::SeatbeltInit (void)
{
    SeatBeltLightLogo= new QLabel(this);
    SeatBeltLightLogo->setPixmap(QPixmap(""));
    SeatBeltLightLogo->setGeometry(210,550,150,100);
}
/**
 * @brief A function to Initailize antilock warning objects and labels
 * 
 */
void Widget::AntiLockBrakeInit (void)
{
    AntiLockBrakeWarning= new QLabel(this);
    AntiLockBrakeWarning->setPixmap(QPixmap(""));
    AntiLockBrakeWarning->setGeometry(405,530,150,150);
}
/**
 * @brief A function to update speed objects and labels
 * 
 */
void Widget::SpeedUpdate (void)
{
    if (u8SpeedValue <= 255)
    {
//        Speed->setText(QString::number(u8SpeedValue)+" Km/h");

        QPixmap SpeedrotatedPixmap(SpeedScalepix.size());
        SpeedrotatedPixmap.fill(QColor::fromRgb(0, 0, 0, 0));
        QPainter* Speedpainter = new QPainter(&SpeedrotatedPixmap);
        QSize Speedsize = SpeedScalepix.size();
        Speedpainter->translate(Speedsize.height()/2,Speedsize.height()/2);
        Speedpainter->rotate(u8SpeedValue);
        Speedpainter->translate(-Speedsize.height()/2,-Speedsize.height()/2);
        Speedpainter->drawPixmap(0, 0, SpeedScalepix);
        Speedpainter->end();
        delete Speedpainter;
        SpeedPointer->setPixmap(SpeedrotatedPixmap);
     }
}
/**
 * @brief A function to update temperature objects and labels
 * 
 */
void Widget::TempUpdate (void)
{
    if(u8TempValue<=250)
    {
        QPixmap TemprotatedPixmap(TempScalepix.size());
        TemprotatedPixmap.fill(QColor::fromRgb(0, 0, 0, 0));
        QPainter* Temppainter = new QPainter(&TemprotatedPixmap);
        QSize Tempsize = TempScalepix.size();
        Temppainter->translate(Tempsize.height()/2,Tempsize.height()/2);
        Temppainter->rotate(u8TempValue*.95+10);
        Temppainter->translate(-Tempsize.height()/2,-Tempsize.height()/2);
        Temppainter->drawPixmap(0, 0, TempScalepix);
        Temppainter->end();
        delete Temppainter;
        TempPointer->setPixmap(TemprotatedPixmap);
        EngineTemp->setText(QString::number(u8TempValue)+" °C");
        if (u8TempValue>=100 )
        {
            TempWarning->setPixmap(QPixmap(":/Images/heat.png"));
        }
        else
        {
            TempWarning->setPixmap(QPixmap(""));
        }
    }
}
/**
 * @brief A function to update fuel objects and labels
 * 
 */
void Widget::FuelUpdate (void)
{
    if (u8FuelValue <= 255)
    {
        QPixmap FuelrotatedPixmap(FuelScalepix.size());
        FuelrotatedPixmap.fill(QColor::fromRgb(0, 0, 0, 0));
        QPainter* FuelPainter = new QPainter(&FuelrotatedPixmap);
        QSize Fuelsize = FuelScalepix.size();
        FuelPainter->translate(Fuelsize.height()/2,Fuelsize.height()/2);
        FuelPainter->rotate(u8FuelValue*180/255+40);
        FuelPainter->translate(-Fuelsize.height()/2,-Fuelsize.height()/2);
        FuelPainter->drawPixmap(0, 0, FuelScalepix);
        FuelPainter->end();
        delete FuelPainter;
        FuelPointer->setPixmap(FuelrotatedPixmap);

        if (u8FuelValue <51)
        {
            FuelWarning->setPixmap(QPixmap(":/Images/fuel.png"));
        }
        else
        {
            FuelWarning->setPixmap(QPixmap(""));
        }
    }
}
/**
 * @brief A function to update battery objects and labels
 * 
 */
void Widget::BatteryUpdate (void)
{
    if(u8BatteryValue <=100)
    {
        BatteryPercentage->setText(QString::number(u8BatteryValue)+"%");
        if(u8BatteryValue < 20)
        {
            Battery->setPixmap(QPixmap(":/Images/bat2.png"));
        }
        else
        {
             Battery->setPixmap(QPixmap(":/Images/bat.png"));
        }
    }
}
/**
 * @brief A function to update seatbelt objects and labels
 * 
 */
void Widget::SeatbeltUpdate (void)
{
    if (u8SeatBeltFlag)
    {
        SeatBeltLightLogo->setPixmap(QPixmap(":/Images/belt.png"));
    }
    else
    {
        SeatBeltLightLogo->setPixmap(QPixmap(""));
    }
}
/**
 * @brief A function to update antilock warning objects and labels
 * 
 */
void Widget::AntiLockBrakeUpdate (void)
{
    if (u8AntiLockFlag)
    {
        AntiLockBrakeWarning->setPixmap(QPixmap(":/Images/skidding.png"));
    }
    else
    {
        AntiLockBrakeWarning->setPixmap(QPixmap(""));
    }
}




