#include "MainScreenController.h"

#include <QDebug>

#define NO_ACTIVE_ROUND -1

MainScreenController::MainScreenController(QObject *parent)
  : QObject(parent)
  , mActiveRoundIdx(NO_ACTIVE_ROUND)
  , mMillisecondsElapsed(0)
  , mPaused(false)
{
}

MainScreenController::~MainScreenController()
{
}

const RoundModel* MainScreenController::addRoundDef(int seconds, int smallBlind)
{
    mRounds.push_back(new RoundModel(seconds, smallBlind, this));
    return mRounds.back();
}

void MainScreenController::setPaused(bool paused)
{
    if( mPaused != paused )
    {
        mPaused = paused;
        emit pausedChanged();
    }
}

RoundModel* MainScreenController::activeRound() const
{
    static RoundModel emptyRoundModel;
    if( mActiveRoundIdx >= 0 && mActiveRoundIdx < static_cast<int>(mRounds.size()))
        return mRounds[mActiveRoundIdx];
    else
        return &emptyRoundModel;
}

void MainScreenController::restart()
{
    mActiveRoundIdx = NO_ACTIVE_ROUND;
    mTime.restart();
    nextRound();
}

bool MainScreenController::nextRound()
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

bool MainScreenController::prevRound()
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

void MainScreenController::tick()
{
    //qDebug() << "tick";
    if(mActiveRoundIdx == NO_ACTIVE_ROUND)
        return;

    if(mPaused)
        return;

    mMillisecondsElapsed = mTime.elapsed();

    int seconds = floor(mMillisecondsElapsed / 1000.0);
    if(seconds > activeRound()->roundTime())
        nextRound();

    emit activeRoundMinutesLeftChanged();
    emit activeRoundSecondsLeftChanged();
}
