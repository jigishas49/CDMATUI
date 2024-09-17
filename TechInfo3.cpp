
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
#include "TechInfo3.h"
#include "Myapp.h"
#include "address.h"
#include <fstream>
#include <tvision/tv.h>
#include "memory_mapping.h"
char  data4[40][20] = {"PRN1","PRN2","PRN3","PRN4","PRN5","PRN6","PRN7","PRN8","PRN9","PRN10","PRN11","PRN12","PRN13","PRN14","PRN15","PRN16","PRN17","PRN18","PRN19","PRN20","PRN21","PRN22","PRN23","PRN24","PRN25","PRN26","PRN27","PRN28","PRN29","PRN30","PRN31","PRN32"};
 

MyTCollection4 *tc4;
void TechInfoView4::draw()
	{
	TDrawBuffer  *tb = new TDrawBuffer;

	TView::draw();
	tb->moveBuf(0, curdata, getColor(1), 10);
	writeBuf(0,0,10,1, *tb );
	}
    
void TechInfoList4::handleEvent(TEvent &event)
	{
         // Call base handleEvent().

	if (event.what == evKeyDown)
		switch (event.keyDown.keyCode)
		 {
		 case kbUp :
           message( TProgram::deskTop, evBroadcast,
                    cmNewData4, tc4->at(focused > 0 ? focused - 1 : focused));
           break;
		 case kbDown :
           message( TProgram::deskTop, evBroadcast,
                    cmNewData4, tc4->at(focused  + 1));
           break;
        
		
		 default :
   		  break;
		}
	
	TListBox::handleEvent( event );
	 if (event.what == evBroadcast && event.message.command == cmListItemSelected) {
        TListBox::handleEvent(event);

        // Get the selected item
        char *selectedItem = (char *)tc4->at(focused);

        // Determine the corresponding value to write to file
         // Default to 0
		 int valueTowrite=1;

	switch (selectedItem[3]) {
    case '1':
    
            if (strcmp(selectedItem, "PRN1") == 0) 
            valueTowrite = 0b00000; 
           else if (strcmp(selectedItem, "PRN10") == 0) 
            valueTowrite = 0b01001; 
            else if (strcmp(selectedItem, "PRN11") == 0) 
            valueTowrite = 0b01010; 
            else if (strcmp(selectedItem, "PRN12") == 0) 
            valueTowrite = 0b01011; 
            else if (strcmp(selectedItem, "PRN13") == 0) 
            valueTowrite = 0b01100; 
           else if (strcmp(selectedItem, "PRN14") == 0) 
            valueTowrite = 0b01101; 
           else if (strcmp(selectedItem, "PRN15") == 0) 
            valueTowrite = 0b01110; 
           else if (strcmp(selectedItem, "PRN16") == 0) 
            valueTowrite = 0b01111; 
          else if (strcmp(selectedItem, "PRN17") == 0) 
            valueTowrite = 0b10000; 
          else   if (strcmp(selectedItem, "PRN18") == 0) 
            valueTowrite = 0b10001; 
          else  if (strcmp(selectedItem, "PRN19") == 0) 
            valueTowrite = 0b10010; 
         
    
        break;
        

        
    
    
    case '2': 
             
            if (strcmp(selectedItem, "PRN2") == 0) 
            valueTowrite = 0b00001; 
           else if (strcmp(selectedItem, "PRN20") == 0) 
            valueTowrite = 0b10011; 
            else if (strcmp(selectedItem, "PRN21") == 0) 
            valueTowrite = 0b10100; 
            else if (strcmp(selectedItem, "PRN22") == 0) 
            valueTowrite = 0b10101; 
            else if (strcmp(selectedItem, "PRN23") == 0) 
            valueTowrite = 0b10110; 
           else if (strcmp(selectedItem, "PRN24") == 0) 
            valueTowrite = 0b10111; 
           else if (strcmp(selectedItem, "PRN25") == 0) 
            valueTowrite = 0b11000; 
           else if (strcmp(selectedItem, "PRN26") == 0) 
            valueTowrite = 0b11001; 
          else if (strcmp(selectedItem, "PRN27") == 0) 
            valueTowrite = 0b11010; 
          else   if (strcmp(selectedItem, "PRN28") == 0) 
            valueTowrite = 0b11011; 
          else  if (strcmp(selectedItem, "PRN29") == 0) 
            valueTowrite = 0b11100; 
     break;
        
    case '3':
        if (strcmp(selectedItem, "PRN3") == 0) 
            valueTowrite = 0b00010; 
           else if (strcmp(selectedItem, "PRN30") == 0) 
            valueTowrite = 0b11101; 
            else if (strcmp(selectedItem, "PRN31") == 0) 
            valueTowrite = 0b11100; 
            else if (strcmp(selectedItem, "PRN32") == 0) 
            valueTowrite = 0b11111; 
            break;

        
        case '4':

        if (strcmp(selectedItem, "PRN4") == 0) 
            valueTowrite = 0b00011; 
            break;
        case '5':

        if (strcmp(selectedItem, "PRN5") == 0) 
            valueTowrite = 0b00100;  
            break;
        case '6':

        if (strcmp(selectedItem, "PRN6") == 0) 
            valueTowrite = 0b00101; 
            break;
        case '7':

        if (strcmp(selectedItem, "PRN7") == 0) 
            valueTowrite = 0b00110;  
            break;
        case '8':

        if (strcmp(selectedItem, "PRN8") == 0) 
            valueTowrite = 0b00111;
            break; 
        case '9':

        if (strcmp(selectedItem, "PRN9") == 0) 
            valueTowrite = 0b01000; 
            break;

    default:
        // Handle invalid selection
        printf("Invalid selection\n");
        break;
    }
TransmitterStatus TransmitterStatus=mem_trans();
		*(TransmitterStatus.prn)=valueTowrite;
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

 

void TechInfoView4::handleEvent(TEvent &event)
	{
	TView::handleEvent( event );

	if (event.what == evBroadcast)
		if (event.message.command == cmNewData4)
			{
			curdata = (char *)event.message.infoPtr;
			drawView();
			}
	}
TechInfoList4::TechInfoList4(TRect& r, ushort numcols, TScrollBar *sb) :
 TListBox ( TRect(r.a.x + 2, r.a.y + 1, r.b.x - 3, r.b.y - 2 ), numcols, sb )
	{
	tc4 = new MyTCollection4 ();
	for (int c = 0; c < 31; c++)
		{
		tc4->insert( (void *)data4[c] );
		}
	newList( tc4);
	}
     