#include "printuserdlg.h"
#include "ui_printuserdlg.h"

PrintUserDlg::PrintUserDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrintUserDlg)
{
    ui->setupUi(this);
}

PrintUserDlg::~PrintUserDlg()
{
    delete ui;
}
