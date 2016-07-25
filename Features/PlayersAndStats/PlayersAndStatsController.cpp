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
    mModel->forEachPlayer([&](PlayerDef* playerDef) {
        if(playerDef->nick() == playerNick && !playerDef->eliminated())
            playerDef->rebuyCount(playerDef->rebuyCount() + 1);
    });
}

void PlayersAndStatsController::eliminate(QString playerNick)
{
    mModel->forEachPlayer([&](PlayerDef* playerDef) {
        if(playerDef->nick() == playerNick)
            playerDef->eliminated(!playerDef->eliminated());
    });
}
