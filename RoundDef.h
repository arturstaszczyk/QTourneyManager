#ifndef ROUNDDEF_H
#define ROUNDDEF_H

#include <QObject>

#include "QAutoProperty.h"

class RoundDef : public QObject
{
    Q_OBJECT

public:
    explicit RoundDef(QObject* parent = nullptr);
    explicit RoundDef(int roundTimeInSeconds, int smallBlind, int bigBlind, QObject *parent = 0);

    READONLY_PROPERTY(int, smallBlind)
    READONLY_PROPERTY(int, bigBlind)
    READONLY_PROPERTY(int, roundTimeInSeconds)
    READONLY_PROPERTY(bool, isValid)
};

#endif // ROUNDDEF_H
