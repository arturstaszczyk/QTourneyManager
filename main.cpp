#include <QtQml>
#include <QTimer>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <chrono>

#include "Commands/CommandRecycler.h"
#include "Timer/TimerLogic.h"
#include "Tournaments/TournamentsListLogic.h"
#include "NavigationBar/NavigationBarController.h"
#include "Settings/HostAddress/HostAddressLogic.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("_cpp", QVariant(true));

    qmlRegisterUncreatableType<RoundDef>("poker.rounddef", 1, 0, "RoundDef", "Cannot create model in QML");


    std::chrono::milliseconds interval(100);

    TimerLogic timerLogic(engine.rootContext(), {});
    timerLogic.startTimer(interval.count());
    CommandRecycler commandRecycler(interval);

    HostAddressLogic addressLogic(engine.rootContext(), &commandRecycler);
//    QObject::connect(&addressLogic, SIGNAL(tournamentRound(int,int,int)),
//                  &timerLogic, SLOT(addRound(int,int,int)));

    TournamentsListLogic tournamentsLogic(engine.rootContext(), &commandRecycler);
    QObject::connect(&addressLogic, SIGNAL(onTournamentParsed(TournamentStructureDef*)),
                     &tournamentsLogic, SLOT(addTournament(TournamentStructureDef*)));

    QObject::connect(&tournamentsLogic, SIGNAL(tournamentSelectedToPlay(TournamentStructureDef*)),
                     &timerLogic, SLOT(addStructure(TournamentStructureDef*)));

    NavigationBarController navigationBar(engine.rootContext());

#ifdef _DEBUG
    addressLogic.onHostAddressChanged("192.168.0.103", true);
#endif

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
