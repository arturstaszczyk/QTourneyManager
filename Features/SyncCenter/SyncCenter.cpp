#include "SyncCenter.h"

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
    RequestAdminCommand* requestAdminCmd = new RequestAdminCommand();
    connect(requestAdminCmd, SIGNAL(adminRequestComplete(bool, QString)), this, SLOT(onAdminRequestComplete(bool, QString)));
    mCommandRecycler->executeAndDispose(requestAdminCmd);
}
