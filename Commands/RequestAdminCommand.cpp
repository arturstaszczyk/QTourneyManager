#include "RequestAdminCommand.h"

#include <QUrlQuery>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkAccessManager>

RequestAdminCommand::RequestAdminCommand(QString hostAddress, QString deviceId, QString password, QObject *parent)
    : Command(COMMAND_NAME(RequestAdminCommand), parent)
    , mDeviceId(deviceId)
    , mPassword(password)
    , mHostAddress(hostAddress)
{

}

void RequestAdminCommand::execute()
{
    QNetworkAccessManager* adminHttp = new QNetworkAccessManager(this);
    connect(adminHttp, SIGNAL(finished(QNetworkReply*)), this, SLOT(onAdminRequestGet(QNetworkReply*)));

    QUrlQuery postParams;
    postParams.addQueryItem("device_id", mDeviceId);
    postParams.addQueryItem("password", mPassword);

    auto url = QString("http://%1:8000/login/").arg(mHostAddress);
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    auto postData = postParams.toString(QUrl::FullyDecoded);
    postData.replace('+', "%2B");
    adminHttp->post(request, postData.toUtf8());

    qDebug() << postData;
}

void RequestAdminCommand::onAdminRequestGet(QNetworkReply* reply)
{
    qDebug() << reply->readAll();
}
