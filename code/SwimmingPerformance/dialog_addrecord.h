#ifndef DIALOG_ADDRECORD_H
#define DIALOG_ADDRECORD_H

#include <QDialog>

#include "globals.h"
#include "swimrecordtablemanager.h"

#define DEBUG_DIALOG_ADDRECORD
//#undef DEBUG_DIALOG_ADDRECORD

namespace Ui {
class Dialog_addRecord;
}

class Dialog_addRecord : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_addRecord(QWidget *parent = 0);
    ~Dialog_addRecord();

private slots:

    void on_pushButton_close_clicked();                                     //点击关闭按钮

    void on_pushButton_confirm_clicked();                                   //点击确认按钮

    void on_spinBox_totalLaps_valueChanged(int arg1);                       //总圈数变化时，自动计算总距离

    void on_lineEdit_totalTime_textChanged(const QString &arg1);            //总时间变化时，自动计算每圈耗时

private:
    Ui::Dialog_addRecord *ui;
    SwimRecordTableManager _tableManager;
};

#endif // DIALOG_ADDRECORD_H
