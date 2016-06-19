#include "HostAddressModel.h"


HostAddressModel::HostAddressModel(QObject *parent)
    : QObject(parent)
{
    this->connect(this, SIGNAL(addressChanged(QString)), this, SLOT(onAddressChanged(QString)));
}

void HostAddressModel::onAddressChanged(QString address)
{
    isValid(address.length() > 0);
}

