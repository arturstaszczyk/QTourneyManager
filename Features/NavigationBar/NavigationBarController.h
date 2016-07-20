#ifndef NAVIGATIONBARCONTROLLER_H
#define NAVIGATIONBARCONTROLLER_H

#include <QObject>
#include <QQmlContext>

#include "NavigationBarModel.h"

class NavigationBarController : public QObject
{
    Q_OBJECT
public:
    explicit NavigationBarController(QQmlContext* context, QObject *parent = 0);

public slots:
    void push(QString screenName);
    void pop();

private:
    QStringList mScreenNames;
    NavigationBarModel* mModel;
};

#endif // NAVIGATIONBARCONTROLLER_H
