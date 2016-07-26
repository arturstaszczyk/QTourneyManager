#include "TournamentStructureDef.h"

TournamentStructureDef::TournamentStructureDef(QString name, QStringList roundUrls, QObject *parent)
    : QObject(parent)
    , a_name(name)
    , a_roundUrls(roundUrls)
{

}

void TournamentStructureDef::addRound(int smallBlind, int bigBlind, int timeInSeconds)
{
    roundsAdd(new RoundDef(timeInSeconds, smallBlind, bigBlind, this));
}
