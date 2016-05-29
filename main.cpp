#include <QtQml>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "sources/GameContext.h"
#include "Models/RoundModel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType< GameContext >( "pokermanager.types", 1, 0, "GameContext" );
    qmlRegisterType< RoundModel >( "pokermanager.types", 1, 0, "RoundDef" );

    GameContext gameContext;
    gameContext.addRoundDef(15, 1);
    gameContext.addRoundDef(15, 2);
    engine.rootContext()->setContextProperty( "gameContext", &gameContext );

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
