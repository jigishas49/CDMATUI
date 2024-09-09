#include "demowindow.h"
#include "myinterior.h"

TDemoWindow::TDemoWindow(const TRect& r, const char *aTitle, short aNumber)
    : TWindow(r, aTitle, aNumber),
      TWindowInit(&TDemoWindow::initFrame)
{
    TRect curRect = getClipRect();
    curRect.grow(-1, -1);
    insert(new MyInterior(curRect));
     _Interior = new MainWindowInterior(curRect);
    insert(_Interior);
}