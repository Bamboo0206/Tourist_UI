#include "logindlg.h"
#include "ui_logindlg.h"
#include"newroutedlg.h"
#include<QMessageBox>
#include"main.h"
PASSENGER *Passengers = NULL, *Passengers_tailPtr = NULL, *User;//User当前系统使用者


LoginDlg::LoginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDlg)
{
    ui->setupUi(this);
}

LoginDlg::~LoginDlg()
{
    delete ui;
}

void LoginDlg::on_login_btn_clicked()
{
    ui->userName_lineEdit->text();
    //char chID[]=;
    strcpy(User->ID, ui->userName_lineEdit->text().toLatin1().data());//输入用户名
    accept();

    /*if(1)//待改：如果用户名存在
    {
        accept();
    }
    else
    {
        QMessageBox::warning(this,tr("warning!"),tr("User Name Inexistent"),QMessageBox::Yes);
        //清空内容并定位光标
        ui->userName_lineEdit->clear();
        ui->userName_lineEdit->setFocus();
    }*/
}
