#include "RoundModel.h"

RoundModel::RoundModel(QObject *parent)
    : QObject(parent)
    , mInitialSeconds(0)
    , mBlindsDef(0)
{
}

RoundModel::RoundModel(int initialSeconds, int smallBlind, QObject *parent)
    : QObject(parent)
    , mInitialSeconds(initialSeconds)
    , mBlindsDef(smallBlind)
{
}
