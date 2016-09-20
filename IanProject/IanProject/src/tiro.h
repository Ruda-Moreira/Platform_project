#ifndef tiro_h
#define tiro_h

#include "ofApp.h"
#include "hero.h"

struct Shoot {
	ofImage snowball;
	ofVec2f position;
	bool direction;
	bool isShooting = false;
};

void shootInit(Shoot &shoot, Hero &hero);

void shootUpdate(Shoot &shoot, float secs);
void shootDraw(Shoot &shoot, Hero &hero);

#endif