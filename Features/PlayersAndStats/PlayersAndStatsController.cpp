#include "PlayersAndStatsController.h"

#include <QJsonArray>
#include <QQmlContext>

#include "Features/PlayerDef.h"

#include "ReturnIf.h"
#include "StatsModel.h"
#include "PlayersModel.h"
#include "Features/BuyinDef.h"

#include "Commands/CommandRecycler.h"
#include "Commands/RequestBuyinCommand.h"
#include "Commands/UpdatePlayerCommand.h"
#include "Commands/RequestPlayersCommand.h"

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

void PlayersAndStatsController::onHostAddressChanged(QString address)
{
    mHostAddress = address;
    RequestPlayersCommand* requestPlayersCmd = new RequestPlayersCommand(mHostAddress, this);
    connect(requestPlayersCmd, SIGNAL(playerParsed(QJsonObject)), this, SLOT(onPlayerParsed(QJsonObject)));
    mCommandRecycler->executeAndDispose(requestPlayersCmd);
}

void PlayersAndStatsController::onPlayerParsed(QJsonObject playerObj)
{
    auto buyinUrl = playerObj["buyin_structure"].toString();
    PlayerDef* playerDef = new PlayerDef(mPlayersModel);
    playerDef->restId(playerObj["pk"].toInt());
    playerDef->nick(playerObj["nick"].toString());
    playerDef->rebuyCount(playerObj["rebuy_count"].toInt());
    playerDef->eliminated(playerObj["eliminated"].toBool());
    playerDef->setBuyinUrl(buyinUrl);

    mPlayersModel->playersAdd(playerDef);

    if(needToDownloadBuyin(buyinUrl))
        downloadBuyin(buyinUrl);

    updateStatsModel();
}

bool PlayersAndStatsController::needToDownloadBuyin(QString buyinUrl)
{
    return mBuyins.find(buyinUrl) == mBuyins.end();
}

void PlayersAndStatsController::downloadBuyin(QString buyinUrl)
{
    RequestBuyinCommand* requestBuyin = new RequestBuyinCommand(buyinUrl, this);
    connect(requestBuyin, SIGNAL(buyinParsed(QString, QJsonObject)), this, SLOT(onBuyinParsed(QString, QJsonObject)));
    mCommandRecycler->executeAndDispose(requestBuyin);

    mBuyins[buyinUrl] = nullptr;
}

void PlayersAndStatsController::onBuyinParsed(QString buyinUrl, QJsonObject buyinObj)
{
    BuyinDef* buyinDef = new BuyinDef(this);
    buyinDef->bankroll(buyinObj["bankroll"].toInt());
    buyinDef->cash(buyinObj["cash"].toInt());
    mBuyins[buyinUrl] = buyinDef;

    updateStatsModel();
}

void PlayersAndStatsController::rebuy(QString playerNick)
{
    PlayerDef* playerToUpdate = nullptr;
    mPlayersModel->forEachPlayer([&](PlayerDef* playerDef) {
        if(playerDef->nick() == playerNick && !playerDef->eliminated())
        {
            playerDef->rebuyCount(playerDef->rebuyCount() + 1);
            playerToUpdate = playerDef;
        }
    });

    updateRestService(playerToUpdate);
    updateStatsModel();
}

void PlayersAndStatsController::eliminate(QString playerNick)
{
    PlayerDef* playerToUpdate = nullptr;
    mPlayersModel->forEachPlayer([&](PlayerDef* playerDef) {
        if(playerDef->nick() == playerNick)
        {
            playerToUpdate = playerDef;
            playerDef->eliminated(!playerDef->eliminated());
        }
    });

    updateRestService(playerToUpdate);
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

void PlayersAndStatsController::updateRestService(PlayerDef *playerDef)
{
    QJsonObject playerObj;
    playerObj["pk"] = playerDef->restId();
    playerObj["nick"] = playerDef->nick();
    playerObj["rebuy_count"] = playerDef->rebuyCount();
    playerObj["eliminated"] = playerDef->eliminated();

    UpdatePlayerCommand* updatePlayerCmd = new UpdatePlayerCommand(mHostAddress, playerObj, this);
    mCommandRecycler->executeAndDispose(updatePlayerCmd);
}
