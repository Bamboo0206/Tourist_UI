#include "loginoptiondlg.h"
#include "ui_loginoptiondlg.h"

LoginOptionDlg::LoginOptionDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginOptionDlg)
{
    ui->setupUi(this);
}

LoginOptionDlg::~LoginOptionDlg()
{
    delete ui;
}

void LoginOptionDlg::on_OKbtm_clicked()
{
    /*获取combox里的信息并执行相关操作*/
    int choice=ui->optionCbx->currentIndex();


    /*关闭*/
    accept();
}
