#include "TournamentStructureDef.h"

TournamentStructureDef::TournamentStructureDef(QString name, QStringList roundUrls, QObject *parent)
    : QObject(parent)
    , mName(name)
    , mRoundUrls(roundUrls)
{

}

void TournamentStructureDef::addRound(int smallBlind, int bigBlind, int timeInSeconds)
{
    mRounds.append(new RoundDef(timeInSeconds, smallBlind, bigBlind, this));
}
