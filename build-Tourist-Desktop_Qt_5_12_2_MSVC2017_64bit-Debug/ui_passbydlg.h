/********************************************************************************
** Form generated from reading UI file 'passbydlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSBYDLG_H
#define UI_PASSBYDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_passbyDlg
{
public:
    QTableWidget *passby_tb;
    QPushButton *pushButton;

    void setupUi(QDialog *passbyDlg)
    {
        if (passbyDlg->objectName().isEmpty())
            passbyDlg->setObjectName(QString::fromUtf8("passbyDlg"));
        passbyDlg->resize(729, 562);
        passby_tb = new QTableWidget(passbyDlg);
        passby_tb->setObjectName(QString::fromUtf8("passby_tb"));
        passby_tb->setGeometry(QRect(0, 0, 451, 501));
        pushButton = new QPushButton(passbyDlg);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(530, 450, 93, 28));

        retranslateUi(passbyDlg);

        QMetaObject::connectSlotsByName(passbyDlg);
    } // setupUi

    void retranslateUi(QDialog *passbyDlg)
    {
        passbyDlg->setWindowTitle(QApplication::translate("passbyDlg", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("passbyDlg", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class passbyDlg: public Ui_passbyDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSBYDLG_H
