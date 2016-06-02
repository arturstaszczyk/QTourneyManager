#ifndef ROUNDDEF_H
#define ROUNDDEF_H

#include <QObject>

#include "BlindsModel.h"

class RoundModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(BlindsModel* blinds READ blinds CONSTANT)
    Q_PROPERTY(bool isValid READ isValid CONSTANT)
    Q_PROPERTY(int roundTime READ roundTime CONSTANT)

public:
    explicit RoundModel(QObject *parent = 0);
    explicit RoundModel(int roundTime, int smallBlind, QObject *parent = 0);

    inline int roundTime() const
    {
        return mRoundTime;
    }

    inline BlindsModel* blinds() const
    {
        return mBlindsModel;
    }

    inline bool isValid() const
    {
        return mBlindsModel->areValid() && mRoundTime > 0;
    }

    bool operator== (const RoundModel& rhs) const
    {
        return this->mBlindsModel == rhs.mBlindsModel &&
                this->mRoundTime == rhs.mRoundTime;
    }

    bool operator!= (const RoundModel& rhs) const
    {
        return !this->operator ==(rhs);
    }

private:
    int             mRoundTime;
    BlindsModel*    mBlindsModel;
};

#endif // ROUNDDEF_H
