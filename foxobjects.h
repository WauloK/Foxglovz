#ifndef _FOXOBJECTS_H_
#define _FOXOBJECTS_H_
#include <stdbool.h>
extern struct gameobject
{
	unsigned long score; 		// Current score
	unsigned int scoreCount; 		// Count left to add to score
	unsigned char scoreCountStep; 	// How many numbers to jump counting up
	unsigned char scoreX;
	unsigned char scoreY;
	unsigned long hiScore;
	unsigned char currentLevel;     // Current game level
	unsigned int baseGraphics;  	// Where to draw graphics. 28672 = onscreen. Other = double-buffering
};

extern struct spriteobject
{
	unsigned char spriteNo;
	int xpos;
	int ypos;
	unsigned char width;
	unsigned char height;
    unsigned char scoreAdd;
    unsigned char hitsToKill;  // Number of hits to kill enemy
	unsigned char collOffsetX; // Collision box offset in pixels - equidistant left/right
	unsigned char collOffsetY; // Collision box offset in pixels - equidistant top/bottom
	bool isEnemy;
};


#endif