#ifndef ROUNDDEF_H
#define ROUNDDEF_H

#include <math.h>
#include <QObject>
#include <QVariant>

#include "blindsdef.h"

class RoundDef : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int bigBlind READ bigBlind CONSTANT)
    Q_PROPERTY(int smallBlind READ smallBlind CONSTANT)
    Q_PROPERTY(bool isValid READ isValid CONSTANT)
    Q_PROPERTY(int initialSeconds READ initialSeconds CONSTANT)

public:
    explicit RoundDef(QObject *parent = 0);
    explicit RoundDef(int initialSeconds, int smallBlind, QObject *parent = 0);

    inline int initialSeconds() const
    {
        return mInitialSeconds;
    }

    inline int smallBlind() const
    {
        return mBlindsDef.smallBlind();
    }

    inline int bigBlind() const
    {
        return mBlindsDef.bigBlind();
    }

    inline bool isValid() const
    {
        return mBlindsDef.areValid();
    }

private:
    int         mInitialSeconds;
    BlindsDef   mBlindsDef;
};

#endif // ROUNDDEF_H
