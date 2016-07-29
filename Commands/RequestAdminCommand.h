#ifndef REQUESTADMINCOMMAND_H
#define REQUESTADMINCOMMAND_H

#include <QObject>

#include "Command.h"

class RequestAdminCommand : public Command
{
    Q_OBJECT
public:
    explicit RequestAdminCommand(QObject *parent = 0);

    void execute() override;

signals:

public slots:
};

#endif // REQUESTADMINCOMMAND_H
