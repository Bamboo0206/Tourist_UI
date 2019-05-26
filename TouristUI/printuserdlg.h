#ifndef PRINTUSERDLG_H
#define PRINTUSERDLG_H

#include <QDialog>

namespace Ui {
class PrintUserDlg;
}

class PrintUserDlg : public QDialog
{
    Q_OBJECT

public:
    explicit PrintUserDlg(QWidget *parent = 0);
    ~PrintUserDlg();

private:
    Ui::PrintUserDlg *ui;
};

#endif // PRINTUSERDLG_H
