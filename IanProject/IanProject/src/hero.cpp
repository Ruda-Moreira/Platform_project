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
    walkRight.frameTime = 0.3;
    walkRight.time = 0;
    
    walkLeft.images = new ofImage[3];
    walkLeft.images[0].load("img/P4.png");
    walkLeft.images[1].load("img/P5.png");
    walkLeft.images[2].load("img/P6.png");
    walkLeft.frame = 0;
    walkLeft.count = 3;
    walkLeft.repeat = true;
    walkLeft.frameTime = 0.3;
    walkLeft.time = 0;
    
    jumpRight.images = new ofImage[3];
    jumpRight.images[0].load("img/P1.png");
    jumpRight.images[1].load("img/P2.png");
    jumpRight.images[2].load("img/P3.png");
    jumpRight.frame = 0;
    jumpRight.count = 3;
    jumpRight.repeat = true;
    jumpRight.frameTime = 0.3;
    jumpRight.time = 0;
    
    jumpLeft.images = new ofImage[3];
    jumpLeft.images[0].load("img/P4.png");
    jumpLeft.images[1].load("img/P5.png");
    jumpLeft.images[2].load("img/P6.png");
    jumpLeft.frame = 0;
    jumpLeft.count = 3;
    jumpLeft.repeat = true;
    jumpLeft.frameTime = 0.3;
    jumpLeft.time = 0;
    
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

        if(tile != '#' && tile != '@' && tile != '%'){
            position.y += secs * 400;
        }
        return;
    }

    if(isJumping) {
        position.y -= secs * 400;
        jumpTime += secs;
        if (jumpTime > 0.3){
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
    
    if(tile != '#' && tile != '@' && !isJumping){
        position.y += secs * 400;
    }
    
	if (position.x <= 0) {
		position.x = 0;
	}
	else if (position.x >= tileMap.getMapWidth()) {
		position.x = tileMap.getMapWidth();
	}	
}

void Hero::draw(const ofVec2f& camera) {
    
    ofVec2f drawPlayer = position - ofVec2f (0,26) - camera;
    
    if (!isJumping){
        if (direction == RIGHT) {
            walkRight.draw(drawPlayer);
        } else {
            walkLeft.draw(drawPlayer);
        }
    } else {
        if (direction == RIGHT) {
            jumpRight.draw(drawPlayer);
        } else {
            jumpLeft.draw(drawPlayer);
        }
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

