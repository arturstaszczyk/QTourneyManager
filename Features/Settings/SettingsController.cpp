#include "SettingsController.h"

#include <QDebug>
#include <QCryptographicHash>

#include "ReturnIf.h"
#include "DeviceId.h"

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

    qDebug() << base64Hash;
    DeviceId deviceId;
    emit adminPasswordChanged(deviceId.getDeviceId().toString(), base64Hash);
}
