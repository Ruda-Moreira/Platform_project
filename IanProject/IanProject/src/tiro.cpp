#include <stdio.h>
#include "tiro.h"
#include "Enemy.h"
#include "Hero.h"

//primeira classe que eu fiz sozinha hehe :3

Shoot::Shoot(const ofVec2f& position, bool direction, bool enemy) : position(position), direction(direction), enemy(enemy) {}

void Shoot::init() {
    shoot.load(enemy? "img/bola.png" : "img/shoot.png");
    alive = true;
}

void Shoot::update(float secs) {
		ofVec2f speed(600, 0);
        if (direction == RIGHT) {
            position += speed * secs;
        }
        else {
            position -= speed * secs;
        }
}
void Shoot::draw(const ofVec2f& camera) {
	shoot.draw(position - camera);
}

bool Shoot::isAlive() const {
    if (position.x > 10000 || position.x < 0) {
        return false;
    }
    return alive;
}

ofRectangle Shoot::bounds(){
    return ofRectangle(position, shoot.getWidth(), shoot.getHeight());
}

void Shoot::collidedWith(GameObject* other){
    Enemy *enemy = dynamic_cast<Enemy*>(other);
    if(enemy && !isEnemy()){
        alive = false;
        return;
    }
    Hero *hero = dynamic_cast<Hero*>(other);
    if (hero && isEnemy()){
        alive = false;
        return;
    }
}

bool Shoot::isEnemy() const {
    return enemy;
}