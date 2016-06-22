#ifndef TOUNRAMENTSLISTMODEL_H
#define TOUNRAMENTSLISTMODEL_H

#include <QObject>

#include "QAutoProperty.h"

class TournamentsListModel : public QObject
{
    Q_OBJECT
public:
    explicit TournamentsListModel(QObject *parent = 0);

    AUTO_PROPERTY(QStringList, tournaments)
};

#endif // TOUNRAMENTSLISTMODEL_H
