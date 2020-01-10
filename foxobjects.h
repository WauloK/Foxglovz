#ifndef _FOXOBJECTS_H_
#define _FOXOBJECTS_H_
#include <stdbool.h>

extern struct gameobject
{
	unsigned long score; 				// Current score
	unsigned int scoreCount; 			// Count left to add to score
	unsigned char scoreCountStep; 		// How many numbers to jump counting up
	unsigned char scoreX;
	unsigned char scoreY;
	unsigned long hiScore;
	unsigned char currentLevel;     	// Current game level
	unsigned int baseGraphics;  		// Where to draw graphics. 28672 = onscreen. Other = double-buffering
	unsigned char noOfEnemies;			// Number of enemies onscreen
	unsigned char noOfSprites;			// Number of Sprites animated and not
	unsigned char noOfAnimatedSprites;	// Number of Sprites to animate
};

extern struct spriteobject
{
	unsigned char spriteNo;
	int xpos;
	int ypos;
	unsigned char width;
	unsigned char height;
    unsigned char scoreAdd;
    unsigned char hitsToKill;  		// Number of hits to kill enemy
	// unsigned char collOffsetX; 	// Collision box offset in pixels - equidistant left/right
	// unsigned char collOffsetY; 	// Collision box offset in pixels - equidistant top/bottom
	unsigned char animObjNo;		// Which animated object refers to this sprite
	bool isEnemy;			   		// My own identifier for collisions
	bool isAnimated;		   		// Do we use the animobject struct?
	bool isEnabled;					// Is the sprite enabled to be drawn?
};

extern struct animobject
{
	unsigned char startSprite;			// First sprite for this animation
	unsigned char noOfSprites;			// Number of sprites for this animation
	char currentSpriteNo;				// Countdown of sprites in animation
	unsigned char updatesPerFrame;		// How many frame updates before changing to next Sprite. Bigger = slower animation
	char currentUpdateCount;			// Countdown of 'framesPerSprite' before changing
	unsigned char spriteOffset;			// Current Sprite is startSprite + spriteOffset
	char animationDirection;			// -1 Backwards. 0 Paused. 1 Forwards
	bool animDirBounce;					// true = animate forwards then backwards, else just forwards
};

#endif