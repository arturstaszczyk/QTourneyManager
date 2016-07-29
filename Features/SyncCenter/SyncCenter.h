#ifndef SYNCCENTER_H
#define SYNCCENTER_H

#include <QObject>

class CommandRecycler;
class SyncCenter : public QObject
{
    Q_OBJECT
public:
    explicit SyncCenter(CommandRecycler* commandRecycler, QObject *parent = 0);

signals:
    void refresh();

public slots:
    void adminLogin(QString deviceId, QString password);

private:
    CommandRecycler* mCommandRecycler;
};

#endif // SYNCCENTER_H
