#ifndef TIME_THREAD_H
#define TIME_THREAD_H

#include "QObject"
#include "QTimer"

class QShow_Time: public QObject
{
    Q_OBJECT

public:
    QShow_Time(QObject *parent = 0);
    virtual ~QShow_Time();

protected:
    virtual void timerEvent(QTimerEvent *event);
    int TimerId;
};






#endif // TIME_THREAD_H
