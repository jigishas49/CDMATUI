#ifndef TUICLOCK_H
#define TUICLOCK_H

#define Uses_TView
#include <tvision/tv.h>

#define cpClockLine "\x09\x0D"

class Clock : public TView
{
public:
public:
    Clock(const TRect& r);
    void draw();
    void update();
    TPalette& getPalette() const;
    virtual ~Clock();

private:
    char _LastTime[80];
    char _CurrentTime[80];
};

#endif // TUICLOCK_H
