﻿#include "RequestRoundsCommand.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkAccessManager>

int RequestRoundsCommand::sRemainigRequestsCount = 0;

RequestRoundsCommand::RequestRoundsCommand(TournamentStructureDef* tourney, QObject* parent)
    : Command(COMMAND_NAME(RequestRoundsCommand), parent)
    , mTourney(tourney)
{

}

void RequestRoundsCommand::execute()
{
    QNetworkAccessManager* roundsHttp = new QNetworkAccessManager(this);
    connect(roundsHttp, SIGNAL(finished(QNetworkReply*)), this, SLOT(onHttpRoundGet(QNetworkReply*)));
    QString apiAddress;

    sRemainigRequestsCount = mTourney->roundUrls().size();
    foreach(apiAddress, mTourney->roundUrls())
    {
        roundsHttp->get(QNetworkRequest(QUrl(apiAddress)));
    }
}

void RequestRoundsCommand::onHttpRoundGet(QNetworkReply *reply)
{
    auto roundDef = reply->readAll();
    QJsonParseError error;
    QJsonDocument roundJson = QJsonDocument::fromJson(roundDef, &error);
    auto roundObject = roundJson.object();

    mTourney->addRound(roundObject["small_blind"].toInt(),
            roundObject["big_blind"].toInt(),
            roundObject["round_duration"].toInt());

    sRemainigRequestsCount--;
    if(sRemainigRequestsCount == 0)
        finish();
}