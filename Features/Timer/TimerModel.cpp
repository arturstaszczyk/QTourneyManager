#include "TimerModel.h"

TimerModel::TimerModel(QObject *parent)
    : QObject(parent)
{
    zero();
}

void TimerModel::zero()
{
    running(false);
    paused(false);
    activeRound(0);
}
