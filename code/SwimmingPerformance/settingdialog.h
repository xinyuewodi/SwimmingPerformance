#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>

#define DEBUG_SETTING_DIALOG
#undef DEBUG_SETTING_DIALOG

namespace Ui {
class SettingDialog;
}

class SettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingDialog(QWidget *parent = 0);
    ~SettingDialog();

private slots:
    void on_pushButton_cancel_clicked();

    void on_pushButton_confirm_clicked();

private:
    Ui::SettingDialog *ui;
};

#endif // SETTINGDIALOG_H
