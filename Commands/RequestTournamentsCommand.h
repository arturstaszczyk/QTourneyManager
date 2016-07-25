#ifndef REQUESTTOURNAMENTSCOMMAND_H
#define REQUESTTOURNAMENTSCOMMAND_H

#include "Command.h"

#include <QJsonObject>
#include <QNetworkReply>

class RequestTournamentsCommand : public Command
{
    Q_OBJECT
public:
    explicit RequestTournamentsCommand(QString hostAddress, QObject *parent = 0);

    void execute() override;

signals:
    void tournamentParsed(QJsonObject);

private slots:
    void onHttpTournamentsGet(QNetworkReply*reply);

private:
    QString mHostAddress;
};

#endif // REQUESTTOURNAMENTSCOMMAND_H
