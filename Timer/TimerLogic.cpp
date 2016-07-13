#include "TimerLogic.h"

#include <math.h>
#include <QtAlgorithms>
#include <QDebug>
#include "ReturnIf.h"
#include "QSortHelpers.h"

TimerLogic::TimerLogic(QQmlContext* context, QList<RoundDef*> rounds, QObject *parent)
    : QObject(parent)
    , mLastTick(0.0f)
    , mElapsedRoundSeconds(0.0f)
{
    mModel = new TimerModel(this);
    mModel->rounds(rounds);

    context->setContextProperty("timerModel", mModel);
    context->setContextProperty("timerController", this);

    mTime.start();
}

void TimerLogic::togglePause()
{
    mModel->running(!mModel->running());
}

void TimerLogic::nextRound()
{
    resetTime();
    if(hasNextRound())
    {
        mModel->activeRound(mModel->activeRound() + 1);
        mModel->running(true);
    }
    else
    {
        mModel->zero();
        mModel->running(false);
    }
}

void TimerLogic::previousRound()
{
    resetTime();
    if(hasPrevRound())
    {
        mModel->activeRound(mModel->activeRound() - 1);
        mModel->running(true);
    }
    else
    {
        mModel->zero();
        mModel->running(false);
    }
}

bool TimerLogic::hasNextRound() const
{
    auto rounds = mModel->rawRoundsList();
    return mModel->activeRound() < rounds.size() - 1;
}

bool TimerLogic::hasPrevRound() const
{
    return mModel->activeRound() > 0;
}

//void TimerLogic::addRound(int smallBlind, int bigBlind, int timeInSeconds)
//{
//    QList<RoundDef*> rounds = mModel->rawRoundsList();
//    rounds.append(new RoundDef(timeInSeconds, smallBlind, bigBlind, this));
//    qSort(rounds.begin(), rounds.end(), QSortHelpers::PtrLess<RoundDef>());

//    mModel->rounds(rounds);
//}

void TimerLogic::addStructure(TournamentStructureDef *tournament)
{
    QList<RoundDef*> rounds = tournament->rounds();
    qSort(rounds.begin(), rounds.end(), QSortHelpers::PtrLess<RoundDef>());
    mModel->rounds(rounds);
}

void TimerLogic::updateModelTime()
{
    RETURN_IF(!mModel->running());

    auto activeRoundId = mModel->activeRound();
    auto rounds = mModel->rawRoundsList();
    auto activeRound = rounds[activeRoundId];

    if(activeRound)
    {
        int secondsLeft = ceil(activeRound->roundTimeInSeconds() - mElapsedRoundSeconds);
        auto secondsLeftStr = RoundDef::secondsToTimeString(secondsLeft);
        mModel->activeRoundRemainingTime(secondsLeftStr);
    }
}

void TimerLogic::resetTime()
{
    mTime.restart();
    mLastTick = 0.0f;
    mElapsedRoundSeconds = 0.0f;
}

void TimerLogic::timerEvent(QTimerEvent* event)
{
    Q_UNUSED(event);

    float seconds = mTime.elapsed() / 1000.0;
    if(mModel->running())
    {
        mElapsedRoundSeconds += seconds - mLastTick;
        mLastTick = seconds;

        auto rounds = mModel->rawRoundsList();
        auto activeRoundId = mModel->activeRound();
        auto activeRound = rounds[activeRoundId];
        if(mElapsedRoundSeconds > activeRound->roundTimeInSeconds())
            nextRound();

        updateModelTime();
    }
    else
        mLastTick = seconds;
}
