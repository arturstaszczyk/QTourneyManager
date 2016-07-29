#ifndef REQUESTADMINCOMMAND_H
#define REQUESTADMINCOMMAND_H

#include <QObject>

#include "Command.h"

class RequestAdminCommand : public Command
{
    Q_OBJECT
public:
    explicit RequestAdminCommand(QString deviceId, QString password, QObject *parent = 0);

    void execute() override;

private:
    QString mDeviceId;
    QString mPassword;
};

#endif // REQUESTADMINCOMMAND_H
