﻿#ifndef HOSTADDRESSLOGIC_H
#define HOSTADDRESSLOGIC_H

#include <QObject>
#include <QQmlContext>
#include <QNetworkReply>

#include "HostAddressModel.h"
#include "TournamentStructureDef.h"
#include "Commands/CommandRecycler.h"

class HostAddressLogic : public QObject
{
    Q_OBJECT
public:
    explicit HostAddressLogic(QQmlContext* qmlContext, CommandRecycler* commandRecycler, QObject *parent = 0);

signals:
    void onTournamentParsed(TournamentStructureDef* torunament);

public slots:
    void onHostAddressChanged(QString address, bool isValid);

private:
    HostAddressModel* mModel;
    CommandRecycler* mCommandRecycler;
};

#endif // HOSTADDRESSLOGIC_H
