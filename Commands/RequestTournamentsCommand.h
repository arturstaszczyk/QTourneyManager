#ifndef REQUESTTOURNAMENTSCOMMAND_H
#define REQUESTTOURNAMENTSCOMMAND_H

#include <QNetworkReply>

#include "Command.h"
#include "Features/TournamentStructureDef.h"

class RequestTournamentsCommand : public Command
{
    Q_OBJECT
public:
    explicit RequestTournamentsCommand(QString hostAddress, QObject *parent = 0);

    void execute() override;

signals:
    void onTournamentParsed(TournamentStructureDef*);

private slots:
    void onHttpTournamentsGet(QNetworkReply*reply);

private:
    QString mHostAddress;
};

#endif // REQUESTTOURNAMENTSCOMMAND_H
