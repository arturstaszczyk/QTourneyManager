#ifndef BLINDSDEF_H
#define BLINDSDEF_H

#include <QObject>

class BlindsModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int smallBlind READ smallBlind CONSTANT)
    Q_PROPERTY(int bigBlind READ bigBlind CONSTANT)

public:
    explicit BlindsModel(QObject* parent = nullptr)
        : QObject(parent)
        , mSmallBlind(0)
    {
    }

    explicit BlindsModel(int smallBlind, QObject* parent = nullptr)
        : QObject(parent)
        , mSmallBlind(smallBlind)
    {
    }

    BlindsModel(const BlindsModel& other)
    {
        this->mSmallBlind = other.mSmallBlind;
    }

    inline int smallBlind() const
    {
        return mSmallBlind;
    }

    inline int bigBlind() const
    {
        return mSmallBlind * 2;
    }

    inline bool areValid() const
    {
        return mSmallBlind != 0;
    }

    bool operator== (const BlindsModel& rhs) const
    {
        return this->mSmallBlind == rhs.mSmallBlind;
    }

private:
    int mSmallBlind;
};

#endif // BLINDSDEF_H
