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