#ifndef NEWROUTEDLG_H
#define NEWROUTEDLG_H

#include <QDialog>
#include<QLineEdit>

namespace Ui {
class newRouteDlg;
}

class newRouteDlg : public QDialog
{
    Q_OBJECT

public:
    explicit newRouteDlg(QWidget *parent = 0);
    ~newRouteDlg();

private slots:

    void on_pushButton_2_clicked();

    void on_passby_btn_clicked();

    void on_strategy_cbx_currentIndexChanged(int index);

private:
    Ui::newRouteDlg *ui;
    QLineEdit *LimTime_le;
};

#endif // NEWROUTEDLG_H
