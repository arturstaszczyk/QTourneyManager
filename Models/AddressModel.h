#ifndef ADDRESSMODEL_H
#define ADDRESSMODEL_H

#include <QObject>

class AddressModel : public QObject
{
    Q_OBJECT
public:

    Q_PROPERTY(QString address READ address WRITE setAddress NOTIFY addressChanged)

    explicit AddressModel(QObject *parent = 0);

    void setAddress(QString address);
    QString address() const { return mAddress; }

private:
    QString mAddress;

signals:
    void addressChanged(QString address);
};
#endif // ADDRESSMODEL_H
