/********************************************************************************
** Form generated from reading UI file 'printuserdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINTUSERDLG_H
#define UI_PRINTUSERDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_PrintUserDlg
{
public:
    QLabel *label;

    void setupUi(QDialog *PrintUserDlg)
    {
        if (PrintUserDlg->objectName().isEmpty())
            PrintUserDlg->setObjectName(QString::fromUtf8("PrintUserDlg"));
        PrintUserDlg->resize(400, 300);
        label = new QLabel(PrintUserDlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 60, 241, 121));

        retranslateUi(PrintUserDlg);

        QMetaObject::connectSlotsByName(PrintUserDlg);
    } // setupUi

    void retranslateUi(QDialog *PrintUserDlg)
    {
        PrintUserDlg->setWindowTitle(QApplication::translate("PrintUserDlg", "Dialog", nullptr));
        label->setText(QApplication::translate("PrintUserDlg", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PrintUserDlg: public Ui_PrintUserDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTUSERDLG_H
