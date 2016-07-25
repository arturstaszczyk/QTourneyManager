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

QQmlListProperty<RoundDef> TimerModel::rounds()
{
    return QQmlListProperty<RoundDef>(this, mRounds);
}

void TimerModel::rounds(QList<RoundDef*> rounds)
{
    mRounds = rounds;
    emit roundsChanged(QQmlListProperty<RoundDef>(this, mRounds));
}
