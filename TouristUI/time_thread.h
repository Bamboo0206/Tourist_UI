#ifndef TIME_THREAD_H
#define TIME_THREAD_H

#include "QObject"

class QShow_Time: public QObject
{
    Q_OBJECT

public:
    QShow_Time(QObject *parent = 0);
    virtual ~QShow_Time();

protected:
    void timerEvent(QTimerEvent *event);
    int TimerId;
};






#endif // TIME_THREAD_H
