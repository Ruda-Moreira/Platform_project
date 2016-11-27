#pragma once

#include "ofApp.h"

#include <string>

#define SIZEX 342
#define SIZEY 91

class Button {

private:
	ofVec2f position;
	ofImage colorNotClicked;
	ofImage colorClicked;
	float clickTime = 0;
	bool IsClicked;
	bool ClickFinished;

public: 

	Button(const ofVec2f& pos, string clicked, string notClicked);
	const bool Check(const ofVec2f& posMouse) const;
	bool SetClick();
	bool isClickFinished() const;
	void Update(float secs);
	void Draw() const;
	~Button();
};
