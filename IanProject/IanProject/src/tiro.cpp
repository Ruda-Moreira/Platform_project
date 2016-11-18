#include <stdio.h>
#include "tiro.h"

//primeira classe que eu fiz sozinha hehe :3

Shoot::Shoot(const ofVec2f& position, bool direction) : position(position), direction(direction) {}

void Shoot::init() {
	snowball.load("img/snowball.png");
}

void Shoot::update(float secs) {
		ofVec2f speed(300, 0);
        if (direction == RIGHT) {
            position += speed * secs;
        }
        else {
            position -= speed * secs;
        }
}
void Shoot::draw(const ofVec2f& camera) {
	snowball.draw(position - camera);
}

bool Shoot::isAlive() const{
    if (position.x > 3000 || position.x < 0) {
        return false;
    }
    return true;
}

ofRectangle Shoot::bounds(){
    return ofRectangle(position, snowball.getWidth(), snowball.getHeight());
}

void Shoot::collidedWith(GameObject* other){
    
}