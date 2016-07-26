#ifndef TIMERMODEL_H
#define TIMERMODEL_H

#include <QObject>
#include <QString>
#include <QQmlListProperty>

#include "QAutoProperty.h"
#include "Features/RoundDef.h"

class TimerModel : public QObject
{
    Q_OBJECT
public:
    explicit TimerModel(QObject *parent = 0);

    AUTO_PROPERTY(bool, running)
    AUTO_PROPERTY(bool, paused)

    AUTO_PROPERTY(int, activeRound)
    AUTO_PROPERTY(QString, activeRoundRemainingTime)

    LIST_PROPERTY(RoundDef, rounds)

public:
    void zero();

};
#endif // TIMERMODEL_H
