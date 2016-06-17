#include "AddressModel.h"

#include <QDebug>

AddressModel::AddressModel(QObject *parent)
    : QObject(parent)
{

}

void AddressModel::setAddress(QString address)
{
    qDebug() << address;
    if(mAddress != address)
    {
        mAddress = address;
        emit addressChanged(mAddress);
    }
}
