#include <stdio.h>
#include "tiro.h"


void shootInit(Shoot &shoot, Hero &hero) {
	shoot.snowball.load("img/snowball.png");
	shoot.position = ofVec2f (200,200);
	if (hero.direction == RIGHT) {
		shoot.direction = RIGHT;
	}
	else {
		shoot.direction = LEFT;
	}
}
void shootUpdate(Shoot &shoot, float secs) {
		ofVec2f speed(300, 0);
		if (shoot.isShooting) {
			if (shoot.direction == RIGHT) {
				shoot.position += speed * secs;
			}
			else {
				shoot.position -= speed * secs;
			}
		}
}
void shootDraw(Shoot &shoot, Hero &hero) {
	shoot.snowball.draw(hero.position);
}