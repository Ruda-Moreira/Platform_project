#include <stdio.h>
#include "hero.h"
//#include "animation.h"

void Hero::init(ofVec2f pos, TileMap* tilemap)
{
    life = 10;
    position = pos;
    isJumping = false;
    
    walkRight.images = new ofImage[3];
    walkRight.images[0].load("img/P1.png");
   // walkRight.images[0].setAnchorPercent(0.5, 0);
    walkRight.images[1].load("img/P2.png");
   // walkRight.images[1].setAnchorPercent(0.5, 0);
    walkRight.images[2].load("img/P3.png");
  //  walkRight.images[2].setAnchorPercent(0.5, 0);
    walkRight.frame = 0;
    walkRight.count = 3;
    walkRight.repeat = true;
    walkRight.frameTime = 0.3;
    walkRight.time = 0;
    
    walkLeft.images = new ofImage[3];
    walkLeft.images[0].load("img/P4.png");
   // walkLeft.images[0].setAnchorPercent(0.5, 0);
    walkLeft.images[1].load("img/P5.png");
  //  walkLeft.images[1].setAnchorPercent(0.5, 0);
    walkLeft.images[2].load("img/P6.png");
  //  walkLeft.images[2].setAnchorPercent(0.5, 0);
    walkLeft.frame = 0;
    walkLeft.count = 3;
    walkLeft.repeat = true;
    walkLeft.frameTime = 0.3;
    walkLeft.time = 0;
    
    direction = RIGHT;
    
    tileMap = tilemap;
}

void Hero::turnRight()
{
    direction = RIGHT;
}
void Hero::turnLeft()
{
    direction = LEFT;
}

void Hero::walk()
{
    isWalking = true;
}

void Hero::jump()
{
    if(isJumping) {
        return;
    }
    isJumping = true;
    jumpTime = 0;
}

void Hero::stop()
{
    isWalking = false;
}

void Hero::update(float secs)
{
    
    if (!isWalking && !isJumping)
    {
        walkRight.frame = 0;
        walkLeft.frame = 0;
        
        ofVec2f posTile = position + ofVec2f(0,TILE);
        char tile = tileMap->getTileChar(posTile);
        if(tile != '#'){
            position.y += secs * 400;
        }
        return;
    }

    if(isJumping){
        position.y -= secs * 400;
        jumpTime += secs;
        if (jumpTime > 0.3){
            isJumping = false;
        }
        return;
    }
    
    ofVec2f speed(200,0);
        
    if (direction == RIGHT) {
        position += speed * secs;
        walkRight.update(secs);
    } else {
        position -= speed * secs;
        walkLeft.update(secs);
    }
    
    ofVec2f posTile = position + ofVec2f(0,TILE);
    char tile = tileMap->getTileChar(posTile);
    if(tile != '#'){
        position.y += secs * 400;
    }
}

void Hero::draw()
{
    //Animation& walkAnimation = direction == RIGHT ? hero.walkRight : hero.walkLeft;
    //animationDraw(, hero.position);
    
    ofVec2f drawPlayer = position - ofVec2f (0,26);
    
    if (direction == RIGHT) {
		walkRight.draw(drawPlayer);
    } else {
		walkLeft.draw(drawPlayer);
    }
}

ofVec2f Hero::getHandPosition()
{
    return position + ofVec2f(45, 45);
}

