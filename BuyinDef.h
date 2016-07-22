#ifndef BUYINDEF_H
#define BUYINDEF_H

#include <QObject>

#include "QAutoProperty.h"

class BuyinDef : public QObject
{
    Q_OBJECT
public:
    explicit BuyinDef(QObject* parent = nullptr);

    AUTO_PROPERTY(int, bankroll)
    AUTO_PROPERTY(int, cash)
};

#endif // BUYINDEF_H
