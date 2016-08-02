#ifndef REQUESTADMINCOMMAND_H
#define REQUESTADMINCOMMAND_H

#include <QObject>
#include <QNetworkReply>

#include "Command.h"

class RequestAdminCommand : public Command
{
    Q_OBJECT
public:
    explicit RequestAdminCommand(QString hostAddress, QString deviceId, QString password, QObject *parent = 0);

    void execute() override;

private slots:
    void onAdminRequestGet(QNetworkReply*reply);

private:
    QString mDeviceId;
    QString mPassword;
    QString mHostAddress;
};

#endif // REQUESTADMINCOMMAND_H
