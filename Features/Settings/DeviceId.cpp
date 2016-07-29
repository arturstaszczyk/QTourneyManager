#include "DeviceId.h"

#include <QDir>
#include <QFile>
#include <QStandardPaths>

QString DeviceId::sConfigFileName = "device.uuid";

int getRandomNumber(uint _min, uint _max)
{
    return ((qrand() % (_max - _min)) + _min);
}

DeviceId::DeviceId(QObject *parent) : QObject(parent)
{
    qsrand(time(nullptr));
}

QUuid DeviceId::getDeviceId()
{
    QUuid uuid = readFromFile();
    if(uuid.isNull())
        uuid = createUuid();

    writeToFile(uuid);

    return uuid;
}

QUuid DeviceId::createUuid()
{
    return QUuid(getRandomNumber(std::numeric_limits<uint>::min(), std::numeric_limits<uint>::max()),
                 getRandomNumber(std::numeric_limits<ushort>::min(), std::numeric_limits<ushort>::max()),
                 getRandomNumber(std::numeric_limits<ushort>::min(), std::numeric_limits<ushort>::max()),
                 getRandomNumber(std::numeric_limits<uchar>::min(), std::numeric_limits<uchar>::max()),
                 getRandomNumber(std::numeric_limits<uchar>::min(), std::numeric_limits<uchar>::max()),
                 getRandomNumber(std::numeric_limits<uchar>::min(), std::numeric_limits<uchar>::max()),
                 getRandomNumber(std::numeric_limits<uchar>::min(), std::numeric_limits<uchar>::max()),
                 getRandomNumber(std::numeric_limits<uchar>::min(), std::numeric_limits<uchar>::max()),
                 getRandomNumber(std::numeric_limits<uchar>::min(), std::numeric_limits<uchar>::max()),
                 getRandomNumber(std::numeric_limits<uchar>::min(), std::numeric_limits<uchar>::max()),
                 getRandomNumber(std::numeric_limits<uchar>::min(), std::numeric_limits<uchar>::max())
                 );
}

QUuid DeviceId::readFromFile()
{
    QUuid uuid;

    auto path = QStandardPaths::locate(QStandardPaths::AppConfigLocation, DeviceId::sConfigFileName);

    if(path.length() != 0)
    {
        QFile idFile(path);
        idFile.open(QIODevice::ReadOnly);
        auto data = idFile.readAll();
        uuid = QUuid(data);
    }

    return uuid;
}

void DeviceId::writeToFile(QUuid uuid)
{
    auto path = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
    auto dir = QDir(path);
    dir = dir.absolutePath();
    if(!dir.exists())
        dir.mkpath(path);

    QFile idFile(path + "/" + DeviceId::sConfigFileName);
    idFile.open(QIODevice::WriteOnly);
    idFile.write(uuid.toByteArray());
}
