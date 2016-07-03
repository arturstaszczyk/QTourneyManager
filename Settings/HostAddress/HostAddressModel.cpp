#include "HostAddressModel.h"


HostAddressModel::HostAddressModel(QObject *parent)
    : QObject(parent)
    , a_address("192.168.0.103")
{
    this->connect(this, SIGNAL(addressChanged(QString)), this, SLOT(onAddressChanged(QString)));
}

void HostAddressModel::onAddressChanged(QString address)
{
    isValid(address.length() > 0);
}

