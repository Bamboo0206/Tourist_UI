/********************************************************************************
** Form generated from reading UI file 'loginoptiondlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINOPTIONDLG_H
#define UI_LOGINOPTIONDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginOptionDlg
{
public:
    QComboBox *optionCbx;
    QPushButton *OKbtm;
    QLabel *label;

    void setupUi(QDialog *LoginOptionDlg)
    {
        if (LoginOptionDlg->objectName().isEmpty())
            LoginOptionDlg->setObjectName(QString::fromUtf8("LoginOptionDlg"));
        LoginOptionDlg->resize(400, 300);
        optionCbx = new QComboBox(LoginOptionDlg);
        optionCbx->addItem(QString());
        optionCbx->addItem(QString());
        optionCbx->addItem(QString());
        optionCbx->setObjectName(QString::fromUtf8("optionCbx"));
        optionCbx->setGeometry(QRect(90, 100, 191, 21));
        OKbtm = new QPushButton(LoginOptionDlg);
        OKbtm->setObjectName(QString::fromUtf8("OKbtm"));
        OKbtm->setGeometry(QRect(260, 200, 93, 28));
        label = new QLabel(LoginOptionDlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 60, 161, 16));

        retranslateUi(LoginOptionDlg);

        QMetaObject::connectSlotsByName(LoginOptionDlg);
    } // setupUi

    void retranslateUi(QDialog *LoginOptionDlg)
    {
        LoginOptionDlg->setWindowTitle(QApplication::translate("LoginOptionDlg", "Dialog", nullptr));
        optionCbx->setItemText(0, QApplication::translate("LoginOptionDlg", "\344\277\256\346\224\271\346\227\205\350\241\214\346\226\271\346\241\210", nullptr));
        optionCbx->setItemText(1, QApplication::translate("LoginOptionDlg", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        optionCbx->setItemText(2, QApplication::translate("LoginOptionDlg", "\346\226\260\345\273\272\351\241\271\347\233\2562", nullptr));

        OKbtm->setText(QApplication::translate("LoginOptionDlg", "\347\241\256\345\256\232", nullptr));
        label->setText(QApplication::translate("LoginOptionDlg", "\350\257\267\351\200\211\346\213\251\346\223\215\344\275\234\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginOptionDlg: public Ui_LoginOptionDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINOPTIONDLG_H
