#ifndef PLAYERSANDSTATSCONTROLLER_H
#define PLAYERSANDSTATSCONTROLLER_H

#include <QMap>
#include <QObject>
#include <QJsonObject>
#include <QQmlApplicationEngine>

class BuyinDef;
class PlayerDef;
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
    void onHostAddressChanged(QString address);

    void rebuy(QString playerNick);
    void eliminate(QString playerNick);

private slots:
    void onPlayerParsed(QJsonObject playerObj);
    void onBuyinParsed(QString buyinUrl, QJsonObject buyinObj);

private:
    bool needToDownloadBuyin(QString buyinUrl);
    void downloadBuyin(QString buyinUrl);

    void updateStatsModel();
    void updateRestService(PlayerDef* playerDef);

private:
    CommandRecycler* mCommandRecycler;
    PlayersModel* mPlayersModel;
    StatsModel* mStatsModel;

    QMap<QString, BuyinDef*> mBuyins;
};

#endif // PLAYERSANDSTATSCONTROLLER_H
