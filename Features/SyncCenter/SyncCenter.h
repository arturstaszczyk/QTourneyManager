﻿#ifndef SYNCCENTER_H
#define SYNCCENTER_H

#include <QObject>
#include "QAutoProperty.h"

class CommandRecycler;
class SyncCenter : public QObject
{
    Q_OBJECT

    AUTO_PROPERTY(bool, isAdmin)

public:
    explicit SyncCenter(CommandRecycler* commandRecycler, QObject *parent = 0);

signals:
    void refresh();

public slots:
    void onRequestAdmin(QString deviceId, QString password);
    void onHostAddressChanged(QString address);
    void onAdminRequestComplete(bool isAdmin);

private:
    CommandRecycler* mCommandRecycler;

    QString mHostAddress;
};

#endif // SYNCCENTER_H
