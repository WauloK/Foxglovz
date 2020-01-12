#include "foxscoring.h"

void fox_doscore() {
	// check for score updates
	if (gameobj.scoreCount) {
		gameobj.scoreCount -= gameobj.scoreCountStep;
		gameobj.score += gameobj.scoreCountStep;
		displayScore(gameobj.scoreX, gameobj.scoreY, gameobj.score);
		if ( gameobj.scoreCount < 0 ) gameobj.scoreCount = 0;
	}
	if (gameobj.score > gameobj.hiScore) gameobj.hiScore = gameobj.score;
}

// Display score numbers to screen
void displayScore(int x, int y, long score) {
	int i, location, score1;
	location = gameobj.baseGraphics + (32 * y) + x;

	for (i = 6; score > 0 && i >= 0; i--)
	{
		score1 = score % 10;
		drawscore(location + i, score1);
		score = score / 10;
	}
}