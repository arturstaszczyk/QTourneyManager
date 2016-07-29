#include "RequestAdminCommand.h"

RequestAdminCommand::RequestAdminCommand(QString deviceId, QString password, QObject *parent)
    : Command(COMMAND_NAME(RequestAdminCommand), parent)
    , mDeviceId(deviceId)
    , mPassword(password)
{

}

void RequestAdminCommand::execute()
{

}
