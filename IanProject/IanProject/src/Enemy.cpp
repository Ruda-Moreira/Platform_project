#include "Enemy.h"

Enemy::Enemy(const ofVec2f& start, const ofVec2f& end,
	const Animation& walkRight, const Animation& walkLeft, const Animation& throwRight, const Animation& throwLeft) 
	: startPos(start), stopPos(end), walkRight(walkRight), walkLeft(walkLeft), attackRight(throwRight), attackLeft(throwLeft) {}

void Enemy::init() {
	dir = false;
	position = startPos;

}

void Enemy::draw(const ofVec2f& camera) {
	if (!dir) {
		walkLeft.draw(position - camera);
	}
	else {
		walkRight.draw(position - camera);
	}
}

void Enemy::update(float secs) {
	ofVec2f path = (dir ? stopPos : startPos) - position;
	float distance = path.length();
	direction = path.normalize();
	position += direction * 200 * secs;
	(dir ? walkRight : walkLeft).update(secs);
	if (distance < 5)
		dir = !dir;
}

bool Enemy::isAlive() const {
	return true;
}

ofRectangle Enemy::bounds() {
	return ofRectangle();
}

void Enemy::collidedWith(GameObject* other) {

}