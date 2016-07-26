#include "TournamentsListController.h"

#include <QDebug>
#include <QJsonObject>

#include "ReturnIf.h"
#include "Commands/RequestRoundsCommand.h"

TournamentsListController::TournamentsListController(QQmlContext* qmlContext, CommandRecycler* recycler, QObject *parent)
    : QObject(parent)
    , mCommandRecycler(recycler)
{
    mModel = new TournamentsListModel(this);
    qmlContext->setContextProperty("tournamentsListModel", mModel);
    qmlContext->setContextProperty("tournamentsListController", this);
}

void TournamentsListController::addTournament(QJsonObject tourneyObj)
{
    TournamentStructureDef* tourney = new TournamentStructureDef(
                tourneyObj["name"].toString(),
                tourneyObj["rounds"].toVariant().toStringList(),
                this);

    mModel->tournamentsAdd(tourney);
    auto tourneyName = tourney->name();

    mStructure[tourneyName] = tourney;

    if(!tourney->isStructureReady())
    {
        RequestRoundsCommand* command = new RequestRoundsCommand(tourneyName, tourney->roundUrls(), this);
        connect(command, SIGNAL(roundParsed(QString,QJsonObject)),
                this, SLOT(onRoundParsed(QString,QJsonObject)));
        mCommandRecycler->executeAndDispose(command);
    }
}

void TournamentsListController::onPlayClicked(QString tournamentName)
{
    emit tournamentSelectedToPlay(mStructure[tournamentName]);
}

void TournamentsListController::onRoundParsed(QString tourneyName, QJsonObject roundObj)
{
    auto tourney = mStructure[tourneyName];
    RETURN_IF(tourney == nullptr);

    tourney->addRound(roundObj["small_blind"].toInt(),
            roundObj["big_blind"].toInt(),
            roundObj["round_duration"].toInt());
}
