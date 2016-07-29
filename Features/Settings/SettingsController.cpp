#include "SettingsController.h"

#include <QCryptographicHash>

#include "ReturnIf.h"

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
    RETURN_IF(!isValid);

    mModel->address(address);
    emit hostAddressChanged(address);
}

void SettingsController::onAdminPasswordChanged(QString adminPassword)
{
    RETURN_IF(adminPassword.length() == 0);

    QCryptographicHash hash(QCryptographicHash::Sha3_256);
    hash.addData(adminPassword.toUtf8());
    QString base64Hash(hash.result().toBase64());

    emit adminPasswordChanged("device_id", base64Hash);
}
