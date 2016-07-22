#include "RequestPlayersCommand.h"

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
    qDebug() << reply->readAll();
}
