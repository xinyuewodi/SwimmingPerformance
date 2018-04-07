#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlTableModel>
#include <QtCharts>

#include "dialog_addrecord.h"
#include "databasemanager.h"
#include "swimrecordtablemanager.h"
#include "settingdialog.h"

#define DEBUG_MAINWINDOW
//#undef DEBUG_MAINWINDOW

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
    void readSettings();
    void initialTableModel();                               //初始化游泳记录表的model

    void refreshUI();                                         //刷新UI中的数据显示
    void refreshTableModel();                               //刷新游泳纪录表的model
    void refreshTotalDistance();                            //刷新游泳总距离
    void refreshTotalTime();                                //刷新总时长
    void refreshSwimAge();                                  //刷新泳龄
    void refreshBarChart();                                 //刷新条形图

private slots:

    void on_pushButton_addRecord_clicked();

    void on_radioButton_last7days_clicked();

    void on_radioButton_last30days_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_delete_clicked();

    void on_actionDisplay_triggered();

private:
    Ui::MainWindow *ui;
    Dialog_addRecord *_pDialog_add;
    DataBaseManager *_pDataBase;
    SwimRecordTableManager _swimRecordManager;
    SettingDialog *_pSettingDialog;
    QSqlTableModel *_pModel;

    QDate _date;                                            //游泳起始日期

    QChartView *pView;
};

#endif // MAINWINDOW_H
