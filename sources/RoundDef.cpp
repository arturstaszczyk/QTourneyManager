#include "rounddef.h"

RoundDef::RoundDef(QObject *parent)
    : QObject(parent)
{
}

RoundDef::RoundDef(int initialSeconds, int smallBlind, QObject *parent)
    : QObject(parent)
    , mInitialSeconds(initialSeconds)
    , mBlindsDef(smallBlind)
{
}
