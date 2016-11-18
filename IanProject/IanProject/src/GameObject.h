//
//  GameObject.h
//  colors
//
//  Created by ViniGodoy on 05/11/16.
//
//

#ifndef GameObject_h
#define GameObject_h

#include "ofMain.h"

class GameObject {
    public:
        virtual void init() = 0;
        virtual bool isAlive() const = 0;
        virtual void draw(const ofVec2f& camera) = 0;
        virtual void update(float secs) = 0;
        virtual ofRectangle bounds() = 0;
        virtual void collidedWith(GameObject* other) = 0;
    
        virtual ~GameObject() {}
};

#endif /* GameObject_h */
