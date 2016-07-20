#include "RequestTournamentsCommand.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkAccessManager>

#include "Features/TournamentStructureDef.h"

RequestTournamentsCommand::RequestTournamentsCommand(QString hostAddress, QObject *parent)
    : Command(COMMAND_NAME(RequestTournamentsCommand), parent)
    , mHostAddress(hostAddress)
{

}

void RequestTournamentsCommand::execute()
{
    QNetworkAccessManager* http = new QNetworkAccessManager(this);
    connect(http, SIGNAL(finished(QNetworkReply*)), this, SLOT(onHttpTournamentsGet(QNetworkReply*)));

    auto addressStr = QString("http://%1:8000/tournaments/").arg(mHostAddress);
    http->get(QNetworkRequest(QUrl(addressStr)));
}

void RequestTournamentsCommand::onHttpTournamentsGet(QNetworkReply *reply)
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
            TournamentStructureDef* tournament = new TournamentStructureDef(tournamentDef["name"].toString(),
                    tournamentDef["rounds"].toVariant().toStringList());
            emit onTournamentParsed(tournament);
        }
    }

    finish();
}
