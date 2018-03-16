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

    void on_pushButton_close_clicked();

    void on_pushButton_confirm_clicked();

    void on_spinBox_totalLaps_valueChanged(int arg1);

private:
    Ui::Dialog_addRecord *ui;
    SwimRecordTableManager _tableManager;
};

#endif // DIALOG_ADDRECORD_H
