

#include "Title.h"

Title::Title( const TRect& r, const char *aTitle ) : TView( r )
{
	strcpy( _Title, aTitle );
}

void Title::setTitle(const char *s) {
	strcpy( _Title, s );
	drawView();
}

void Title::draw() {
	TDrawBuffer b;
	ushort color = getColor( 0x0201 );
	b.moveChar( 0, ' ', color, size.x );

	b.moveCStr( (size.x - strlen(_Title))/2, _Title, color );
	writeLine( 0, 0, size.x, 1, b );
}

TPalette& Title::getPalette() const {
	static TPalette palette( cpTitleLine, sizeof(cpTitleLine)-1 );
	return palette;
}

Title::~Title() {
	// TODO Auto-generated destructor stub
}

