#ifndef OUTPUTROUTEDLG_H
#define OUTPUTROUTEDLG_H

#include <QDialog>

#include"main.h"

namespace Ui {
class outputRouteDlg;
}

class outputRouteDlg : public QDialog
{
    Q_OBJECT

public:
    explicit outputRouteDlg(PATH tour,QWidget *parent = 0);
    ~outputRouteDlg();

private slots:

    void on_start_btn_clicked();

private:
    Ui::outputRouteDlg *ui;
};

#endif // OUTPUTROUTEDLG_H
