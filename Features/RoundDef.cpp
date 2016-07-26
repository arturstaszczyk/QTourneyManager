#include "RoundDef.h"


RoundDef::RoundDef(QObject* parent)
    : QObject(parent)
{
}

RoundDef::RoundDef(int roundTimeInSeconds, int smallBlind, int bigBlind, QObject *parent)
    : QObject(parent)
    , a_smallBlind(smallBlind)
    , a_bigBlind(bigBlind)
    , a_roundTimeInSeconds(roundTimeInSeconds)
    , a_roundTimeString(RoundDef::secondsToTimeString(roundTimeInSeconds))
{

}

QString RoundDef::secondsToTimeString(int seconds)
{
    return QString("%1:%2").
            arg(seconds / 60, 2, 10, QChar('0')).
            arg(seconds % 60, 2, 10, QChar('0'));

}
