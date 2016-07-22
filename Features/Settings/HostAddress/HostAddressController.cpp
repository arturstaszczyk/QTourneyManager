#include "HostAddressController.h"


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

    RequestTournamentsCommand* command = new RequestTournamentsCommand(address, this);
    connect(command, SIGNAL(onTournamentParsed(TournamentStructureDef*)), this, SIGNAL(onTournamentParsed(TournamentStructureDef*)));
    mCommandRecycler->executeAndDispose(command);
}
