#include <QtQml>
#include <QTimer>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "sources/MainScreenController.h"
#include "Models/RoundModel.h"
#include "Models/BlindsModel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<BlindsModel>( "pokermanager.types", 1, 0, "BlindsModel" );
    qmlRegisterType<RoundModel>( "pokermanager.types", 1, 0, "RoundModel" );
    qmlRegisterType<MainScreenController>( "pokermanager.types", 1, 0, "MainScreenController" );

    MainScreenController controller;
    QTimer timer;
    timer.start(200);
    QObject::connect(&timer, SIGNAL(timeout()), &controller, SLOT(tick()));

    controller.addRoundDef(15, 1);
    controller.addRoundDef(15, 2);
    controller.restart();
    engine.rootContext()->setContextProperty( "mainScreenController", &controller );

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
