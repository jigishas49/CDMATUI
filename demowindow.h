#ifndef DEMOWINDOW_H
#define DEMOWINDOW_H

#define Uses_TKeys
#define Uses_TApplication
#define Uses_TEvent
#define Uses_TRect
#define Uses_TDialog
#define Uses_TStaticText
#define Uses_TButton
#define Uses_TEvent
#define Uses_TMenuBar
#define Uses_TSubMenu
#define Uses_TMenuItem
#define Uses_TStatusLine
#define Uses_TStatusItem
#define Uses_TStatusDef
#define Uses_TDeskTop
#include <tvision/tv.h>
#include "myinterior.h"
#include "WindowIn.h"
class TDemoWindow : public TWindow {
public:
    TDemoWindow(const TRect& r, const char *aTitle, short aNumber);
    private:
    MainWindowInterior *_Interior;
};

#endif