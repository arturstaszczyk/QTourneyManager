#ifndef ADDRESSMODEL_H
#define ADDRESSMODEL_H

#include <QObject>
#include "QAutoProperty.h"

class AddressModel : public QObject
{
    Q_OBJECT

public:
    explicit AddressModel(QObject *parent = 0);

    AUTO_PROPERTY(QString, address)
    AUTO_PROPERTY(bool, isValid)

private slots:
    void onAddressChanged(QString address);

};
#endif // ADDRESSMODEL_H
