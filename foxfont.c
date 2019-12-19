#include "foxfont.h"

char *fontarray; // Sprite data to display

int fontdataoffset = 4;
int arrayoffset = 2;

void fox_textat(struct myfontspecs *myfont, char *text)
{
	// Start rendering init
	int i,j,fontdatastart,textchar;
	int fontoffset,charval;
	int textxloc;
	struct fontspecs fontspec;
	struct maxvalues mymaxvalues;
	
	// Computer specific settings (VZ200 & VZ300)
	mymaxvalues.xmax = getmaxx(); // Maximum X value onscreen
	mymaxvalues.ymax = getmaxy();
	mymaxvalues.colmax = 8; // Maximum colours
	
	fontspec.width = *(font+2);
	fontspec.height = *(font+3);

	// Allocate memory space for our own font array for sprites
	fontarray = (char*)calloc((fontspec.height+arrayoffset),sizeof(char));
	
	// Check parameters are valid
	if (myfont->xpos < 0 || myfont->xpos > mymaxvalues.xmax) return;
	if (myfont->ypos < 0 || myfont->ypos > mymaxvalues.ymax) return;
	if (myfont->colour < 0 || myfont->colour > mymaxvalues.colmax) return;

	// Change sprite font colour
	textcolor(myfont->colour);

	fontspec.spacing = myfont->spacing;
	fontoffset = 32;
	
	// Set up the start X co-ord for sprite
	textxloc = myfont->xpos;

	// Build fontarray height data for sprite
	fontarray[1] = fontspec.height;

	for (i=0;i < strlen(text); i++) 
	{ 
		textchar = text[i];
		// Add fontarray height data for each char
		fontarray[0] = charwidth[textchar-fontoffset];	
	
		fontdatastart = fontspec.height*(textchar-fontoffset)+fontdataoffset;
		for (j=0;j<fontspec.height;j++)
		{ 
			charval = *(font+fontdatastart+j);
			if (myfont->fx & (1<<_fxinverse)) charval = ~charval;
			memset(fontarray+j+arrayoffset,charval,sizeof(char));
		}
		putsprite(spr_or, textxloc, myfont->ypos, fontarray);
		textxloc += (fontspec.spacing + fontarray[0]);
	}
	// Add fx
	if (myfont->fx & (1<<_fxunderline)) {
		draw(myfont->xpos, myfont->ypos+fontspec.height-2, textxloc-2, myfont->ypos+fontspec.height-2);
	}
	free(fontarray); // Free calloc memory
	return 0;
}