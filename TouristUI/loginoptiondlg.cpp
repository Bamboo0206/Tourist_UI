#include "loginoptiondlg.h"
#include "ui_loginoptiondlg.h"
#include "changeuserinfodlg.h"
#include"main.h"

extern PASSENGER *User;
extern PASSENGER *Passengers, *Passengers_tailPtr;

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
    int choice=ui->optionCbx->currentIndex();//0,1

	if (choice == 0)
	{
		//调用调整旅行方案的函数
		ChangeUserInfoDlg *cDlg = new ChangeUserInfoDlg(this);
        if(cDlg->exec()==QDialog::Accepted)
        {
            /*关闭*/
            accept();
        }
	}
	else
	{
		//旅客退出
		Write_user_file(3);
        User = NULL;

        /*关闭*/
        accept();
	}
}
