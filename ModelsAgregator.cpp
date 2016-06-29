#include "ModelsAgregator.h"
#include "AppExceptions.h"

ModelsAgregator* ModelsAgregator::sInstance = nullptr;
QQmlContext* ModelsAgregator::sQmlContext = nullptr;

ModelsAgregator* ModelsAgregator::instance()
{
    if(sInstance == nullptr)
        sInstance = new ModelsAgregator();

    return sInstance;
}

void ModelsAgregator::setQmlContext(QQmlContext *qmlContext)
{
    sQmlContext = qmlContext;
}

ModelsAgregator::ModelsAgregator(QObject *parent)
    : QObject(parent)
{
    if(sQmlContext == nullptr)
        throw NotInitializedException();
}

ModelsAgregator::ModelsAgregator(const ModelsAgregator& other)
    : QObject(other.parent())
{
    if(sQmlContext == nullptr)
        throw NotInitializedException();
}

void ModelsAgregator::addModel(QString modelName, IModel *model)
{
}
