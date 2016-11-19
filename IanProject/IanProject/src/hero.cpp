#include "hero.h"
#include "tiro.h"
#include "Keyboard.h"
#include "GameManager.h"


Hero::Hero(TileMap& map) : state(IDLE), direction(RIGHT), tileMap(map), position(tileMap.getSpawnPoint()) {

}

//-------> MÉTODOS PRINCIPAIS
void Hero::init() {
	walkRight.addFrame("img/IdleR.png");
	walkRight.addFrame("img/P2.png");
	walkRight.addFrame("img/P3.png");
	walkRight.setFrameTime(0.3f);

	walkLeft.addFrame("img/IdleL.png");
	walkLeft.addFrame("img/P5.png");
	walkLeft.addFrame("img/P6.png");
	walkLeft.setFrameTime(0.3f);

	jumpRight.addFrame("img/IdleR.png");
	jumpRight.addFrame("img/jumpR1.png");
	jumpRight.addFrame("img/jumpR2.png");
	jumpRight.addFrame("img/jumpR3.png");
	jumpRight.addFrame("img/jumpR4.png");
	jumpRight.addFrame("img/jumpR5.png");
	jumpRight.addFrame("img/IdleR.png");
	jumpRight.setFrameTime(0.1f);

	jumpLeft.addFrame("img/IdleL.png");
	jumpLeft.addFrame("img/jumpL1.png");
	jumpLeft.addFrame("img/jumpL2.png");
	jumpLeft.addFrame("img/jumpL3.png");
	jumpLeft.addFrame("img/jumpL4.png");
	jumpLeft.addFrame("img/jumpL5.png");
	jumpLeft.addFrame("img/IdleL.png");
	jumpLeft.setFrameTime(0.1f);
}

void Hero::update(float secs) {

	ofVec2f speed(300, 0);
	switch (state) {
	case IDLE: {
		if (KEYS.isPressed(OF_KEY_UP))
			jump();
		if (KEYS.isPressed(OF_KEY_LEFT))
			walk(LEFT);
		if (KEYS.isPressed(OF_KEY_RIGHT))
			walk(RIGHT);

		testFall();
		break;
	}

	case WALKING: {

		if (KEYS.isPressed(OF_KEY_UP)) {
			jump();
		}
		else if (KEYS.isPressed(OF_KEY_LEFT)) {
			walk(LEFT);
		}
		else if (KEYS.isPressed(OF_KEY_RIGHT)) {
			walk(RIGHT);
		}

		if (!KEYS.isPressed(OF_KEY_LEFT) &&
			!KEYS.isPressed(OF_KEY_RIGHT) &&
			!KEYS.isPressed(OF_KEY_UP)) {
			stop();
			state = IDLE;
		}

		cout << "walking" << endl;
		
		testFall();
		if (direction == RIGHT) {
			if (tileMap.isSolid(position + ofVec2f(TILE, 0))) {
				position += speed * secs;
			}
		}
		else {
			if (tileMap.isSolid(position - ofVec2f(TILE, 0))) {
				position -= speed * secs;
			}
		}
		getAnimation().update(secs);
		break;
	}

	case JUMPING: {
		position.y -= secs * 400;
		jumpTime += secs;

		if (KEYS.isPressed(OF_KEY_LEFT)) {
			position -= speed * secs;
		}
		else if (KEYS.isPressed(OF_KEY_RIGHT)) {
			position += speed * secs;
		}

		if (jumpTime > 0.5) {
			state = FALLING;
		}
		getAnimation().update(secs);
		break;
	}

	case FALLING: {
		if (!tileMap.isSolid(position + ofVec2f(0, TILE))) {
			state = IDLE;
		}
		else
			position.y += secs * 400;
		break;
	}
	}
	blockBorder();
}

void Hero::draw(const ofVec2f& camera) {
	ofVec2f positionToDraw = position - ofVec2f(0, 26) - camera;
	getAnimation().draw(positionToDraw);
}

//--------> MÉTODOS DE TROCA DE ESTADO
void Hero::walk(bool direction) {
	if (state == JUMPING || state == FALLING || state == WALKING) return;
	state = WALKING;
	this->direction = direction;
	getAnimation().reset();
}

void Hero::jump() {
	if (state == FALLING || state == JUMPING) return;
	state = JUMPING;
	jumpTime = 0;
	getAnimation().reset();
}

void Hero::stop() {
	if (state != WALKING) return;
	state = IDLE;
}

void Hero::testFall() {
	if (tileMap.isSolid(position + ofVec2f(0, TILE))) {
		state = FALLING;
		getAnimation().reset();
	}
}

//--------> MÉTODOS DE INTERAÇÃO
void Hero::shoot() {
	GAMEMANAGER.add(new Shoot(getHandPosition(), direction));
}

void Hero::blockBorder() {
	if (position.x <= 0) {
		position.x = 0;
	}
	else if (position.x >= tileMap.getMapWidth()) {
		position.x = tileMap.getMapWidth();
	}
}

void Hero::collidedWith(GameObject* other) {

}

//--------> MÉTODOS DE COMUNICAÇÃO (GETTERS - SETTERS)
bool Hero::isAlive() const {
	return true;
}

ofVec2f Hero::getPosition() const {
	return position;
}

ofVec2f Hero::getHandPosition() const {
	return position + ofVec2f(45, 45);
}

Animation& Hero::getAnimation() {
	switch (state) {
	case IDLE:
	case WALKING:
	case FALLING:
		return direction == RIGHT ? walkRight : walkLeft;
	case JUMPING:
		return direction == RIGHT ? jumpRight : jumpLeft;
	}
}

ofRectangle Hero::bounds() {
	return ofRectangle(position, walkLeft.getFrameSize().x, walkLeft.getFrameSize().y);
}

