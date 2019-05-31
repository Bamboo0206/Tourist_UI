#include "mainwindow.h"

#include <QApplication>
#include "main.h"
#include <windows.h>
#include <process.h>

bool Quit = false;
extern SYSTEM_TIME System_Time;
extern MainWindow *MW;

/*unsigned __stdcall window_thread(void* pArguments)
{
    MainWindow w;
    //MW指针用于关闭mainwindow

    w.initCoordinate();
    w.show();
    cout<<"MainWindow showed"<<endl;
    MW = &w;


    _endthreadex(0);
    return 0;
}*/
void createMainWindow()
{
    MainWindow w;
    //MW指针用于关闭mainwindow

    w.initCoordinate();
    w.show();
    w.change_sysTime();

    cout<<"MainWindow showed"<<endl;
    MW = &w;

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand((unsigned)time(NULL));

    //准备函数
    if (Prepare() != OK)
        cout << "Function Prepare ERROR" << endl;

    cout<<"创建mouse_thread线程和time_thread线程"<<endl;

    //创建mouse_thread线程和time_thread线程
    //HANDLE Time_Thread = (HANDLE)_beginthreadex(NULL, 0, time_thread, NULL, 0, NULL);
    //命令行版本
    //HANDLE mouse_thread = (HANDLE)_beginthreadex(NULL, 0, window_thread, NULL, 0, NULL);

    /*创建线程*/
    thread t(time_thread);
    t.detach();

    /*thread mT(createMainWindow);
    mT.join();*/

    cout<<"创建mouse_thread线程和time_thread线程完成"<<endl;


    MainWindow w;
    //MW指针用于关闭mainwindow

    w.initCoordinate();
    w.show();

    cout<<"MainWindow showed"<<endl;
    MW = &w;


    //等待线程关闭信号，退出线程
    //WaitForSingleObject(mouse_thread, MY_INFINITE);
    //CloseHandle(mouse_thread);
    //等待线程关闭信号，退出线程
    //WaitForSingleObject(Time_Thread, MY_INFINITE);
    //CloseHandle(Time_Thread);

    return a.exec();
}


