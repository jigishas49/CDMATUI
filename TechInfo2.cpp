
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
#include "TechInfo2.h"
#include "Myapp.h"
#include "address.h"
#include <fstream>
#include <tvision/tv.h>
#include "memory_mapping.h"
char  data2[20][20] = {"1Mcps","2.5Mcps", "5Mcps","10Mcps" };
 

MyTCollection2 *tc2;
void TechInfoView2::draw()
	{
	TDrawBuffer  *tb = new TDrawBuffer;

	TView::draw();
	tb->moveBuf(0, curdata, getColor(1), 10);
	writeBuf(0,0,10,1, *tb );
	}
    
void TechInfoList2::handleEvent(TEvent &event)
	{
         // Call base handleEvent().

	if (event.what == evKeyDown)
		switch (event.keyDown.keyCode)
		 {
		 case kbUp :
           message( TProgram::deskTop, evBroadcast,
                    cmNewData2, tc2->at(focused > 0 ? focused - 1 : focused));
           break;
		 case kbDown :
           message( TProgram::deskTop, evBroadcast,
                    cmNewData2, tc2->at(focused  + 1));
           break;
        
		
		 default :
   		  break;
		}
	
	TListBox::handleEvent( event );
	 if (event.what == evBroadcast && event.message.command == cmListItemSelected) {
        TListBox::handleEvent(event);

        // Get the selected item
        char *selectedItem = (char *)tc2->at(focused);

        // Determine the corresponding value to write to file
         // Default to 0
		 int valueTowrite=1;

	switch (selectedItem[0]) {
    case '1':  // if selectedItem == "1MCps" or "10MCps"
        if (strcmp(selectedItem, "1Mcps") == 0) {
            valueTowrite = 0b00;  // binary representation of 0
        } else if (strcmp(selectedItem, "10Mcps") == 0) {
            valueTowrite = 0b11;  // binary representation of 3
        }
        break;

    case '2':  // if selectedItem == "2.5MCps"
        if (strcmp(selectedItem, "2.5Mcps") == 0) {
            valueTowrite = 0b01;  // binary representation of 1
        }
        break;

    case '5':  // if selectedItem == "5MCps"
        if (strcmp(selectedItem, "5Mcps") == 0) {
            valueTowrite = 0b10;  // binary representation of 2
        }
        break;

    default:
        // Handle invalid selection
        printf("Invalid selection\n");
        break;
    }
TransmitterStatus TransmitterStatus=mem_trans();
		*(TransmitterStatus.chip_sel)=valueTowrite;
    std::ofstream outFile("example.txt");
        if (outFile.is_open()) {
            outFile << "Value: " << valueTowrite << std::endl;
            outFile.close();
        } else {
            // Handle the case when the file can't be opened
            std::cerr << "Unable to open file for writing." << std::endl;
        }
         
       
       //reg = set_registers2(uczMappedArea2, ulSUMAddressOffset2);
        // Write to file
        
    }else {
        TListBox::handleEvent(event);
    }
	
	}

 

void TechInfoView2::handleEvent(TEvent &event)
	{
	TView::handleEvent( event );

	if (event.what == evBroadcast)
		if (event.message.command == cmNewData2)
			{
			curdata = (char *)event.message.infoPtr;
			drawView();
			}
	}
TechInfoList2::TechInfoList2(TRect& r, ushort numcols, TScrollBar *sb) :
 TListBox ( TRect(r.a.x + 2, r.a.y + 1, r.b.x - 3, r.b.y - 2 ), numcols, sb )
	{
	tc2 = new MyTCollection2 ();
	for (int c = 0; c < 5; c++)
		{
		tc2->insert( (void *)data2[c] );
		}
	newList( tc2 );
	}
     