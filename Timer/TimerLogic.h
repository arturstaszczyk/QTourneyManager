﻿#ifndef TIMERLOGIC_H
#define TIMERLOGIC_H

#include <QList>
#include <QTime>
#include <QObject>
#include <QQmlContext>

#include "TimerModel.h"
#include "RoundDef.h"

class TimerLogic : public QObject
{
    Q_OBJECT
public:
    explicit TimerLogic(QQmlContext* qmlContext, TimerModel* timerModel, QList<RoundDef*> rounds, QObject *parent = 0);

public slots:
    void togglePause();
    void nextRound();
    void previousRound();

    void addRound(int smallBlind, int bigBlind, int timeInSeconds);

private:
    void resetTime();
    bool hasNextRound() const;
    bool hasPrevRound() const;

    void updateModelBlinds();
    void updateModelTime();

    void timerEvent(QTimerEvent* event) override;

private:
    TimerModel*             mTimerModel;

    QTime                   mTime;
    QList<RoundDef*>        mRounds;
    int                     mActiveRound;

    bool                    mIsPaused;
    float                   mLastTick;

    float                   mElapsedRoundSeconds;
};

#endif // TIMERLOGIC_H
