/********************************************************************************
** Form generated from reading UI file 'dialog_addrecord.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_ADDRECORD_H
#define UI_DIALOG_ADDRECORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog_addRecord
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_avgTime;
    QLabel *label_totalTime;
    QLabel *label_avgTime;
    QSpinBox *spinBox_totalLaps;
    QLabel *label_totalLaps;
    QLineEdit *lineEdit_totalLength;
    QLineEdit *lineEdit_totalTime;
    QLabel *label_2;
    QComboBox *comboBox_poolLength;
    QLabel *label_3;
    QDateEdit *dateEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_confirm;
    QPushButton *pushButton_close;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *Dialog_addRecord)
    {
        if (Dialog_addRecord->objectName().isEmpty())
            Dialog_addRecord->setObjectName(QStringLiteral("Dialog_addRecord"));
        Dialog_addRecord->resize(486, 143);
        QIcon icon;
        icon.addFile(QStringLiteral(":/picture/pic/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog_addRecord->setWindowIcon(icon);
        verticalLayout_2 = new QVBoxLayout(Dialog_addRecord);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(Dialog_addRecord);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 2, 1, 1);

        lineEdit_avgTime = new QLineEdit(groupBox);
        lineEdit_avgTime->setObjectName(QStringLiteral("lineEdit_avgTime"));
        lineEdit_avgTime->setReadOnly(true);

        gridLayout->addWidget(lineEdit_avgTime, 2, 3, 1, 1);

        label_totalTime = new QLabel(groupBox);
        label_totalTime->setObjectName(QStringLiteral("label_totalTime"));

        gridLayout->addWidget(label_totalTime, 2, 0, 1, 1);

        label_avgTime = new QLabel(groupBox);
        label_avgTime->setObjectName(QStringLiteral("label_avgTime"));

        gridLayout->addWidget(label_avgTime, 2, 2, 1, 1);

        spinBox_totalLaps = new QSpinBox(groupBox);
        spinBox_totalLaps->setObjectName(QStringLiteral("spinBox_totalLaps"));
        spinBox_totalLaps->setMaximum(999);

        gridLayout->addWidget(spinBox_totalLaps, 1, 1, 1, 1);

        label_totalLaps = new QLabel(groupBox);
        label_totalLaps->setObjectName(QStringLiteral("label_totalLaps"));

        gridLayout->addWidget(label_totalLaps, 1, 0, 1, 1);

        lineEdit_totalLength = new QLineEdit(groupBox);
        lineEdit_totalLength->setObjectName(QStringLiteral("lineEdit_totalLength"));
        lineEdit_totalLength->setReadOnly(false);

        gridLayout->addWidget(lineEdit_totalLength, 1, 3, 1, 1);

        lineEdit_totalTime = new QLineEdit(groupBox);
        lineEdit_totalTime->setObjectName(QStringLiteral("lineEdit_totalTime"));

        gridLayout->addWidget(lineEdit_totalTime, 2, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        comboBox_poolLength = new QComboBox(groupBox);
        comboBox_poolLength->addItem(QString());
        comboBox_poolLength->addItem(QString());
        comboBox_poolLength->setObjectName(QStringLiteral("comboBox_poolLength"));

        gridLayout->addWidget(comboBox_poolLength, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        dateEdit = new QDateEdit(groupBox);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setCalendarPopup(true);

        gridLayout->addWidget(dateEdit, 0, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);


        verticalLayout_2->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_confirm = new QPushButton(Dialog_addRecord);
        pushButton_confirm->setObjectName(QStringLiteral("pushButton_confirm"));

        horizontalLayout->addWidget(pushButton_confirm);

        pushButton_close = new QPushButton(Dialog_addRecord);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));

        horizontalLayout->addWidget(pushButton_close);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(lineEdit_totalLength);
        label_totalTime->setBuddy(lineEdit_totalTime);
        label_avgTime->setBuddy(lineEdit_avgTime);
        label_totalLaps->setBuddy(spinBox_totalLaps);
        label_2->setBuddy(comboBox_poolLength);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(comboBox_poolLength, spinBox_totalLaps);
        QWidget::setTabOrder(spinBox_totalLaps, lineEdit_totalTime);
        QWidget::setTabOrder(lineEdit_totalTime, lineEdit_avgTime);
        QWidget::setTabOrder(lineEdit_avgTime, pushButton_confirm);
        QWidget::setTabOrder(pushButton_confirm, pushButton_close);
        QWidget::setTabOrder(pushButton_close, lineEdit_totalLength);

        retranslateUi(Dialog_addRecord);

        QMetaObject::connectSlotsByName(Dialog_addRecord);
    } // setupUi

    void retranslateUi(QDialog *Dialog_addRecord)
    {
        Dialog_addRecord->setWindowTitle(QApplication::translate("Dialog_addRecord", "\350\256\260\345\275\225\346\270\270\346\263\263\346\225\260\346\215\256", nullptr));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("Dialog_addRecord", "\346\200\273\350\267\235\347\246\273\357\274\210\347\261\263\357\274\211*", nullptr));
        lineEdit_avgTime->setText(QApplication::translate("Dialog_addRecord", "00:00:00", nullptr));
        label_totalTime->setText(QApplication::translate("Dialog_addRecord", "\346\200\273\346\227\266\351\227\264*", nullptr));
        label_avgTime->setText(QApplication::translate("Dialog_addRecord", "\345\271\263\345\235\207\346\257\217\345\234\210\350\200\227\346\227\266", nullptr));
        label_totalLaps->setText(QApplication::translate("Dialog_addRecord", "\346\200\273\345\234\210\346\225\260*", nullptr));
        lineEdit_totalTime->setText(QApplication::translate("Dialog_addRecord", "00:00:00", nullptr));
        label_2->setText(QApplication::translate("Dialog_addRecord", "\346\263\263\346\261\240\351\225\277\345\272\246\357\274\210\347\261\263\357\274\211", nullptr));
        comboBox_poolLength->setItemText(0, QApplication::translate("Dialog_addRecord", "25", nullptr));
        comboBox_poolLength->setItemText(1, QApplication::translate("Dialog_addRecord", "50", nullptr));

        label_3->setText(QApplication::translate("Dialog_addRecord", "\346\227\245\346\234\237", nullptr));
        pushButton_confirm->setText(QApplication::translate("Dialog_addRecord", "\347\241\256\345\256\232", nullptr));
        pushButton_close->setText(QApplication::translate("Dialog_addRecord", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_addRecord: public Ui_Dialog_addRecord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_ADDRECORD_H
