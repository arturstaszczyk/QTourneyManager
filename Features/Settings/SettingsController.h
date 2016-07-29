#ifndef HOSTADDRESSLOGIC_H
#define HOSTADDRESSLOGIC_H

#include <QObject>
#include <QQmlContext>
#include <QJsonObject>
#include <QNetworkReply>

#include "SettingsModel.h"
#include "Commands/CommandRecycler.h"
#include "Features/TournamentStructureDef.h"

class SettingsController : public QObject
{
    Q_OBJECT
public:
    explicit SettingsController(QQmlContext* qmlContext, CommandRecycler* commandRecycler, QObject *parent = 0);

signals:
    void hostAddressChanged(QString);
    void adminPasswordChanged(QString deviceId, QString base64Hash);

public slots:
    void onHostAddressChanged(QString address, bool isValid);
    void onAdminPasswordChanged(QString adminPassword);

private:
    SettingsModel* mModel;
    CommandRecycler* mCommandRecycler;
};

#endif // HOSTADDRESSLOGIC_H
