#include "RequestBuyinCommand.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkAccessManager>

RequestBuyinCommand::RequestBuyinCommand(QString buyinUrl, QObject *parent)
    : Command(COMMAND_NAME(RequestBuyinCommand), parent)
    , mBuyinUrl(buyinUrl)
{

}

void RequestBuyinCommand::execute()
{
    QNetworkAccessManager* buyinHttp = new QNetworkAccessManager(this);
    connect(buyinHttp, SIGNAL(finished(QNetworkReply*)), this, SLOT(onHttpBuyinGet(QNetworkReply*)));

    buyinHttp->get(QNetworkRequest(QUrl(mBuyinUrl)));
    qDebug() << "Requesting " << mBuyinUrl;
}

void RequestBuyinCommand::onHttpBuyinGet(QNetworkReply *reply)
{
    QJsonParseError error;
    QByteArray resp = reply->readAll();
    QJsonDocument json = QJsonDocument::fromJson(resp, &error);
    qDebug() << error.errorString();

    if(json.isObject())
    {
        auto buyinObj = json.object();
        emit buyinParsed(mBuyinUrl, buyinObj);
    }

    finish();
}
