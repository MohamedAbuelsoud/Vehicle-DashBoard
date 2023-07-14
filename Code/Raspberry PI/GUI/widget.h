/**
 * @file widget.h
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
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QRadioButton>
#include <QLCDNumber>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
/**
 * @brief Construct a new Widget object
 * 
 * @param parent 
 */
    Widget(QWidget *parent = nullptr);
/**
 * @brief Destroy the Widget object
 * 
 */
    ~Widget();

private:
    Ui::Widget *ui;
    QLabel *BackGround;
    QLabel *SpeedScale;
    QLabel *SpeedPointer;
    QPixmap SpeedScalepix;
    QLabel *EngineTemp;
    QLabel *TempScale;
    QPixmap TempScalepix;
    QLabel *TempPointer;
    QLabel *TempWarning;
    QLabel *Battery;
    QLabel *BatteryPercentage;
    QLabel *SeatBeltLightLogo;

    QLabel *AntiLockBrakeWarning;
    QLabel *FuelWarning;
    QLabel *FuelScale;
    QLabel *FuelPointer;
    QPixmap FuelScalepix;

/**
 * @brief Set the Background object
 * 
 */
    void SetBackground (void);
/**
 * @brief A function to Initailize speed objects and labels
 * 
 */
    void SpeedInit (void);
/**
 * @brief A function to Initailize temperature objects and labels
 * 
 */
    void TempInit (void);
/**
 * @brief A function to Initailize fuel objects and labels
 * 
 */
    void FuelInit (void);
/**
 * @brief A function to Initailize battery objects and labels
 * 
 */
    void BatteryInit (void);
/**
 * @brief A function to Initailize seatbelt objects and labels
 * 
 */
    void SeatbeltInit (void);
/**
 * @brief A function to Initailize antilock warning objects and labels
 * 
 */
    void AntiLockBrakeInit (void);

/**
 * @brief A function to update speed objects and labels
 * 
 */
    void SpeedUpdate (void);
/**
 * @brief A function to update temperature objects and labels
 * 
 */
    void TempUpdate (void);
/**
 * @brief A function to update fuel objects and labels
 * 
 */
    void FuelUpdate (void);
/**
 * @brief A function to update battery objects and labels
 * 
 */
    void BatteryUpdate (void);
/**
 * @brief A function to update seatbelt objects and labels
 * 
 */
    void SeatbeltUpdate (void);
/**
 * @brief A function to update antilock warning objects and labels
 * 
 */
    void AntiLockBrakeUpdate (void);

 public slots:
/**
 * @brief WidgetvidUpdateValues is a function to update the sensor readings in GUI
 * 
 */
    void WidgetvidUpdateValues(void);
};
#endif // WIDGET_H
