#include "changeuserinfodlg.h"
#include "ui_changeuserinfodlg.h"
#include"passbydlg.h"
#include"outputroutedlg.h"
#include"main.h"
#include<QMessageBox>

extern PASSENGER *Passengers , *Passengers_tailPtr
        , *User;//User当前系统使用者
extern GRAPH city_graph;
extern SYSTEM_TIME System_Time;
extern FILE *fptr_input;
extern int Travelstate[10];

ChangeUserInfoDlg::ChangeUserInfoDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeUserInfoDlg)
{
    ui->setupUi(this);

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

    ui->dest_cbx->addItems(cities);

    //判断旅客是否到达终点

    fprintf(fptr_input, "ID：%s  更改旅行计划\n", User->ID);//用户输入写入input.txt文件


    //判断旅客位置
    if (User->status.loca == STAY_IN_CITY)
    {
        User->src = User->status.src;/*修改起点为目前城市*/
        User->start_time = System_Time;
        WritePrivateProfileSectionA(User->ID, "", ".\\User_Route.ini");
    }
    else if(User->status.loca != ARRIVE)
    {
        User->src = User->status.dest;

        PASSENGER *temp = Passengers;
        int touristnum = 0;
        while (temp != NULL)
        {
            if (temp == User)
                break;

            touristnum++;
            temp = temp->next_passenger;
        }

        char str1[10]={'\0'};
        sprintf(str1, "No.%d", Travelstate[touristnum]);
        PathNode cur;

        GetPrivateProfileStructA(User->ID, str1, &cur, sizeof(PathNode), ".\\User_Route.ini");

        int hours = cur.time-(System_Time-cur.start_time);

        User->start_time = System_Time + hours;

        WritePrivateProfileSectionA(User->ID, "", ".\\User_Route.ini");
        memset(str1, 0, sizeof(str1));
        sprintf(str1, "No.1");
        WritePrivateProfileStructA(User->ID, str1, &cur, sizeof(PathNode), ".\\User_Route.ini");

        Travelstate[touristnum] = 1;
        //User->status.loca = STAY_IN_CITY;
    }
    else
    {
        User->src = User->status.dest;
        User->start_time=System_Time;
        User->status.loca = STAY_IN_CITY;
    }

    cout<<"psg current location: "<<city_graph.City_Name[User->src]<<endl;
    ui->src_lb->setText(QString::fromLocal8Bit(city_graph.City_Name[User->src]));
    ui->src_lb->show();
}

ChangeUserInfoDlg::~ChangeUserInfoDlg()
{
    delete ui;
}

void ChangeUserInfoDlg::on_compute_btn_clicked()//计算路径的按钮
{

    //判断旅客是否到达终点

    /*fprintf(fptr_input, "ID：%s  更改旅行计划\n", User->ID);//用户输入写入input.txt文件


    //判断旅客位置
    if (User->status.loca == STAY_IN_CITY)
    {
        User->src = User->status.src;//修改起点为目前城市
        User->start_time = System_Time;
        WritePrivateProfileSectionA(User->ID, "", ".\\User_Route.ini");
    }
    else if(User->status.loca != ARRIVE)
    {
        User->src = User->status.dest;

        PASSENGER *temp = Passengers;
        int touristnum = 0;
        while (temp != NULL)
        {
            if (temp == User)
                break;

            touristnum++;
            temp = temp->next_passenger;
        }

        char str1[10]={'\0'};
        sprintf(str1, "No.%d", Travelstate[touristnum]);
        PathNode cur;

        GetPrivateProfileStructA(User->ID, str1, &cur, sizeof(PathNode), ".\\User_Route.ini");

        int hours = cur.time-(System_Time-cur.start_time);

        User->start_time = System_Time + hours;

        WritePrivateProfileSectionA(User->ID, "", ".\\User_Route.ini");
        memset(str1, 0, sizeof(str1));
        sprintf(str1, "No.1");
        WritePrivateProfileStructA(User->ID, str1, &cur, sizeof(PathNode), ".\\User_Route.ini");

        Travelstate[touristnum] = 1;
    }
    else
        User->src = User->status.dest;

    cout<<"psg current location: "<<city_graph.City_Name[User->src]<<endl;
    ui->src_lb->setText(QString::fromLocal8Bit(city_graph.City_Name[User->src]));
    ui->src_lb->show();
    */

    /*获取各项输入*/

    User->dest = ui->dest_cbx->currentIndex();
    User->strategy = ui->strategy_cbx->currentIndex();//0/1/2
    if(User->strategy==2)
        User->Time_Limited = LimTime_le->text().toInt();
    else
        User->Time_Limited= NULL;

    /*调用计算路径的函数*/
    switch (User->strategy)
        {
        case 0:
            Min_Cost();
            cout<<"change route :compute route done."<<endl;
            accept();//退出change route窗口
            break;
        case 1:
            Min_Time();
            cout<<"change route :compute route done."<<endl;
            accept();//退出change route窗口
            break;
        case 2:
        if(Min_Cost_Limited_Time()==Error)
        {
            QMessageBox::warning(this, QString::fromLocal8Bit("警告！"),
                               QString::fromLocal8Bit("限制时间过短，请重新输入"),
                               QMessageBox::Yes);
        }
        else
        {
            cout<<"change route :compute route done."<<endl;
            accept();//退出change route窗口
        }

        break;
        default:
            break;
        }

}

void ChangeUserInfoDlg::on_strategy_cbx_currentIndexChanged(int index)
{
    index=ui->strategy_cbx->currentIndex();
    cout<<"Index changed : "<<index<<endl;
    if(index==2)
    {
        QLabel *lb=new QLabel(this);
        lb->move(380,220);
        lb->setText(QString::fromLocal8Bit("请输入限制时间"));
        lb->show();

        LimTime_le=new QLineEdit(this);
        LimTime_le->move(550,220);
        LimTime_le->show();
    }
}

void ChangeUserInfoDlg::on_passby_btn_clicked()//弹窗 途经城市
{
    int row=ui->cityNum_lineEdit->text().toInt();
    User->num_passby=row;

    passbyDlg *pDlg=new passbyDlg(this);//弹窗
    pDlg->setPassby_tb(row);
    pDlg->show();
}
