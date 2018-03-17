#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCharts>
using namespace QtCharts;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initialDataBase();
    initialValues();

    QChartView *pView = new QChartView(this);
    ui->verticalLayout_barChart->addWidget(pView);
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
    pDialog_add = nullptr;
}

void MainWindow::drawBarChart_last30days()
{

}

void MainWindow::drawBarChart_last7days()
{

}

void MainWindow::on_pushButton_addRecord_clicked()
{
    pDialog_add = new Dialog_addRecord;
    pDialog_add->setAttribute(Qt::WA_DeleteOnClose);
    pDialog_add->exec();
}

void MainWindow::on_radioButton_last7days_clicked()
{
    drawBarChart_last7days();
}

void MainWindow::on_radioButton_last30days_clicked()
{
    drawBarChart_last30days();
}
