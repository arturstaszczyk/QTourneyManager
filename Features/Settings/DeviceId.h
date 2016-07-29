#ifndef DEVICEID_H
#define DEVICEID_H

#include <QObject>
#include <QUuid>

class DeviceId : public QObject
{
    Q_OBJECT
public:
    explicit DeviceId(QObject *parent = 0);

    QUuid getDeviceId();

private:
    QUuid readFromFile();
    QUuid createUuid();

    void writeToFile(QUuid uuid);

private:
    static QString sConfigFileName;

};

#endif // DEVICEID_H
