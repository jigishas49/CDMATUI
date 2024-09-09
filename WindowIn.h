#ifndef TUIMAINWINDOWINTERIOR_H
#define TUIMAINWINDOWINTERIOR_H

#define Uses_TView
#include <tvision/tv.h>

#include "Types.h"

class MainWindowInterior : public TView
{
public:
    MainWindowInterior(const TRect& bounds);
    virtual void draw();// Called when the view must be displayed

    //Functions to update
    void updateReceiverStatus(ReceiverStatus status);
private:
    ReceiverStatus      _ReceiverStatus;

    void displayReceiverParameters();
};

#endif // TUIMAINWINDOWINTERIOR_H
