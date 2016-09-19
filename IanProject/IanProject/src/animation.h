#ifndef animation_h
#define animation_h

#include "ofApp.h"

struct Animation {
    ofImage* images;
    int count;
    bool repeat;
    float frameTime;
    
    float time;
    int frame;
};

void animationUpdate(Animation& animation, float secs);
void animationDraw(Animation& animation, ofVec2f position);

#endif
