#include "TimerLogic.h"

#include "ReturnIf.h"
#define NO_ACTIVE_ROUND -1

TimerLogic::TimerLogic(QQmlContext* context, TimerModel* timerModel, QList<RoundDef*> rounds, QObject *parent)
    : QObject(parent)
    , mTimerModel(timerModel)
    , mRounds(rounds)
    , mActiveRound(NO_ACTIVE_ROUND)
    , mIsPaused(false)
    , mLastTick(0.0f)
    , mElapsedRoundSeconds(0.0f)
    , mElapsedPasueSeconds(0.0f)
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
    {
        mActiveRound++;
        RoundDef* activeRound = mRounds[mActiveRound];

        mTimerModel->smallBlind(activeRound->smallBlind());
        mTimerModel->bigBlind(activeRound->bigBlind());
    }
    else
    {
        mActiveRound = NO_ACTIVE_ROUND;
        mTimerModel->zero();
    }
}

void TimerLogic::previousRound()
{
    resetTime();
    if(hasPrevRound())
    {
        mActiveRound--;
        RoundDef* activeRound = mRounds[mActiveRound];
        mTimerModel->smallBlind(activeRound->smallBlind());
        mTimerModel->bigBlind(activeRound->bigBlind());
    }
    else
    {
        mActiveRound = NO_ACTIVE_ROUND;
        mTimerModel->zero();
    }
}

bool TimerLogic::hasNextRound() const
{
    return mActiveRound < mRounds.size() - 1;
}

bool TimerLogic::hasPrevRound() const
{
    return mActiveRound > 0;
}

void TimerLogic::resetTime()
{
    mTime.restart();
    mLastTick = 0.0f;
    mElapsedRoundSeconds = mElapsedPasueSeconds = 0.0f;
    mIsPaused = false;
}

void TimerLogic::timerEvent(QTimerEvent* event)
{
    Q_UNUSED(event);

    RETURN_IF(mActiveRound == NO_ACTIVE_ROUND)

    RoundDef* activeRound = mRounds[mActiveRound];
    float seconds = mTime.elapsed() / 1000.0;
    if(mIsPaused)
    {
        mLastTick = seconds;
    }
    else
    {
        mElapsedRoundSeconds += seconds - mLastTick;
        mLastTick = seconds;

        if(mElapsedRoundSeconds > activeRound->roundTimeInSeconds())
            nextRound();

        mTimerModel->timeString(QString("%1").arg(mElapsedRoundSeconds));
    }
}
