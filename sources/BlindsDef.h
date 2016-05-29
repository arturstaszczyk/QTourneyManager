#ifndef BLINDSDEF_H
#define BLINDSDEF_H

class BlindsDef
{
public:
    BlindsDef()
        : mSmallBlind(1)
    {
        // NOP
    }

    BlindsDef(int smallBlind)
        : mSmallBlind(smallBlind)
    {
        // NOP
    }

    BlindsDef(const BlindsDef& other)
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

    bool operator== (BlindsDef& rhs)
    {
        return this->mSmallBlind == rhs.mSmallBlind;
    }

private:
    int mSmallBlind;
};

#endif // BLINDSDEF_H
