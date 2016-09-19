//
//  hero.cpp
//  platform
//
//  Created by ViniGodoy on 09/09/16.
//
//

#include <stdio.h>
#include "hero.h"

void heroInit(Hero& hero)
{
    hero.life = 10;
    hero.position = ofVec2f(100, 100);
    
    hero.walkRight.images = new ofImage[3];
    hero.walkRight.images[0].load("img/P1.png");
    hero.walkRight.images[1].load("img/P2.png");
    hero.walkRight.images[2].load("img/P3.png");
    hero.walkRight.frame = 0;
    hero.walkRight.count = 3;
    hero.walkRight.repeat = true;
    hero.walkRight.frameTime = 0.5;
    hero.walkRight.time = 0;
    
    hero.walkLeft.images = new ofImage[3];
    hero.walkLeft.images[0].load("img/P4.png");
    hero.walkLeft.images[1].load("img/P5.png");
    hero.walkLeft.images[2].load("img/P6.png");
    hero.walkLeft.frame = 0;
    hero.walkLeft.count = 3;
    hero.walkLeft.repeat = true;
    hero.walkLeft.frameTime = 0.5;
    hero.walkLeft.time = 0;
    
    hero.direction = RIGHT;
}

void heroTurnRight(Hero& hero)
{
    hero.direction = RIGHT;
}
void heroTurnLeft(Hero& hero)
{
    hero.direction = LEFT;
}

void heroWalk(Hero& hero)
{
    hero.isWalking = true;
}

void heroStop(Hero& hero)
{
    hero.isWalking = false;
}

void heroUpdate(Hero& hero, float secs)
{
    if (!hero.isWalking)
    {
        hero.walkRight.frame = 0;
        hero.walkLeft.frame = 0;
        return;
    }
    
    ofVec2f speed(200,0);
        
    if (hero.direction == RIGHT) {
        hero.position += speed * secs;
        animationUpdate(hero.walkRight, secs);
    } else {
        hero.position -= speed * secs;
        animationUpdate(hero.walkLeft, secs);
    }
}

void heroDraw(Hero& hero)
{
    //Animation& walkAnimation = direction == RIGHT ? hero.walkRight : hero.walkLeft;
    //animationDraw(, hero.position);
    
    if (hero.direction == RIGHT) {
        animationDraw(hero.walkRight, hero.position);
    } else {
        animationDraw(hero.walkLeft, hero.position);
    }
}
