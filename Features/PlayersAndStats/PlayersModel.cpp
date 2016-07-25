#include "PlayersModel.h"

#include <QDebug>

#include "Features/PlayerDef.h"

PlayersModel::PlayersModel(QObject *parent) : QObject(parent)
{

}

QQmlListProperty<PlayerDef> PlayersModel::players()
{
    return QQmlListProperty<PlayerDef>(this, mPlayers);
}

void PlayersModel::addPlayer(QString player, int rebuyCount, QString buyinStructure)
{
    PlayerDef* playerDef = new PlayerDef(this);
    playerDef->nick(player);
    playerDef->rebuyCount(rebuyCount);
    playerDef->setBuyinUrl(buyinStructure);

    mPlayers.append(playerDef);

    emit playersChanged(QQmlListProperty<PlayerDef>(this, mPlayers));
}

void PlayersModel::forEachPlayer(const std::function<void(PlayerDef*)>& lambda)
{
    auto endIter = mPlayers.end();
    for(auto iter = mPlayers.begin(); iter != endIter; ++iter)
    {
        PlayerDef* playerDef = qobject_cast<PlayerDef*>(*iter);
        lambda(playerDef);
    }
}
