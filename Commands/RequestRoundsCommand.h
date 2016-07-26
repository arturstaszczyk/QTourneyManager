#ifndef REQUESTROUNDSCOMMAND_H
#define REQUESTROUNDSCOMMAND_H

#include <QJsonObject>
#include <QNetworkReply>

#include "Command.h"

class RequestRoundsCommand : public Command
{
    Q_OBJECT

public:
    explicit RequestRoundsCommand(QString tourneyName, QStringList roundsUrlList, QObject* parent = nullptr);

    void execute() override;

signals:
    void roundParsed(QString tourneyName, QJsonObject roundObj);

private slots:
    void onHttpRoundGet(QNetworkReply*reply);

private:
    QString mTourneyName;
    QStringList mRoundsUrlList;

    int mRemainigRequestsCount;
};

#endif // REQUESTROUNDSCOMMAND_H
