#include "TournamentStructureModel.h"

#define NO_ACTIVE_ROUND -1

TournamentStructureModel::TournamentStructureModel(QObject* parent)
    : QObject(parent)
    , mActiveRoundIdx(NO_ACTIVE_ROUND)
{
}

const RoundModel* TournamentStructureModel::addRound(int seconds, int smallBlind)
{
    mRounds.push_back(new RoundModel(seconds, smallBlind, this));
    return mRounds.back();
}

void TournamentStructureModel::reset()
{
    mActiveRoundIdx = NO_ACTIVE_ROUND;
}

RoundModel* TournamentStructureModel::activeRound() const
{
    static RoundModel emptyRoundModel;
    if( mActiveRoundIdx >= 0 && mActiveRoundIdx < static_cast<int>(mRounds.size()))
        return mRounds[mActiveRoundIdx];
    else
        return &emptyRoundModel;
}

bool TournamentStructureModel::nextRound()
{
    bool advanced = false;
    if(++mActiveRoundIdx < static_cast<int>(mRounds.size()))
        advanced = true;
    else
        mActiveRoundIdx = NO_ACTIVE_ROUND;

    return advanced;
}

bool TournamentStructureModel::prevRound()
{
    bool advanced = false;
    if(--mActiveRoundIdx >= 0)
        advanced = true;
    else
        mActiveRoundIdx = NO_ACTIVE_ROUND;

    return advanced;
}

bool TournamentStructureModel::isActive()
{
    return mActiveRoundIdx != NO_ACTIVE_ROUND;
}
