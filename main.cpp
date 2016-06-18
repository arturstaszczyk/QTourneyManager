#include <QtQml>
#include <QTimer>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <chrono>

#include "Models/AddressModel.h"
#include "Timer/TimerLogic.h"
#include "Timer/TimerModel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    std::chrono::milliseconds interval(100);

    RoundDef r1(3, 1, 2);
    RoundDef r2(3, 2, 4);

    TimerModel timerModel;
    TimerLogic timerLogic(engine.rootContext(), &timerModel, {&r1, &r2});
    timerLogic.startTimer(interval.count());

    AddressModel addressModel;

    engine.rootContext()->setContextProperty("addressModel", &addressModel);

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
