﻿#ifndef PLAYERSANDSTATSMODEL_H
#define PLAYERSANDSTATSMODEL_H

#include <QList>
#include <QObject>
#include <functional>

#include "QAutoProperty.h"

class PlayerDef;
class PlayersAndStatsModel : public QObject
{
    Q_OBJECT
public:
    explicit PlayersAndStatsModel(QObject *parent = 0);

    AUTO_PROPERTY(QList<QObject*>, players)

public:
    void forEachPlayer(const std::function<void(PlayerDef*)>& lambda);

public slots:
    void addPlayer(QString player, int rebuyCount, QString buyinStructure);
};

#endif // PLAYERSANDSTATSMODEL_H
