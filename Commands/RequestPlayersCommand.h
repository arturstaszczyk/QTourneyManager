#ifndef REQUESTPLAYERSCOMMAND_H
#define REQUESTPLAYERSCOMMAND_H

#include "Command.h"

#include <QJsonObject>
#include <QNetworkReply>

class RequestPlayersCommand : public Command
{
    Q_OBJECT

public:
    explicit RequestPlayersCommand(QString hostAddress, QObject* parent = nullptr);

    void execute() override;

public slots:
    void onHttpPlayersGet(QNetworkReply* reply);

signals:
    void playerParsed(QJsonObject);

private:
    QString mHostAddress;
};

#endif // REQUESTPLAYERSCOMMAND_H
