#pragma once

#include "ofApp.h"
#include "hero.h"
#include "tiro.h"

class ShootManager {

private:
	vector<Shoot*> tiro;

public:
	ShootManager();
	void update(float secs);
	void draw(const ofVec2f& camera) const;
	~ShootManager();

	void shooting(Hero& hero);
};