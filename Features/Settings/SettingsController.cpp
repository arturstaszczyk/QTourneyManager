#include "SettingsController.h"

SettingsController::SettingsController(QQmlContext* qmlContext, CommandRecycler* commandRecycler, QObject *parent)
    : QObject(parent)
    , mCommandRecycler(commandRecycler)
{
    mModel = new SettingsModel(this);
    qmlContext->setContextProperty("settingsModel", mModel);
    qmlContext->setContextProperty("settingsController", this);
}

void SettingsController::onHostAddressChanged(QString address, bool isValid)
{
    if(isValid)
    {
        mModel->address(address);
        emit hostAddressChanged(address);
    }
}
