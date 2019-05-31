#include "newroutedlg.h"
#include "ui_newroutedlg.h"
#include"passbydlg.h"
#include<QMessageBox>
#include"main.h"

extern PASSENGER *Passengers , *Passengers_tailPtr 
        , *User;//User当前系统使用者
extern GRAPH city_graph;
extern SYSTEM_TIME System_Time;

newRouteDlg::newRouteDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newRouteDlg)
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

    ui->src_cbx->addItems(cities);
    ui->dest_cbx->addItems(cities);

    cout<<"newRouteDlg showed"<<endl;
}

newRouteDlg::~newRouteDlg()
{
    delete ui;
}


//按下计算路径的按钮
void newRouteDlg::on_pushButton_2_clicked()
{
    /*获取各项输入*/

    User->src = ui->src_cbx->currentIndex();
    User->dest = ui->dest_cbx->currentIndex();
    User->strategy = ui->strategy_cbx->currentIndex();//???????0\1\2???
    if(User->strategy==2)
        User->Time_Limited = LimTime_le->text().toInt();
    else
        User->Time_Limited= NULL;
    User->start_time=System_Time;
    cout<<"src"<<User->src<<" dest"<<User->dest<<" strategy"<<User->strategy<<endl;


    /*调用计算路径的函数*/
    switch (User->strategy)
        {
        case 0:
            Min_Cost();

            cout<<"compute route done."<<endl;
            accept();//退出newRoute窗口
            break;
        case 1:
            Min_Time();
            cout<<"compute route done."<<endl;
            accept();//退出newRoute窗口
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

void newRouteDlg::on_passby_btn_clicked()//弹窗 途经城市
{
    int row=ui->cityNum_lineEdit->text().toInt();
    User->num_passby=row;

    passbyDlg *pDlg=new passbyDlg(this);//弹窗
    pDlg->setPassby_tb(row);
    pDlg->show();
}

void newRouteDlg::on_strategy_cbx_currentIndexChanged(int index)//如果是限制时间最短路径还要输入时间
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
