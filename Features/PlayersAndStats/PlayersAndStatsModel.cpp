﻿#include "PlayersAndStatsModel.h"

#include <QDebug>

#include "Features/PlayerDef.h"

PlayersAndStatsModel::PlayersAndStatsModel(QObject *parent) : QObject(parent)
{

}

void PlayersAndStatsModel::addPlayer(QString player, int rebuyCount, QString buyinStructure)
{
    PlayerDef* playerDef = new PlayerDef(this);
    playerDef->nick(player);
    playerDef->rebuyCount(rebuyCount);
    playerDef->setBuyinUrl(buyinStructure);

    auto playerList = players();
    playerList.append(playerDef);
    players(playerList);

    qDebug() << "Added player " << player << players().count();
}
