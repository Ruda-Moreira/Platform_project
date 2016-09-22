#ifndef animation_h
#define animation_h

#include "ofApp.h"


class Animation {
public:
	ofImage* images;
	int frame;
	int count;
	bool repeat;
	float frameTime;
	float time;
	void update(float secs);
	void draw(ofVec2f position);
};

#endif
