
#define Uses_TDialog
#define Uses_TRect
#define Uses_TStaticText
#define Uses_TButton
#define Uses_TEvent
#define Uses_TWindow
#define Uses_TColorGroup
#define Uses_TColorItem
#define Uses_TColorDialog
#define Uses_TPalette
#define Uses_TDeskTop
#define Uses_TApplication
#define Uses_TChDirDialog
#define Uses_TScreen
#include "TechInfo.h"
#include "Myapp.h"
#include "address.h"
#include <fstream>
#include <tvision/tv.h>
#include "memory_mapping.h"
char data[5][5] = {"ON","OFF" };
 

MyTCollection *tc;
void TechInfoView::draw()
	{
	TDrawBuffer  *tb = new TDrawBuffer;

	TView::draw();
	tb->moveBuf(0, curdata, getColor(1), 10);
	writeBuf(0,0,10,1, *tb );
	}
    
void TechInfoList::handleEvent(TEvent &event)
	{
         // Call base handleEvent().

	if (event.what == evKeyDown)
		switch (event.keyDown.keyCode)
		 {
		 case kbUp :
           message( TProgram::deskTop, evBroadcast,
                    cmNewData, tc->at(focused > 0 ? focused - 1 : focused));
           break;
		 case kbDown :
           message( TProgram::deskTop, evBroadcast,
                    cmNewData, tc->at(focused  + 1));
           break;
        
		
		 default :
   		  break;
		}
	TListBox::handleEvent( event );
	 if (event.what == evBroadcast && event.message.command == cmListItemSelected) {
        TListBox::handleEvent(event);

        // Get the selected item
        char *selectedItem = (char *)tc->at(focused);

        // Determine the corresponding value to write to file
         // Default to 0
		 int valueTowrite=0;
        if (strcmp(selectedItem, "ON") == 0) {
            valueTowrite = 1;
        }
         mem_trans(valueTowrite);
       //reg = set_registers2(uczMappedArea2, ulSUMAddressOffset2);
        // Write to file
        
    } else {
        TListBox::handleEvent(event);
    }
	
	}

 

void TechInfoView::handleEvent(TEvent &event)
	{
	TView::handleEvent( event );

	if (event.what == evBroadcast)
		if (event.message.command == cmNewData)
			{
			curdata = (char *)event.message.infoPtr;
			drawView();
			}
	}
TechInfoList::TechInfoList(TRect& r, ushort numcols, TScrollBar *sb) :
 TListBox ( TRect(r.a.x + 2, r.a.y + 1, r.b.x - 3, r.b.y - 2 ), numcols, sb )
	{
	tc = new MyTCollection ();
	for (int c = 0; c < 2; c++)
		{
		tc->insert( (void *)data[c] );
		}
	newList( tc );
	}
