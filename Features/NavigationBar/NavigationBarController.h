#ifndef NAVIGATIONBARCONTROLLER_H
#define NAVIGATIONBARCONTROLLER_H

#include <QObject>
#include <QQmlApplicationEngine>

#include "NavigationBarModel.h"

class NavigationBarController : public QObject
{
    Q_OBJECT
public:
    explicit NavigationBarController(QQmlApplicationEngine* engine, QObject *parent = 0);

public slots:

    void requestTimerScreen();
    void requestTournamentScreen();
    void requestPlayerAndStatsScreen();
    void requestHostAddressScreen();

    void requestPop();

private:
    void push(QString screenName);
    void pop();

private:
    QStringList mScreenNames;
    NavigationBarModel* mModel;

    QObject* mMainStackView;
    QObject* mTournamentsScreen;
    QObject* mTimerScreen;
    QObject* mHostAddressScreen;
};

#endif // NAVIGATIONBARCONTROLLER_H
