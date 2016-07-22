#include "NavigationBarController.h"

#include <QUrl>
#include <QQmlContext>
#include <QQmlComponent>

NavigationBarController::NavigationBarController(QQmlApplicationEngine* engine, QObject *parent)
    : QObject(parent)
{
    mModel = new NavigationBarModel(this);
    engine->rootContext()->setContextProperty("navigationBarModel", mModel);
    engine->rootContext()->setContextProperty("navigationBarController", this);

    engine->load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    auto rootObj = engine->rootObjects()[0];
    mMainStackView = rootObj->findChild<QObject*>("MainStackView");
    mScreenNames.push_back("main");
    mModel->title("main");

    QQmlComponent tourneysComponent(engine, QUrl("qrc:/qml/Tounraments/TournamentsScreen.qml"));
    mTournamentsScreen = tourneysComponent.create();

    QQmlComponent timerComponent(engine, QUrl("qrc:/qml/Timer/TimerScreen.qml"));
    mTimerScreen = timerComponent.create();

    QQmlComponent hostAddressComponent(engine, QUrl("qrc:/qml/Settings/HostAddressScreen.qml"));
    mHostAddressScreen = hostAddressComponent.create();

    QQmlComponent playersAndStatsComponent(engine, QUrl("qrc:/qml/PlayerAndStats/PlayersAndStatsScreen.qml"));
    mPlayersAndSettingsScreen = playersAndStatsComponent.create();
}

void NavigationBarController::push(QString screenName)
{
    mScreenNames.append(screenName);
    mModel->title(screenName);
    mModel->isRoot(mScreenNames.count() <= 1);
}

void NavigationBarController::pop()
{
    mScreenNames.pop_back();
    mModel->title(mScreenNames.last());
    mModel->isRoot(mScreenNames.count() <= 1);
}

void NavigationBarController::requestTimerScreen()
{
    auto param = QVariant::fromValue<QObject*>(mTimerScreen);
    QMetaObject::invokeMethod(mMainStackView, "push", Q_ARG(QVariant, param));
    push("timer");
}

void NavigationBarController::requestTournamentScreen()
{
    auto param = QVariant::fromValue<QObject*>(mTournamentsScreen);
    QMetaObject::invokeMethod(mMainStackView, "push", Q_ARG(QVariant, param));
    push("tournaments");
}

void NavigationBarController::requestPlayerAndStatsScreen()
{
    auto param = QVariant::fromValue<QObject*>(mPlayersAndSettingsScreen);
    QMetaObject::invokeMethod(mMainStackView, "push", Q_ARG(QVariant, param));
    push("players & stats");
}

void NavigationBarController::requestHostAddressScreen()
{
    auto param = QVariant::fromValue<QObject*>(mHostAddressScreen);
    QMetaObject::invokeMethod(mMainStackView, "push", Q_ARG(QVariant, param));
    push("settings/address");
}

void NavigationBarController::requestPop()
{
    QVariant ret;
    QMetaObject::invokeMethod(mMainStackView, "pop", Q_ARG(QVariant, ret));
    pop();
}
