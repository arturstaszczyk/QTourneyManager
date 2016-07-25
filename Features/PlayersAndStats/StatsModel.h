#ifndef STATSMODEL_H
#define STATSMODEL_H

#include <QObject>

#include "QAutoProperty.h"

class StatsModel : public QObject
{
    Q_OBJECT
public:
    explicit StatsModel(QObject *parent = 0)
        : QObject(parent) {}

    AUTO_PROPERTY(int, buyinCash)
    AUTO_PROPERTY(int, buyinChips)

    AUTO_PROPERTY(int, totalChips)
    AUTO_PROPERTY(int, averageChipsCount)
    AUTO_PROPERTY(int, playersInGame)

};

#endif // STATSMODEL_H
