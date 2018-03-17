#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCharts>
#include <QSettings>
using namespace QtCharts;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initialDataBase();
    initialValues();

    //创建条形图视图
    QChartView *pView = new QChartView(this);
    ui->verticalLayout_barChart->addWidget(pView);

    //设置组织和应用名称
    QCoreApplication::setOrganizationName("ZhouSoft");
    QCoreApplication::setOrganizationDomain("zhousoft.com");
    QCoreApplication::setApplicationName("SwimmingRecord");

    //读取配置文件
    readSettings();
}

MainWindow::~MainWindow()
{
    delete ui;
    //关闭数据库
    _pDataBase->closeConnection();
}

bool MainWindow::initialDataBase()
{
    //初始化数据库
    _pDataBase = DataBaseManager::getInstance();
    bool flag = _pDataBase->createConnection();
    if(false == flag)
        return false;

    //创建表
    flag = _swimRecordManager.creatTable();
    if(false == flag)
        return false;

    return true;
}

void MainWindow::initialValues()
{
    _pDialog_add = nullptr;
}

void MainWindow::drawBarChart_last30days()
{

}

void MainWindow::drawBarChart_last7days()
{

}

void MainWindow::readSettings()
{
    QSettings settings;
    QString settings_str = settings.value("DataDisplay").toString();
    if("last7days" == settings_str)
    {
        ui->radioButton_last7days->setChecked(true);
    }
    else if("last30days" == settings_str)
    {
        ui->radioButton_last30days->setChecked(true);
    }
    else{}
}

void MainWindow::on_pushButton_addRecord_clicked()
{
    _pDialog_add = new Dialog_addRecord;
    _pDialog_add->setAttribute(Qt::WA_DeleteOnClose);
    _pDialog_add->exec();
}

void MainWindow::on_radioButton_last7days_clicked()
{
    drawBarChart_last7days();
}

void MainWindow::on_radioButton_last30days_clicked()
{
    drawBarChart_last30days();
}

void MainWindow::on_pushButton_clear_clicked()
{
    QMessageBox msg1;
    msg1.setText("清空数据");
    msg1.setInformativeText("确认清空所有游泳数据？");
    msg1.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    msg1.setDefaultButton(QMessageBox::Cancel);
    int ret = msg1.exec();

    if(QMessageBox::Yes == ret)
    {
        _swimRecordManager.clearRecord();

        QMessageBox msg2;
        msg2.setText("清空数据");
        msg2.setInformativeText("完成数据清空");
        msg2.exec();
    }
}

void MainWindow::on_pushButton_delete_clicked()
{

}

void MainWindow::on_pushButton_setting_clicked()
{
    _pSettingDialog = new SettingDialog;
    _pSettingDialog->setAttribute(Qt::WA_DeleteOnClose);
    _pSettingDialog->exec();
}
