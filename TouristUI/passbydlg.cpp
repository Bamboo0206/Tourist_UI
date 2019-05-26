#include "passbydlg.h"
#include "ui_passbydlg.h"
#include<QTableWidget>
#include<QTableWidgetItem>
#include<QComboBox>
#include"main.h"

PASSENGER *Passengers = NULL, *Passengers_tailPtr = NULL, *User;//User当前系统使用者


passbyDlg::passbyDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::passbyDlg)
{
    ui->setupUi(this);

}

passbyDlg::~passbyDlg()
{
    delete ui;
}
void passbyDlg::setPassby_tb(int row=0)
{
    ui->passby_tb->setColumnCount(2);
    ui->passby_tb->setRowCount(row);
    ui->passby_tb->setHorizontalHeaderLabels(QStringList()<<"city"<<"time to stay");//设置表头
    for(int i=0;i<row;i++)//为每行第一列添加下拉选项
    {
        QComboBox *combox=new QComboBox();
        QStringList cities = QStringList()
                        <<QString::fromLocal8Bit("北京")<<QString::fromLocal8Bit("天津");
        combox->addItems(cities);
        ui->passby_tb->setCellWidget(i,0,combox);
    }
    ui->passby_tb->show();
}
void passbyDlg::on_pushButton_clicked()//关闭对话框
{
    /*待改：在此获取表格输入*/
    for(int i=0; i < ui->passby_tb->rowCount();i++)
    {
        //row0要求途经的城市;row1在该地停留时间
        User->pass_by[0][i]= ui->passby_tb->item(i,0)->text().toInt();
        User->pass_by[1][i]= ui->passby_tb->item(i,1)->text().toInt();
    }


    /*关闭对话框*/
    accept();
}
