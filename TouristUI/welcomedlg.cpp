#include "welcomedlg.h"
#include "ui_welcomedlg.h"

WelcomeDlg::WelcomeDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WelcomeDlg)
{
    ui->setupUi(this);
}

WelcomeDlg::~WelcomeDlg()
{
    delete ui;
}
