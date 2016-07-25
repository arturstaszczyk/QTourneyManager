#include "PlayersAndStatsController.h"

#include <QQmlContext>

PlayersAndStatsController::PlayersAndStatsController(QQmlApplicationEngine* engine,
                                                     CommandRecycler* commandsRecycler, QObject *parent)
    : QObject(parent)
    , mCommandRecycler(commandsRecycler)
{
    mModel = new PlayersAndStatsModel(this);

    engine->rootContext()->setContextProperty("playersAndStatsModel", mModel);
}

void PlayersAndStatsController::addPlayer(QJsonObject playerObj)
{
    auto nick = playerObj["nick"].toString();
    auto rebuyCount = playerObj["rebuy_count"].toInt();
    auto buyinUrl = playerObj["buyin_structure"].toString();

    mModel->addPlayer(nick, rebuyCount, buyinUrl);
}
