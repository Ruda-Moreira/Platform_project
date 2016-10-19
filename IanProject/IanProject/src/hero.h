#ifndef hero_h
#define hero_h

#include "ofApp.h"
#include "animation.h"
#include "TileMap.h"

#define RIGHT true
#define LEFT false

class Hero {
private:
    ofVec2f position;
    int life;
    Animation walkLeft;
    Animation walkRight;
    
    bool isWalking;
    bool isJumping;
    float jumpTime;
public:
    bool direction;
    
    TileMap* tileMap;

    void init(ofVec2f pos, TileMap* tilemap);
    void turnRight();
    void turnLeft();
    void jump();
    void walk();
    void stop();
    void update(float secs);
    void draw();
    
    ofVec2f getHandPosition();    
	ofVec2f getPlayerPosition();
};


#endif /* hero_h */
