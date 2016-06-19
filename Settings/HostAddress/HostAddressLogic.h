#ifndef HOSTADDRESSLOGIC_H
#define HOSTADDRESSLOGIC_H

#include <QObject>
#include <QQmlContext>
#include <QNetworkReply>

#include "HostAddressModel.h"

class HostAddressLogic : public QObject
{
    Q_OBJECT
public:
    explicit HostAddressLogic(QQmlContext* qmlContext, HostAddressModel* model, QObject *parent = 0);

signals:
    void tournamentName(QString name);
    void tournamentRound(int smallBlind, int bigBlind, int timeInSeconds);

public slots:
    void onHostAddressChanged(QString address, bool isValid);

private slots:
    void onHttpTournamentsGet(QNetworkReply* reply);
    void onHttpRoundGet(QNetworkReply* reply);

private:
    void getRounds(QStringList rounds);

private:
    HostAddressModel* mModel;

};

#endif // HOSTADDRESSLOGIC_H
