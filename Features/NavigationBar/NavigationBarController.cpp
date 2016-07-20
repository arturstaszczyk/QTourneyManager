#include "NavigationBarController.h"

NavigationBarController::NavigationBarController(QQmlContext* context, QObject *parent)
    : QObject(parent)
{
    mModel = new NavigationBarModel(this);
    context->setContextProperty("navigationBarModel", mModel);
    context->setContextProperty("navigationBarController", this);
}

void NavigationBarController::push(QString screenName)
{
    mScreenNames.append(screenName);
    mModel->title(screenName);
    mModel->isRoot(mScreenNames.count() <= 1);
}

void NavigationBarController::pop()
{
    mScreenNames.pop_back();
    mModel->title(mScreenNames.last());
    mModel->isRoot(mScreenNames.count() <= 1);
}
