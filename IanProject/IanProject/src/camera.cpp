#include "camera.h"


void Camera::update(ofVec2f player, ofVec2f background) {
	SCREEN_CENTER.set(ofGetWidth() / 2, ofGetHeight() / 2);
	cameraPos.set(player - SCREEN_CENTER);

	maxX = background.x - ofGetWidth();
	maxY = background.y - ofGetHeight();

	if (cameraPos.x <= 0) {
		cameraPos.x = 0;
	}
	else if (cameraPos.x >= maxX) {
		cameraPos.x = maxX;
	}

	/*if(cameraPos.y <= 0) {
		cameraPos.y = 0;
	}
	else if (cameraPos.y >= maxY) {
		cameraPos.y = maxY;
	}*/
}

ofVec2f Camera::getPosition() {
	return cameraPos;
}