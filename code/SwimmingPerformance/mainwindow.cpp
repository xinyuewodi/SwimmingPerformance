#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCharts>
#include <QSettings>
#include <QItemSelectionModel>

using namespace QtCharts;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initialDataBase();
    initialValues();

    //创建条形图视图
    pView = new QChartView(this);
    ui->verticalLayout_barChart->addWidget(pView);

    //设置组织和应用名称
    QCoreApplication::setOrganizationName("ZhouSoft");
    QCoreApplication::setOrganizationDomain("zhousoft.com");
    QCoreApplication::setApplicationName("SwimmingRecord");

    //读取配置文件
    readSettings();

    //设置初始页面
    ui->tabWidget->setCurrentIndex(0);

    //初始化model
    initialTableModel();

    //刷新UI显示
    refreshUI();
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
    QList<QDate> dateList;
    QDate today = QDate::currentDate();
    QDate tmpDate;
    for(int i=0; i<30; ++i)
    {
        tmpDate = today.addDays(-1);
        dateList << tmpDate;
        today = tmpDate;
    }
}

void MainWindow::drawBarChart_last7days()
{
    //获取横轴坐标
    QList<QDate> dateList;
    QDate today = QDate::currentDate();
    for(int i=0; i<7; ++i)
    {
        dateList << today;
        today = today.addDays(-1);
    }

    //画图
    QBarSet *set = new QBarSet("游泳数据");
    *set << 1 << 2 << 3 << 4 << 5 << 6 << 7;

    QBarSeries *series = new QBarSeries();
    series->append(set);

    QChart *pchart = new QChart();
    pchart->addSeries(series);
    pchart->setAnimationOptions(QChart::AllAnimations);

    QStringList categories;
    for(int i=6; i>=0; --i)
    {
        categories << QString::number(dateList.at(i).day());
    }
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);

    pchart->createDefaultAxes();
    pchart->setAxisX(axis, series);

    pView->setChart(pchart);
    pView->setRenderHint(QPainter::Antialiasing);
}

void MainWindow::readSettings()
{
    QSettings settings;
    //读取 数据显示
    QString settings_display = settings.value("DataDisplay").toString();
    if("last7days" == settings_display)
    {
        ui->radioButton_last7days->setChecked(true);
    }
    else if("last30days" == settings_display)
    {
        ui->radioButton_last30days->setChecked(true);
    }
    else{}
    //读取 开始游泳日期
    _date = settings.value("SwimStartDate").toDate();
}

void MainWindow::initialTableModel()
{
    _pModel = new QSqlTableModel(this, _pDataBase->getConnection());
}

void MainWindow::refreshUI()
{
    //刷新列表显示
    refreshTableModel();
    //刷新总距离
    refreshTotalDistance();
    //刷新总时长
    refreshTotalTime();
    //刷新泳龄
    refreshSwimAge();
    //刷新条形图
    refreshBarChart();
}

void MainWindow::refreshTableModel()
{
    _pModel->setTable("SwimRecordTable");
    _pModel->setEditStrategy(QSqlTableModel::OnRowChange);
    _pModel->setSort(5, Qt::DescendingOrder);
    _pModel->select();
    _pModel->setHeaderData(0, Qt::Horizontal, tr("Id"));
    _pModel->setHeaderData(1, Qt::Horizontal, tr("全程（米）"));
    _pModel->setHeaderData(2, Qt::Horizontal, tr("总圈数"));
    _pModel->setHeaderData(3, Qt::Horizontal, tr("总耗时"));
    _pModel->setHeaderData(4, Qt::Horizontal, tr("每圈平均耗时"));
    _pModel->setHeaderData(5, Qt::Horizontal, tr("日期"));

    ui->tableView_dataDisplay->setModel(_pModel);
    ui->tableView_dataDisplay->hideColumn(0);
}

void MainWindow::refreshTotalDistance()
{
    int totalDistance = _swimRecordManager.getTotalDistance();

    ui->lineEdit_totalDistance->setText(QString::number(totalDistance) + "米");
}

void MainWindow::refreshTotalTime()
{
    QString totalTime;
    totalTime = _swimRecordManager.getTotalTimeCost();
#ifdef DEBUG_MAINWINDOW
    qDebug() << "total time :" << totalTime;
#endif
    ui->lineEdit_totalTime->setText(totalTime);
}

void MainWindow::refreshSwimAge()
{
    if(false == _date.isValid())
        return;

    qint64 days = _date.daysTo(QDate::currentDate());
#ifdef DEBUG_MAINWINDOW
    qDebug() << "total days :" << days;
#endif
    int year = days/365;
    int month = days%365/30;
    int day = days%365%30;
    ui->lineEdit_swimAge->setText(QString("%1 年 %2 个月 %3 天").arg(year).arg(month).arg(day));
}

void MainWindow::refreshBarChart()
{
    if(true == ui->radioButton_last7days->isChecked())
    {
        drawBarChart_last7days();
    }
    else
    {
        drawBarChart_last30days();
    }
}

void MainWindow::on_pushButton_addRecord_clicked()
{
    _pDialog_add = new Dialog_addRecord;
    _pDialog_add->setAttribute(Qt::WA_DeleteOnClose);
    _pDialog_add->exec();

    refreshUI();
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

        //刷新UI显示
        refreshUI();
    }
}

void MainWindow::on_pushButton_delete_clicked()
{
    //获取选择model信息
    QItemSelectionModel *pSelectionModel = ui->tableView_dataDisplay->selectionModel();
    if(false == pSelectionModel->hasSelection())
        return;

    //获取选中行id的index
    QModelIndex currentIndex = pSelectionModel->currentIndex();
    QModelIndex idIndex = currentIndex.sibling(currentIndex.row(), 0);
    int idToBeDel = _pModel->data(idIndex, Qt::DisplayRole).toInt();
#ifdef DEBUG_MAINWINDOW
    qDebug() << "id to be delete:" << idToBeDel;
#endif

    //提示是否删除
    int ret = QMessageBox::question(this,
                                  "删除记录", "确认删除？",
                                  QMessageBox::Yes | QMessageBox::Cancel,
                                  QMessageBox::Cancel);

    //执行删除操作
    if(QMessageBox::Yes == ret)
    {
        _swimRecordManager.removeRecord(idToBeDel);

        //刷新UI显示
        refreshUI();
    }
}

void MainWindow::on_actionDisplay_triggered()
{
    _pSettingDialog = new SettingDialog;
    _pSettingDialog->setAttribute(Qt::WA_DeleteOnClose);
    _pSettingDialog->exec();

    //刷新泳龄
    refreshSwimAge();
}
