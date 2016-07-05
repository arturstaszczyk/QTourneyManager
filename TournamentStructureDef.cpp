#include "TournamentStructureDef.h"

TournamentStructureDef::TournamentStructureDef(QString name, QObject *parent)
    : QObject(parent)
    , mName(name)
{

}

void TournamentStructureDef::addRound(int smallBlind, int bigBlind, int timeInSeconds)
{
    mRounds.append(new RoundDef(timeInSeconds, smallBlind, bigBlind, this));
}
