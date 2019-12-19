#ifndef _FOXOBJECTS_H_
#define _FOXOBJECTS_H_

extern struct spriteobject
{
	unsigned char spriteNo;
	int xpos;
	int ypos;
	unsigned char width;
	unsigned char height;
    unsigned char scoreAdd;
    unsigned char hitsToKill;  //Number of hits to kill enemy
	unsigned char collOffsetX; // Collision box offset in pixels - equidistant left/right
	unsigned char collOffsetY; // Collision box offset in pixels - equidistant top/bottom
	bool isEnemy;
};

extern struct spriteobjectcollision
{
	unsigned char spriteNo;
	int xpos;
	int ypos;
	unsigned char width;
	unsigned char height;
    unsigned char scoreAdd;
    unsigned char hitsToKill;  //Number of hits to kill enemy
	unsigned char collOffsetX; // Collision box offset in pixels - equidistant left/right
	unsigned char collOffsetY; // Collision box offset in pixels - equidistant top/bottom
	bool isEnemy;
};

#endif