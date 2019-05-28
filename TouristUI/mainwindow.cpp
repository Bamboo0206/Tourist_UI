#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logindlg.h"
#include "loginoptiondlg.h"
#include "newroutedlg.h"
#include "signupdlg.h"
#include "printuserdlg.h"
#include "passbydlg.h"
#include "outputroutedlg.h"
#include <QImage>
#include <QtGui>
#include <vector>
#include "main.h"
#include "time_thread.h"

extern bool inputing;
extern bool Quit;
extern PASSENGER *Passengers, *Passengers_tailPtr, *User;//User当前系统使用者
extern SYSTEM_TIME System_Time;
extern GRAPH city_graph;
extern int Travelstate[10];

MainWindow *MW;
COORDINATE coordinate[100/*城市数量*/];

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    cout<<"creating MainWindow"<<endl;
    ui->setupUi(this);

    /*添加图片*/
    QImage *img=new QImage;//新建一个image对象
    if(!(img->load("D:/SourceCode/Tourist_UI/TouristUI/map.jpg")))//将图像资源载入对象img
    {
        ui->pic_lb->setText("fail to load picture");
    }
    else
        ui->pic_lb->setPixmap((QPixmap::fromImage(*img)));

    /*设置当前用户的表格*/
    ui->allUser_tb->setColumnCount(4);//列数
    ui->allUser_tb->setHorizontalHeaderLabels(
                QStringList()<<QString::fromLocal8Bit("用户名")
                <<QStringList()<<QString::fromLocal8Bit("状态")
                <<QStringList()<<QString::fromLocal8Bit("所在地")
                <<QStringList()<<QString::fromLocal8Bit("班次"));
    ui->allUser_tb->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止修改

    QShow_Time *showtime=new QShow_Time(this);

    /*添加定时器*/
    QTimer *timer=new QTimer(this);//声明一个定时器
    //连接信号与槽
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));//更新画图
    timer->start(1000);//每1000ms timeout一次，于是就update一次

    cout<<"create MainWindow successfully"<<endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_signIn_btn_clicked()//登陆
{
    inputing=true;
    LoginDlg *lDlg=new LoginDlg(this);
    if(lDlg->exec()==QDialog::Accepted)
    {
        /*显示选择操作的窗口*/
        LoginOptionDlg *loDlg=new LoginOptionDlg(this);
        loDlg->show();
    }
    inputing=false;
}

void MainWindow::on_signUp_btn_clicked()//注册
{
    inputing=true;
    SignupDlg *sDlg=new SignupDlg(this);
    if(sDlg->exec()==QDialog::Accepted)
    {
        newRouteDlg nDlg(this);//新建一个窗口（对象），并等待返回值
        if(nDlg.exec()==QDialog::Accepted)
        {
            cout<<"newRout Dialog accepted"<<endl;

            //初始化用户状态，用于输出
            PASSENGER *temp=Passengers;
            int touristnum=0;
            while(temp!=User)
            {
                temp=temp->next_passenger;
                touristnum++;
            }
            Refresh(User, touristnum);

            /*在mainWindow界面里的表格里增加一行*/
            int RowCount=ui->allUser_tb->rowCount();
            ui->allUser_tb->insertRow(RowCount);
            /*待改 插入元素*/
            ui->allUser_tb->setItem(RowCount,0,new QTableWidgetItem(tr(User->ID)));//改为变量

            string loca[5] = { "IN_CAR", "IN_TRAIN", "IN_AIRPLANE", "STAY_IN_CITY" , "ARRIVE" };

            //旅客姓名      状态                  地点                  车次
            //a            STAY_IN_CITY         A
            //b            IN_CAR               B --> C               Q26
            //c            ARRIVE               D

            switch (User->status.loca) {
            case STAY_IN_CITY:
                ui->allUser_tb->setItem(RowCount,1,new QTableWidgetItem(tr(loca[3].c_str())));
                ui->allUser_tb->setItem(RowCount,2,new QTableWidgetItem(QString::fromLocal8Bit(city_graph.City_Name[User->status.src])));
                break;
            case ARRIVE:
                ui->allUser_tb->setItem(RowCount,1,new QTableWidgetItem(tr(loca[4].c_str())));
                ui->allUser_tb->setItem(RowCount,2,new QTableWidgetItem(QString::fromLocal8Bit(city_graph.City_Name[User->status.dest])));
                break;
            default:
                ui->allUser_tb->setItem(RowCount,1,new QTableWidgetItem(tr(loca[(int)User->status.loca].c_str())));
                string s1=city_graph.City_Name[User->status.src];
                string s2=city_graph.City_Name[User->status.dest];
                string s3=" --> ";
                string str=s1+s3+s2;
                ui->allUser_tb->setItem(RowCount,2,new QTableWidgetItem(QString::fromLocal8Bit(str.c_str())));

                ui->allUser_tb->setItem(RowCount,3,new QTableWidgetItem(tr(User->status.name)));
                break;
            }

            ui->allUser_tb->show();
            cout<<"add Row in main table done"<<endl;
        }
    }
    inputing=false;
}


void MainWindow::paintEvent(QPaintEvent *)
{
    /*刷新路径*/
    updatePath();
    /*刷新时间*/
    change_sysTime();

    /*画出所有路径*/
    QPainter painter(this);
    PASSENGER *temp=Passengers;
    while(temp!=NULL)
    {
        if(temp->qPath!=NULL)
        {
            /*设置画笔颜色 随机数？不应该在这里随机？不然每次颜色不一样*/
            QPen pen;
            pen.setColor(QColor(temp->red, temp->green, temp->blue));//分量红、绿、蓝的值
            pen.setWidth(5);
            painter.setPen(pen); //添加画笔

            /*画图*/
            painter.save();
            painter.drawPath(*(temp->qPath));
            painter.restore();
        }
        temp=temp->next_passenger;
    }

}
void MainWindow::updatePath()
{
    /*更新所有路径*/
    PASSENGER *temp=Passengers;
    while(temp!=NULL)
    {
        if(temp->status.loca==STAY_IN_CITY)
        {
            int CurrentCity=temp->status.src;
            int x,y;
            x=coordinate[CurrentCity].x;
            y=coordinate[CurrentCity].y;
            temp->qPath->lineTo((qreal)x,(qreal)y);
        }
        else if(temp->status.loca==ARRIVE)//到达终点，删除路径
        {
            delete temp->qPath;
            temp->qPath=NULL;
        }
        else//途中
        {
            int src=temp->status.src;
            int dest=temp->status.dest;
            /*取src\dest中点*/
            int x,y;
            x=(coordinate[src].x+coordinate[dest].x)/2;
            y=(coordinate[src].y+coordinate[dest].y)/2;
            temp->qPath->lineTo((qreal)x,(qreal)y);
        }

        temp=temp->next_passenger;
    }
}

void MainWindow::initCoordinate()//初始化每个城市的坐标
{
    coordinate[0].x=780;
    coordinate[0].y=339;
    coordinate[1].x=793;
    coordinate[1].y=365;
    coordinate[2].x=627;
    coordinate[2].y=488;
    coordinate[3].x=880;
    coordinate[3].y=561;
    coordinate[4].x=734;
    coordinate[4].y=579;
    coordinate[5].x=526;
    coordinate[5].y=573;
    coordinate[6].x=500;
    coordinate[6].y=704;
    coordinate[7].x=708;
    coordinate[7].y=632;
    coordinate[8].x=714;
    coordinate[8].y=747;
    coordinate[9].x=823;
    coordinate[9].y=542;
    cout<<"initial coordinate successfully"<<endl;
}

void MainWindow::on_exitSys_btn_clicked()
{
    Quit=true;
    MW->close();
}

void MainWindow::change_sysTime()
{
    char t[100];
    sprintf(t,"%d-%d-%d****%d:00:00",
           System_Time.year, System_Time.month, System_Time.date, System_Time.hour);
    ui->SysTime_lb->setText(t);//打印系统时间
}

void MainWindow::updateTable()//更新main里的表格
{
    string loca[5] = { "IN_CAR", "IN_TRAIN", "IN_AIRPLANE", "STAY_IN_CITY" , "ARRIVE" };
    int RowCount=ui->allUser_tb->rowCount();
    PASSENGER *temp=Passengers;
    int Row=0;
    while(temp!=NULL&&Row<RowCount)
    {
        ui->allUser_tb->setItem(Row,0,new QTableWidgetItem(tr(User->ID)));//改为变量

        switch (User->status.loca) {
        case STAY_IN_CITY:
            ui->allUser_tb->setItem(Row,1,new QTableWidgetItem(tr(loca[3].c_str())));
            ui->allUser_tb->setItem(Row,2,new QTableWidgetItem(tr(city_graph.City_Name[User->status.src])));
            break;
        case ARRIVE:
            ui->allUser_tb->setItem(Row,1,new QTableWidgetItem(tr(loca[4].c_str())));
            ui->allUser_tb->setItem(Row,2,new QTableWidgetItem(tr(city_graph.City_Name[User->status.dest])));
            break;
        default:
            ui->allUser_tb->setItem(Row,1,new QTableWidgetItem(tr(loca[(int)User->status.loca].c_str())));
            string s1=city_graph.City_Name[User->status.src];
            string s2=city_graph.City_Name[User->status.dest];
            string s3="-->";
            string str=s1+s3+s2;
            ui->allUser_tb->setItem(RowCount,2,new QTableWidgetItem(tr(str.c_str())));


            ui->allUser_tb->setItem(RowCount,3,new QTableWidgetItem(tr(User->status.name)));
            break;
        }
    }
}
