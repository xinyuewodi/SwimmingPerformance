#ifndef SWIMRECORDTABLEMANAGER_H
#define SWIMRECORDTABLEMANAGER_H

#include <QSqlQuery>
#include <QSqlIndex>
#include <QSqlError>
#include <QSqlTableModel>

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

private:
    DataBaseManager *_pManager;
};

#endif // SWIMRECORDTABLEMANAGER_H
