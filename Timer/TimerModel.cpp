#include "TimerModel.h"

TimerModel::TimerModel(QObject *parent)
    : QObject(parent)
{
    zero();
}

void TimerModel::zero()
{
    smallBlind(0);
    bigBlind(0);
    timeString("--:--");
}
