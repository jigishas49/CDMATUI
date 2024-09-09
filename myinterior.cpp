#include "myinterior.h"

MyInterior::MyInterior(const TRect& bounds) : TView(bounds) {
    growMode = gfGrowHiX | gfGrowHiY;
    options = options | ofFramed;
}

void MyInterior::draw() {
    const char *hstr = "Welcome to Turbo Vision";
    ushort color = getColor(0x0301);
    
    TView::draw();
    TDrawBuffer b;
    b.moveStr(0, hstr, color);
    writeLine(0, 0, 23, 1, b);
}