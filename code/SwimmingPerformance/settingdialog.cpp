#include "settingdialog.h"
#include "ui_settingdialog.h"

#include <QMessageBox>
#include <QSettings>
#include <QDebug>
#include <QFileDialog>

SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);
    //载入之前的设置
    readSettings();
}

SettingDialog::~SettingDialog()
{
    delete ui;
}

void SettingDialog::readSettings()
{
    QSettings settings;
    QString dataDisplay;
    int poolLength;
    QDate startSwimDate;
    //读取配置文件
    dataDisplay = settings.value("DataDisplay").toString();
    poolLength = settings.value("PoolLength").toInt();
    startSwimDate = settings.value("SwimStartDate").toDate();
    //设置UI显示
    if("last7days" == dataDisplay)
    {
        ui->radioButton_last7days->setChecked(true);
    }
    else if("last30days" == dataDisplay)
    {
        ui->radioButton_last30days->setChecked(true);
    }

    if(50 == poolLength)
    {
        ui->radioButton_pollLength50->setChecked(true);
    }
    else if(25 == poolLength)
    {
        ui->radioButton_poolLength25->setChecked(true);
    }

    ui->dateEdit_swimAge->setDate(startSwimDate);
}

void SettingDialog::on_pushButton_cancel_clicked()
{
    this->close();
}

void SettingDialog::on_pushButton_confirm_clicked()
{
    QSettings settings;
    if(true == ui->radioButton_last7days->isChecked())
    {
        settings.setValue("DataDisplay", "last7days");
    }
    else
    {
        settings.setValue("DataDisplay", "last30days");
    }

    if(true == ui->radioButton_pollLength50->isChecked())
    {
        settings.setValue("PoolLength", 50);
    }
    else
    {
        settings.setValue("PoolLength", 25);
    }
#ifdef DEBUG_SETTING_DIALOG
    qDebug() << "setting file name:" << settings.fileName();
#endif

    QMessageBox msg;
    msg.setText("保存成功");
    msg.exec();
    this->close();
}

void SettingDialog::on_pushButton_confirmAge_clicked()
{
    QDate date = ui->dateEdit_swimAge->date();
    QSettings settings;
    settings.setValue("SwimStartDate",date);

    QMessageBox msg;
    msg.setText("保存成功");
    msg.exec();
}
