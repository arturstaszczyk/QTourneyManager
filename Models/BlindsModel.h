#ifndef BLINDSDEF_H
#define BLINDSDEF_H

class BlindsModel
{
public:
    BlindsModel()
        : mSmallBlind(0)
    {
        // NOP
    }

    BlindsModel(int smallBlind)
        : mSmallBlind(smallBlind)
    {
        // NOP
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

    bool operator== (BlindsModel& rhs)
    {
        return this->mSmallBlind == rhs.mSmallBlind;
    }

private:
    int mSmallBlind;
};

#endif // BLINDSDEF_H
