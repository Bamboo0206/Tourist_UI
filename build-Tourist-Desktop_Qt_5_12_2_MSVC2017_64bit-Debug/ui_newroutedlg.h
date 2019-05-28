/********************************************************************************
** Form generated from reading UI file 'newroutedlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWROUTEDLG_H
#define UI_NEWROUTEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_newRouteDlg
{
public:
    QComboBox *src_cbx;
    QLabel *label;
    QLabel *label_2;
    QComboBox *dest_cbx;
    QLabel *label_3;
    QLineEdit *cityNum_lineEdit;
    QPushButton *passby_btn;
    QLabel *label_4;
    QComboBox *strategy_cbx;
    QPushButton *pushButton_2;

    void setupUi(QDialog *newRouteDlg)
    {
        if (newRouteDlg->objectName().isEmpty())
            newRouteDlg->setObjectName(QString::fromUtf8("newRouteDlg"));
        newRouteDlg->resize(736, 350);
        src_cbx = new QComboBox(newRouteDlg);
        src_cbx->setObjectName(QString::fromUtf8("src_cbx"));
        src_cbx->setGeometry(QRect(150, 70, 131, 22));
        label = new QLabel(newRouteDlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 70, 72, 15));
        label_2 = new QLabel(newRouteDlg);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(450, 70, 72, 15));
        dest_cbx = new QComboBox(newRouteDlg);
        dest_cbx->setObjectName(QString::fromUtf8("dest_cbx"));
        dest_cbx->setGeometry(QRect(510, 70, 131, 22));
        label_3 = new QLabel(newRouteDlg);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 150, 111, 16));
        cityNum_lineEdit = new QLineEdit(newRouteDlg);
        cityNum_lineEdit->setObjectName(QString::fromUtf8("cityNum_lineEdit"));
        cityNum_lineEdit->setGeometry(QRect(230, 150, 91, 21));
        passby_btn = new QPushButton(newRouteDlg);
        passby_btn->setObjectName(QString::fromUtf8("passby_btn"));
        passby_btn->setGeometry(QRect(350, 150, 93, 28));
        label_4 = new QLabel(newRouteDlg);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(100, 220, 72, 15));
        strategy_cbx = new QComboBox(newRouteDlg);
        strategy_cbx->addItem(QString());
        strategy_cbx->addItem(QString());
        strategy_cbx->addItem(QString());
        strategy_cbx->setObjectName(QString::fromUtf8("strategy_cbx"));
        strategy_cbx->setGeometry(QRect(190, 220, 151, 22));
        pushButton_2 = new QPushButton(newRouteDlg);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(500, 280, 131, 41));

        retranslateUi(newRouteDlg);

        QMetaObject::connectSlotsByName(newRouteDlg);
    } // setupUi

    void retranslateUi(QDialog *newRouteDlg)
    {
        newRouteDlg->setWindowTitle(QApplication::translate("newRouteDlg", "Dialog", nullptr));
        label->setText(QApplication::translate("newRouteDlg", "\350\265\267\347\202\271\357\274\232", nullptr));
        label_2->setText(QApplication::translate("newRouteDlg", "\347\273\210\347\202\271\357\274\232", nullptr));
        label_3->setText(QApplication::translate("newRouteDlg", "\351\200\224\347\273\217\345\237\216\345\270\202\346\225\260\351\207\217\357\274\232", nullptr));
        passby_btn->setText(QApplication::translate("newRouteDlg", "\347\241\256\345\256\232", nullptr));
        label_4->setText(QApplication::translate("newRouteDlg", "\346\227\205\350\241\214\347\255\226\347\225\245\357\274\232", nullptr));
        strategy_cbx->setItemText(0, QApplication::translate("newRouteDlg", "\346\234\200\345\260\221\350\212\261\350\264\271", nullptr));
        strategy_cbx->setItemText(1, QApplication::translate("newRouteDlg", "\346\234\200\347\237\255\347\224\250\346\227\266", nullptr));
        strategy_cbx->setItemText(2, QApplication::translate("newRouteDlg", "\351\231\220\345\210\266\346\227\266\351\227\264\346\234\200\345\260\221\350\212\261\350\264\271", nullptr));

        pushButton_2->setText(QApplication::translate("newRouteDlg", "\350\256\241\347\256\227\350\267\257\347\272\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newRouteDlg: public Ui_newRouteDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWROUTEDLG_H
