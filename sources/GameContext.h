#ifndef GAMECONTEXT_H
#define GAMECONTEXT_H

#include <vector>
#include <QObject>

#include "rounddef.h"

#define NO_ACTIVE_ROUND -1

class GameContext : public QObject
{
    Q_OBJECT

    Q_PROPERTY(RoundDef* activeRound READ activeRound NOTIFY activeRoundChanged)

    Q_PROPERTY(int activeRoundMinutesLeft READ activeRoundMinutesLeft NOTIFY activeRoundMinutesLeftChanged)
    Q_PROPERTY(int activeRoundSecondsLeft READ activeRoundSecondsLeft NOTIFY activeRoundSecondsLeftChanged)

    Q_PROPERTY(bool paused READ paused WRITE setPaused NOTIFY pausedChanged)

public:

    void setPaused( bool paused )
    {
        if( mPaused != paused )
        {
            mPaused = paused;
            emit pausedChanged();
        }
    }

    bool paused() const
    {
        return mPaused;
    }

    RoundDef* activeRound()
    {
        if( mActiveRoundIdx >= 0 && mActiveRoundIdx < static_cast<int>(mRounds.size()))
            return mRounds[mActiveRoundIdx];
        else
            return &mEmptyRound;
    }

    int activeRoundMinutesLeft()
    {
        return floor(totalSecondsLeft() / 60.0);
    }

    int activeRoundSecondsLeft()
    {
        return totalSecondsLeft() - activeRoundMinutesLeft() * 60;
    }

public:
    explicit GameContext(QObject *parent = 0);
    ~GameContext();

    const RoundDef* addRoundDef(int seconds, int smallBlind);

public slots:

    void restart();
    bool nextRound();
    bool prevRound();

    void tick(int millisecondsElapsed);

signals:
    void activeRoundChanged();
    void activeRoundMinutesLeftChanged();
    void activeRoundSecondsLeftChanged();
    void pausedChanged();

private:

    int totalSecondsLeft()
    {
        return activeRound()->initialSeconds() - floor(mMillisecondsElapsed / 1000.0);
    }

private:
    std::vector<RoundDef*>  mRounds;
    RoundDef                mEmptyRound;

    int                     mActiveRoundIdx;
    int                     mMillisecondsElapsed;

    bool                    mPaused;
};

#endif // GAMECONTEXT_H
