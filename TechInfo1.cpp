
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

#include "TechInfo1.h"
#include "Myapp.h"
#include "address.h"
#include <fstream>
#include <tvision/tv.h>
#include "memory_mapping.h"
char data1[5][5] = {"ON","OFF" };
 

MyTCollection1 *tc1;
void TechInfoView1::draw()
	{
	TDrawBuffer  *tb = new TDrawBuffer;

	TView::draw();
	tb->moveBuf(0, curdata, getColor(1), 10);
	writeBuf(0,0,10,1, *tb );
	}
    
void TechInfoList1::handleEvent(TEvent &event)
	{
         // Call base handleEvent().

	if (event.what == evKeyDown)
		switch (event.keyDown.keyCode)
		 {
		 case kbUp :
           message( TProgram::deskTop, evBroadcast,
                    cmNewData1, tc1->at(focused > 0 ? focused - 1 : focused));
           break;
		 case kbDown :
           message( TProgram::deskTop, evBroadcast,
                    cmNewData1, tc1->at(focused  + 1));
           break;
        
		
		 default :
   		  break;
		}
	TListBox::handleEvent( event );
	 if (event.what == evBroadcast && event.message.command == cmListItemSelected) {
        TListBox::handleEvent(event);

        // Get the selected item
        char *selectedItem = (char *)tc1->at(focused);

        // Determine the corresponding value to write to file
         // Default to 0
		 int valueTowrite=0;
        if (strcmp(selectedItem, "ON") == 0) {
            valueTowrite = 1;
        }
          std::ofstream outFile("example.txt");
        if (outFile.is_open()) {
            outFile << "Value: " << valueTowrite << std::endl;
            outFile.close();
        } else {
            // Handle the case when the file can't be opened
            std::cerr << "Unable to open file for writing." << std::endl;
        }
          TransmitterStatus TransmitterStatus=mem_trans();
		*(TransmitterStatus.mod_on_off)=valueToWrite;
       
       //reg = set_registers2(uczMappedArea2, ulSUMAddressOffset2);
        // Write to file
        
    } else {
        TListBox::handleEvent(event);
    }
	
	}

 

void TechInfoView1::handleEvent(TEvent &event)
	{
	TView::handleEvent( event );

	if (event.what == evBroadcast)
		if (event.message.command == cmNewData1)
			{
			curdata = (char *)event.message.infoPtr;
			drawView();
			}
	}
TechInfoList1::TechInfoList1(TRect& r, ushort numcols, TScrollBar *sb) :
 TListBox ( TRect(r.a.x + 2, r.a.y + 1, r.b.x - 3, r.b.y - 2 ), numcols, sb )
	{
	tc1 = new MyTCollection1 ();
	for (int c = 0; c < 2; c++)
		{
		tc1->insert( (void *)data1[c] );
		}
	newList( tc1 );
	}
     