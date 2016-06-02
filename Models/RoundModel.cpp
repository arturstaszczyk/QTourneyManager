#include "RoundModel.h"

RoundModel::RoundModel(QObject *parent)
    : QObject(parent)
    , mRoundTime(0)
    , mBlindsModel(new BlindsModel(this))
{
}

RoundModel::RoundModel(int initialSeconds, int smallBlind, QObject *parent)
    : QObject(parent)
    , mRoundTime(initialSeconds)
    , mBlindsModel(new BlindsModel(smallBlind, this))
{
}
