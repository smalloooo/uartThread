#ifndef UARTTHREAD_H
#define UARTTHREAD_H

#include <QObject>
#include <QMutex>
#include <QThread>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#include "support.h"


#define FUNC1 1
#define FUNC2 2
#define FUNC3 3
#define FUNC4 4

class uartThread : public QThread
{
    Q_OBJECT
public:
    explicit uartThread(QObject *parent = 0);
    ~uartThread();

    void setAbort(bool in){m_abort = in;}
    void setState(int in){m_State = in;}

protected:
    void run();

signals:

public slots:

private:
    int m_State;
    bool m_abort;
    QMutex mutex;
    QSerialPort m_ComPort;
};

#endif // UARTTHREAD_H
