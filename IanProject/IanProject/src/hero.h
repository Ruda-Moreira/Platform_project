#pragma once

#include "animation.h"
#include "TileMap.h"
#include "GameObject.h"

#define RIGHT true
#define LEFT false

enum HeroStates {
    IDLE, WALKING, JUMPING, FALLING
};

class Hero : public GameObject {

private:
    
    Animation walkLeft;
    Animation walkRight;
	Animation jumpLeft;
	Animation jumpRight;
    HeroStates state;
    TileMap& tileMap;
    ofVec2f position;

	float jumpTime;
    float cooldown;
	bool direction;

    Animation& getAnimation();
    void testFall();
    void blockBorder();
    void jump();
    void walk(bool direction);
    void stop();
    void shoot();
    
public:

    Hero(TileMap& map);
    void init();
    void update(float secs);
    void draw(const ofVec2f& camera);
    void collidedWith(GameObject* other);
	bool isAlive() const;

    ofRectangle bounds();
    ofVec2f getHandPosition() const;
	ofVec2f getPosition() const;
};
