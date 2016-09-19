//
//  hero.h
//  platform
//
//  Created by ViniGodoy on 09/09/16.
//
//

#ifndef hero_h
#define hero_h

#include "ofApp.h"
#include "animation.h"

#define RIGHT true
#define LEFT false

struct Hero {
    ofVec2f position;
    int life;
    bool direction;
    
    Animation walkLeft;
    Animation walkRight;
    
    bool isWalking;
};

void heroInit(Hero& hero);

void heroTurnRight(Hero& hero);
void heroTurnLeft(Hero& hero);
void heroWalk(Hero& hero);
void heroStop(Hero& hero);

void heroUpdate(Hero& hero, float secs);
void heroDraw(Hero& hero);

#endif /* hero_h */
