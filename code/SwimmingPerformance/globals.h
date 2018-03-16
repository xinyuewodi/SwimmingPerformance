#ifndef GLOBALS_H
#define GLOBALS_H

#include <QString>
#include <QTime>
#include <QDebug>

/**
 * @brief 游泳记录结构体
 */
struct SwimRecord
{
    int id;
    int totalLength;                    //总长度
    int totalLap;                       //总圈数
    QTime totalTime;                    //总时间
    QTime avgTime;                      //每圈平均时间
    QDate date;
};

#endif // GLOBALS_H
