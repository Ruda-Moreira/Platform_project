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
    
    void init(ofVec2f pos);
    void turnRight();
    void turnLeft();
    void walk();
    void stop();
    void update(float secs);
    void draw();
    
    ofVec2f getHandPosition();    
};


#endif /* hero_h */
