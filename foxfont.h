#ifndef _FOXFONT_H_
#define _FOXFONT_H_

void fox_textat(struct myfontspecs *myfont, char *text);
int getmaxx();
int getmaxy();
int calloc();
int textcolor();
int strlen();
int memset();
int draw();
int free();

// Specifications from font.h file
extern struct fontspecs
{
	unsigned char width;
	unsigned char height;
	unsigned char spacing;
};

// Specifications passed from user program
extern struct myfontspecs
{
	unsigned char name[20];
	unsigned char xpos;
	unsigned char ypos;
	unsigned char spacing;
	unsigned char colour;
	unsigned char fx;
};

// Defint maximum values for sprite info
extern struct maxvalues {
	unsigned char xmax; // Maximum X value onscreen
	unsigned char ymax;
	unsigned char colmax; // Maximum colours
};

extern int _vzgreen = 1;
extern int _vzyellow = 2;
extern int _vzblue = 3;
extern int _vzred = 4;
extern int _vzbuff = 5;
extern int _vzcyan = 6;
extern int _vzmagenta = 7;
extern int _vzorange = 8;

extern int _fxnormal = 0;
extern int _fxinverse = 1;
extern int _fxunderline = 2;

#endif