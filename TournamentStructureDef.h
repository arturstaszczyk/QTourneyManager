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
    explicit TournamentStructureDef(QString name, QObject *parent = 0);

    void addRound(int smallBlind, int bigBlind, int timeInSeconds);

private:
    QString mName;
    QList<RoundDef*> mRounds;
};

#endif // TOURNAMENTSTRUCTUREDEF_H
