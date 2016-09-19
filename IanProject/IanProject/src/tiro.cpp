#include <stdio.h>
#include "tiro.h"


void shootInit(Shoot &shoot) {
	shoot.snowball.load("img/snowball.png");
}
void shootUpdate(Shoot &shoot,Hero &hero, float secs) {
		ofVec2f speed(300, 0);
		if (hero.direction == RIGHT) {
			shoot.position += speed * secs;
		}
		else {
			shoot.position -= speed * secs;
		}
}
void shootDraw(Shoot &shoot, Hero &hero) {
	shoot.snowball.draw(hero.position);
}