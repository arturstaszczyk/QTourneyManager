#ifndef HOSTADDRESSMODEL_H
#define HOSTADDRESSMODEL_H

#include <QObject>
#include "QAutoProperty.h"

class HostAddressModel : public QObject
{
    Q_OBJECT

public:
    explicit HostAddressModel(QObject *parent = 0);

    AUTO_PROPERTY(QString, address)
    AUTO_PROPERTY(bool, isValid)

private slots:
    void onAddressChanged(QString address);

};

#endif // HOSTADDRESSMODEL_H
