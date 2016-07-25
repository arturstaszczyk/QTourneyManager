#include "RequestPlayersCommand.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkAccessManager>

RequestPlayersCommand::RequestPlayersCommand(QString hostAddress, QObject* parent)
    : Command(COMMAND_NAME(RequestPlayersCommand), parent)
    , mHostAddress(hostAddress)
{

}

void RequestPlayersCommand::execute()
{
    QNetworkAccessManager* playersHttp = new QNetworkAccessManager(this);
    connect(playersHttp, SIGNAL(finished(QNetworkReply*)), this, SLOT(onHttpPlayersGet(QNetworkReply*)));

    auto addressStr = QString("http://%1:8000/players/").arg(mHostAddress);
    playersHttp->get(QNetworkRequest(QUrl(addressStr)));
    qDebug() << "Requesting " << addressStr;
}

void RequestPlayersCommand::onHttpPlayersGet(QNetworkReply *reply)
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
            QJsonObject playerObj = (*iter).toObject();
            qDebug() << playerObj;

            emit playerParsed(playerObj);
        }
    }

    finish();
}
