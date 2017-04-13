#ifndef UARTTHREAD_H
#define UARTTHREAD_H

#include <QObject>

class uartThread : public QObject
{
    Q_OBJECT
public:
    explicit uartThread(QObject *parent = 0);

signals:

public slots:
};

#endif // UARTTHREAD_H