#ifndef SWIMRECORDTABLEMANAGER_H
#define SWIMRECORDTABLEMANAGER_H

#include <QSqlQuery>
#include <QSqlIndex>
#include <QSqlError>
#include <QSqlTableModel>

#include <QTime>

#include "globals.h"
#include "databasemanager.h"

class SwimRecordTableManager
{
public:
    SwimRecordTableManager();

    bool creatTable();                                  //创建表
    bool appendRecord(SwimRecord &record);              //添加记录，并返回记录id
    bool removeRecord(int id);                          //删除记录
    bool getRecord(int id, SwimRecord &record);         //获取记录
    bool getRecord_last7Times(QList<SwimRecord> &recordList);           //获取最后7次记录
    bool getRecord_last30Times(QList<SwimRecord> &recordList);           //获取最后30次记录
    bool clearRecord();                                 //清空数据

    int getTotalDistance();                             //获取游泳总距离
    QString getTotalTimeCost();                           //获取总时长

private:
    DataBaseManager *_pManager;
};

#endif // SWIMRECORDTABLEMANAGER_H
