#include "transmiter.h"

Transmiter::Transmiter(QObject *parent) : QObject(parent)
{
    iface = new com::qt::dbus::interface("com.qt.dbus.service","/com/qt/dbus",QDBusConnection::sessionBus(),this);
}

void Transmiter::sendSignalDbus(int data)
{
    QDBusMessage msg = QDBusMessage::createSignal("/com/qt/dbus", "com.qt.dbus.interface", "signalTransmiter");
    msg << data;
    QDBusConnection::sessionBus().send(msg);
}

void Transmiter::methodCallDbus(int data)
{

    qDebug() << "methodCallDbus" << data;

    /*Call Method via Interface*/
    //iface->onMethodCallReceiveData(10);

    /*Call Method via function MethodCall of Qt*/
    QDBusMessage msg = QDBusMessage::createMethodCall("com.qt.dbus.service",
                                                      "/com/qt/dbus",
                                                      "com.qt.dbus.interface",
                                                      "onMethodCallReceiveData");
    msg << data;
    QDBusMessage response = QDBusConnection::sessionBus().call(msg,QDBus::Block,2000);
    //qDebug() << "response is: " << response.errorMessage();

}
