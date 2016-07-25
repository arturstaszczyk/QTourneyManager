#include "PlayersAndStatsController.h"

#include <QQmlContext>

#include "Features/PlayerDef.h"

PlayersAndStatsController::PlayersAndStatsController(QQmlApplicationEngine* engine,
                                                     CommandRecycler* commandsRecycler, QObject *parent)
    : QObject(parent)
    , mCommandRecycler(commandsRecycler)
{
    mModel = new PlayersAndStatsModel(this);

    engine->rootContext()->setContextProperty("playersAndStatsController", this);
    engine->rootContext()->setContextProperty("playersAndStatsModel", mModel);
}

void PlayersAndStatsController::addPlayer(QJsonObject playerObj)
{
    auto nick = playerObj["nick"].toString();
    auto rebuyCount = playerObj["rebuy_count"].toInt();
    auto buyinUrl = playerObj["buyin_structure"].toString();

    mModel->addPlayer(nick, rebuyCount, buyinUrl);
}

void PlayersAndStatsController::rebuy(QString playerNick)
{
    auto playerList = mModel->players();
    auto endIter = playerList.end();
    for(auto iter = playerList.begin(); iter != endIter; ++iter)
    {
        PlayerDef* playerDef = qobject_cast<PlayerDef*>(*iter);
        if(playerDef->nick() == playerNick)
            playerDef->rebuyCount(playerDef->rebuyCount() + 1);
    }
}
