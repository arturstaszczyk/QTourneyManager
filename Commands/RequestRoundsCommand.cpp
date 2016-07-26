#include "RequestRoundsCommand.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkAccessManager>


RequestRoundsCommand::RequestRoundsCommand(QString tourneyName, QStringList roundsUrlList, QObject* parent)
    : Command(COMMAND_NAME(RequestRoundsCommand), parent)
    , mTourneyName(tourneyName)
    , mRoundsUrlList(roundsUrlList)
    , mRemainigRequestsCount(0)
{
}

void RequestRoundsCommand::execute()
{
    QNetworkAccessManager* roundsHttp = new QNetworkAccessManager(this);
    connect(roundsHttp, SIGNAL(finished(QNetworkReply*)), this, SLOT(onHttpRoundGet(QNetworkReply*)));

    mRemainigRequestsCount = mRoundsUrlList.size();

    QString apiAddress;
    foreach(apiAddress, mRoundsUrlList)
    {
        roundsHttp->get(QNetworkRequest(QUrl(apiAddress)));
        qDebug() << "Requesting " << apiAddress;
    }
}

void RequestRoundsCommand::onHttpRoundGet(QNetworkReply *reply)
{
    auto roundDef = reply->readAll();
    QJsonParseError error;
    QJsonDocument roundJson = QJsonDocument::fromJson(roundDef, &error);
    auto roundObject = roundJson.object();

    emit roundParsed(mTourneyName, roundObject);

    mRemainigRequestsCount--;
    if(mRemainigRequestsCount == 0)
        finish();
}
