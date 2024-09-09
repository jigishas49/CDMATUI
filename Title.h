/*
 * TUITitle.h
 *
 *  Created on: 17 Jun 2024
 *      Author: rajath
 */

#ifndef TUITITLE_H_
#define TUITITLE_H_

#define Uses_TView
#define Uses_TRect
#define Uses_TDrawBuffer
#include <tvision/tv.h>

#define cpTitleLine "\x09\x0D"    // bright white/yellow on blue

class Title: public TView {
public:
    Title( const TRect& r, const char *aTitle );
	void draw();
	TPalette& getPalette() const;
	void setTitle( const char *s );
    virtual ~Title();

private:
	char _Title[80];
};

#endif /* TUITITLE_H_ */