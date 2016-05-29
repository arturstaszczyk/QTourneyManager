#include "gamecontext.h"

GameContext::GameContext(QObject *parent)
  : QObject(parent)
  , mEmptyRound(0,0)
  , mActiveRoundIdx(NO_ACTIVE_ROUND)
  , mMillisecondsElapsed(0)
  , mPaused(false)
{
}

GameContext::~GameContext()
{
    std::vector<RoundDef*>::iterator it, endIt = mRounds.end();
    for(it = mRounds.begin(); it != endIt; ++it)
        delete *it;
}

const RoundDef* GameContext::addRoundDef(int seconds, int smallBlind)
{
    mRounds.push_back(new RoundDef(seconds, smallBlind));
    return mRounds.back();
}

void GameContext::restart()
{
    mActiveRoundIdx = NO_ACTIVE_ROUND;
    nextRound();
}

bool GameContext::nextRound()
{
    bool advanced = false;
    if(++mActiveRoundIdx < static_cast<int>(mRounds.size()))
        advanced = true;
    else
        mActiveRoundIdx = NO_ACTIVE_ROUND;

    mMillisecondsElapsed = 0;
    mPaused = false;

    emit activeRoundChanged();

    return advanced;
}

bool GameContext::prevRound()
{
    bool advanced = false;
    if(--mActiveRoundIdx >= 0)
        advanced = true;
    else
        mActiveRoundIdx = NO_ACTIVE_ROUND;

    mMillisecondsElapsed = 0;
    mPaused = false;

    emit activeRoundChanged();

    return advanced;
}

void GameContext::tick(int millisecondsElapsed)
{
    if(mActiveRoundIdx == NO_ACTIVE_ROUND)
        return;

    if(mPaused)
        return;

    mMillisecondsElapsed += millisecondsElapsed;

    int seconds = floor(mMillisecondsElapsed / 1000.0);
    if(seconds > activeRound()->initialSeconds())
        nextRound();

    emit activeRoundMinutesLeftChanged();
    emit activeRoundSecondsLeftChanged();
}
