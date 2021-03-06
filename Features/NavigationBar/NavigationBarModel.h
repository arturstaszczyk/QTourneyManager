﻿#ifndef NAVIGATIONBARMODEL_H
#define NAVIGATIONBARMODEL_H

#include <QObject>

#include "QAutoProperty.h"

class NavigationBarModel : public QObject
{
    Q_OBJECT
public:
    explicit NavigationBarModel(QObject *parent = 0)
        : QObject(parent)
        , a_title("hah")
        , a_isRoot(true) {}

    AUTO_PROPERTY(QString, title)
    AUTO_PROPERTY(bool, isRoot)
};

#endif // NAVIGATIONBARMODEL_H
