#include "receiver.h"

Receiver::Receiver()
{
    /*Create Service,Interface on dbus linux*/
    /*Method call need registerService and registerObject*/
    /*Signal dont need registerService and registerObject*/
    QDBusConnection::sessionBus().registerObject("/com/qt/dbus",this);
    QDBusConnection::sessionBus().registerService("com.qt.dbus.service");
    /*Attach local method to Interface dbus method, when interface method is called, local method will call automatic*/
    /*Bring this object to dbus */
    adaptor = new InterfaceAdaptor(this);

    iface = new com::qt::dbus::interface("com.qt.dbus.service","/com/qt/dbus",QDBusConnection::sessionBus(),this);
    if(!iface){
        qDebug() <<"Can not connect Session bus";
    }

    /*Connect dbus signal with slot local*/
    QDBusConnection::sessionBus().connect(QString(),QString(),"com.qt.dbus.interface","signalTransmiter",this,SLOT(onSignalReceiveData(int)));
}

Receiver::~Receiver()
{

}

void Receiver::onMethodCallReceiveData(int data)
{

    qDebug()<< "onMethodCallReceiveData " <<  data;
}

void Receiver::onSignalReceiveData(int data)
{
    qDebug()<< "onSignalReceiveData " << data;
}
