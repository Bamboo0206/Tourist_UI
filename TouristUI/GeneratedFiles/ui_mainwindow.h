/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *pic_lb;
    QLabel *lable;
    QLabel *SysTime_lb;
    QLabel *allUser_lb;
    QTableWidget *allUser_tb;
    QPushButton *signUp_btn;
    QPushButton *signIn_btn;
    QPushButton *exitSys_btn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1623, 896);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pic_lb = new QLabel(centralWidget);
        pic_lb->setObjectName(QStringLiteral("pic_lb"));
        pic_lb->setGeometry(QRect(20, 20, 1021, 811));
        pic_lb->setStyleSheet(QStringLiteral(""));
        lable = new QLabel(centralWidget);
        lable->setObjectName(QStringLiteral("lable"));
        lable->setGeometry(QRect(1070, 110, 72, 15));
        SysTime_lb = new QLabel(centralWidget);
        SysTime_lb->setObjectName(QStringLiteral("SysTime_lb"));
        SysTime_lb->setGeometry(QRect(1160, 110, 271, 16));
        allUser_lb = new QLabel(centralWidget);
        allUser_lb->setObjectName(QStringLiteral("allUser_lb"));
        allUser_lb->setGeometry(QRect(1070, 150, 72, 15));
        allUser_tb = new QTableWidget(centralWidget);
        allUser_tb->setObjectName(QStringLiteral("allUser_tb"));
        allUser_tb->setGeometry(QRect(1060, 190, 551, 291));
        signUp_btn = new QPushButton(centralWidget);
        signUp_btn->setObjectName(QStringLiteral("signUp_btn"));
        signUp_btn->setGeometry(QRect(1210, 530, 93, 28));
        signIn_btn = new QPushButton(centralWidget);
        signIn_btn->setObjectName(QStringLiteral("signIn_btn"));
        signIn_btn->setGeometry(QRect(1210, 590, 93, 28));
        exitSys_btn = new QPushButton(centralWidget);
        exitSys_btn->setObjectName(QStringLiteral("exitSys_btn"));
        exitSys_btn->setGeometry(QRect(1210, 650, 93, 28));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1623, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pic_lb->setText(QApplication::translate("MainWindow", "map_picture", nullptr));
        lable->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\346\227\266\351\227\264", nullptr));
        SysTime_lb->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        allUser_lb->setText(QApplication::translate("MainWindow", "\346\211\200\346\234\211\347\224\250\346\210\267", nullptr));
        signUp_btn->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214", nullptr));
        signIn_btn->setText(QApplication::translate("MainWindow", "\347\231\273\351\231\206", nullptr));
        exitSys_btn->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\263\273\347\273\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
