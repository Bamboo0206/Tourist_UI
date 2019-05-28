/********************************************************************************
** Form generated from reading UI file 'signupdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPDLG_H
#define UI_SIGNUPDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SignupDlg
{
public:
    QLineEdit *userName_lineEdit;
    QLabel *userName_lb;
    QPushButton *signUp_btn;

    void setupUi(QDialog *SignupDlg)
    {
        if (SignupDlg->objectName().isEmpty())
            SignupDlg->setObjectName(QString::fromUtf8("SignupDlg"));
        SignupDlg->resize(400, 300);
        userName_lineEdit = new QLineEdit(SignupDlg);
        userName_lineEdit->setObjectName(QString::fromUtf8("userName_lineEdit"));
        userName_lineEdit->setGeometry(QRect(120, 110, 221, 21));
        userName_lb = new QLabel(SignupDlg);
        userName_lb->setObjectName(QString::fromUtf8("userName_lb"));
        userName_lb->setGeometry(QRect(30, 110, 72, 15));
        signUp_btn = new QPushButton(SignupDlg);
        signUp_btn->setObjectName(QString::fromUtf8("signUp_btn"));
        signUp_btn->setGeometry(QRect(250, 190, 93, 28));

        retranslateUi(SignupDlg);

        QMetaObject::connectSlotsByName(SignupDlg);
    } // setupUi

    void retranslateUi(QDialog *SignupDlg)
    {
        SignupDlg->setWindowTitle(QApplication::translate("SignupDlg", "Dialog", nullptr));
        userName_lb->setText(QApplication::translate("SignupDlg", "\347\224\250\346\210\267\345\220\215", nullptr));
        signUp_btn->setText(QApplication::translate("SignupDlg", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignupDlg: public Ui_SignupDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPDLG_H
