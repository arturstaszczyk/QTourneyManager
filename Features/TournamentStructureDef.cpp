﻿#include "TournamentStructureDef.h"

#include <QtAlgorithms>
#include "QSortHelpers.h"

TournamentStructureDef::TournamentStructureDef(QString name, QStringList roundUrls, QObject *parent)
    : QObject(parent)
    , a_name(name)
    , a_roundUrls(roundUrls)
{
}

void TournamentStructureDef::addRound(int smallBlind, int bigBlind, int timeInSeconds)
{
    roundsAdd(new RoundDef(timeInSeconds, smallBlind, bigBlind, this));
    qSort(a_roundsRaw.begin(), a_roundsRaw.end(), QSortHelpers::PtrLess<RoundDef>());
}
