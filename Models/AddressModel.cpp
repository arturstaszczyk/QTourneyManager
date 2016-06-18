#include "AddressModel.h"

#include <QDebug>

AddressModel::AddressModel(QObject *parent)
    : QObject(parent)
{
    this->connect(this, SIGNAL(addressChanged(QString)), this, SLOT(onAddressChanged(QString)));
}

void AddressModel::onAddressChanged(QString address)
{
    isValid(address.length() > 0);
}

