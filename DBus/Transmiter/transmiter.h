#ifndef TRANSMITER_H
#define TRANSMITER_H

#include <QObject>
#include <QDebug>
#include "dbus_interface.h"


class Transmiter : public QObject
{
    Q_OBJECT
public:
    explicit Transmiter(QObject *parent = nullptr);
signals:
public slots:
    void methodCallDbus(int);
    void sendSignalDbus(int);
private:
    com::qt::dbus::interface *iface;

};

#endif // TRANSMITER_H
