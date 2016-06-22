#include <QtQml>
#include <QTimer>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <chrono>

#include "Timer/TimerLogic.h"
#include "Tournaments/TournamentsListLogic.h"
#include "Settings/HostAddress/HostAddressLogic.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    std::chrono::milliseconds interval(100);

    TimerLogic timerLogic(engine.rootContext(), {});
    timerLogic.startTimer(interval.count());

    HostAddressLogic addressLogic(engine.rootContext());
    QObject::connect(&addressLogic, SIGNAL(tournamentRound(int,int,int)),
                  &timerLogic, SLOT(addRound(int,int,int)));

    TournamentsListLogic tournamentsLogic(engine.rootContext());
    QObject::connect(&addressLogic, SIGNAL(tournamentName(QString)),
                     &tournamentsLogic, SLOT(addTournament(QString)));

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
