#include "logindlg.h"
#include "ui_logindlg.h"
#include"newroutedlg.h"
#include<QMessageBox>
#include"main.h"

extern PASSENGER *Passengers , *Passengers_tailPtr , *User;//User当前系统使用者


LoginDlg::LoginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDlg)
{
    ui->setupUi(this);
    ui->password_le->setEchoMode(QLineEdit::Password);
}

LoginDlg::~LoginDlg()
{
    delete ui;
}

void LoginDlg::on_login_btn_clicked()
{
    char userID[100];
    strcpy(userID, ui->userName_lineEdit->text().toLatin1().data());//输入用户名

    bool find_passenger = false;
    PASSENGER *temp = Passengers;

    //寻找与用户输入ID匹配的旅客
    while (temp != NULL && !find_passenger)
    {
        if (strcmp(userID, temp->ID) != 0)
        {
            temp = temp->next_passenger;
        }
        else
        {
            User = temp;
            Write_user_file(2);
            find_passenger = true;
        }
    }

    //用户不存在，需要重新输入ID
    if (find_passenger == false)
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("警告！"),
                           QString::fromLocal8Bit("用户名不存在！"),
                           QMessageBox::Yes);
        //清空内容并定位光标
        ui->userName_lineEdit->clear();
        ui->userName_lineEdit->setFocus();
    }

    else
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
