#ifndef GAMECONTEXT_H
#define GAMECONTEXT_H

#include <cmath>
#include <vector>
#include <QTime>
#include <QTimer>
#include <QObject>

#include "Models/RoundModel.h"
#include "Models/TournamentStructureModel.h"

class MainScreenController : public QObject
{
    Q_OBJECT

public:
    Q_PROPERTY(RoundModel* activeRound READ activeRound NOTIFY activeRoundChanged)

    Q_PROPERTY(int activeRoundMinutesLeft READ activeRoundMinutesLeft NOTIFY activeRoundMinutesLeftChanged)
    Q_PROPERTY(int activeRoundSecondsLeft READ activeRoundSecondsLeft NOTIFY activeRoundSecondsLeftChanged)

    Q_PROPERTY(bool isPaused READ isPaused WRITE setPaused NOTIFY pausedChanged)

public:
    explicit MainScreenController(QObject* parent = nullptr)
        : QObject(parent)
    {}

    explicit MainScreenController(TournamentStructureModel* tournamentStructure,
                                  QObject *parent = 0);

    RoundModel* activeRound() const;
    bool isPaused() const { return mIsPaused; }

    int activeRoundMinutesLeft() const
    {
        return floor(totalSecondsLeft() / 60.0);
    }

    int activeRoundSecondsLeft() const
    {
        return totalSecondsLeft() - activeRoundMinutesLeft() * 60;
    }

public slots:

    void setPaused(bool isPaused);

    void restart();
    bool nextRound();
    bool prevRound();

signals:
    void activeRoundChanged();
    void activeRoundMinutesLeftChanged();
    void activeRoundSecondsLeftChanged();
    void pausedChanged();

private:

    void timerEvent(QTimerEvent* event) override;

    int totalSecondsLeft() const
    {
        return ceil(activeRound()->roundTime() - mElapsedRoundSeconds);
    }

private:
    QTime mTime;
    TournamentStructureModel* mTournamentStructure;

    bool                    mIsPaused;
    float                   mLastTick;

    float                   mElapsedRoundSeconds;
    float                   mElapsedPasueSeconds;
};

#endif // GAMECONTEXT_H
