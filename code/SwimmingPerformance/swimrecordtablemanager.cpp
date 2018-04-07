#include "swimrecordtablemanager.h"
#include <QStringListIterator>

SwimRecordTableManager::SwimRecordTableManager()
{
    _pManager = DataBaseManager::getInstance();
}

bool SwimRecordTableManager::creatTable()
{
    QString create_sql = "create table if not exists 'SwimRecordTable'"
                         "(Id integer primary key autoincrement,"
                         "TotalLength integer NOT NULL,"
                         "TotalLapCount integer NOT NULL,"
                         "TotalTimeCost TIME NOT NULL,"
                         "AvgTimeCost TIME,"
                         "Date DATE NOT NULL)";

    QSqlQuery query(_pManager->getConnection());
    query.prepare(create_sql);

    bool flag = query.exec();
    if(false == flag)
    {
        qDebug() << "SwimRecordTableManager::creatTable"<<query.lastError();
    }
    return flag;
}

bool SwimRecordTableManager::appendRecord(SwimRecord &record)
{
    if(0 >= record.totalLap)
    {
        qDebug() << "total lap is zero!";
        return false;
    }

    QString append_sql = "insert into SwimRecordTable(TotalLength,TotalLapCount,TotalTimeCost,AvgTimeCost,Date)"
                         " values(?,?,?,?,?)";
    QSqlQuery query(_pManager->getConnection());
    query.prepare(append_sql);
    query.addBindValue(record.totalLength);
    query.addBindValue(record.totalLap);
    query.addBindValue(record.totalTime);
    query.addBindValue(record.avgTime);
    query.addBindValue(record.date);

    bool flag = query.exec();
    if(false == flag)
    {
        qDebug() << "SwimRecordTableManager::appendRecord:"<< query.lastError();
    }

    record.id = query.lastInsertId().toInt();

    return flag;
}

bool SwimRecordTableManager::removeRecord(int id)
{
    if(0 >= id)
        return false;

    QString remove_sql = "delete from SwimRecordTable where Id=?";
    QSqlQuery query(_pManager->getConnection());
    query.prepare(remove_sql);
    query.addBindValue(id);

    bool flag = query.exec();
    if(false == flag)
    {
        qDebug() << "SwimRecordTableManager::removeRecord:"<< query.lastError();
    }

    return flag;
}

bool SwimRecordTableManager::getRecord(int id, SwimRecord &record)
{
    if(0 >= id)
        return false;

    QString select_sql = "select * from SwimRecordTable where Id=?";
    QSqlQuery query(_pManager->getConnection());
    query.prepare(select_sql);
    query.addBindValue(id);

    bool flag = query.exec();
    if(false == flag)
    {
        qDebug() << "SwimRecordTableManager::getRecord:"<< query.lastError();
        return false;
    }

    while(query.next())
    {
        record.id = query.value(0).toInt();
        record.totalLength = query.value(1).toInt();
        record.totalLap = query.value(2).toInt();
        record.totalTime = query.value(3).toTime();
        record.avgTime = query.value(4).toTime();
        record.date = query.value(5).toDate();
    }
    return true;
}

bool SwimRecordTableManager::getRecord_last7Times(QList<SwimRecord> &recordList)
{
    QString select_sql = "select * from SwimRecordTable order by Date desc limit 0,7";
    QSqlQuery query(_pManager->getConnection());
    query.prepare(select_sql);

    bool flag = query.exec();
    if(false == flag)
    {
        qDebug() << "SwimRecordTableManager::getRecord_last7Times:"<< query.lastError();
        return false;
    }

    SwimRecord tmpRec;
    while(query.next())
    {
        tmpRec.id = query.value(0).toInt();
        tmpRec.totalLength = query.value(1).toInt();
        tmpRec.date = query.value(5).toDate();
        recordList << tmpRec;
    }

    return true;
}

bool SwimRecordTableManager::getRecord_last30Times(QList<SwimRecord> &recordList)
{
    QString select_sql = "select * from SwimRecordTable order by Date desc limit 0,30";
    QSqlQuery query(_pManager->getConnection());
    query.prepare(select_sql);

    bool flag = query.exec();
    if(false == flag)
    {
        qDebug() << "SwimRecordTableManager::getRecord_last7Times:"<< query.lastError();
        return false;
    }

    SwimRecord tmpRec;
    while(query.next())
    {
        tmpRec.id = query.value(0).toInt();
        tmpRec.totalLength = query.value(1).toInt();
        tmpRec.date = query.value(5).toDate();
        recordList << tmpRec;
    }

    return true;
}

bool SwimRecordTableManager::clearRecord()
{
    QString clear_sql = "delete from SwimRecordTable";
    QSqlQuery query(_pManager->getConnection());
    query.prepare(clear_sql);
    bool flag = query.exec();
    if(false == flag)
    {
        qDebug() << "SwimRecordTableManager::clearRecord():" << query.lastError();
        return false;
    }
    return true;
}

int SwimRecordTableManager::getTotalDistance()
{
    QString totalDistance_sql;
    totalDistance_sql = "select sum(TotalLength) from SwimRecordTable";
    QSqlQuery query(_pManager->getConnection());
    query.prepare(totalDistance_sql);

    bool flag = query.exec();
    if(false == flag)
    {
        qDebug() << "SwimRecordTableManager::getTotalDistance():" << query.lastError();
        return 0;
    }

    int totalDistance = 0;
    while(query.next())
    {
        totalDistance = query.value(0).toInt();
    }
    return totalDistance;
}

QString SwimRecordTableManager::getTotalTimeCost()
{
    QString totalTime_sql;
    totalTime_sql = "select TotalTimeCost from SwimRecordTable";

    QSqlQuery query(_pManager->getConnection());
    query.prepare(totalTime_sql);

    bool flag = query.exec();
    if(false == flag)
    {
        qDebug() << "SwimRecordTableManager::getTotalTimeCost():" << query.lastError();
        return QString();
    }

    QString time;                   //单个时间
    int totalHours = 0;             //总小时
    int totalMinutes = 0;           //总分钟
    int totalSeconds = 0;           //总秒
    //从数据库中获取所有时间列表
    while(query.next())
    {
        totalHours += query.value(0).toTime().hour();
        totalMinutes += query.value(0).toTime().minute();
        totalSeconds += query.value(0).toTime().second();
    }

    //计算后的总时间

    int Seconds = totalSeconds%60;                                  //秒
    int Minutes = (totalMinutes + totalSeconds/60)%60;              //分钟
    int Hours = (totalHours + totalMinutes/60)%60;                  //小时
    int Days = (totalHours + totalMinutes/60)/24;                   //天数
    time = QString("%1 天 %2 小时 %3 分钟 %4 秒").arg(Days).arg(Hours).arg(Minutes).arg(Seconds);

    return time;
}
