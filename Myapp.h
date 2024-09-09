#ifndef MYAPP_H
#define MYAPP_H
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
#define Uses_TWindow
#define Uses_TCustomView
#define Uses_TDialogBox
#include <tvision/tv.h>
#include "demowindow.h" 
#include "TechInfo.h"
#include "Title.h"
#include "clock.h"

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <cstring>
#include "WindowIn.h"
const int cmModalBox    = 100; 
const int cmRadioDialog = 200;

class TMyApp : public TApplication {
public:
    TMyApp();
    static TStatusLine *initStatusLine(TRect r);
    static TMenuBar *initMenuBar(TRect r);
    static TDeskTop *initDeskTop(TRect r);
    virtual void handleEvent(TEvent& event);
    void myNewWindow();
    void idle();
    void TechInfo();
    void Tech1();
   void RadioDialog(void);

private:
    Title* _TitleLine;
    Clock* _Clock;
     TDemoWindow* _MainWindowInstance;

};

#endif 