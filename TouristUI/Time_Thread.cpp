﻿#include"main.h"
#include<windows.h>
#include<process.h>
#include"mainwindow.h"
#include <QElapsedTimer>
#include <QApplication>
#include "time_thread.h"
#include"mainwindow.h"
#include "QDebug"
//#include "QTimer"

SYSTEM_TIME System_Time={2019, 5, 20, 0};
extern bool Quit;
extern GRAPH city_graph;
extern PASSENGER *Passengers;
bool inputing = false;
extern MainWindow *MW;
extern mutex myMutex;//线程锁

//假定最多10个旅客，缓存每个旅客的当前旅行到的第几个城市
int Travelstate[10] = { 0 };

QShow_Time::QShow_Time(QObject *parent)
    :QObject(parent)
{
    TimerId=startTimer(5000);
}

QShow_Time::~QShow_Time()
{
    if(TimerId!=0)
        killTimer(TimerId);
}

void QShow_Time::timerEvent(QTimerEvent *event)
{
    qDebug()<<"timerEvent() called"<<endl;
    if(!inputing)
    {
    //time_thread();
    //MW->paintEvent();
    MW->showUserCoordinate();
    MW->updateTable();
    qDebug()<<"timerEvent() done"<<endl;
   /* if(TimerId!=0)
        killTimer(TimerId);*/
    }
}




//unsigned __stdcall time_thread(void* pArguments)
void time_thread()
{

    //获取当前的时间
    QTime curTime = QTime::currentTime();
    QTime preTime = QTime::currentTime();

    while (Quit == false)
        //if (Quit == false)
	{
        //????
        //QApplication::processEvents();

        //每次循环获取当前的时间//可以再加一句sleep（）
        QTime curTime = QTime::currentTime();

        //if (!inputing)
        if((curTime.second()-preTime.second())>=5
                ||(curTime.minute()-preTime.minute())>0
                ||(curTime.hour()-preTime.hour())>0
                )//大于1s就刷新
		{
            /*线程加锁*/
            lock_guard<mutex> LockGuard(myMutex);//lock_gurad创建的时候开始加锁，在其析构的时候，释放锁。


            preTime=curTime;
             qDebug()<<"looping: time_thread() updating";
            //Sleep(1000);



			System_Time.hour++;
			if (System_Time.hour == 24)
			{
				System_Time.date++;
				System_Time.hour = 0;
			}
			if (System_Time.date == 31)//让我们假设每个月都30天
			{
				System_Time.month++;
				System_Time.date = 1;
			}
			if (System_Time.month == 13)
			{
				System_Time.year++;
				System_Time.month = 1;
			}

			//对所有旅客刷新其旅行状态
			PASSENGER *temp = Passengers;
			int touristnum = 0;
			while (temp != NULL)
			{
				if (temp->status.loca != ARRIVE && Travelstate[touristnum] != 0)
					Refresh(temp, touristnum);

				touristnum++;
				temp = temp->next_passenger;
			}

            /*刷新路径*/
            //MW->updatePath();
            /*刷新时间*/
            MW->change_sysTime();
            /*刷新旅客坐标并显示*/
            //updateUserCoordinate();
            //MW->showUserCoordinate();
            //QShow_Time *show_time=new QShow_Time();

		}
		else if (inputing)
		{
			Sleep(500);//休眠0.5s
            qDebug()<<"looping: time_thread() pause";
		}


        //}

//        if(!inputing)
//        {

//        }


    //MW->change_sysTime();
    //MW->paintEvent();

    /*写需要保存的系统状态*/
    //Write_system_file();
	//释放动态申请的内存
    //Freememory();

    if(Quit==true)
    {
        /*写需要保存的系统状态*/
        Write_system_file();
        //释放动态申请的内存
        Freememory();
        return;//???
    }
    }

    //_endthreadex(0);

    //return 0;
}

bool operator<(const SYSTEM_TIME& A, const SYSTEM_TIME& B)
{
	if (A.year < B.year ||
		A.year == B.year&&A.month < B.month ||
		A.year == B.year&&A.month == B.month&&A.date < B.date ||
		A.year == B.year&&A.month == B.month&&A.date == B.date&&A.hour < B.hour)
		return true;
	else
		return false;
}

SYSTEM_TIME operator+(const SYSTEM_TIME& A, int hour)
{
	SYSTEM_TIME temp = A;

	temp.hour += hour;
	if (temp.hour >= 24)
	{
		temp.date += temp.hour / 24;
		temp.hour = temp.hour % 24;
	}

	while(temp.date >= 31)//让我们假设每个月都30天
	{
		temp.month ++;
		temp.date -=30;
	}

	while(temp.month >= 13)
	{
		temp.year++;
		temp.month -= 12;
	}

	return temp;
}

int operator-(const SYSTEM_TIME& A, const SYSTEM_TIME& B)
{
	return 
		(A.year - B.year) * 12 * 30 * 24 +
		(A.month - B.month) * 30 * 24 +
		(A.date - B.date) * 24 +
		(A.hour - B.hour);
}

//刷新旅客状态
Status Refresh(PASSENGER *tourist, int touristnum)
{
    cout<<"Refresh() called"<<endl;
	PathNode cur;
    char filename[100] = { "D:\\SourceCode\\Tourist_UI\\TouristUI\\User_Route.ini" };
	char str1[100];
	bool RefreshOK = false;

	memset(str1, 0, sizeof(str1));
	sprintf(str1, "No.%d", Travelstate[touristnum]);
    if(GetPrivateProfileStructA(tourist->ID, str1, &cur, sizeof(PathNode), filename)==0)
    {
        cout<<"Refresh ERROR, GetStruct failed"<<endl;
        return Error;
    }

	while (!RefreshOK)
	{
		if (System_Time < cur.start_time)
			//旅客停留在当前城市
		{
			tourist->status = { System_Time , STAY_IN_CITY , cur.src, cur.dest };
			RefreshOK = true;
		}
		else if ((System_Time.year - cur.start_time.year) * 360 * 24 + (System_Time.month - cur.start_time.month) * 30 * 24 +
			(System_Time.date - cur.start_time.date) * 24 + (System_Time.hour - cur.start_time.hour) < cur.time)
			//旅客出发前往下一个城市
        {
			struct trans_t *trans = city_graph.pp_G[cur.src][cur.dest].p_TransTable;
			while (trans != NULL)
			{
				if (trans->number == cur.number)
					break;

				trans = trans->nextPtr;
			}

			tourist->status = { System_Time , (Location)trans->transport , cur.src, cur.dest};
			strcpy(tourist->status.name, trans->name);
			RefreshOK = true;
		}
		else
		{
			//判断是否达到终点
			if (cur.dest == tourist->dest)
			{
				tourist->status= { System_Time , ARRIVE , cur.dest, cur.dest, 0 };
				Travelstate[touristnum] = 0;
				break;
			}

			//旅客已经旅行到了下一个城市
			Travelstate[touristnum]++;
			memset(str1, 0, sizeof(str1));
			sprintf(str1, "No.%d", Travelstate[touristnum]);
			GetPrivateProfileStructA(tourist->ID, str1, &cur, sizeof(PathNode), filename);
            if(GetPrivateProfileStructA(tourist->ID, str1, &cur, sizeof(PathNode), filename)==0)
            {
                cout<<"Refresh ERROR, GetStruct failed"<<endl;
                break;
            }
		}
	}

	return OK;
}

