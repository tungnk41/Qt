#ifndef RECEIVER_H
#define RECEIVER_H
#include <QObject>
#include <QDBusConnection>
#include <QDebug>
#include "dbus_interface.h"
#include "dbus_adaptor.h"


class Receiver : public QObject
{
    Q_OBJECT
public:
    Receiver();
    virtual ~Receiver();
signals:
public slots:
    void onMethodCallReceiveData(int);
    void onSignalReceiveData(int);
private:
    com::qt::dbus::interface *iface;
    InterfaceAdaptor *adaptor;
};

#endif // RECEIVER_H
