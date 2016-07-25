#ifndef REQUESTBUYINCOMMAND_H
#define REQUESTBUYINCOMMAND_H

#include <QObject>
#include <QJsonObject>
#include <QNetworkReply>

#include "Command.h"

class RequestBuyinCommand : public Command
{
    Q_OBJECT
public:
    explicit RequestBuyinCommand(QString buyinUrl, QObject *parent = 0);

    void execute() override;

signals:
    void buyinParsed(QString buyinUrl, QJsonObject buyinObj);

private slots:
    void onHttpBuyinGet(QNetworkReply* reply);

private:
    QString mBuyinUrl;

};

#endif // REQUESTBUYINCOMMAND_H
