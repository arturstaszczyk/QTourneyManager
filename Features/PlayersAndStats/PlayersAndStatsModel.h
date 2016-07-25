#ifndef PLAYERSANDSTATSMODEL_H
#define PLAYERSANDSTATSMODEL_H

#include <QObject>
#include <QList>

#include "QAutoProperty.h"

class PlayersAndStatsModel : public QObject
{
    Q_OBJECT
public:
    explicit PlayersAndStatsModel(QObject *parent = 0);

    AUTO_PROPERTY(QList<QObject*>, players)

public slots:
    void addPlayer(QString player, int rebuyCount, QString buyinStructure);
};

#endif // PLAYERSANDSTATSMODEL_H
