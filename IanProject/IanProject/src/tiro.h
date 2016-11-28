#ifndef tiro_h
#define tiro_h

#include "ofMain.h"
#include "GameObject.h"
#include "hero.h"

class Shoot : public GameObject {
    private:
        ofImage shoot;
        ofVec2f position;
        bool direction;
        bool enemy;
        bool alive;
		
    public:
        Shoot(const ofVec2f& position, bool direction, bool enemy);
        void init();
        void update(float secs);
        void draw(const ofVec2f& camera);
        bool isAlive() const;
        bool isEnemy() const;
        ofRectangle bounds();
        void collidedWith(GameObject* other);

};

#endif