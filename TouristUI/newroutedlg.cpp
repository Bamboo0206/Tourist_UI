#include "newroutedlg.h"
#include "ui_newroutedlg.h"
#include"passbydlg.h"
#include"outputroutedlg.h"
#include"main.h"

PASSENGER *Passengers = NULL, *Passengers_tailPtr = NULL
        , *User;//User当前系统使用者

newRouteDlg::newRouteDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newRouteDlg)
{
    ui->setupUi(this);
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
        User->Time_Limited= NULL;//??????

    /*调用计算路径的函数*/
    switch (User->strategy)
        {
        case 0:
            Min_Cost();
            break;
        case 1:
            Min_Time();
            break;
        case 2:
            Min_Time_Limited_Time();
            break;
        default:
            break;
        }

    //弹窗：输出路径
    outputRouteDlg *oDlg=new outputRouteDlg;
    if(oDlg->exec()==QDialog::Accepted)
    {
        accept();//退出newRoute窗口
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
    if(index==2)
    {
        QLabel *lb=new QLabel(this);
        lb->move(200,300);//参数待改
        lb->setText(tr("请输入限制时间"));

        LimTime_le=new QLineEdit(this);
        LimTime_le->move(200,400);
    }
}
