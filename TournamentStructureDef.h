#ifndef TOURNAMENTSTRUCTUREDEF_H
#define TOURNAMENTSTRUCTUREDEF_H

#include <QList>
#include <QObject>
#include <QString>

#include "RoundDef.h"

class TournamentStructureDef : public QObject
{
    Q_OBJECT
public:
    explicit TournamentStructureDef(QString name, QStringList roundUrls, QObject *parent = 0);

    void addRound(int smallBlind, int bigBlind, int timeInSeconds);
    const QList<RoundDef*>& rounds() const { return mRounds; }
    QString name() const { return mName; }
    QStringList roundUrls() const { return mRoundUrls; }

    bool isStructureReady() const { return mRoundUrls.size() == mRounds.size(); }

private:
    QString mName;
    QStringList mRoundUrls;
    QList<RoundDef*> mRounds;
};

#endif // TOURNAMENTSTRUCTUREDEF_H
