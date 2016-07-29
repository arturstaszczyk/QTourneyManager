#ifndef TOURNAMENTSTRUCTUREDEF_H
#define TOURNAMENTSTRUCTUREDEF_H

#include <QList>
#include <QObject>
#include <QString>

#include "RoundDef.h"
#include "QAutoProperty.h"

class TournamentStructureDef : public QObject
{
    Q_OBJECT
public:
    explicit TournamentStructureDef(QString name, QStringList roundUrls, QObject *parent = 0);

    AUTO_PROPERTY(QString, name)
    AUTO_PROPERTY(QStringList, roundUrls)
    LIST_PROPERTY(RoundDef, rounds)

public:
    void addRound(int smallBlind, int bigBlind, int timeInSeconds, bool isBreak, int number);
    bool isStructureReady() const { return a_roundUrls.size() == a_roundsRaw.size(); }

};

#endif // TOURNAMENTSTRUCTUREDEF_H
