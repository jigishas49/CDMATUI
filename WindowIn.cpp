
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

#include "WindowIn.h"
#include "address.h" 
#include "memory_mapping.h"
#include "Types.h"
#include "tvision/tv.h"

#include "Myapp.h"

 ReceiverStatus receiver_status ; 
MainWindowInterior::MainWindowInterior(const TRect &bounds) : TView(bounds)
{
    growMode = gfGrowHiX | gfGrowHiY;
    options = options | ofFramed;
  
    
   
}

void MainWindowInterior::draw()
{
    displayReceiverParameters();
}

void MainWindowInterior::updateReceiverStatus(ReceiverStatus status)
{
    memcpy(&_ReceiverStatus, &status, sizeof (_ReceiverStatus));
      drawView(); 
}


void MainWindowInterior::update()
{
   
         receiver_status = mem_rx();
    updateReceiverStatus(receiver_status); // Update and redraw the view
}
void MainWindowInterior::displayReceiverParameters()
{
    char szFields[10][20] = {"Module", "Config", "PRN", "FLL", "FLL_carr", "PSR", "Lock Status", "Lock Time"};
    char szText[30] = "";
    TDrawBuffer b;
    TView::draw();                      // Called whenever the view must draw itself.
    ushort color = getColor(0x0302);    // Maps the palette indices
                                        // in the low and high bytes
                           // of color.
    for(int iIndex = 0; iIndex < 10; iIndex++) {
        sprintf(szText, "%-12s:", szFields[iIndex]);
        b.moveStr(0, szText, color );         // moves the string to draw buffer
        writeLine( 0, iIndex, strlen(szText), 1, b);         // writes the buffer to screen
    }

   

    sprintf(szText, "------Receiver-----");
    b.moveStr(0, szText, color );         // moves the string to draw buffer
    writeLine(16, 0, strlen(szText), 1, b);         // writes the buffer to screen
    //Configuration
    
  
 

    

    ReceiverStatus receiver_status = mem_rx(); 
    b.moveStr(0, szText, color );         // moves the string to draw buffer
    writeLine(16, 1, strlen(szText), 1, b);         // writes the buffer to screen
    //PRN
      sprintf(szText, "%u", *(receiver_status.prn));
    b.moveStr(0, szText, color );         // moves the string to draw buffer
    writeLine(16, 2, strlen(szText), 1, b);         // writes the buffer to screen
    //Frequency
   sprintf(szText, "%u", *(receiver_status.fll));
    b.moveStr(0, szText, color );         // moves the string to draw buffer
    writeLine(16, 3, strlen(szText), 1, b);         // writes the buffer to screen
    //Power
  sprintf(szText, "%f", *(receiver_status.fll_carr)-10e6);
    b.moveStr(0, szText, color );         // moves the string to draw buffer
    writeLine(16, 4, strlen(szText), 1, b);         // writes the buffer to screen
    //C/No
    sprintf(szText, "%f",*(receiver_status.psr)*0.299792458);
    b.moveStr(0, szText, color );         // moves the string to draw buffer
    writeLine(16, 5, strlen(szText), 1, b); 
     sprintf(szText,"%u", *(receiver_status.adr_int));
    b.moveStr(0, szText, color );         // moves the string to draw buffer
    writeLine(16, 6, strlen(szText), 1, b);           // writes the buffer to screen
    //Lock Status
  
    b.moveStr(0, szText, color );         // moves the string to draw buffer
    writeLine(16, 7, strlen(szText), 1, b);         // writes the buffer to screen
    //Lock Time
  
}
void MainWindowInterior::handleEvent(TEvent& event)
{
    TView::handleEvent(event);

    
        update();  // Call the update function to refresh the receiver parameters
   int interval_ms=1000;
std::thread([this, interval_ms]() {
        while (true) {
            std::this_thread::sleep_for(std::chrono::milliseconds(interval_ms));
            {
                std::lock_guard<std::mutex> lock(mtx); // Lock the mutex for thread safety
                update(); // Call the update method
            }
        }
    }).detach(); // Deta
   
}