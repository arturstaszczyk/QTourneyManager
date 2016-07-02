#ifndef TIMERMODEL_H
#define TIMERMODEL_H

#include <QObject>
#include <QString>
#include <QQmlListProperty>

#include "RoundDef.h"
#include "QAutoProperty.h"

class TimerModel : public QObject
{
    Q_OBJECT
public:
    explicit TimerModel(QObject *parent = 0);

    AUTO_PROPERTY(bool, running)
    AUTO_PROPERTY(int, activeRound)
    AUTO_PROPERTY(QString, activeRoundRemainingTime)
    Q_PROPERTY(QQmlListProperty<RoundDef> rounds READ rounds NOTIFY roundsChanged)

public:
    void zero();

    QQmlListProperty<RoundDef> rounds();
    const QList<RoundDef*>& rawRoundsList() const { return mRounds; }
    void rounds(QList<RoundDef*> blinds);

signals:
    void roundsChanged(QQmlListProperty<RoundDef> rounds);

private:
    QList<RoundDef*> mRounds;
};

#endif // TIMERMODEL_H
