#include <QtQml>
#include <QTimer>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <chrono>

#include "Commands/CommandRecycler.h"
#include "Features/RoundDef.h"
#include "Features/PlayerDef.h"
#include "Features/Timer/TimerController.h"
#include "Features/Settings/SettingsController.h"
#include "Features/Tournaments/TournamentsListController.h"
#include "Features/NavigationBar/NavigationBarController.h"
#include "Features/PlayersAndStats/PlayersAndStatsController.h"

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    qmlRegisterUncreatableType<PlayerDef>("poker.playerdef", 1, 0, "PlayerDef", "Cannot create model in QML");
    qmlRegisterUncreatableType<RoundDef>("poker.rounddef", 1, 0, "RoundDef", "Cannot create model in QML");
    qmlRegisterUncreatableType<TournamentStructureDef>("poker.tournamentstructuredef", 1, 0,
                                         "TournamentStructureDef", "Cannot create model in QML");


    std::chrono::milliseconds interval(100);
    CommandRecycler commandRecycler(interval);

    TimerController timerController(engine.rootContext());
    timerController.startTimer(interval.count());

    SettingsController addressController(engine.rootContext(), &commandRecycler);

    TournamentsListController tournamentsController(engine.rootContext(), &commandRecycler);
    QObject::connect(&addressController, SIGNAL(hostAddressChanged(QString)),
                     &tournamentsController, SLOT(onHostAddressChanged(QString)));

    QObject::connect(&tournamentsController, SIGNAL(tournamentSelectedToPlay(TournamentStructureDef*)),
                     &timerController, SLOT(addStructure(TournamentStructureDef*)));

    PlayersAndStatsController playersAndStatsController(&engine, &commandRecycler);
    QObject::connect(&addressController, SIGNAL(hostAddressChanged(QString)),
                     &playersAndStatsController, SLOT(onHostAddressChanged(QString)));


    NavigationBarController navigationBar(&engine);

#ifdef _DEBUG
    addressController.onHostAddressChanged("localhost", true);
#endif


    return app.exec();
}
