#include "uartthread.h"
#include "QDebug"

uartThread::uartThread(QObject *parent)
    : QThread(parent)
{
    m_abort = false;
    m_State = 0;
    start();
}

uartThread::~uartThread()
{

}

void uartThread::run()
{
    m_ComPort = new QSerialPort();
    m_bIsComConnect = false;
    m_ComPortSettings.name = "COM4";
    m_ComPortSettings.baudRate = QSerialPort::Baud57600;
    m_ComPortSettings.dataBits = QSerialPort::Data8;
    m_ComPortSettings.parity   = QSerialPort::NoParity;
    m_ComPortSettings.stopBits = QSerialPort::OneStop;
    connectComPort();
    setParameter();

    while(1)
    {
        switch (m_State) {
        case SET_PARAMETER:
            setParameter();
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

void uartThread::setParameter()
{
    QString sendCmd = cmd.cmd;
    writeStr(sendCmd);
}

void uartThread::writeStr(const QString cmd)
{
    int waitTimeout = 100;
    QByteArray byteCmd = cmd.toLocal8Bit();
    m_ComPort->write(byteCmd);

    if(m_ComPort->waitForBytesWritten(waitTimeout))
    {
        if(m_ComPort->waitForReadyRead(waitTimeout))
        {
            QByteArray responseData = m_ComPort->readAll();
            while (m_ComPort->waitForReadyRead(10))
                responseData += m_ComPort->readAll();
            QString response(responseData);
            qDebug()<<"response = "<<response;
        }
    }
}

QString uartThread::readStr()
{
    QString res;
    int errCnt = 0;

    while(errCnt < 1000 && !res.contains("\r\n"))
    {
        res.append(m_ComPort->readAll());
        errCnt++;
        msleep(1);
    }
    res = res.mid(0, res.length()-2);
    return res;
}

bool uartThread::connectComPort()
{
    try
    {
        if(m_ComPort->isOpen())
        {
            m_ComPort->close();
        }

        m_ComPort->setPortName(m_ComPortSettings.name);
        m_ComPort->setBaudRate(m_ComPortSettings.baudRate);
        m_ComPort->setDataBits(m_ComPortSettings.dataBits);
        m_ComPort->setStopBits(m_ComPortSettings.stopBits);
        m_ComPort->setParity(  m_ComPortSettings.parity);
        if(m_ComPort->open(QIODevice::ReadWrite))
        {
            m_bIsComConnect = true;
        }
        else
        {
            m_bIsComConnect = false;
        }
    }
    catch(...)
    {
        m_bIsComConnect = false;
    }
    return m_bIsComConnect;
}




