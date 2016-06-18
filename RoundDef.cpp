#include "RoundDef.h"

RoundDef::RoundDef(QObject* parent)
    : QObject(parent)
    , a_isValid(false)
{
}

RoundDef::RoundDef(int roundTimeInSeconds, int smallBlind, int bigBlind, QObject *parent)
    : QObject(parent)
    , a_smallBlind(smallBlind)
    , a_bigBlind(bigBlind)
    , a_roundTimeInSeconds(roundTimeInSeconds)
    , a_isValid(true)
{
}
