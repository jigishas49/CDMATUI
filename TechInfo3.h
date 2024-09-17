

#ifndef TECHINFO3_H_
#define TECHINFO3_H_
#define Uses_TApplication
#define Uses_TButton
#define Uses_TCheckBoxes
#define Uses_TCollection
#define Uses_TDialog
#define Uses_TDeskTop
#define Uses_TDrawBuffer
#define Uses_TEvent
#define Uses_THistory
#define Uses_TInputLine
#define Uses_TKeys
#define Uses_TLabel
#define Uses_TListBox
#define Uses_TMenuBar
#define Uses_TMenu
#define Uses_TMenuItem
#define Uses_TRadioButtons
#define Uses_TRect
#define Uses_TScrollBar
#define Uses_TSItem
#define Uses_TStaticText
#define Uses_TStatusLine
#define Uses_TStatusDef
#define Uses_TStatusItem
#define Uses_TView
#define Uses_TWindow
#define Uses_TStringCollection
#define Uses_MsgBox

  #define Uses_TKeys
  #define Uses_TRect
  #define Uses_TEvent
  #define Uses_TLabel
  #define Uses_TButton
  #define Uses_TInputLine
  #define Uses_TDialog
  #define Uses_TMenuBar
  #define Uses_TMenu
  #define Uses_TMenuItem
  #define Uses_TStaticText
  #define Uses_MsgBox
  #define Uses_TDeskTop
  #define Uses_TApplication
#include <tvision/tv.h>
#include "address.h"

const int  cmNewData4  = 107;
const int cmTechInfo4= 108;

#pragma hdrstop
class TechInfoList4 : public TListBox
		{
		public:


		TechInfoList4( TRect&, ushort, TScrollBar* );
        void handleEvent( TEvent & );
		};


class TechInfoDialog4 : public TDialog 
	{
	public :
    
	TechInfoDialog4(TRect& r ) :
					TWindowInit(&TechInfoDialog4::initFrame),
					TDialog (r, "Data ListBox")
		{
		TRect *t = new TRect();
		*t = getExtent();
		t->a.x++;
        t->a.y++;
		t->b.x --;
		t->b.y -= 2;
        TScrollBar *sb = new TScrollBar
                 ( TRect(t->b.x - 2, t->a.y + 1, t->b.x - 1, t->b.y - 2) );

        insert( sb );
		insert( new TechInfoList4( *t, 1, sb ) );
        insert( new TButton(TRect(10, t->b.y - 1, 20, t->b.y + 1),
                          "~O~k", cmOK, bfDefault) );
        

		}
		
      
	};



class TechInfoView4 : public TView
		{
		const char *curdata;

		public:

		TechInfoView4(TRect r) : TView (r)
                         {
                         eventMask |= evBroadcast;
                         curdata = "Press Up or Down Arrow";
                         };
		void draw();
		void handleEvent(TEvent&);
		};


class MyTCollection4: public TStringCollection
		{
		public :

		MyTCollection4() : TStringCollection (10,5) {};
		void *readItem( ipstream& is) { return this; };
		void writeItem( void *item, opstream& os) {};
		};

#endif