#ifndef PLAYERDEF_H
#define PLAYERDEF_H

#include <QObject>

#include "QAutoProperty.h"

class PlayerDef : public QObject
{
    Q_OBJECT
public:
    explicit PlayerDef(QObject *parent = 0);

    AUTO_PROPERTY(QString, nick)
    AUTO_PROPERTY(int, rebuyCount)
    AUTO_PROPERTY(bool, eliminated)

public:
    void setBuyinUrl(QString buyinUrl) { mByuinUrl = buyinUrl; }

private:
    QString mByuinUrl;
};

#endif // PLAYERDEF_H
