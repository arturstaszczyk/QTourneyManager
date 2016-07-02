#include "TimerLogic.h"

#include <math.h>
#include <QtAlgorithms>
#include <QDebug>
#include "ReturnIf.h"
#include "QSortHelpers.h"

TimerLogic::TimerLogic(QQmlContext* context, QList<RoundDef*> rounds, QObject *parent)
    : QObject(parent)
    , mRounds(rounds)
    , mIsPaused(false)
    , mLastTick(0.0f)
    , mElapsedRoundSeconds(0.0f)
{
    mTimerModel = new TimerModel(this);
    context->setContextProperty("timerModel", mTimerModel);
    context->setContextProperty("timerController", this);
}

void TimerLogic::togglePause()
{
    mIsPaused = !mIsPaused;
}

void TimerLogic::nextRound()
{
    resetTime();
    if(hasNextRound())
    {
        mTimerModel->activeRound(mTimerModel->activeRound() + 1);
        mTimerModel->running(true);
    }
    else
    {
        mTimerModel->zero();
        mTimerModel->running(false);
    }
}

void TimerLogic::previousRound()
{
    resetTime();
    if(hasPrevRound())
    {
        mTimerModel->activeRound(mTimerModel->activeRound() - 1);
        mTimerModel->running(true);
    }
    else
    {
        mTimerModel->zero();
        mTimerModel->running(false);
    }
}

bool TimerLogic::hasNextRound() const
{
    return mTimerModel->activeRound() < mRounds.size() - 1;
}

bool TimerLogic::hasPrevRound() const
{
    return mTimerModel->activeRound() > 0;
}

void TimerLogic::addRound(int smallBlind, int bigBlind, int timeInSeconds)
{
    mRounds.append(new RoundDef(timeInSeconds, smallBlind, bigBlind, this));
    qSort(mRounds.begin(), mRounds.end(), QSortHelpers::PtrLess<RoundDef>());

    mTimerModel->rounds(mRounds);
}

void TimerLogic::updateModelTime()
{
    RETURN_IF(!mTimerModel->running());

    auto activeRoundId = mTimerModel->activeRound();
    auto activeRound = mRounds[activeRoundId];

    if(activeRound)
    {
        int secondsLeft = ceil(activeRound->roundTimeInSeconds() - mElapsedRoundSeconds);
        auto secondsLeftStr = RoundDef::secondsToTimeString(secondsLeft);
        mTimerModel->activeRoundRemainingTime(secondsLeftStr);
    }
}

void TimerLogic::resetTime()
{
    mTime.restart();
    mLastTick = 0.0f;
    mElapsedRoundSeconds = 0.0f;
    mIsPaused = false;
}

void TimerLogic::timerEvent(QTimerEvent* event)
{
    Q_UNUSED(event);

    RETURN_IF(!mTimerModel->running())

    float seconds = mTime.elapsed() / 1000.0;
    if(!mIsPaused)
    {
        mElapsedRoundSeconds += seconds - mLastTick;
        mLastTick = seconds;

        auto activeRound = mRounds[mTimerModel->activeRound()];
        if(mElapsedRoundSeconds > activeRound->roundTimeInSeconds())
            nextRound();

        updateModelTime();
    }
    else
        mLastTick = seconds;
}
