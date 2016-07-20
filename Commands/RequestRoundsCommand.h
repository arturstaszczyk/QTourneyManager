#ifndef REQUESTROUNDSCOMMAND_H
#define REQUESTROUNDSCOMMAND_H

#include <QNetworkReply>

#include "Command.h"
#include "Features/TournamentStructureDef.h"

class RequestRoundsCommand : public Command
{
    Q_OBJECT

    static int sRemainigRequestsCount;

public:
    explicit RequestRoundsCommand(TournamentStructureDef* tourney, QObject* parent = nullptr);

    void execute() override;

private slots:
    void onHttpRoundGet(QNetworkReply*reply);

private:
    TournamentStructureDef* mTourney;
};

#endif // REQUESTROUNDSCOMMAND_H
