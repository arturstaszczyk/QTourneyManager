#ifndef MODELSAGREGATOR_H
#define MODELSAGREGATOR_H

#include <QObject>
#include <QQmlContext>

#include "MVC/IModel.h"

class ModelsAgregator : public QObject
{
    Q_OBJECT

public:
    static ModelsAgregator* instance();
    static void setQmlContext(QQmlContext* qmlContext);

    void addModel(QString modelName, IModel* model);

private:
    explicit ModelsAgregator(QObject *parent = 0);
    explicit ModelsAgregator(const ModelsAgregator& other);

    static ModelsAgregator* sInstance;
    static QQmlContext* sQmlContext;

signals:

public slots:
};

#endif // MODELSAGREGATOR_H
