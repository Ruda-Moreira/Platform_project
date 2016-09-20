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

class Hero {
private:
    ofVec2f position;
    int life;
    Animation walkLeft;
    Animation walkRight;
    
    bool isWalking;
public:
    bool direction;
    
    void init();
    void turnRight();
    void turnLeft();
    void walk();
    void stop();
    void update(float secs);
    void draw();
    
    ofVec2f getHandPosition();    
};


#endif /* hero_h */
