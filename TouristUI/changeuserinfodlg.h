#ifndef CHANGEUSERINFODLG_H
#define CHANGEUSERINFODLG_H

#include <QDialog>
#include<QLineEdit>

namespace Ui {
class ChangeUserInfoDlg;
}

class ChangeUserInfoDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeUserInfoDlg(QWidget *parent = 0);
    ~ChangeUserInfoDlg();

private slots:
    void on_compute_btn_clicked();

    void on_strategy_cbx_currentIndexChanged(int index);

    void on_passby_btn_clicked();

private:
    Ui::ChangeUserInfoDlg *ui;
    QLineEdit *LimTime_le;
};

#endif // CHANGEUSERINFODLG_H
