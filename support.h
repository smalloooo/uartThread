#ifndef SUPPORT_H
#define SUPPORT_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

struct ComSettings {
    QString name;
    qint32 baudRate;
    QString stringBaudRate;
    QSerialPort::DataBits dataBits;
    QString stringDataBits;
    QSerialPort::Parity parity;
    QString stringParity;
    QSerialPort::StopBits stopBits;
    QString stringStopBits;
    QSerialPort::FlowControl flowControl;
    QString stringFlowControl;
    bool localEchoEnabled;
};

struct IWT_CMD{
    QString cmd;
    QString para1;
    QString para2;
    QString para3;
};

class support
{
public:
    support();


private:


};

#endif // SUPPORT_H
