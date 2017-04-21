#ifndef UARTTHREAD_H
#define UARTTHREAD_H

#include <QObject>
#include <QMutex>
#include <QThread>

#include "support.h"

#define SET_PARAMETER 1
#define FUNC2 2
#define FUNC3 3
#define FUNC4 4



class uartThread : public QThread
{
    Q_OBJECT
public:
    explicit uartThread(QObject *parent = 0);
    explicit uartThread(QObject *parent = 0, support *in);
    ~uartThread();

    bool connectComPort();
    QString readStr();
    void writeStr(const QString);

    void setAbort(bool in){m_abort = in;}
    void setState(int in){m_State = in;}
    void setState(int in, IWT_CMD cmdIn){m_State = in, cmd = cmdIn;}

    void setParameter();

protected:
    void run();

signals:

public slots:

private:
    int m_State;
    bool m_abort, m_bIsComConnect;
    QMutex mutex;
    QSerialPort *m_ComPort;
    ComSettings m_ComPortSettings;
    IWT_CMD cmd;
    support *pSupport;
};

#endif // UARTTHREAD_H
