/********************************************************************************
** Form generated from reading UI file 'outputroutedlg.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTPUTROUTEDLG_H
#define UI_OUTPUTROUTEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_outputRouteDlg
{
public:
    QLabel *label;
    QPushButton *start_btn;
    QLabel *route;

    void setupUi(QDialog *outputRouteDlg)
    {
        if (outputRouteDlg->objectName().isEmpty())
            outputRouteDlg->setObjectName(QStringLiteral("outputRouteDlg"));
        outputRouteDlg->resize(675, 300);
        label = new QLabel(outputRouteDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 71, 31));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);
        start_btn = new QPushButton(outputRouteDlg);
        start_btn->setObjectName(QStringLiteral("start_btn"));
        start_btn->setGeometry(QRect(540, 250, 93, 28));
        start_btn->setFont(font);
        route = new QLabel(outputRouteDlg);
        route->setObjectName(QStringLiteral("route"));
        route->setGeometry(QRect(40, 70, 601, 161));

        retranslateUi(outputRouteDlg);

        QMetaObject::connectSlotsByName(outputRouteDlg);
    } // setupUi

    void retranslateUi(QDialog *outputRouteDlg)
    {
        outputRouteDlg->setWindowTitle(QApplication::translate("outputRouteDlg", "Dialog", nullptr));
        label->setText(QApplication::translate("outputRouteDlg", "\350\267\257\347\272\277\344\270\272", nullptr));
        start_btn->setText(QApplication::translate("outputRouteDlg", "\345\274\200\345\247\213", nullptr));
        route->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class outputRouteDlg: public Ui_outputRouteDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTPUTROUTEDLG_H
