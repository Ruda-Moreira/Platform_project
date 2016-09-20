#include <stdio.h>
#include "tiro.h"


void Shoot::init(Hero &hero) {    
	snowball.load("img/snowball.png");
	position = hero.getHandPosition();
    
	if (hero.direction == RIGHT) {
		direction = RIGHT;
	}
	else {
		direction = LEFT;
	}
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
void Shoot::draw() {
	snowball.draw(position);
}