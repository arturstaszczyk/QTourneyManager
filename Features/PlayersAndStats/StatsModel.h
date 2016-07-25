#ifndef STATSMODEL_H
#define STATSMODEL_H

#include <QObject>

#include "QAutoProperty.h"

class StatsModel : public QObject
{
    Q_OBJECT
public:
    explicit StatsModel(QObject *parent = 0);

    AUTO_PROPERTY(int, averageChipsCount)

};

#endif // STATSMODEL_H
