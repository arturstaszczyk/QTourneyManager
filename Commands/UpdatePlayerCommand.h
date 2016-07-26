﻿#ifndef UPDATEPLAYERCOMMAND_H
#define UPDATEPLAYERCOMMAND_H

#include <QObject>
#include <QJsonObject>

#include "Command.h"

class QNetworkReply;
class UpdatePlayerCommand : public Command
{
    Q_OBJECT
public:
    explicit UpdatePlayerCommand(QJsonObject playerObj, QObject *parent = 0);

    void execute() override;

public slots:
    void onRequestFinished(QNetworkReply*);

private:
    QJsonObject mPlayerObj;
};

#endif // UPDATEPLAYERCOMMAND_H
