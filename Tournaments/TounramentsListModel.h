#ifndef TOUNRAMENTSLISTMODEL_H
#define TOUNRAMENTSLISTMODEL_H

#include <QObject>

#include "QAutoProperty.h"

class TounramentsListModel : public QObject
{
    Q_OBJECT
public:
    explicit TounramentsListModel(QObject *parent = 0);

    AUTO_PROPERTY(QStringList, tournaments)

signals:

public slots:
};

#endif // TOUNRAMENTSLISTMODEL_H
