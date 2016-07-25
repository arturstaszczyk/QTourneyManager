#include "PlayersModel.h"

#include <QDebug>

#include "Features/PlayerDef.h"

PlayersModel::PlayersModel(QObject *parent) : QObject(parent)
{

}

void PlayersModel::addPlayer(QString player, int rebuyCount, QString buyinStructure)
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

void PlayersModel::forEachPlayer(const std::function<void(PlayerDef*)>& lambda)
{
    auto playerList = players();
    auto endIter = playerList.end();
    for(auto iter = playerList.begin(); iter != endIter; ++iter)
    {
        PlayerDef* playerDef = qobject_cast<PlayerDef*>(*iter);
        lambda(playerDef);
    }
}
