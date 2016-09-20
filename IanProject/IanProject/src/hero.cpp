//
//  hero.cpp
//  platform
//
//  Created by ViniGodoy on 09/09/16.
//
//

#include <stdio.h>
#include "hero.h"

void Hero::init()
{
    life = 10;
    position = ofVec2f(100, 100);
    
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
    
    direction = RIGHT;
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

void Hero::stop()
{
    isWalking = false;
}

void Hero::update(float secs)
{
    if (!isWalking)
    {
        walkRight.frame = 0;
        walkLeft.frame = 0;
        return;
    }
    
    ofVec2f speed(200,0);
        
    if (direction == RIGHT) {
        position += speed * secs;
        animationUpdate(walkRight, secs);
    } else {
        position -= speed * secs;
        animationUpdate(walkLeft, secs);
    }
}

void Hero::draw()
{
    //Animation& walkAnimation = direction == RIGHT ? hero.walkRight : hero.walkLeft;
    //animationDraw(, hero.position);
    
    if (direction == RIGHT) {
        animationDraw(walkRight, position);
    } else {
        animationDraw(walkLeft, position);
    }
}

ofVec2f Hero::getHandPosition()
{
    return position + ofVec2f(250, 250);
}

