#ifndef tiro_h
#define tiro_h

#include "ofApp.h"
#include "hero.h"

#define RIGHT true
#define LEFT false

struct Shoot {
	ofImage snowball;
	ofVec2f position;
	bool isShooting = false;
};

void shootInit(Shoot &shoot);

void shootUpdate(Shoot &shoot,Hero &hero, float secs);
void shootDraw(Shoot &shoot, Hero &hero);

#endif