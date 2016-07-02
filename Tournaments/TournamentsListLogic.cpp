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
}

void TournamentsListLogic::onTournamentSelected(QString tournamentName)
{
    Q_UNUSED(tournamentName);
}
