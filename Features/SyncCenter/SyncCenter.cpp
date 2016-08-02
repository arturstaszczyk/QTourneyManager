#include "SyncCenter.h"

#include <QDebug>

#include "Commands/CommandRecycler.h"
#include "Commands/RequestAdminCommand.h"

SyncCenter::SyncCenter(CommandRecycler* commandRecycler, QObject *parent)
    : QObject(parent)
    , mCommandRecycler(commandRecycler)
{

}

void SyncCenter::onHostAddressChanged(QString address)
{
    mHostAddress = address;
}

void SyncCenter::onRequestAdmin(QString deviceId, QString password)
{
    RequestAdminCommand* requestAdminCmd = new RequestAdminCommand(mHostAddress, deviceId, password);
    connect(requestAdminCmd, SIGNAL(adminRequestComplete(bool)), this, SLOT(onAdminRequestComplete(bool)));
    mCommandRecycler->executeAndDispose(requestAdminCmd);
}

void SyncCenter::onAdminRequestComplete(bool isAdmin)
{
    this->isAdmin(isAdmin);
}
