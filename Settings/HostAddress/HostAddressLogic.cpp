#include "HostAddressLogic.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkAccessManager>

HostAddressLogic::HostAddressLogic(QQmlContext* qmlContext, QObject *parent)
    : QObject(parent)
{
    mModel = new HostAddressModel(this);
    qmlContext->setContextProperty("hostAddressModel", mModel);
    qmlContext->setContextProperty("hostAddressController", this);
}

void HostAddressLogic::onHostAddressChanged(QString address, bool isValid)
{
    if(isValid)
        mModel->address(address);

    QNetworkAccessManager* http = new QNetworkAccessManager(this);
    connect(http, SIGNAL(finished(QNetworkReply*)), this, SLOT(onHttpTournamentsGet(QNetworkReply*)));

    auto addressStr = QString("http://%1:8000/tournaments/").arg(address);
    http->get(QNetworkRequest(QUrl(addressStr)));
}

void HostAddressLogic::onHttpTournamentsGet(QNetworkReply *reply)
{
    QJsonParseError error;
    QByteArray resp = reply->readAll();
    QJsonDocument json = QJsonDocument::fromJson(resp, &error);
    qDebug() << error.errorString();

    if(json.isArray())
    {
        QJsonArray jsonArray = json.array();

        QJsonArray::ConstIterator iter, endIter = jsonArray.constEnd();
        for(iter = jsonArray.constBegin(); iter != endIter; ++iter)
        {
            QJsonObject tournamentDef = (*iter).toObject();
            emit tournamentName(tournamentDef["name"].toString());

            auto rounds = tournamentDef["rounds"].toVariant().toStringList();
            qDebug() << rounds;
            getRounds(rounds);
        }
    }
}

void HostAddressLogic::getRounds(QStringList rounds)
{
    QNetworkAccessManager* roundsHttp = new QNetworkAccessManager(this);
    connect(roundsHttp, SIGNAL(finished(QNetworkReply*)), this, SLOT(onHttpRoundGet(QNetworkReply*)));
    QString apiAddress;

    foreach(apiAddress, rounds)
    {
        roundsHttp->get(QNetworkRequest(QUrl(apiAddress)));
    }
}

void HostAddressLogic::onHttpRoundGet(QNetworkReply *reply)
{
    auto roundDef = reply->readAll();
    QJsonParseError error;
    QJsonDocument roundJson = QJsonDocument::fromJson(roundDef, &error);
    auto roundObject = roundJson.object();

    emit tournamentRound(roundObject["small_blind"].toInt(),
            roundObject["big_blind"].toInt(),
            roundObject["round_duration"].toInt());
}
