#ifndef MAINSCREENCONTROLLER_H
#define MAINSCREENCONTROLLER_H

#include <QObject>

class MainScreenController : public QObject
{
    Q_OBJECT

public:
    explicit MainScreenController(QObject *parent = 0);

};

#endif // MAINSCREENCONTROLLER_H
