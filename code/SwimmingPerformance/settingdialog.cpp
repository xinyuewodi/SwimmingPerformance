#include "settingdialog.h"
#include "ui_settingdialog.h"

#include <QMessageBox>
#include <QSettings>
#include <QDebug>

SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{
    ui->setupUi(this);
}

SettingDialog::~SettingDialog()
{
    delete ui;
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
