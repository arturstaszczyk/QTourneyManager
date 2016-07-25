#include <QtQml>
#include <QTimer>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <chrono>

#include "Commands/CommandRecycler.h"
#include "Features/Timer/TimerController.h"
#include "Features/Tournaments/TournamentsListController.h"
#include "Features/NavigationBar/NavigationBarController.h"
#include "Features/PlayersAndStats/PlayersAndStatsController.h"
#include "Features/Settings/HostAddress/HostAddressController.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterUncreatableType<RoundDef>("poker.rounddef", 1, 0, "RoundDef", "Cannot create model in QML");

    std::chrono::milliseconds interval(100);

    CommandRecycler commandRecycler(interval);

    TimerController timerController(engine.rootContext());
    timerController.startTimer(interval.count());

    HostAddressController addressController(engine.rootContext(), &commandRecycler);

    TournamentsListController tournamentsController(engine.rootContext(), &commandRecycler);
    QObject::connect(&addressController, SIGNAL(onTournamentParsed(QJsonObject)),
                     &tournamentsController, SLOT(addTournament(QJsonObject)));

    QObject::connect(&tournamentsController, SIGNAL(tournamentSelectedToPlay(TournamentStructureDef*)),
                     &timerController, SLOT(addStructure(TournamentStructureDef*)));

    PlayersAndStatsController playersAndStatsController(&engine, &commandRecycler);
    QObject::connect(&addressController, SIGNAL(onPlayerParsed(QJsonObject)),
                     &playersAndStatsController, SLOT(addPlayer(QJsonObject)));

    NavigationBarController navigationBar(&engine);

#ifdef _DEBUG
    addressController.onHostAddressChanged("localhost", true);
#endif


    return app.exec();
}
