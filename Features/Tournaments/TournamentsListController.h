﻿#ifndef TOURNAMENTSLOGIC_H
#define TOURNAMENTSLOGIC_H

#include <QMap>
#include <QObject>
#include <QJsonObject>
#include <QQmlContext>

#include "TournamentsListModel.h"
#include "Commands/CommandRecycler.h"
#include "Features/TournamentStructureDef.h"

class TournamentsListController : public QObject
{
    Q_OBJECT
public:
    explicit TournamentsListController(QQmlContext* qmlContext, CommandRecycler* recycler, QObject *parent = 0);

signals:
    void tournamentSelectedToPlay(TournamentStructureDef*);

public slots:
    void addTournament(QJsonObject tourneyObj);

    void onPlayClicked(QString);
    void onRoundParsed(QString tourneyName, QJsonObject roundObj);

private:
    TournamentsListModel* mModel;

    CommandRecycler* mCommandRecycler;
    QMap<QString, TournamentStructureDef*> mStructure;
};

#endif // TOURNAMENTSLOGIC_H
