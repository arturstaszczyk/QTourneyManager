#include "MainScreenController.h"

MainScreenController::MainScreenController(TournamentStructureModel* tournamentStructure, QObject *parent)
  : QObject(parent)
  , mTournamentStructure(tournamentStructure)
  , mIsPaused(false)
  , mLastTick(0.0f)
  , mElapsedRoundSeconds(0.0f)
  , mElapsedPasueSeconds(0.0f)
{
}

void MainScreenController::setPaused(bool paused)
{
    if( mIsPaused != paused )
    {
        mIsPaused = paused;
        emit pausedChanged();
    }
}

RoundModel* MainScreenController::activeRound() const
{
    return mTournamentStructure->activeRound();
}

void MainScreenController::restart()
{
    mTournamentStructure->reset();
    nextRound();
}

bool MainScreenController::nextRound()
{
    bool advanced = mTournamentStructure->nextRound();

    mTime.restart();
    mLastTick = 0.0f;
    mElapsedRoundSeconds = mElapsedPasueSeconds = 0.0f;
    mIsPaused = false;

    emit activeRoundChanged();
    return advanced;
}

bool MainScreenController::prevRound()
{
    bool advanced = mTournamentStructure->prevRound();

    mTime.restart();
    mLastTick = 0.0f;
    mElapsedRoundSeconds = mElapsedPasueSeconds = 0.0f;
    mIsPaused = false;

    emit activeRoundChanged();
    return advanced;
}

void MainScreenController::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);

    if(!mTournamentStructure->isActive())
        return;

    float seconds = mTime.elapsed() / 1000.0;
    if(mIsPaused)
    {
        mLastTick = seconds;
    }
    else
    {
        mElapsedRoundSeconds += seconds - mLastTick;
        mLastTick = seconds;

        if(mElapsedRoundSeconds > activeRound()->roundTime())
            nextRound();

        emit activeRoundMinutesLeftChanged();
        emit activeRoundSecondsLeftChanged();
    }
}
