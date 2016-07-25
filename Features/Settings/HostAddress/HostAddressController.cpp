#include "HostAddressController.h"

#include "Commands/RequestPlayersCommand.h"
#include "Commands/RequestTournamentsCommand.h"

HostAddressController::HostAddressController(QQmlContext* qmlContext, CommandRecycler* commandRecycler, QObject *parent)
    : QObject(parent)
    , mCommandRecycler(commandRecycler)
{
    mModel = new HostAddressModel(this);
    qmlContext->setContextProperty("hostAddressModel", mModel);
    qmlContext->setContextProperty("hostAddressController", this);
}

void HostAddressController::onHostAddressChanged(QString address, bool isValid)
{
    if(isValid)
        mModel->address(address);

    RequestTournamentsCommand* requestTourneysCmd = new RequestTournamentsCommand(address, this);
    connect(requestTourneysCmd, SIGNAL(tournamentParsed(TournamentStructureDef*)),
            this, SIGNAL(onTournamentParsed(TournamentStructureDef*)));
    mCommandRecycler->executeAndDispose(requestTourneysCmd);

    RequestPlayersCommand* requestPlayersCmd = new RequestPlayersCommand(address, this);
    //connect(requestPlayersCmd, SIGNAL(onPlayerParsed(), )
    mCommandRecycler->executeAndDispose(requestPlayersCmd);
}
