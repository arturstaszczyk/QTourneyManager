﻿#ifndef TIMERLOGIC_H
#define TIMERLOGIC_H

#include <QList>
#include <QTime>
#include <QObject>
#include <QQmlContext>

#include "TimerModel.h"
#include "Features/RoundDef.h"
#include "Features/TournamentStructureDef.h"

class TimerController : public QObject
{
    Q_OBJECT
public:
    explicit TimerController(QQmlContext* qmlContext, QList<RoundDef*> rounds = {}, QObject *parent = 0);

public slots:
    void togglePause();
    void nextRound();
    void previousRound();

    //void addRound(int smallBlind, int bigBlind, int timeInSeconds);
    void addStructure(TournamentStructureDef* tournament);

private:
    void resetTime();
    bool hasNextRound() const;
    bool hasPrevRound() const;

    void updateModelTime();

    void timerEvent(QTimerEvent* event) override;

private:
    TimerModel*             mModel;

    QTime                   mTime;
    float                   mLastTick;
    float                   mElapsedRoundSeconds;
};

#endif // TIMERLOGIC_H
