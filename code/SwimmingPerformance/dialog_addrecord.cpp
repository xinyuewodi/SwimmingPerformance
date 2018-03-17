#include "dialog_addrecord.h"
#include "ui_dialog_addrecord.h"

#include <QDebug>
#include <QMessageBox>
#include <QTimeEdit>

Dialog_addRecord::Dialog_addRecord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_addRecord)
{
    ui->setupUi(this);
}

Dialog_addRecord::~Dialog_addRecord()
{
    delete ui;
}

void Dialog_addRecord::on_pushButton_close_clicked()
{
    this->close();
}

void Dialog_addRecord::on_pushButton_confirm_clicked()
{
    //1.提取输入数据
    SwimRecord record;
    QString tmpTime;
    record.totalLength = ui->lineEdit_totalLength->text().toInt();  //总距离
    record.totalLap = ui->spinBox_totalLaps->text().toInt();        //总圈数
    tmpTime = ui->lineEdit_totalTime->text();
    record.totalTime = QTime::fromString(tmpTime, "hh:mm:ss");      //总时间
    tmpTime = ui->lineEdit_avgTime->text();
    record.avgTime = QTime::fromString(tmpTime, "hh:mm:ss");        //每圈平均时间
    record.date = QDate::currentDate();                             //今天日期

#ifdef DEBUG_DIALOG_ADDRECORD
    qDebug() << "total length:" << record.totalLength;
    qDebug() << "total Lap count:" << record.totalLap;
    qDebug() << "total Time:" << record.totalTime;
    qDebug() << "avg Time:" << record.avgTime;
    qDebug() << "date:" << record.date;
#endif

    //3.写入数据库
    bool flag = _tableManager.appendRecord(record);
    if(false == flag)
    {
        QMessageBox msg;
        msg.setWindowTitle("输入");
        msg.setText("输入操作失败");
        msg.exec();
        return;
    }

    //4.弹框提示完成
    QMessageBox msg;
    msg.setWindowTitle("输入");
    msg.setText("输入完成");
    msg.exec();

    this->close();
}

void Dialog_addRecord::on_spinBox_totalLaps_valueChanged(int arg1)
{
    int poolLength = ui->comboBox_poolLength->currentText().toInt();
    int length = 2*poolLength*arg1;
    ui->lineEdit_totalLength->setText(QString::number(length));
}

void Dialog_addRecord::on_lineEdit_totalTime_textChanged(const QString &arg1)
{
    int lapCount = ui->spinBox_totalLaps->text().toInt();           //总圈数
    //检查参数非零
    if(0 == lapCount || "00:00:00" == arg1)
        return;

    QTime tmpTime = QTime::fromString(arg1, "hh:mm:ss");
    int seconds = tmpTime.hour()*60*60 + tmpTime.minute()*60 + tmpTime.second();    //换算成秒
    int avgSeconds = seconds/lapCount;                                              //每圈平均耗时
    //每圈平均耗时 从秒 转换为 时分秒
    int hour = avgSeconds/3600;
    int minute = avgSeconds%3600/60;
    int second = avgSeconds%3600%60;
    QTime avgTime;
    avgTime.setHMS(hour, minute, second);
    QString avgTime_str = avgTime.toString("hh:mm:ss");
    //显示
    ui->lineEdit_avgTime->setText(avgTime_str);
}
