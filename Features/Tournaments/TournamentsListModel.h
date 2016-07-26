#ifndef TOUNRAMENTSLISTMODEL_H
#define TOUNRAMENTSLISTMODEL_H

#include <QObject>

#include "QAutoProperty.h"
#include "Features/TournamentStructureDef.h"

class TournamentsListModel : public QObject
{
    Q_OBJECT
public:
    explicit TournamentsListModel(QObject *parent = 0)
        : QObject(parent) {}

    LIST_PROPERTY(TournamentStructureDef, tournaments)
};

#endif // TOUNRAMENTSLISTMODEL_H
