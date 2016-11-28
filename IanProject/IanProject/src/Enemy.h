#pragma once

#include "GameObject.h"
#include "animation.h"

class Enemy : public GameObject{
private:
	ofVec2f position;
	ofVec2f startPos;
	ofVec2f stopPos;
	ofVec2f direction;
	Animation walkRight;
	Animation walkLeft;
	Animation attackRight;
	Animation attackLeft;

	bool dir;
public:
	Enemy(const ofVec2f& start, const ofVec2f& end, 
		const Animation& walkRight, const Animation& walkLeft, const Animation& throwRight, const Animation& throwLeft);
	void init();
	bool isAlive() const;
	void draw(const ofVec2f& camera);
	void update(float secs);
	ofRectangle bounds();
	void collidedWith(GameObject* other);
};