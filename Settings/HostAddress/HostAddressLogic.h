﻿#ifndef HOSTADDRESSLOGIC_H
#define HOSTADDRESSLOGIC_H

#include <QObject>
#include <QQmlContext>

#include "HostAddressModel.h"

class HostAddressLogic : public QObject
{
    Q_OBJECT
public:
    explicit HostAddressLogic(QQmlContext* qmlContext, HostAddressModel* model, QObject *parent = 0);

public slots:
    void onHostAddressChanged(QString address, bool isValid);

private:
    HostAddressModel* mModel;

};

#endif // HOSTADDRESSLOGIC_H
