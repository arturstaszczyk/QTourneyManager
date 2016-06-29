#ifndef IMODEL_H
#define IMODEL_H

#include <QObject>

class IModel : QObject
{
    Q_OBJECT

public:
    explicit IModel(QObject* parent = nullptr)
        : QObject(parent)
    {}

};

#endif // IMODEL_H
