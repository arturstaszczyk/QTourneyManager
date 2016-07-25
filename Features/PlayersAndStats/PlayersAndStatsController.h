#ifndef PLAYERSANDSTATSCONTROLLER_H
#define PLAYERSANDSTATSCONTROLLER_H

#include <QMap>
#include <QObject>
#include <QJsonObject>
#include <QQmlApplicationEngine>

class BuyinDef;
class StatsModel;
class PlayersModel;
class CommandRecycler;
class PlayersAndStatsController : public QObject
{
    Q_OBJECT
public:
    explicit PlayersAndStatsController(QQmlApplicationEngine* engine,
                                       CommandRecycler* commandsRecycler,
                                       QObject *parent = 0);

public slots:
    void addPlayer(QJsonObject playerObj);
    void addBuyin(QString buyinUrl, QJsonObject buyinObj);

    void rebuy(QString playerNick);
    void eliminate(QString playerNick);

private:
    bool needToDownloadBuyin(QString buyinUrl);
    void downloadBuyin(QString buyinUrl);

    void updateStatsModel();

private:
    CommandRecycler* mCommandRecycler;
    PlayersModel* mPlayersModel;
    StatsModel* mStatsModel;

    QMap<QString, BuyinDef*> mBuyins;
};

#endif // PLAYERSANDSTATSCONTROLLER_H
