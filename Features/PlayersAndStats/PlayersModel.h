#ifndef PLAYERSANDSTATSMODEL_H
#define PLAYERSANDSTATSMODEL_H

#include <QList>
#include <QObject>
#include <QQmlListProperty>
#include <functional>

#include "QAutoProperty.h"

class PlayerDef;
class PlayersModel : public QObject
{
    Q_OBJECT
public:
    explicit PlayersModel(QObject *parent = 0);

    Q_PROPERTY(QQmlListProperty<PlayerDef> players READ players NOTIFY playersChanged)

public:
    void forEachPlayer(const std::function<void(PlayerDef*)>& lambda);

    QQmlListProperty<PlayerDef> players();
    QList<PlayerDef*> rawPlayers() const { return mPlayers; }

public slots:
    void addPlayer(QString player, int rebuyCount, QString buyinStructure);

signals:
    void playersChanged(QQmlListProperty<PlayerDef> players);

private:
    QList<PlayerDef*> mPlayers;
};

#endif // PLAYERSANDSTATSMODEL_H
