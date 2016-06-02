#include "MainScreenController.h"

#include <QDebug>

MainScreenController::MainScreenController(TournamentStructureModel* tournamentStructure, QObject *parent)
  : QObject(parent)
  , mTournamentStructure(tournamentStructure)
  , mIsPaused(false)
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
    mTime.restart();
    nextRound();
}

bool MainScreenController::nextRound()
{
    bool advanced = mTournamentStructure->nextRound();
    mTime.restart();
    mIsPaused = false;

    emit activeRoundChanged();
    return advanced;
}

bool MainScreenController::prevRound()
{
    bool advanced = mTournamentStructure->prevRound();
    mTime.restart();
    mIsPaused = false;

    emit activeRoundChanged();
    return advanced;
}

void MainScreenController::tick()
{
    if(!mTournamentStructure->isActive())
        return;

    if(mIsPaused)
        return;

    int seconds = floor(mTime.elapsed() / 1000.0);
    if(seconds > activeRound()->roundTime())
        nextRound();

    emit activeRoundMinutesLeftChanged();
    emit activeRoundSecondsLeftChanged();
}
