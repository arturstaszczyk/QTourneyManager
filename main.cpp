#include <QtQml>
#include <QTimer>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "sources/MainScreenController.h"
#include "Models/RoundModel.h"
#include "Models/BlindsModel.h"
#include "Models/TournamentStructureModel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<BlindsModel>( "pokermanager.types", 1, 0, "BlindsModel" );
    qmlRegisterType<RoundModel>( "pokermanager.types", 1, 0, "RoundModel" );
    qmlRegisterType<MainScreenController>( "pokermanager.types", 1, 0, "MainScreenController" );

    QTimer timer;
    timer.start(200);


    TournamentStructureModel* tournamentStructure = new TournamentStructureModel();
    tournamentStructure->addRound(15, 1);
    tournamentStructure->addRound(15, 2);

    MainScreenController controller(tournamentStructure);
    QObject::connect(&timer, SIGNAL(timeout()), &controller, SLOT(tick()));
    controller.restart();
    engine.rootContext()->setContextProperty( "mainScreenController", &controller );

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
