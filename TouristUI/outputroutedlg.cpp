﻿#include "outputroutedlg.h"
#include "ui_outputroutedlg.h"
#include"main.h"
#include<string>
#include<sstream>

extern PASSENGER *Passengers , *Passengers_tailPtr , *User;//User当前系统使用者
extern int Travelstate[10];
extern COORDINATE coordinate[100/*城市数量*/];
extern GRAPH city_graph;

#define Passengers_headPtr Passengers

outputRouteDlg::outputRouteDlg(PATH tour,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::outputRouteDlg)
{
    ui->setupUi(this);
    cout<<"output Route"<<endl;

    /*输出路径*/

    int number = 0;
    PATH temp = tour;

    stringstream ss;

    while (temp != NULL)
    {
        number++;
        Ptr_trans_t_Node trans = city_graph.pp_G[temp->src][temp->dest].p_TransTable;
        while (trans != NULL)
        {
            if (trans->number == temp->number)
                break;

            trans = trans->nextPtr;
        }

        ss << "No." << number << " " << city_graph.City_Name[temp->src]
            << "----->" << city_graph.City_Name[temp->dest] << " "
            << trans->name << "  发车时间：" << temp->start_time.year << "-" << temp->start_time.month
            << "-" << temp->start_time.date << " " << temp->start_time.hour << ":00:00" << "\t旅行时长:"
            <<temp->time << '\n';

        temp = temp->next;
    }

    ui->route->setText(QString::fromLocal8Bit(ss.str().c_str()));


}

outputRouteDlg::~outputRouteDlg()
{
    delete ui;
}


void outputRouteDlg::on_start_btn_clicked()//开始旅行按钮
{
//    /*修改qPath*/
//    User->qPath=new QPainterPath;
//    int location=User->src;
//    User->qPath->moveTo(coordinate[location].x,coordinate[location].y/*起点坐标*/);
//    User->red=rand()%256;
//    User->green=rand()%256;
//    User->blue=rand()%256;



    Write_user_file(1);//将用户注册信息写入User_File.ini






//    PASSENGER *temp = Passengers;
//        int touristnum = 0;
//        while (temp != NULL)
//        {
//            if (temp == User)
//                break;
//            else
//                touristnum ++;

//            temp = temp->next_passenger;
//        }
//        Travelstate[touristnum] = 1;


    /*刷新main的表格？*/


    accept();
}
