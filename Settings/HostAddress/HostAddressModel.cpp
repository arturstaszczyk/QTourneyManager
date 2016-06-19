#include "HostAddressModel.h"


HostAddressModel::HostAddressModel(QObject *parent)
    : QObject(parent)
    , a_address("127.0.0.1")
{
    this->connect(this, SIGNAL(addressChanged(QString)), this, SLOT(onAddressChanged(QString)));
}

void HostAddressModel::onAddressChanged(QString address)
{
    isValid(address.length() > 0);
}

