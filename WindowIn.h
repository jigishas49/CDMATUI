#ifndef TUIMAINWINDOWINTERIOR_H
#define TUIMAINWINDOWINTERIOR_H

#define Uses_TView
#include <tvision/tv.h>
#include <thread>
#include <chrono>
#include "Types.h"
#include <mutex>
class MainWindowInterior : public TView
{
public:
    MainWindowInterior(const TRect& bounds);
    virtual void draw();// Called when the view must be displayed

    //Functions to update
    void updateReceiverStatus(ReceiverStatus status);
    void update();
     void handleEvent( TEvent & );
   
private:
    ReceiverStatus      _ReceiverStatus;

    std::mutex mtx;
    void displayReceiverParameters();
};

#endif // TUIMAINWINDOWINTERIOR_H
