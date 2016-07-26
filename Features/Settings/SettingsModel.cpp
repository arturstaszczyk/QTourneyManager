#include "SettingsModel.h"


SettingsModel::SettingsModel(QObject *parent)
    : QObject(parent)
    , a_address("192.168.0.103")
{
    //this->connect(this, SIGNAL(addressChanged(QString)), this, SLOT(onAddressChanged(QString)));
}

//void SettingsModel::onAddressChanged(QString address)
//{
//    isValid(address.length() > 0);
//}

