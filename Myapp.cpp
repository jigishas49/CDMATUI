#include "Myapp.h"
#include "TechInfo.h"
#include "TModalBox.h"
#include "WindowIn.h"
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
    r.a.y = r.b.y - 1;
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
        *new TMenuItem("~M~ode", cmTechInfo, kbF3, hcNoContext, "F3") +
        *new TMenuItem("~O~pen", cmTechInfo, kbF3, hcNoContext, "F3") +
        *new TMenuItem("~N~ew", cmMyNewWin, kbF4, hcNoContext, "F4") +
        *new TMenuItem("~C~hipRate", cmRadioDialog, kbF4, hcNoContext, "F4")+
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
            TechInfo();
            break;
        case cmRadioDialog:
        RadioDialog();
        break;
        case cmClose:
             Tech1();
            case cmMyNewWin:
            
            TView* t = (TView*)validView(new TModalBox());
            if (t)
            {
                // ExecView() a modal dialog box
                deskTop->execView(t);

                // Must destroy a modal dialog box
                destroy(t);
            }
            break;
          
        }
        clearEvent(event);
    }
}
void TMyApp::Tech1()
{
    
 
    
  
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
}
void TMyApp::RadioDialog(void)
{
    TDialog *pd = new TDialog( TRect( 2,1,40,15), " Radio Buttons ");
    if( validView( pd ) )
    {
        TSItem *J1 = new TSItem("Nietsche",
                     new TSItem("Kant",
                     new TSItem("Daly",
                     new TSItem("Socrates",
                     new TSItem("Descartes",
                    
                     new TSItem("Bird",
                     new TSItem("Jordan", 0 )))))));

    


   



        TView *RadioButtons = new TRadioButtons( TRect(2,1,40,16), J1 );

        pd->insert( RadioButtons );
         TButton *btnOk = new TButton(TRect(10,  8, 25, 10), "~O~k", cmOK, bfDefault);
        pd->insert(btnOk);
        deskTop->execView( pd );
         TRadioButtons *rb = static_cast<TRadioButtons *>(RadioButtons);
        int selectedIndex = rb->mark(0); // Mark the first radio button (index 0)

       
        
    }

    destroy(pd);
}