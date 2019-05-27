#ifndef WELCOMEDLG_H
#define WELCOMEDLG_H

#include <QDialog>

namespace Ui {
class WelcomeDlg;
}

class WelcomeDlg : public QDialog
{
    Q_OBJECT

public:
    explicit WelcomeDlg(QWidget *parent = 0);
    ~WelcomeDlg();

private:
    Ui::WelcomeDlg *ui;
};

#endif // WELCOMEDLG_H
