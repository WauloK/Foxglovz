#ifndef _FOXSPRITES_H_
#define _FOXSPRITES_H_

void fox_asm_spriteat();
void fox_spriteat(char x, char y, unsigned char spriteno);
// bool fox_checkcollision(int x1, int y1, char width1, char height1, char collOffsetX1, char collOffsetY1,	int x2, int y2, char width2, char height2, char collOffsetX2, char collOffsetY2);
bool fox_checkcollision(int x1, int y1, char width1, char height1, int x2, int y2, char width2, char height2);

#endif