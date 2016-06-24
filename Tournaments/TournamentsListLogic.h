#ifndef TOURNAMENTSLOGIC_H
#define TOURNAMENTSLOGIC_H

#include <QObject>
#include <QQmlContext>

#include "TournamentsListModel.h"

class TournamentsListLogic : public QObject
{
    Q_OBJECT
public:
    explicit TournamentsListLogic(QQmlContext* qmlContext, QObject *parent = 0);

public slots:
    void addTournament(QString tournamentName);

    void onTournamentSelected(QString tournamentName);

private:
    TournamentsListModel* mModel;
};

#endif // TOURNAMENTSLOGIC_H
