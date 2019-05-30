/********************************************************************************
** Form generated from reading UI file 'changeuserinfodlg.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEUSERINFODLG_H
#define UI_CHANGEUSERINFODLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ChangeUserInfoDlg
{
public:
    QPushButton *passby_btn;
    QPushButton *compute_btn;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_4;
    QComboBox *strategy_cbx;
    QComboBox *dest_cbx;
    QLineEdit *cityNum_lineEdit;
    QLabel *src_lb;

    void setupUi(QDialog *ChangeUserInfoDlg)
    {
        if (ChangeUserInfoDlg->objectName().isEmpty())
            ChangeUserInfoDlg->setObjectName(QStringLiteral("ChangeUserInfoDlg"));
        ChangeUserInfoDlg->resize(646, 359);
        passby_btn = new QPushButton(ChangeUserInfoDlg);
        passby_btn->setObjectName(QStringLiteral("passby_btn"));
        passby_btn->setGeometry(QRect(320, 140, 93, 28));
        compute_btn = new QPushButton(ChangeUserInfoDlg);
        compute_btn->setObjectName(QStringLiteral("compute_btn"));
        compute_btn->setGeometry(QRect(470, 270, 131, 41));
        label_2 = new QLabel(ChangeUserInfoDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(420, 60, 72, 15));
        label_3 = new QLabel(ChangeUserInfoDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 140, 111, 16));
        label = new QLabel(ChangeUserInfoDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 60, 72, 15));
        label_4 = new QLabel(ChangeUserInfoDlg);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 210, 72, 15));
        strategy_cbx = new QComboBox(ChangeUserInfoDlg);
        strategy_cbx->addItem(QString());
        strategy_cbx->addItem(QString());
        strategy_cbx->addItem(QString());
        strategy_cbx->setObjectName(QStringLiteral("strategy_cbx"));
        strategy_cbx->setGeometry(QRect(160, 210, 151, 22));
        dest_cbx = new QComboBox(ChangeUserInfoDlg);
        dest_cbx->setObjectName(QStringLiteral("dest_cbx"));
        dest_cbx->setGeometry(QRect(480, 60, 131, 22));
        cityNum_lineEdit = new QLineEdit(ChangeUserInfoDlg);
        cityNum_lineEdit->setObjectName(QStringLiteral("cityNum_lineEdit"));
        cityNum_lineEdit->setGeometry(QRect(200, 140, 91, 21));
        src_lb = new QLabel(ChangeUserInfoDlg);
        src_lb->setObjectName(QStringLiteral("src_lb"));
        src_lb->setGeometry(QRect(140, 60, 72, 15));

        retranslateUi(ChangeUserInfoDlg);

        QMetaObject::connectSlotsByName(ChangeUserInfoDlg);
    } // setupUi

    void retranslateUi(QDialog *ChangeUserInfoDlg)
    {
        ChangeUserInfoDlg->setWindowTitle(QApplication::translate("ChangeUserInfoDlg", "Dialog", nullptr));
        passby_btn->setText(QApplication::translate("ChangeUserInfoDlg", "\347\241\256\345\256\232", nullptr));
        compute_btn->setText(QApplication::translate("ChangeUserInfoDlg", "\350\256\241\347\256\227\350\267\257\347\272\277", nullptr));
        label_2->setText(QApplication::translate("ChangeUserInfoDlg", "\347\273\210\347\202\271\357\274\232", nullptr));
        label_3->setText(QApplication::translate("ChangeUserInfoDlg", "\351\200\224\347\273\217\345\237\216\345\270\202\346\225\260\351\207\217\357\274\232", nullptr));
        label->setText(QApplication::translate("ChangeUserInfoDlg", "\350\265\267\347\202\271\357\274\232", nullptr));
        label_4->setText(QApplication::translate("ChangeUserInfoDlg", "\346\227\205\350\241\214\347\255\226\347\225\245\357\274\232", nullptr));
        strategy_cbx->setItemText(0, QApplication::translate("ChangeUserInfoDlg", "\346\234\200\345\260\221\350\212\261\350\264\271", nullptr));
        strategy_cbx->setItemText(1, QApplication::translate("ChangeUserInfoDlg", "\346\234\200\347\237\255\347\224\250\346\227\266", nullptr));
        strategy_cbx->setItemText(2, QApplication::translate("ChangeUserInfoDlg", "\351\231\220\345\210\266\346\227\266\351\227\264\346\234\200\345\260\221\350\212\261\350\264\271", nullptr));

        src_lb->setText(QApplication::translate("ChangeUserInfoDlg", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangeUserInfoDlg: public Ui_ChangeUserInfoDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEUSERINFODLG_H
