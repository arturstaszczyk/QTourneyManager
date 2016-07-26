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

    playersAdd(playerDef);
}

void PlayersModel::forEachPlayer(const std::function<void(PlayerDef*)>& lambda)
{
    auto endIter = a_playersRaw.end();
    for(auto iter = a_playersRaw.begin(); iter != endIter; ++iter)
    {
        PlayerDef* playerDef = qobject_cast<PlayerDef*>(*iter);
        lambda(playerDef);
    }
}
