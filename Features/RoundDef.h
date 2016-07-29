#ifndef ROUNDDEF_H
#define ROUNDDEF_H

#include <QObject>

#include "QAutoProperty.h"

class RoundDef : public QObject
{
    Q_OBJECT

public:
    explicit RoundDef(QObject* parent = nullptr);
    explicit RoundDef(int roundTimeInSeconds, int smallBlind, int bigBlind, bool isBreak, int number, QObject *parent = 0);

    static QString secondsToTimeString(int seconds);

    READONLY_PROPERTY(int, smallBlind)
    READONLY_PROPERTY(int, bigBlind)
    READONLY_PROPERTY(int, roundTimeInSeconds)
    READONLY_PROPERTY(QString, roundTimeString)
    READONLY_PROPERTY(bool, isBreak)
    READONLY_PROPERTY(int, number)

public:
    bool operator < (const RoundDef& other) const
    {
        return this->a_number < other.a_number;
    }

};

#endif // ROUNDDEF_H
