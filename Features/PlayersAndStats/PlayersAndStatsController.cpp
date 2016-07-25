#include "PlayersAndStatsController.h"

#include <QQmlContext>

#include "Features/PlayerDef.h"

#include "ReturnIf.h"
#include "StatsModel.h"
#include "PlayersModel.h"
#include "Features/BuyinDef.h"
#include "Commands/CommandRecycler.h"
#include "Commands/RequestBuyinCommand.h"

PlayersAndStatsController::PlayersAndStatsController(QQmlApplicationEngine* engine,
                                                     CommandRecycler* commandsRecycler, QObject *parent)
    : QObject(parent)
    , mCommandRecycler(commandsRecycler)
{
    mPlayersModel = new PlayersModel(this);
    mStatsModel = new StatsModel(this);

    engine->rootContext()->setContextProperty("playersAndStatsController", this);
    engine->rootContext()->setContextProperty("playersModel", mPlayersModel);
    engine->rootContext()->setContextProperty("statsModel", mStatsModel);
}

bool PlayersAndStatsController::needToDownloadBuyin(QString buyinUrl)
{
    return mBuyins.find(buyinUrl) == mBuyins.end();
}

void PlayersAndStatsController::downloadBuyin(QString buyinUrl)
{
    RequestBuyinCommand* requestBuyin = new RequestBuyinCommand(buyinUrl, this);
    connect(requestBuyin, SIGNAL(buyinParsed(QString, QJsonObject)), this, SLOT(addBuyin(QString, QJsonObject)));
    mCommandRecycler->executeAndDispose(requestBuyin);

    mBuyins[buyinUrl] = nullptr;
}

void PlayersAndStatsController::addPlayer(QJsonObject playerObj)
{
    auto nick = playerObj["nick"].toString();
    auto rebuyCount = playerObj["rebuy_count"].toInt();
    auto buyinUrl = playerObj["buyin_structure"].toString();

    mPlayersModel->addPlayer(nick, rebuyCount, buyinUrl);

    if(needToDownloadBuyin(buyinUrl))
        downloadBuyin(buyinUrl);

    updateStatsModel();
}

void PlayersAndStatsController::addBuyin(QString buyinUrl, QJsonObject buyinObj)
{
    BuyinDef* buyinDef = new BuyinDef(this);
    buyinDef->bankroll(buyinObj["bankroll"].toInt());
    buyinDef->cash(buyinObj["cash"].toInt());
    mBuyins[buyinUrl] = buyinDef;

    updateStatsModel();
}

void PlayersAndStatsController::rebuy(QString playerNick)
{
    mPlayersModel->forEachPlayer([&](PlayerDef* playerDef) {
        if(playerDef->nick() == playerNick && !playerDef->eliminated())
            playerDef->rebuyCount(playerDef->rebuyCount() + 1);
    });

    updateStatsModel();
}

void PlayersAndStatsController::eliminate(QString playerNick)
{
    mPlayersModel->forEachPlayer([&](PlayerDef* playerDef) {
        if(playerDef->nick() == playerNick)
            playerDef->eliminated(!playerDef->eliminated());
    });

    updateStatsModel();
}

void PlayersAndStatsController::updateStatsModel()
{
    RETURN_IF(mBuyins.size() == 0);
    RETURN_IF(mBuyins.first() == nullptr);

    int rebuyCountSum = 0;
    int playersCount = 0;

    mPlayersModel->forEachPlayer([&](PlayerDef* player){
        rebuyCountSum += player->rebuyCount();
        if(!player->eliminated())
            playersCount++;
    });

    auto buyinChips = mBuyins.first()->bankroll();
    auto buyinCash = mBuyins.first()->cash();

    mStatsModel->buyinChips(buyinChips);
    mStatsModel->buyinCash(buyinCash);

    mStatsModel->averageChipsCount(playersCount == 0 ? 0 : rebuyCountSum * buyinChips / playersCount);
    mStatsModel->totalChips(rebuyCountSum * buyinChips);
    mStatsModel->playersInGame(playersCount);
}
