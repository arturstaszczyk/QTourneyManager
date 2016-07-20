#include "TournamentsListLogic.h"

#include <QDebug>

#include "Commands/RequestRoundsCommand.h"

TournamentsListLogic::TournamentsListLogic(QQmlContext* qmlContext, CommandRecycler* recycler, QObject *parent)
    : QObject(parent)
    , mCommandRecycler(recycler)
{
    mModel = new TournamentsListModel(this);
    qmlContext->setContextProperty("tournamentsListModel", mModel);
    qmlContext->setContextProperty("tournamentsListController", this);
}

void TournamentsListLogic::addTournament(TournamentStructureDef* tourney)
{
    auto tourneyList = mModel->tournaments();
    auto tourneyName = tourney->name();

    tourneyList.append(tourneyName);
    mModel->tournaments(tourneyList);

    mStructure[tourneyName] = tourney;
    tourney->setParent(this);

    if(!tourney->isStructureReady())
    {
        RequestRoundsCommand* command = new RequestRoundsCommand(tourney, this);
        mCommandRecycler->executeAndDispose(command);
    }
}

void TournamentsListLogic::onPlayClicked(QString tournamentName)
{
    qDebug() << tournamentName;
    qDebug() << mStructure[tournamentName]->rounds().size();
    emit tournamentSelectedToPlay(mStructure[tournamentName]);
}
