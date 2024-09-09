#include "clock.h"


Clock::Clock(const TRect &r) : TView( r )
{
    strcpy(_LastTime, "        ");
    strcpy(_CurrentTime, "        ");
}

void Clock::draw()
{
    TDrawBuffer buf;
    ushort color = getColor( 0x0201 );

    buf.moveChar(0, ' ', color, (short)size.x);
    buf.moveStr(0, _CurrentTime, color);
    writeLine(0, 0, (short)size.x, 1, buf);
}

void Clock::update()
{
    time_t t = time(nullptr);
    char *date = ctime(&t);

    date[19] = '\0';
    strcpy(_CurrentTime, &date[11]);        /* Extract time. */

    if( strcmp(_LastTime, _CurrentTime)) {
        drawView();
        strcpy(_LastTime, _CurrentTime);
    }
}

TPalette &Clock::getPalette() const
{
    static TPalette palette( cpClockLine, sizeof(cpClockLine)-1 );
    return palette;
}

Clock::~Clock()
{

}


