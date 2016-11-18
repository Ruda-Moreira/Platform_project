#ifndef tiro_h
#define tiro_h

#include "ofMain.h"
#include "GameObject.h"
#include "hero.h"

class Shoot : public GameObject {
    private:
        ofImage snowball;
        ofVec2f position;
        bool direction;
		
    public:
        Shoot(const ofVec2f& position, bool direction);
        void init();
        void update(float secs);
        void draw(const ofVec2f& camera);
        bool isAlive() const;
        ofRectangle bounds();
        void collidedWith(GameObject* other);

};

#endif