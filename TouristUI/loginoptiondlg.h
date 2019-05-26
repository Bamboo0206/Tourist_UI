#ifndef LOGINOPTIONDLG_H
#define LOGINOPTIONDLG_H

#include <QDialog>
#include<QWidget>

namespace Ui {
class LoginOptionDlg;
}

class LoginOptionDlg : public QDialog
{
    Q_OBJECT

public:
    explicit LoginOptionDlg(QWidget *parent = 0);
    ~LoginOptionDlg();

private slots:
    void on_OKbtm_clicked();

private:
    Ui::LoginOptionDlg *ui;
};

#endif // LOGINOPTIONDLG_H
