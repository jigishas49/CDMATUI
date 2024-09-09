#include "WindowIn.h"
#include "address.h" 
#include "memory_mapping.h"

   u_int32_t** reg;

MainWindowInterior::MainWindowInterior(const TRect &bounds) : TView(bounds)
{
    growMode = gfGrowHiX | gfGrowHiY;
    options = options | ofFramed;
    _ReceiverStatus.ChipRate = ChippingRates_1M;
    _ReceiverStatus.PRN = 1;
    _ReceiverStatus.Frequency = 70000000.1234;
    _ReceiverStatus.Power = -56.24;
    _ReceiverStatus.CByNo = 56.24;
    _ReceiverStatus.LockStatus = CodeCarrierLock;
    _ReceiverStatus.LockTime = 1325;
}

void MainWindowInterior::draw()
{
    displayReceiverParameters();
}

void MainWindowInterior::updateReceiverStatus(ReceiverStatus status)
{
    memcpy(&_ReceiverStatus, &status, sizeof (_ReceiverStatus));
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

    //Upate Receiver parameters
   

    sprintf(szText, "------Receiver-----");
    b.moveStr(0, szText, color );         // moves the string to draw buffer
    writeLine(16, 0, strlen(szText), 1, b);         // writes the buffer to screen
    //Configuration
  
     reg = mem_rx();
 

    
    switch(_ReceiverStatus.ChipRate) {
    case ChippingRates_1M:
        sprintf(szText, "1M Chips/s");
        break;
    case ChippingRates_2_5M:
        sprintf(szText, "2.5M Chips/s");
        break;
    case ChippingRates_5M:
        sprintf(szText, "5M Chips/s");
        break;
    case ChippingRates_10M:
        sprintf(szText, "10M Chips/s");
        break;
    }
    
    b.moveStr(0, szText, color );         // moves the string to draw buffer
    writeLine(16, 1, strlen(szText), 1, b);         // writes the buffer to screen
    //PRN
      sprintf(szText, "%u", *reg[0]);
    b.moveStr(0, szText, color );         // moves the string to draw buffer
    writeLine(16, 2, strlen(szText), 1, b);         // writes the buffer to screen
    //Frequency
   sprintf(szText, "%u", *reg[1]);
    b.moveStr(0, szText, color );         // moves the string to draw buffer
    writeLine(16, 3, strlen(szText), 1, b);         // writes the buffer to screen
    //Power
  sprintf(szText, "%f", *reg[2]-10e6);
    b.moveStr(0, szText, color );         // moves the string to draw buffer
    writeLine(16, 4, strlen(szText), 1, b);         // writes the buffer to screen
    //C/No
    sprintf(szText, "%f",*reg[3]*0.299792458);
    b.moveStr(0, szText, color );         // moves the string to draw buffer
    writeLine(16, 5, strlen(szText), 1, b); 
     sprintf(szText,"%u", *reg[4]);
    b.moveStr(0, szText, color );         // moves the string to draw buffer
    writeLine(16, 6, strlen(szText), 1, b);           // writes the buffer to screen
    //Lock Status
    switch (_ReceiverStatus.LockStatus) {
    case Unlocked:
        sprintf(szText, "Unlocked");
        break;
    case CodeLock:
        sprintf(szText, "Code Lock");
        break;
    case CodeCarrierLock:
        sprintf(szText, "Code + Carrier");
        break;
    }
    b.moveStr(0, szText, color );         // moves the string to draw buffer
    writeLine(16, 7, strlen(szText), 1, b);         // writes the buffer to screen
    //Lock Time
    sprintf(szText, "%d s", _ReceiverStatus.LockTime);
    b.moveStr(0, szText, color );         // moves the string to draw buffer
    writeLine(16, 8, strlen(szText), 1, b);
}
