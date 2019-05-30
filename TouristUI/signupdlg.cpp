#include "signupdlg.h"
#include "ui_signupdlg.h"
#include"newroutedlg.h"
#include<QMessageBox>
#include"main.h"

PASSENGER *Passengers = NULL, *Passengers_tailPtr = NULL, *User;//User当前系统使用者

#define Passengers_headPtr Passengers

SignupDlg::SignupDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignupDlg)
{
    ui->setupUi(this);
    ui->password_le->setEchoMode(QLineEdit::Password);
}

SignupDlg::~SignupDlg()
{
    delete ui;
}


void SignupDlg::on_signUp_btn_clicked()//注册按钮被按下
{

    if(User)//不为空
    {
        cout<<"User不为空,我把它覆盖了"<<endl;    }

    /*新建用户*/
    User = new PASSENGER;
    User->next_passenger=NULL;
    User->coor_x=0;
    User->coor_y=0;

    /*加入passenger链表*/
    if (Passengers_headPtr == NULL)
        {
            Passengers_headPtr = User;
            Passengers_tailPtr = User;
        }
        else
        {
            Passengers_tailPtr->next_passenger = User;
            Passengers_tailPtr = Passengers_tailPtr->next_passenger;
        }

    strcpy(User->ID, ui->userName_lineEdit->text().toLatin1().data());//输入用户名

    cout<<"added into passenger链表"<<endl;
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
