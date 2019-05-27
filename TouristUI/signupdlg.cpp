#include "signupdlg.h"
#include "ui_signupdlg.h"
#include"newroutedlg.h"
#include<QMessageBox>
#include"main.h"
PASSENGER *Passengers = NULL, *Passengers_tailPtr = NULL, *User;//User当前系统使用者


SignupDlg::SignupDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignupDlg)
{
    ui->setupUi(this);
}

SignupDlg::~SignupDlg()
{
    delete ui;
}


void SignupDlg::on_signUp_btn_clicked()//注册按钮被按下
{

    if(User)//不为空
    {
        qDebug()<<"User不为空,我把它覆盖了";
    }

    /*新建用户*/
    User = new PASSENGER;
    User->next_passenger=NULL;
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
