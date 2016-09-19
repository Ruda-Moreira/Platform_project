//
//  animation.cpp
//  platform
//
//  Created by ViniGodoy on 09/09/16.
//
//

#include "animation.h"

void animationUpdate(Animation& animation, float secs)
{
    animation.time += secs;
    if (animation.time >= animation.frameTime)
    {
        animation.time = 0;
        if (animation.frame == animation.count-1)
        {
            if (animation.repeat)
            {
                animation.frame = 0;
            }
        }
        else
        {
            animation.frame = animation.frame + 1;
        }
    }
    
}
void animationDraw(Animation& animation, ofVec2f position)
{
    animation.images[animation.frame].draw(position);
}
