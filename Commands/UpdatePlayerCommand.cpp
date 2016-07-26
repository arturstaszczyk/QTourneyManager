#include "UpdatePlayerCommand.h"

#include <QDebug>
#include <QJsonArray>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

UpdatePlayerCommand::UpdatePlayerCommand(QJsonObject playerObj, QObject *parent)
    : Command(COMMAND_NAME(UpdatePlayerCommand), parent)
    , mPlayerObj(playerObj)
{

}

void UpdatePlayerCommand::execute()
{
    QNetworkAccessManager* postPlayer = new QNetworkAccessManager(this);
    connect(postPlayer, SIGNAL(finished(QNetworkReply*)), this, SLOT(onRequestFinished(QNetworkReply*)));

    auto address = QString("http://localhost:8000/players/%1/").arg(mPlayerObj["pk"].toInt());

    QNetworkRequest req((QUrl(address)));
    req.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));

    QJsonDocument doc(mPlayerObj);
    postPlayer->put(req, doc.toJson());
}

void UpdatePlayerCommand::onRequestFinished(QNetworkReply *reply)
{
    qDebug() << reply->readAll();
    finish();
}
