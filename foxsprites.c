#include "foxsprites.h"
//#include "foxobjects.c"

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

// Updates the animation object info ready for blitting to the screen
void fox_doanimation() {
	int i;
	for (i=0;i < gameObj.noOfAnimatedSprites; i++) {
		// Count down updates (delay) before changing sprite offset
		animobj[i].currentUpdateCount--;
		displayScore(10*i, 0, (long)animobj[i].spriteOffset);		
		if (animobj[i].currentUpdateCount < 0) {
			animobj[i].currentUpdateCount = animobj[i].updatesPerFrame;
			animobj[i].spriteOffset+=animobj[i].animationDirection;
			animobj[i].currentSpriteNo--;
			if (animobj[i].currentSpriteNo < 1) {
				 // We've displayed all sprites in this animation
				animobj[i].currentSpriteNo = animobj[i].noOfSprites;
				if (animobj[i].animDirBounce == true) {
					if (animobj[i].animationDirection == 1) { animobj[i].animationDirection=-1; }
					else { animobj[i].animationDirection = 1;}
				}
				else {
					animobj[i].spriteOffset = 0;
				}
			}
		}
	}
} 

// Update all the animated sprites onscreen
void fox_updatesprites() {
	int i,j;
	for (i=0;i<gameObj.noOfSprites;i++) {
		if (spriteobj[i].isEnabled) {
			if (spriteobj[i].isAnimated) {
				j = spriteobj[i].animObjNo;
				fox_spriteat(spriteobj[i].xpos, spriteobj[i].ypos, animobj[j].startSprite+animobj[j].spriteOffset);
			}
			else {
				fox_spriteat(spriteobj[i].xpos, spriteobj[i].ypos, spriteobj[2].spriteNo);
			}
		}
	}
}