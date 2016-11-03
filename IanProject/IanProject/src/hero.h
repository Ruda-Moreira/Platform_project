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
    Animation jumpRight;
    Animation jumpLeft;
    
    bool isWalking;
    bool isJumping;
    float jumpTime;
public:
    bool direction;
    
    TileMap& tileMap;

    Hero(TileMap& map);
    void init();
    void turnRight();
    void turnLeft();
    void jump();
    void walk();
    void stop();
    void update(float secs);
    void draw(const ofVec2f& camera);
	bool getJumpStatus() const;
    
    ofVec2f getHandPosition() const;    
	ofVec2f getPosition() const;
};


#endif /* hero_h */
