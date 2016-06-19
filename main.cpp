#include <QtQml>
#include <QTimer>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <chrono>

#include "Settings/HostAddress/HostAddressModel.h"
#include "Settings/HostAddress/HostAddressLogic.h"
#include "Timer/TimerLogic.h"
#include "Timer/TimerModel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    std::chrono::milliseconds interval(100);

    TimerModel timerModel;
    TimerLogic timerLogic(engine.rootContext(), &timerModel, {});
    timerLogic.startTimer(interval.count());

    HostAddressModel addressModel;
    HostAddressLogic addressLogic(engine.rootContext(), &addressModel);
    QObject::connect(&addressLogic, SIGNAL(tournamentRound(int,int,int)),
                  &timerLogic, SLOT(addRound(int,int,int)));

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
