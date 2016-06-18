#ifndef TIMERMODEL_H
#define TIMERMODEL_H

#include <QObject>

#include "QAutoProperty.h"

class TimerModel : public QObject
{
    Q_OBJECT
public:
    explicit TimerModel(QObject *parent = 0);

    AUTO_PROPERTY(int, smallBlind)
    AUTO_PROPERTY(int, bigBlind)
    AUTO_PROPERTY(QString, timeString)

public:
    void zero();
};

#endif // TIMERMODEL_H
