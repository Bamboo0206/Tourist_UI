#include "welcomedlg.h"
#include "ui_welcomedlg.h"
#include"main.h"

extern SYSTEM_TIME System_Time;

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

void WelcomeDlg::on_yes_btn_clicked()
{
    if (Read_system_file() == UNABLE)
        printf("读取存档失败！创建新系统\n");

    accept();
}

void WelcomeDlg::on_no_btn_clicked()
{
    System_Time.year = 2019;
    System_Time.month = 6;
    System_Time.date = 1;
    System_Time.hour = 0;

    WritePrivateProfileStringA("able_or_unable", "able", "0", "D:\\SourceCode\\Tourist_UI\\TouristUI\\System_File.ini");
    //WritePrivateProfileStringA("System_Time", "time", " ", "D:\\SourceCode\\Tourist_UI\\TouristUI\\System_File.ini");

    WritePrivateProfileSectionA("Passenger", "", "D:\\SourceCode\\Tourist_UI\\TouristUI\\System_File.ini");

    accept();
}
