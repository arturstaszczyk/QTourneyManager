#include "TournamentsListLogic.h"

TournamentsListLogic::TournamentsListLogic(QQmlContext* qmlContext, QObject *parent) : QObject(parent)
{
    mModel = new TournamentsListModel(this);
    qmlContext->setContextProperty("tournamentsListModel", mModel);
    qmlContext->setContextProperty("tournamentsListController", this);
}

void TournamentsListLogic::addTournament(QString tournamentName)
{
    auto tournaments = mModel->tournaments();
    tournaments.append(tournamentName);
    mModel->tournaments(tournaments);
    mCurrentTournament = tournamentName;
}

void TournamentsListLogic::addRoundToCurrentTournament(int smallBlind, int bigBlind, int timeInSeconds)
{
    if(mStructure.find(mCurrentTournament) == mStructure.end())
        mStructure[mCurrentTournament] = new TournamentStructureDef(mCurrentTournament, this);
    mStructure[mCurrentTournament]->addRound(smallBlind, bigBlind, timeInSeconds);
}
