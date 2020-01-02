#include "foxsprites.h"
#include "foxobjects.c"

void fox_spriteat(char x, char y, unsigned char spriteno) {
	int location;
	int screenOrigin = gameObj.baseGraphics;
	location = screenOrigin + (32 * y + x); // 0 > x > 31 | 0 > y > 63
	if (x < 0 || x > 31 || y < 0 || y > 63) return; // Maximum VZ screen values
    fox_asm_spriteat(location, spriteno);
}

bool fox_checkcollision(int x1, int y1, char width1, char height1, int x2, int y2, char width2, char height2) {
	if( x1 < x2  + width2 &&
		x1  + width1 > x2  &&
		y1 < y2 + height2 &&
		y1 > y2 ) return true;
		return false;
}

/*  Uncomment to use offsets
bool fox_checkcollision(int x1, int y1, char width1, char height1, char collOffsetX1, char collOffsetY1, 
	int x2, int y2, char width2, char height2, char collOffsetX2, char collOffsetY2) {
	if( x1  + collOffsetX1 < x2  + width2 - collOffsetX2 &&
		x1  + width1 - collOffsetX1 > x2  + collOffsetX2 &&
		y1 + collOffsetY1 < y2 + height2 - collOffsetY2 &&
		y1 - collOffsetY1 > y2 ) return true;
		return false;
} */