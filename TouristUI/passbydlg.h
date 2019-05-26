#ifndef PASSBYDLG_H
#define PASSBYDLG_H

#include <QDialog>

namespace Ui {
class passbyDlg;
}

class passbyDlg : public QDialog
{
    Q_OBJECT

public:
    explicit passbyDlg(QWidget *parent = 0);
    ~passbyDlg();

    void setPassby_tb(int row);

private slots:
    void on_pushButton_clicked();

private:
    Ui::passbyDlg *ui;

};

#endif // PASSBYDLG_H
