#include <stdio.h>
#include "hero.h"
//#include "animation.h"

Hero::Hero(TileMap& map) : tileMap(map) {
    
}

void Hero::init() {

    position = tileMap.getSpawnPoint();
    isJumping = false;

    walkRight.addFrame("img/IdleR.png");
    walkRight.addFrame("img/P2.png");
    walkRight.addFrame("img/P3.png");

    walkLeft.addFrame("img/IdleL.png");
    walkLeft.addFrame("img/P5.png");
    walkLeft.addFrame("img/P6.png");

	jumpRight.addFrame("img/IdleR.png");
	jumpRight.addFrame("img/jumpR1.png");
	jumpRight.addFrame("img/jumpR2.png");
	jumpRight.addFrame("img/jumpR3.png");
	jumpRight.addFrame("img/jumpR4.png");
	jumpRight.addFrame("img/jumpR5.png");
	jumpRight.addFrame("img/IdleR.png");

	jumpLeft.addFrame("img/IdleL.png");
	jumpLeft.addFrame("img/jumpL1.png");
	jumpLeft.addFrame("img/jumpL2.png");
	jumpLeft.addFrame("img/jumpL3.png");
	jumpLeft.addFrame("img/jumpL4.png");
	jumpLeft.addFrame("img/jumpL5.png");
	jumpLeft.addFrame("img/IdleL.png");
    
    direction = RIGHT;
}

void Hero::turnRight() {
    direction = RIGHT;
}

void Hero::turnLeft() {
    direction = LEFT;
}

void Hero::walk() {
    isWalking = true;
}

void Hero::jump() {
    if(isJumping) {
        return;
    }
    isJumping = true;
    jumpTime = 0;
}

void Hero::stop() {
	walkRight.setFrame(0);
	walkLeft.setFrame(0);
	jumpRight.setFrame(0);
	jumpLeft.setFrame(0);
    isWalking = false;
}

void Hero::update(float secs) {

	if (!isWalking && !isJumping) {
		ofVec2f posTile = position + ofVec2f(0, TILE);
		char tile = tileMap.getTileChar(posTile);

		if (tile != '#' && tile != '@' && tile != '%') {
			position.y += secs * 400;
		}
		return;
	}

	if (isJumping) {
		position.y -= secs * 400;
		jumpTime += secs;
		if (jumpTime > 0.5) {
			isJumping = false;
		}
		jumpRight.update(secs);
		jumpLeft.update(secs);
	}

	ofVec2f speed(300, 0);

	if (direction == RIGHT) {
		ofVec2f posTileX = position + ofVec2f(TILE, 0);
		char tile = tileMap.getTileChar(posTileX);
		if (tile != '#' && tile != '@' && tile != '%') {
			position += speed * secs;
			walkRight.update(secs);
		}
	}
	else {
		ofVec2f posTileX = position - ofVec2f(TILE, 0);
		char tile = tileMap.getTileChar(posTileX);
		if (tile != '#' && tile != '@' && tile != '%') {
			position -= speed * secs;
			walkLeft.update(secs);
		}
	}

	ofVec2f posTile = position + ofVec2f(0, TILE);
	char tile = tileMap.getTileChar(posTile);

	if (tile != '#' && tile != '@' && !isJumping) {
		position.y += secs * 400;
	}

	//travando a borda 
	if (position.x <= 0) {
		position.x = 0;
	}
	else if (position.x >= tileMap.getMapWidth()) {
		position.x = tileMap.getMapWidth();
	}
}

void Hero::draw(const ofVec2f& camera) {

	ofVec2f drawPlayer = position - ofVec2f(0, 26) - camera;

	if (!isJumping) {
		if (direction == RIGHT) {
			walkRight.setFrameTime(0.3f);
			walkRight.draw(drawPlayer);
		}
		else {
			walkLeft.setFrameTime(0.3f);
			walkLeft.draw(drawPlayer);
		}
	}
	else {
		if (direction == RIGHT) {
			jumpRight.setFrameTime(0.1f);
			jumpRight.draw(drawPlayer);
		}
		else {
			jumpLeft.setFrameTime(0.1f);
			jumpLeft.draw(drawPlayer);
		}
	}

}

bool Hero::isAlive() {
	return true;
}

bool Hero::getJumpStatus() const {
	return isJumping;
}

ofVec2f Hero::getPosition() const {
	return position;
}

ofVec2f Hero::getHandPosition() const {
    return position + ofVec2f(45, 45);
}

