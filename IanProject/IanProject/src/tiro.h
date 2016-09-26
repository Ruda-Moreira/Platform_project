#ifndef tiro_h
#define tiro_h

#include "ofApp.h"
#include "hero.h"

class Shoot {
    private:
        ofImage snowball;
        ofVec2f position;
        bool direction;
		
    public:
		int count = 0;
        void init(Hero &hero);
        void update(float secs);
        void draw();
};

#endif