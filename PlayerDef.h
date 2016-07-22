#ifndef PLAYERDEF_H
#define PLAYERDEF_H

#include <QObject>

class PlayerDef : public QObject
{
    Q_OBJECT
public:
    explicit PlayerDef(QObject *parent = 0);

signals:

public slots:
};

#endif // PLAYERDEF_H