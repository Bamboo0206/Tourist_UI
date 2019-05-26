#include "outputroutedlg.h"
#include "ui_outputroutedlg.h"
#include"main.h"

PASSENGER *Passengers = NULL, *Passengers_tailPtr = NULL, *User;//User当前系统使用者
extern int Travelstate[10];
extern COORDINATE coordinate[100/*城市数量*/];

outputRouteDlg::outputRouteDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::outputRouteDlg)
{
    ui->setupUi(this);

    /*输出路径*/

}

outputRouteDlg::~outputRouteDlg()
{
    delete ui;
}


void outputRouteDlg::on_start_btn_clicked()
{
    /*修改qPath*/
    User->qPath=new QPainterPath;
    int location=User->src;
    User->qPath->moveTo(coordinate[location].x,coordinate[location].y/*起点坐标*/);
    User->red=rand()%256;
    User->green=rand()%256;
    User->blue=rand()%256;

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

    Write_user_file(1);//将用户注册信息写入User_File.ini






    PASSENGER *temp = Passengers;
        int touristnum = 0;
        while (temp != NULL)
        {
            if (temp == User)
                break;
            else
                touristnum ++;

            temp = temp->next_passenger;
        }
        Travelstate[touristnum] = 1;


    /*刷新main的表格？*/


    accept();
}
