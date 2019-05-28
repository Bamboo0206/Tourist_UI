#ifndef OUTPUTROUTEDLG_H
#define OUTPUTROUTEDLG_H

#include <QDialog>

namespace Ui {
class outputRouteDlg;
}

class outputRouteDlg : public QDialog
{
    Q_OBJECT

public:
    explicit outputRouteDlg(QWidget *parent = 0/*, PATH tour*/);
    ~outputRouteDlg();

private slots:

    void on_start_btn_clicked();

private:
    Ui::outputRouteDlg *ui;
};

#endif // OUTPUTROUTEDLG_H
