/********************************************************************************
** Form generated from reading UI file 'settingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGDIALOG_H
#define UI_SETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab_general;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton_last7times;
    QRadioButton *radioButton_last30times;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton_pollLength50;
    QRadioButton *radioButton_poolLength25;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_confirm;
    QPushButton *pushButton_cancel;
    QSpacerItem *horizontalSpacer;
    QWidget *tab_user;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton_confirmAge;
    QDateEdit *dateEdit_swimAge;
    QLabel *label;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *SettingDialog)
    {
        if (SettingDialog->objectName().isEmpty())
            SettingDialog->setObjectName(QStringLiteral("SettingDialog"));
        SettingDialog->resize(417, 260);
        verticalLayout_3 = new QVBoxLayout(SettingDialog);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tabWidget = new QTabWidget(SettingDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_general = new QWidget();
        tab_general->setObjectName(QStringLiteral("tab_general"));
        verticalLayout = new QVBoxLayout(tab_general);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(tab_general);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        radioButton_last7times = new QRadioButton(groupBox);
        radioButton_last7times->setObjectName(QStringLiteral("radioButton_last7times"));
        radioButton_last7times->setChecked(true);

        horizontalLayout_2->addWidget(radioButton_last7times);

        radioButton_last30times = new QRadioButton(groupBox);
        radioButton_last30times->setObjectName(QStringLiteral("radioButton_last30times"));

        horizontalLayout_2->addWidget(radioButton_last30times);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(tab_general);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        radioButton_pollLength50 = new QRadioButton(groupBox_2);
        radioButton_pollLength50->setObjectName(QStringLiteral("radioButton_pollLength50"));
        radioButton_pollLength50->setChecked(true);

        horizontalLayout_3->addWidget(radioButton_pollLength50);

        radioButton_poolLength25 = new QRadioButton(groupBox_2);
        radioButton_poolLength25->setObjectName(QStringLiteral("radioButton_poolLength25"));

        horizontalLayout_3->addWidget(radioButton_poolLength25);

        horizontalSpacer_3 = new QSpacerItem(130, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(groupBox_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_confirm = new QPushButton(tab_general);
        pushButton_confirm->setObjectName(QStringLiteral("pushButton_confirm"));

        horizontalLayout->addWidget(pushButton_confirm);

        pushButton_cancel = new QPushButton(tab_general);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));

        horizontalLayout->addWidget(pushButton_cancel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tabWidget->addTab(tab_general, QString());
        tab_user = new QWidget();
        tab_user->setObjectName(QStringLiteral("tab_user"));
        verticalLayout_2 = new QVBoxLayout(tab_user);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_confirmAge = new QPushButton(tab_user);
        pushButton_confirmAge->setObjectName(QStringLiteral("pushButton_confirmAge"));

        gridLayout->addWidget(pushButton_confirmAge, 0, 2, 1, 1);

        dateEdit_swimAge = new QDateEdit(tab_user);
        dateEdit_swimAge->setObjectName(QStringLiteral("dateEdit_swimAge"));
        dateEdit_swimAge->setFrame(false);
        dateEdit_swimAge->setCalendarPopup(true);

        gridLayout->addWidget(dateEdit_swimAge, 0, 1, 1, 1);

        label = new QLabel(tab_user);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 79, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        tabWidget->addTab(tab_user, QString());

        verticalLayout_3->addWidget(tabWidget);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(dateEdit_swimAge);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(tabWidget, radioButton_last7times);
        QWidget::setTabOrder(radioButton_last7times, radioButton_last30times);
        QWidget::setTabOrder(radioButton_last30times, radioButton_pollLength50);
        QWidget::setTabOrder(radioButton_pollLength50, radioButton_poolLength25);
        QWidget::setTabOrder(radioButton_poolLength25, pushButton_confirm);
        QWidget::setTabOrder(pushButton_confirm, pushButton_cancel);
        QWidget::setTabOrder(pushButton_cancel, dateEdit_swimAge);
        QWidget::setTabOrder(dateEdit_swimAge, pushButton_confirmAge);

        retranslateUi(SettingDialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SettingDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingDialog)
    {
        SettingDialog->setWindowTitle(QApplication::translate("SettingDialog", "\350\256\276\347\275\256", nullptr));
        groupBox->setTitle(QApplication::translate("SettingDialog", "\351\273\230\350\256\244\346\225\260\346\215\256\346\230\276\347\244\272", nullptr));
        radioButton_last7times->setText(QApplication::translate("SettingDialog", "\350\277\207\345\216\2737\346\254\241\346\225\260\346\215\256", nullptr));
        radioButton_last30times->setText(QApplication::translate("SettingDialog", "\350\277\207\345\216\27330\346\254\241\346\225\260\346\215\256", nullptr));
        groupBox_2->setTitle(QApplication::translate("SettingDialog", "\351\273\230\350\256\244\346\263\263\346\261\240\351\225\277\345\272\246", nullptr));
        radioButton_pollLength50->setText(QApplication::translate("SettingDialog", "50\347\261\263", nullptr));
        radioButton_poolLength25->setText(QApplication::translate("SettingDialog", "25\347\261\263", nullptr));
        pushButton_confirm->setText(QApplication::translate("SettingDialog", "\347\241\256\345\256\232", nullptr));
        pushButton_cancel->setText(QApplication::translate("SettingDialog", "\345\217\226\346\266\210", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_general), QApplication::translate("SettingDialog", "\351\200\232\347\224\250", nullptr));
        pushButton_confirmAge->setText(QApplication::translate("SettingDialog", "\347\241\256\345\256\232", nullptr));
        label->setText(QApplication::translate("SettingDialog", "\347\254\254\344\270\200\346\254\241\346\270\270\346\263\263", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_user), QApplication::translate("SettingDialog", "\347\224\250\346\210\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingDialog: public Ui_SettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGDIALOG_H
