#include "Myapp.h"
#include "TechInfo.h"

#include "TModalBox.h"
#include "WindowIn.h"
#include "TechInfo1.h"
#include "address.h"
#include "memory_mapping.h"
#include "TechInfo2.h"
#include "TechInfo3.h"

#include <ctime> 

#define UPDATE_INTERVAL 1000
const int cmMyFileOpen = 200;
const int cmMyNewWin   = 201;

static short winNumber = 0;

TMyApp::TMyApp() :
    TProgInit(&TMyApp::initStatusLine,
              &TMyApp::initMenuBar,
              &TMyApp::initDeskTop)
{
   TRect r = deskTop->getBounds();     // get size of deskTop
	++r.a.y;                            // compensate for title line
	

    //Draw the Title
	r = getExtent();
	r.b.y = r.a.y + 1;                  // put title at top
    _TitleLine = new Title( r, "TWSTFT Modem v1.0" );
	insert(_TitleLine);
    r = getExtent();                      // Create the clock view.
    r.a.x = r.b.x-15;      r.b.y = r.a.y + 1;
    _Clock = new Clock( r );
    _Clock->growMode = gfGrowLoX | gfGrowHiX;
    insert(_Clock);
     r = getExtent();
    r.b.y = r.b.y - 2;
    _MainWindowInstance = new TDemoWindow(r, "Main Window", 1);
	deskTop->insert(_MainWindowInstance);

}

TDeskTop  *TMyApp::initDeskTop(TRect r) {
	return new TDeskTop(r);
}
TStatusLine *TMyApp::initStatusLine(TRect r)
{
    r.a.y = r.b.y - 1;if (deskTop->current)
        {
            MainWindowInterior *view = dynamic_cast<MainWindowInterior*>(deskTop->current);
            if (view)
            {
                view->update(); // Call update method
            }
        }
    return new TStatusLine(r,
        *new TStatusDef(0, 0xFFFF) +
        *new TStatusItem(0, kbF10, cmMenu) +
        *new TStatusItem("~Alt-X~ Exit", kbAltX, cmQuit) +
        *new TStatusItem("~Alt-F3~ Close", kbAltF3, cmClose)
    );
}

TMenuBar *TMyApp::initMenuBar(TRect r)
{
    ++r.a.y;
	    r.b.y =  r.a.y + 1;

    return new TMenuBar(r,
        *new TSubMenu("~T~ransmitter", kbAltF) +
        *new TMenuItem("~Tx", cmTechInfo1, kbF3, hcNoContext, "F3") +
        *new TMenuItem("~Mod", cmTechInfo1, kbF3, hcNoContext, "F3") +
        *new TMenuItem("~M~essage", cmMyNewWin, kbF4, hcNoContext, "F4") +
        *new TMenuItem("~C~hipRate", cmRadioDialog, kbF4, hcNoContext, "F4")+
        *new TMenuItem("~P~RN", cmRadioDialog2, kbF4, hcNoContext, "F4")+
        newLine() +
        *new TMenuItem("E~x~it", cmQuit, cmQuit, hcNoContext, "Alt-X") +
        *new TSubMenu("~W~indow", kbAltW) +
        *new TMenuItem("~N~ext", cmNext, kbF6, hcNoContext, "F6") +
        *new TMenuItem("~Z~oom", cmZoom, kbF5, hcNoContext, "F5")
    );
}

void TMyApp::handleEvent(TEvent& event)
{
    TApplication::handleEvent(event);
    if (event.what == evCommand)
    {
        switch (event.message.command)
        {
        
            
        case cmTechInfo:
            TechInfo1();
            break;
        case cmTechInfo1:
             TechInfo1();
             break;
        case cmRadioDialog:
        RadioDialog();
        break;
        case cmRadioDialog2:
        RadioDialog2();
        case cmClose:
             Tech1();
            case cmMyNewWin:
            Message();
           
            break;
          
        }
        clearEvent(event);
    }
}
void TMyApp::Tech1()
{
    
 
    
  
}
void TMyApp::Message()
	  {
	  TRect tr;

	  tr.a.x = 10;
	  tr.a.y = 17;
	  tr.b.x = tr.a.x + 30;
	  tr.b.y = tr.a.y + 3;
	  TechInfoView1 *tv = new TechInfoView1(TRect(1,1,10,3));
	  TWindow *twv =  new TWindow(
                     TRect( tr.a.x - 1, tr.a.y - 1, tr.b.x + 1, tr.b.y + 1 ),
											 "Individual View", 2 );
	  twv->insert( tv );
	  deskTop->insert( twv );

	  tr.a.x = 10;
	  tr.a.y = 3;
	  tr.b.x = tr.a.x + 30;
	  tr.b.y = tr.a.y + 10;
	  TechInfoDialog1 *ti = new TechInfoDialog1( tr );
      
	  deskTop->execView( ti );
         destroy(ti);
   }
void TMyApp::TechInfo1()
	  {
	  TRect tr;

	  tr.a.x = 10;
	  tr.a.y = 17;
	  tr.b.x = tr.a.x + 30;
	  tr.b.y = tr.a.y + 3;
	  TechInfoView1 *tv = new TechInfoView1(TRect(1,1,10,3));
	  TWindow *twv =  new TWindow(
                     TRect( tr.a.x - 1, tr.a.y - 1, tr.b.x + 1, tr.b.y + 1 ),
											 "Individual View", 2 );
	  twv->insert( tv );
	  deskTop->insert( twv );

	  tr.a.x = 10;
	  tr.a.y = 3;
	  tr.b.x = tr.a.x + 30;
	  tr.b.y = tr.a.y + 10;
	  TechInfoDialog1 *ti = new TechInfoDialog1( tr );
      
	  deskTop->execView( ti );
         destroy(ti);
   }

void TMyApp::TechInfo()
	  {
	  TRect tr;

	  tr.a.x = 10;
	  tr.a.y = 17;
	  tr.b.x = tr.a.x + 30;
	  tr.b.y = tr.a.y + 3;
	  TechInfoView *tv = new TechInfoView(TRect(1,1,10,3));
	  TWindow *twv =  new TWindow(
                     TRect( tr.a.x - 1, tr.a.y - 1, tr.b.x + 1, tr.b.y + 1 ),
											 "Individual View", 2 );
	  twv->insert( tv );
	  deskTop->insert( twv );

	  tr.a.x = 10;
	  tr.a.y = 3;
	  tr.b.x = tr.a.x + 30;
	  tr.b.y = tr.a.y + 10;
	  TechInfoDialog *ti = new TechInfoDialog( tr );
      
	  deskTop->execView( ti );
         destroy(ti);
   }

void TMyApp::idle()
{
    TProgram::TProgram::idle();
    _Clock->update();
   
        

        // Optionally, add a delay to control update frequency
        
}
void TMyApp::RadioDialog(void)
{
    
        TRect dialogRect(2, 1, 50, 20);
        TRect tr;

	  tr.a.x = 10;
	  tr.a.y = 17;
	  tr.b.x = tr.a.x + 30;
	  tr.b.y = tr.a.y + 3;
	  TechInfoView1 *tv = new TechInfoView1(TRect(1,1,10,3));
	  TWindow *twv =  new TWindow(
                     TRect( tr.a.x - 1, tr.a.y - 1, tr.b.x + 1, tr.b.y + 1 ),
											 "Individual View", 2 );
	  twv->insert( tv );
	  deskTop->insert( twv );

	  tr.a.x = 10;
	  tr.a.y = 3;
	  tr.b.x = tr.a.x + 30;
	  tr.b.y = tr.a.y + 10;
         TechInfoDialog2 *ti = new TechInfoDialog2( tr);
        
        deskTop->execView( ti );
         destroy(ti);
        
         
       
        
    }

   

void TMyApp::RadioDialog2(void)
{
    TRect dialogRect(2, 1, 50, 20);
        TRect tr;

	  tr.a.x = 5;
	  tr.a.y = 10;
	  tr.b.x = tr.a.x + 100;
	  tr.b.y = tr.a.y + 10;
	  TechInfoView1 *tv = new TechInfoView1(TRect(1,1,10,3));
	  TWindow *twv =  new TWindow(
                     TRect( tr.a.x - 1, tr.a.y - 1, tr.b.x + 1, tr.b.y + 1 ),
											 "Individual View", 2 );
	  twv->insert( tv );
	  deskTop->insert( twv );

	  tr.a.x = 10;
	  tr.a.y = 3;
	  tr.b.x = tr.a.x + 30;
	  tr.b.y = tr.a.y + 10;
         TechInfoDialog4 *ti = new TechInfoDialog4( tr);
        
        deskTop->execView( ti );
         destroy(ti);
        
}