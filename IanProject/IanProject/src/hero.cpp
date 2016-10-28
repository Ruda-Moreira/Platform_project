#include <stdio.h>
#include "hero.h"
//#include "animation.h"

Hero::Hero(TileMap& map) : tileMap(map) {
    
}

void Hero::init() {
    life = 10;
    position = tileMap.getSpawnPoint();
    isJumping = false;

    walkRight.images = new ofImage[3];
    walkRight.images[0].load("img/P1.png");
    walkRight.images[1].load("img/P2.png");
    walkRight.images[2].load("img/P3.png");
    walkRight.frame = 0;
    walkRight.count = 3;
    walkRight.repeat = true;
    walkRight.frameTime = 0.5;
    walkRight.time = 0;
    
    walkLeft.images = new ofImage[3];
    walkLeft.images[0].load("img/P4.png");
    walkLeft.images[1].load("img/P5.png");
    walkLeft.images[2].load("img/P6.png");
    walkLeft.frame = 0;
    walkLeft.count = 3;
    walkLeft.repeat = true;
    walkLeft.frameTime = 0.5;
    walkLeft.time = 0;
    
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
    isWalking = false;
}

void Hero::update(float secs) {

    if (!isWalking && !isJumping) {
        walkRight.frame = 0;
        walkLeft.frame = 0;
        
        ofVec2f posTile = position + ofVec2f(0, TILE);
        char tile = tileMap.getTileChar(posTile);

        if(tile != '#' && tile != '%'){
            position += secs * 400;
        }
        return;
    }

    if(isJumping) {
        position.y -= secs * 400;
        jumpTime += secs;
        if (jumpTime > 0.3){
            isJumping = false;
        }
        return;
    }

	ofVec2f speed(200, 0);

	if (direction == RIGHT) {
		position += speed * secs;
		walkRight.update(secs);
	}
	else {
		position -= speed * secs;
		walkLeft.update(secs);
	}

	//-->fora
	//Y
	ofVec2f posTile = position + ofVec2f(0, TILE);
	char tile = tileMap.getTileChar(posTile);
	if (tile != '#' && tile != '%') {
		position += secs * 400;
	}
	//X
	ofVec2f posTileX = position + ofVec2f(TILE, 0);
	char tile = tileMap.getTileChar(posTileX);
	if (tile != '#' && tile != '%') {
		if (direction == RIGHT) {
			position += speed * secs;
		}
		else {
			position -= speed * secs;
		}
	}
	//-->end fora

	if (position.x <= 0) {
		position.x = 0;
	}
	else if (position.x >= tileMap.getMapWidth()) {
		position.x = tileMap.getMapWidth();
	}	
}

void Hero::draw(const ofVec2f& camera) {
    
    ofVec2f drawPlayer = position - ofVec2f (0,26) - camera;
    
    if (direction == RIGHT) {
		walkRight.draw(drawPlayer);
    } else {
		walkLeft.draw(drawPlayer);
    }
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

