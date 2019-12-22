#include "foxscoring.h"

void fox_doscore() {
	// check for score updates
	if (gameObj.scoreCount) {
		gameObj.scoreCount -= gameObj.scoreCountStep;
		gameObj.score += gameObj.scoreCountStep;
		displayScore(gameObj.scoreX, gameObj.scoreY, gameObj.score);
		if ( gameObj.scoreCount < 0 ) gameObj.scoreCount = 0;
	}
	if (gameObj.score > gameObj.hiScore) gameObj.hiScore = gameObj.score;
}