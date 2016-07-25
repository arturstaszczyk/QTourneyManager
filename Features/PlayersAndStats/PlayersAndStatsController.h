#ifndef PLAYERSANDSTATSCONTROLLER_H
#define PLAYERSANDSTATSCONTROLLER_H

#include <QObject>
#include <QJsonObject>
#include <QQmlApplicationEngine>

#include "PlayersAndStatsModel.h"
#include "Commands/CommandRecycler.h"

class PlayersAndStatsController : public QObject
{
    Q_OBJECT
public:
    explicit PlayersAndStatsController(QQmlApplicationEngine* engine,
                                       CommandRecycler* commandsRecycler,
                                       QObject *parent = 0);

public slots:
    void addPlayer(QJsonObject playerObj);
    void rebuy(QString playerNick);
    void eliminate(QString playerNick);

private:
    CommandRecycler* mCommandRecycler;
    PlayersAndStatsModel* mModel;
};

#endif // PLAYERSANDSTATSCONTROLLER_H
