#ifndef TOURNAMENTSTRUCTUREMODEL_H
#define TOURNAMENTSTRUCTUREMODEL_H

#include <QObject>
#include "RoundModel.h"

class TournamentStructureModel : public QObject
{
    Q_OBJECT

public:
    explicit TournamentStructureModel(QObject* parent = nullptr);

    const RoundModel* addRound(int seconds, int smallBlind);

    void reset();

    RoundModel* activeRound() const;
    bool nextRound();
    bool prevRound();

    bool isActive();
private:
    QList<RoundModel*> mRounds;
    int mActiveRoundIdx;
};

#endif // TOURNAMENTSTRUCTUREMODEL_H
