/********************************************************************************
** Form generated from reading UI file 'welcomedlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMEDLG_H
#define UI_WELCOMEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_WelcomeDlg
{
public:
    QPushButton *yes_btn;
    QPushButton *no_btn;
    QLabel *label;

    void setupUi(QDialog *WelcomeDlg)
    {
        if (WelcomeDlg->objectName().isEmpty())
            WelcomeDlg->setObjectName(QString::fromUtf8("WelcomeDlg"));
        WelcomeDlg->resize(428, 310);
        yes_btn = new QPushButton(WelcomeDlg);
        yes_btn->setObjectName(QString::fromUtf8("yes_btn"));
        yes_btn->setGeometry(QRect(40, 140, 93, 28));
        no_btn = new QPushButton(WelcomeDlg);
        no_btn->setObjectName(QString::fromUtf8("no_btn"));
        no_btn->setGeometry(QRect(210, 140, 93, 28));
        label = new QLabel(WelcomeDlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 80, 231, 16));

        retranslateUi(WelcomeDlg);

        QMetaObject::connectSlotsByName(WelcomeDlg);
    } // setupUi

    void retranslateUi(QDialog *WelcomeDlg)
    {
        WelcomeDlg->setWindowTitle(QApplication::translate("WelcomeDlg", "Dialog", nullptr));
        yes_btn->setText(QApplication::translate("WelcomeDlg", "\346\230\257", nullptr));
        no_btn->setText(QApplication::translate("WelcomeDlg", "\345\220\246", nullptr));
        label->setText(QApplication::translate("WelcomeDlg", "\346\230\257\345\220\246\346\201\242\345\244\215\344\270\212\346\254\241\346\211\223\345\274\200\347\232\204\347\263\273\347\273\237\357\274\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WelcomeDlg: public Ui_WelcomeDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEDLG_H
