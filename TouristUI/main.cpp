#include "mainwindow.h"
#include <QApplication>
#include"main.h"
#include<windows.h>
#include<process.h>
bool Quit = false;
extern SYSTEM_TIME System_Time;
extern MainWindow *MW;

int main(int argc, char *argv[])
{
    srand((unsigned)time(NULL));

    //准备函数
    if (Prepare() != OK)
        cout << "Function Prepare ERROR" << endl;

    //创建mouse_thread线程和time_thread线程
    HANDLE time_thread = (HANDLE)_beginthreadex(NULL, 0, time, NULL, 0, NULL);
    //HANDLE mouse_thread = (HANDLE)_beginthreadex(NULL, 0, mouse, NULL, 0, NULL);

    QApplication a(argc, argv);
    MainWindow w;
    MW = &w;
    w.initCoordinate();
    w.show();

    //等待线程关闭信号，退出线程
    /*WaitForSingleObject(mouse_thread, MY_INFINITE);
    CloseHandle(mouse_thread);*/
    //等待线程关闭信号，退出线程
    WaitForSingleObject(time_thread, MY_INFINITE);
    CloseHandle(time_thread);

    return a.exec();
}
