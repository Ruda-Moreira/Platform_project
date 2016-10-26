#pragma once

#include "ofApp.h"

class Camera {

	private:
		ofVec2f SCREEN_CENTER;
		ofVec2f cameraPos;

		float maxX, maxY;

	public:
		void update(ofVec2f player, ofVec2f background);

		ofVec2f getPosition();
};