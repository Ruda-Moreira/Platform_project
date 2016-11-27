#include "Enemy.h"

Enemy::Enemy(const ofVec2f& end) : stopPoint(end) {}

void Enemy::init() {
	dir = false;
	position.set(1600, 712);
	walkLeft.addFrame("img/walkLeft.png");
	walkLeft.addFrame("img/walkLeft1.png");
	walkLeft.addFrame("img/walkLeft2.png");
	walkLeft.addFrame("img/walkLeft3.png");
	walkLeft.setFrameTime(0.3f);

	walkRight.addFrame("img/walkRight.png");
	walkRight.addFrame("img/walkRight1.png");
	walkRight.addFrame("img/walkRight2.png");
	walkRight.addFrame("img/walkRight3.png");
	walkRight.setFrameTime(0.3f);
}

void Enemy::draw(const ofVec2f& camera) {
	if (!dir) {
		walkLeft.draw(position - camera);
	} else
	walkRight.draw(position - camera);
}

void Enemy::update(float secs) {
	ofVec2f oldPos = position;
	float distance = (stopPoint - position).length();
	if (!dir) {
		direction = (stopPoint - position).normalize();
		position += direction * 200 * secs;
		walkLeft.update(secs);
	}else if (distance < 5) {
		dir = true;
		direction += (position - stopPoint).normalize();
		position -= direction * 200 * secs;
		walkRight.update(secs);
	}
}

bool Enemy::isAlive() const {
	return true;
}

ofRectangle Enemy::bounds() {
	return ofRectangle();
}

void Enemy::collidedWith(GameObject* other) {

}