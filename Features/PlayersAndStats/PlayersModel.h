#ifndef PLAYERSANDSTATSMODEL_H
#define PLAYERSANDSTATSMODEL_H

#include <QList>
#include <QObject>
#include <functional>

#include "QAutoProperty.h"

class PlayerDef;
class PlayersModel : public QObject
{
    Q_OBJECT
public:
    explicit PlayersModel(QObject *parent = 0);

    LIST_PROPERTY(PlayerDef, players)

public:
    void forEachPlayer(const std::function<void(PlayerDef*)>& lambda);

public slots:
    void addPlayer(QString player, int rebuyCount, QString buyinStructure);

};

#endif // PLAYERSANDSTATSMODEL_H
