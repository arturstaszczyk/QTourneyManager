#ifndef GAMECONTEXT_H
#define GAMECONTEXT_H

#include <cmath>
#include <vector>
#include <QTime>
#include <QTimer>
#include <QObject>

#include "Models/RoundModel.h"

class MainScreenController : public QObject
{
    Q_OBJECT

public:
    Q_PROPERTY(RoundModel* activeRound READ activeRound NOTIFY activeRoundChanged)

    Q_PROPERTY(int activeRoundMinutesLeft READ activeRoundMinutesLeft NOTIFY activeRoundMinutesLeftChanged)
    Q_PROPERTY(int activeRoundSecondsLeft READ activeRoundSecondsLeft NOTIFY activeRoundSecondsLeftChanged)

    Q_PROPERTY(bool paused READ paused WRITE setPaused NOTIFY pausedChanged)

public:
    explicit MainScreenController(QObject *parent = 0);
    ~MainScreenController();

    const RoundModel* addRoundDef(int seconds, int smallBlind);

    RoundModel* activeRound() const;
    bool paused() const { return mPaused; }

    int activeRoundMinutesLeft() const
    {
        return floor(totalSecondsLeft() / 60.0);
    }

    int activeRoundSecondsLeft() const
    {
        return totalSecondsLeft() - activeRoundMinutesLeft() * 60;
    }

public slots:

    void setPaused(bool paused);
    void tick();
    void restart();
    bool nextRound();
    bool prevRound();

signals:
    void activeRoundChanged();
    void activeRoundMinutesLeftChanged();
    void activeRoundSecondsLeftChanged();
    void pausedChanged();

private:

    int totalSecondsLeft() const
    {
        return activeRound()->roundTime() - floor(mMillisecondsElapsed / 1000.0);
    }

private:
    QTime mTime;
    std::vector<RoundModel*>  mRounds;

    int                     mActiveRoundIdx;
    int                     mMillisecondsElapsed;

    bool                    mPaused;
};

#endif // GAMECONTEXT_H
