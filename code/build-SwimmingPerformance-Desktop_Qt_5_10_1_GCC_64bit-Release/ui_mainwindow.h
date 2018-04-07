/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDisplay;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_7;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_totalDistance;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *lineEdit_totalTime;
    QLabel *label_3;
    QLineEdit *lineEdit_swimAge;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_barChart;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_last7times;
    QRadioButton *radioButton_last30times;
    QSpacerItem *horizontalSpacer;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_2;
    QTableView *tableView_dataDisplay;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_addRecord;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_clear;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1203, 646);
        QIcon icon;
        icon.addFile(QStringLiteral(":/picture/pic/swim.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setTabShape(QTabWidget::Triangular);
        actionDisplay = new QAction(MainWindow);
        actionDisplay->setObjectName(QStringLiteral("actionDisplay"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_7 = new QVBoxLayout(centralWidget);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit_totalDistance = new QLineEdit(groupBox);
        lineEdit_totalDistance->setObjectName(QStringLiteral("lineEdit_totalDistance"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_totalDistance->sizePolicy().hasHeightForWidth());
        lineEdit_totalDistance->setSizePolicy(sizePolicy);
        lineEdit_totalDistance->setFrame(false);
        lineEdit_totalDistance->setReadOnly(true);

        gridLayout->addWidget(lineEdit_totalDistance, 1, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 2, 2, 1, 1);

        lineEdit_totalTime = new QLineEdit(groupBox);
        lineEdit_totalTime->setObjectName(QStringLiteral("lineEdit_totalTime"));
        sizePolicy.setHeightForWidth(lineEdit_totalTime->sizePolicy().hasHeightForWidth());
        lineEdit_totalTime->setSizePolicy(sizePolicy);
        lineEdit_totalTime->setMinimumSize(QSize(0, 0));
        lineEdit_totalTime->setFrame(false);
        lineEdit_totalTime->setReadOnly(true);

        gridLayout->addWidget(lineEdit_totalTime, 2, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_swimAge = new QLineEdit(groupBox);
        lineEdit_swimAge->setObjectName(QStringLiteral("lineEdit_swimAge"));
        sizePolicy.setHeightForWidth(lineEdit_swimAge->sizePolicy().hasHeightForWidth());
        lineEdit_swimAge->setSizePolicy(sizePolicy);
        lineEdit_swimAge->setFrame(false);
        lineEdit_swimAge->setReadOnly(true);

        gridLayout->addWidget(lineEdit_swimAge, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 2, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 2, 3, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_barChart = new QVBoxLayout();
        verticalLayout_barChart->setSpacing(6);
        verticalLayout_barChart->setObjectName(QStringLiteral("verticalLayout_barChart"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        radioButton_last7times = new QRadioButton(groupBox_2);
        radioButton_last7times->setObjectName(QStringLiteral("radioButton_last7times"));
        radioButton_last7times->setChecked(true);

        horizontalLayout->addWidget(radioButton_last7times);

        radioButton_last30times = new QRadioButton(groupBox_2);
        radioButton_last30times->setObjectName(QStringLiteral("radioButton_last30times"));

        horizontalLayout->addWidget(radioButton_last30times);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_barChart->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout_barChart);


        verticalLayout_3->addWidget(groupBox_2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        horizontalLayout_2 = new QHBoxLayout(tab_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tableView_dataDisplay = new QTableView(tab_2);
        tableView_dataDisplay->setObjectName(QStringLiteral("tableView_dataDisplay"));
        tableView_dataDisplay->setAutoFillBackground(true);
        tableView_dataDisplay->setAlternatingRowColors(true);
        tableView_dataDisplay->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView_dataDisplay->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_dataDisplay->setGridStyle(Qt::DashLine);
        tableView_dataDisplay->horizontalHeader()->setCascadingSectionResizes(true);
        tableView_dataDisplay->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableView_dataDisplay->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout_2->addWidget(tableView_dataDisplay);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_addRecord = new QPushButton(tab_2);
        pushButton_addRecord->setObjectName(QStringLiteral("pushButton_addRecord"));

        verticalLayout->addWidget(pushButton_addRecord);

        pushButton_delete = new QPushButton(tab_2);
        pushButton_delete->setObjectName(QStringLiteral("pushButton_delete"));

        verticalLayout->addWidget(pushButton_delete);

        pushButton_clear = new QPushButton(tab_2);
        pushButton_clear->setObjectName(QStringLiteral("pushButton_clear"));

        verticalLayout->addWidget(pushButton_clear);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_7->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1203, 28));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
        label_2->setBuddy(lineEdit_totalDistance);
        label_3->setBuddy(lineEdit_totalTime);
        label_4->setBuddy(lineEdit_swimAge);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(tabWidget, radioButton_last7times);
        QWidget::setTabOrder(radioButton_last7times, radioButton_last30times);
        QWidget::setTabOrder(radioButton_last30times, pushButton_addRecord);
        QWidget::setTabOrder(pushButton_addRecord, pushButton_delete);
        QWidget::setTabOrder(pushButton_delete, pushButton_clear);
        QWidget::setTabOrder(pushButton_clear, tableView_dataDisplay);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionDisplay);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\346\270\270\346\263\263\345\201\245\345\260\206", nullptr));
        actionDisplay->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\346\200\273\346\263\263\347\250\213:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\346\200\273\346\263\263\346\227\266:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\346\263\263\351\276\204:", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\346\235\241\345\275\242\345\233\276", nullptr));
        radioButton_last7times->setText(QApplication::translate("MainWindow", "\350\277\207\345\216\2737\346\254\241", nullptr));
        radioButton_last30times->setText(QApplication::translate("MainWindow", "\350\277\207\345\216\27330\346\254\241", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\346\246\202\350\247\210", nullptr));
        pushButton_addRecord->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
        pushButton_delete->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        pushButton_clear->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\350\257\246\347\273\206\346\225\260\346\215\256", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
