#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<vector>
#include <QPainter>
#include"main.h"
extern GRAPH city_graph;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    vector <QPainterPath> v_Path;


    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void change_sysTime();//修改系统时间的lable
    void initCoordinate();//初始化每个城市的坐标
    void updatePath();/*更新所有路径*/
    void updateTable();

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void on_signIn_btn_clicked();

    void on_signUp_btn_clicked();

    void on_exitSys_btn_clicked();

private:

    Ui::MainWindow *ui;//???????
};



#endif // MAINWINDOW_H
