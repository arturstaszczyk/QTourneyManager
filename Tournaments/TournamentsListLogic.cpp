#include "TournamentsListLogic.h"

TournamentsListLogic::TournamentsListLogic(QQmlContext* qmlContext, QObject *parent) : QObject(parent)
{
    mModel = new TournamentsListModel(this);
    qmlContext->setContextProperty("tournamentsListModel", mModel);
}

void TournamentsListLogic::addTournament(QString tournamentName)
{
    auto tournaments = mModel->tournaments();
    tournaments.append(tournamentName);
    mModel->tournaments(tournaments);
}
