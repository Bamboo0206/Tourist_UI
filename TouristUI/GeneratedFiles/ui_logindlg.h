/********************************************************************************
** Form generated from reading UI file 'logindlg.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDLG_H
#define UI_LOGINDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDlg
{
public:
    QLabel *userName_lb;
    QLineEdit *userName_lineEdit;
    QPushButton *login_btn;

    void setupUi(QDialog *LoginDlg)
    {
        if (LoginDlg->objectName().isEmpty())
            LoginDlg->setObjectName(QStringLiteral("LoginDlg"));
        LoginDlg->resize(400, 300);
        userName_lb = new QLabel(LoginDlg);
        userName_lb->setObjectName(QStringLiteral("userName_lb"));
        userName_lb->setGeometry(QRect(30, 130, 72, 15));
        userName_lineEdit = new QLineEdit(LoginDlg);
        userName_lineEdit->setObjectName(QStringLiteral("userName_lineEdit"));
        userName_lineEdit->setGeometry(QRect(120, 130, 221, 21));
        login_btn = new QPushButton(LoginDlg);
        login_btn->setObjectName(QStringLiteral("login_btn"));
        login_btn->setGeometry(QRect(250, 210, 93, 28));

        retranslateUi(LoginDlg);

        QMetaObject::connectSlotsByName(LoginDlg);
    } // setupUi

    void retranslateUi(QDialog *LoginDlg)
    {
        LoginDlg->setWindowTitle(QApplication::translate("LoginDlg", "Dialog", nullptr));
        userName_lb->setText(QApplication::translate("LoginDlg", "\347\224\250\346\210\267\345\220\215", nullptr));
        login_btn->setText(QApplication::translate("LoginDlg", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDlg: public Ui_LoginDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDLG_H
