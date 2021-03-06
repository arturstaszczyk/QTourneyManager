﻿#include "TimerController.h"

#include <math.h>
#include <QDebug>
#include <QSound>
#include <QtAlgorithms>
#include "ReturnIf.h"
#include "QSortHelpers.h"

TimerController::TimerController(QQmlContext* context, QList<RoundDef*> rounds, QObject *parent)
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

void TimerController::togglePause()
{
    RETURN_IF(mModel->roundsRaw().empty());

    if(mModel->running())
    {
        mModel->paused(!mModel->paused());
    }
    else
    {
        mModel->running(true);
        mModel->paused(false);
    }
}

void TimerController::nextRound()
{
    RETURN_IF(mModel->roundsRaw().empty());

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

void TimerController::previousRound()
{
    RETURN_IF(mModel->roundsRaw().empty());

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

bool TimerController::hasNextRound() const
{
    auto rounds = mModel->roundsRaw();
    return mModel->activeRound() < rounds.size() - 1;
}

bool TimerController::hasPrevRound() const
{
    return mModel->activeRound() > 0;
}

void TimerController::addStructure(TournamentStructureDef *tournament)
{
    auto rounds = tournament->roundsRaw();
    //qSort(rounds.begin(), rounds.end(), QSortHelpers::PtrLess<RoundDef>());
    mModel->rounds(rounds);
}

void TimerController::updateModelTime()
{
    RETURN_IF(!mModel->running());
    RETURN_IF(mModel->paused());

    auto activeRoundId = mModel->activeRound();
    auto rounds = mModel->roundsRaw();
    auto activeRound = rounds[activeRoundId];

    if(activeRound)
    {
        int secondsLeft = ceil(activeRound->roundTimeInSeconds() - mElapsedRoundSeconds);
        auto secondsLeftStr = RoundDef::secondsToTimeString(secondsLeft);
        mModel->activeRoundRemainingTime(secondsLeftStr);
    }
}

void TimerController::resetTime()
{
    mTime.restart();
    mLastTick = 0.0f;
    mElapsedRoundSeconds = 0.0f;
}

void TimerController::timerEvent(QTimerEvent* event)
{
    Q_UNUSED(event);

    float seconds = mTime.elapsed() / 1000.0;
    if(mModel->running() && !mModel->paused())
    {
        mElapsedRoundSeconds += seconds - mLastTick;
        mLastTick = seconds;

        auto rounds = mModel->roundsRaw();
        auto activeRoundId = mModel->activeRound();
        auto activeRound = rounds[activeRoundId];
        if(mElapsedRoundSeconds > activeRound->roundTimeInSeconds())
        {
            QSound::play(":/sounds/bell.wav");
            nextRound();
        }

        updateModelTime();
    }
    else
        mLastTick = seconds;
}
