#ifndef HOSTADDRESSMODEL_H
#define HOSTADDRESSMODEL_H

#include <QObject>
#include "QAutoProperty.h"

class SettingsModel : public QObject
{
    Q_OBJECT

public:
    explicit SettingsModel(QObject *parent = 0);

    AUTO_PROPERTY(QString, address)
    AUTO_PROPERTY(QString, adminPassword)
   // AUTO_PROPERTY(bool, isAddressValid)

private slots:
    //void onAddressChanged(QString address);

};

#endif // HOSTADDRESSMODEL_H
