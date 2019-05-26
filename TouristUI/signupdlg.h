#ifndef SIGNUPDLG_H
#define SIGNUPDLG_H

#include <QDialog>

namespace Ui {
class SignupDlg;
}

class SignupDlg : public QDialog
{
    Q_OBJECT

public:
    explicit SignupDlg(QWidget *parent = 0);
    ~SignupDlg();

private slots:


    void on_signUp_btn_clicked();

private:
    Ui::SignupDlg *ui;
};

#endif // SIGNUPDLG_H
