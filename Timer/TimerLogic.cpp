#include "TimerLogic.h"

#include <math.h>
#include <QtAlgorithms>

#include "ReturnIf.h"
#include "QSortHelpers.h"

#define NO_ACTIVE_ROUND -1

TimerLogic::TimerLogic(QQmlContext* context, TimerModel* timerModel, QList<RoundDef*> rounds, QObject *parent)
    : QObject(parent)
    , mTimerModel(timerModel)
    , mRounds(rounds)
    , mActiveRound(NO_ACTIVE_ROUND)
    , mIsPaused(false)
    , mLastTick(0.0f)
    , mElapsedRoundSeconds(0.0f)
{
    context->setContextProperty("timerModel", timerModel);
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
        mActiveRound++;
    else
        mActiveRound = NO_ACTIVE_ROUND;

    updateModelBlinds();
}

void TimerLogic::previousRound()
{
    resetTime();
    if(hasPrevRound())
        mActiveRound--;
    else
        mActiveRound = NO_ACTIVE_ROUND;
    updateModelBlinds();
}

bool TimerLogic::hasNextRound() const
{
    return mActiveRound < mRounds.size() - 1;
}

bool TimerLogic::hasPrevRound() const
{
    return mActiveRound > 0;
}

void TimerLogic::addRound(int smallBlind, int bigBlind, int timeInSeconds)
{
    mRounds.append(new RoundDef(timeInSeconds, smallBlind, bigBlind, this));
    qSort(mRounds.begin(), mRounds.end(), QSortHelpers::PtrLess<RoundDef>());
}

void TimerLogic::updateModelBlinds()
{
    RoundDef* activeRound = nullptr;
    if(mActiveRound >= 0)
        activeRound = mRounds[mActiveRound];

    if(activeRound)
    {
        mTimerModel->smallBlind(activeRound->smallBlind());
        mTimerModel->bigBlind(activeRound->bigBlind());
    }
    else
        mTimerModel->zero();
}

void TimerLogic::updateModelTime()
{
    RoundDef* activeRound = nullptr;
    if(mActiveRound >= 0)
        activeRound = mRounds[mActiveRound];

    if(activeRound)
    {
        int secondsLeft = ceil(activeRound->roundTimeInSeconds() - mElapsedRoundSeconds);
        auto out = QString("%1:%2").
                arg(secondsLeft / 60, 2, 10, QChar('0')).
                arg(secondsLeft % 60, 2, 10, QChar('0'));
        mTimerModel->timeString(out);
    }
    else
        mTimerModel->zero();
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

    RETURN_IF(mActiveRound == NO_ACTIVE_ROUND)

    float seconds = mTime.elapsed() / 1000.0;
    if(!mIsPaused)
    {
        mElapsedRoundSeconds += seconds - mLastTick;
        mLastTick = seconds;

        auto activeRound = mRounds[mActiveRound];
        if(mElapsedRoundSeconds > activeRound->roundTimeInSeconds())
            nextRound();

        updateModelTime();
    }
    else
        mLastTick = seconds;
}
