#include "animation.h"

void Animation::update(float secs) {
    time += secs;
    if (time >= frameTime) {
        time = 0;
        if (frame == count-1) {
            if (repeat) {
                frame = 0;
            }
        }
        else {
            frame = frame + 1;
        }
    }   
}
void Animation::draw(const ofVec2f& position) {
    images[frame].draw(position);
}
