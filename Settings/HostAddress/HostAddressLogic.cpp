#include "HostAddressLogic.h"

HostAddressLogic::HostAddressLogic(QQmlContext* qmlContext, HostAddressModel* model, QObject *parent)
    : QObject(parent)
    , mModel(model)
{
    qmlContext->setContextProperty("hostAddressModel", model);
    qmlContext->setContextProperty("hostAddressController", this);
}

void HostAddressLogic::onHostAddressChanged(QString address, bool isValid)
{
    if(isValid)
        mModel->address(address);
}
