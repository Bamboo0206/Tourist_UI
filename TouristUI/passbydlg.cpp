#include "passbydlg.h"
#include "ui_passbydlg.h"
#include<QTableWidget>
#include<QTableWidgetItem>
#include<QComboBox>
#include"main.h"

extern PASSENGER *Passengers , *Passengers_tailPtr , *User;//User当前系统使用者
extern GRAPH city_graph;

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
        <<QString::fromLocal8Bit(city_graph.City_Name[0])
        <<QString::fromLocal8Bit(city_graph.City_Name[1])
        <<QString::fromLocal8Bit(city_graph.City_Name[2])
        <<QString::fromLocal8Bit(city_graph.City_Name[3])
        <<QString::fromLocal8Bit(city_graph.City_Name[4])
        <<QString::fromLocal8Bit(city_graph.City_Name[5])
        <<QString::fromLocal8Bit(city_graph.City_Name[6])
        <<QString::fromLocal8Bit(city_graph.City_Name[7])
        <<QString::fromLocal8Bit(city_graph.City_Name[8])
        <<QString::fromLocal8Bit(city_graph.City_Name[9]);
        combox->addItems(cities);
        ui->passby_tb->setCellWidget(i,0,combox);
    }
    ui->passby_tb->show();
}
void passbyDlg::on_pushButton_clicked()//关闭对话框
{
    /*待改：在此获取表格输入*/
    int RowCount=ui->passby_tb->rowCount();
    cout<<"RowCount:"<<RowCount<<endl;
    for(int i=0; i < RowCount;i++)
    {
        //row0要求途经的城市;row1在该地停留时间
        cout<<"No."<<i<<"city:"<<ui->passby_tb->item(i,0)->text().toInt()
        <<"\t time:"<<ui->passby_tb->item(i,1)->text().toInt()<<endl;

        User->pass_by[0][i]= ui->passby_tb->item(i,0)->text().toInt();
        User->pass_by[1][i]= ui->passby_tb->item(i,1)->text().toInt();
    }
    cout<<"got input: pass by"<<endl;

    /*关闭对话框*/
    accept();
}
