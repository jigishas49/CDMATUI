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
#ifndef evTimer
#define evTimer 4
#endif
const int cmModalBox    = 100; 
const int cmRadioDialog = 202;
const int cmRadioDialog2 = 300;
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
    void TechInfo1();
    void Tech1();
    void Message();
   void RadioDialog(void);
void RadioDialog2(void);
private:
    Title* _TitleLine;
    Clock* _Clock;
     TDemoWindow* _MainWindowInstance;

};

#endif 