#ifndef TOURNAMENTSLOGIC_H
#define TOURNAMENTSLOGIC_H

#include <QMap>
#include <QObject>
#include <QQmlContext>

#include "TournamentStructureDef.h"
#include "TournamentsListModel.h"

class TournamentsListLogic : public QObject
{
    Q_OBJECT
public:
    explicit TournamentsListLogic(QQmlContext* qmlContext, QObject *parent = 0);

public slots:
    void addTournament(QString tournamentName);
    void addRoundToCurrentTournament(int smallBlind, int bigBlind, int timeInSeconds);

private:
    TournamentsListModel* mModel;

    QString mCurrentTournament;
    QMap<QString, TournamentStructureDef*> mStructure;
};

#endif // TOURNAMENTSLOGIC_H
