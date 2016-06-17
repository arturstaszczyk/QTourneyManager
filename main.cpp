#include <QtQml>
#include <QTimer>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "sources/MainScreenController.h"
#include "Models/AddressModel.h"
#include "Models/RoundModel.h"
#include "Models/BlindsModel.h"
#include "Models/TournamentStructureModel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    TournamentStructureModel* tournamentStructure = new TournamentStructureModel();
    tournamentStructure->addRound(15, 1);
    tournamentStructure->addRound(15, 2);

    AddressModel* addressModel = new AddressModel();

    MainScreenController controller(tournamentStructure);
    controller.restart();
    engine.rootContext()->setContextProperty( "mainScreenController", &controller );
    engine.rootContext()->setContextProperty("addressModel", addressModel);

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    controller.startTimer(200);

    return app.exec();
}
