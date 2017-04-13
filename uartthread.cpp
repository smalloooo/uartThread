#include "uartthread.h"
#include "QDebug"

uartThread::uartThread(QObject *parent)
    : QThread(parent)
{
    m_abort = false;
    m_State = 0;
}

uartThread::~uartThread()
{

}

void uartThread::run()
{
    while(1)
    {
        switch (m_State) {
        case FUNC1:
            qDebug()<<"func1";
            break;
        case FUNC2:
            qDebug()<<"func2";
            break;
        case FUNC3:
            qDebug()<<"func3";
            break;
        case FUNC4:
            qDebug()<<"func4";
            break;
        default:
            break;
        }
        m_State = 0;
        msleep(1);
    }
}


