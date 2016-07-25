#include "TournamentsListController.h"

#include <QDebug>

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

    auto tourneyList = mModel->tournaments();
    auto tourneyName = tourney->name();

    tourneyList.append(tourneyName);
    mModel->tournaments(tourneyList);

    mStructure[tourneyName] = tourney;

    if(!tourney->isStructureReady())
    {
        RequestRoundsCommand* command = new RequestRoundsCommand(tourney, this);
        mCommandRecycler->executeAndDispose(command);
    }
}

void TournamentsListController::onPlayClicked(QString tournamentName)
{
    qDebug() << tournamentName;
    qDebug() << mStructure[tournamentName]->rounds().size();
    emit tournamentSelectedToPlay(mStructure[tournamentName]);
}
