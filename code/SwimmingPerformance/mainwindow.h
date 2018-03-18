#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlTableModel>

#include "dialog_addrecord.h"
#include "databasemanager.h"
#include "swimrecordtablemanager.h"
#include "settingdialog.h"

#define DEBUG_MAINWINDOW
#undef DEBUG_MAINWINDOW

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
    void refreshTableModel();                               //刷新游泳纪录表的model
    void refreshTotalDistance();                            //刷新游泳总距离

private slots:

    void on_pushButton_addRecord_clicked();

    void on_radioButton_last7days_clicked();

    void on_radioButton_last30days_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_add2_clicked();

    void on_actionDisplay_triggered();

private:
    Ui::MainWindow *ui;
    Dialog_addRecord *_pDialog_add;
    DataBaseManager *_pDataBase;
    SwimRecordTableManager _swimRecordManager;
    SettingDialog *_pSettingDialog;
    QSqlTableModel *_pModel;
};

#endif // MAINWINDOW_H
