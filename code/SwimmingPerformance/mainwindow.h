#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>


#include "dialog_addrecord.h"
#include "databasemanager.h"
#include "swimrecordtablemanager.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    bool initialDataBase();
    void initialValues();
    void drawBarChart_last30days();                         //画过去30天的数据
    void drawBarChart_last7days();                          //画过去7天的数据

private slots:

    void on_pushButton_addRecord_clicked();

    void on_radioButton_last7days_clicked();

    void on_radioButton_last30days_clicked();

private:
    Ui::MainWindow *ui;
    Dialog_addRecord *pDialog_add;
    DataBaseManager *_pDataBase;
    SwimRecordTableManager _swimRecordManager;
};

#endif // MAINWINDOW_H
