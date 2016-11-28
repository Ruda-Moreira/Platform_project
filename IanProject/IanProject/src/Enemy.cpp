#include "Enemy.h"
#include "tiro.h"
#include "GameManager.h"

Enemy::Enemy(const ofVec2f& start, const ofVec2f& end,
	const Animation& walkRight, const Animation& walkLeft, const Animation& throwRight, const Animation& throwLeft,
    const Hero& hero)
	: startPos(start), stopPos(end), walkRight(walkRight), walkLeft(walkLeft), attackRight(throwRight), attackLeft(throwLeft),
    hero(hero) {}

void Enemy::init() {
    alive = true;
	dir = false;
	position = startPos;
    cooldown = 100;

}

void Enemy::draw(const ofVec2f& camera) {
    getAnimation().draw(position - camera);
}

void Enemy::update(float secs) {
    cooldown += secs;
	ofVec2f path = (dir ? stopPos : startPos) - position;
	float distance = path.length();
	direction = path.normalize();
	position += direction * 200 * secs;
	getAnimation().update(secs);
	if (distance < 5)
		dir = !dir;
    if(cooldown > 1){
        if(&getAnimation() == &attackRight && getAnimation().isLastFrame()){
            GAMEMANAGER.add(new Shoot(position + ofVec2f(0, 50), RIGHT, true));
            cooldown = 0;
        } else if (&getAnimation() == &attackLeft && getAnimation().isLastFrame()){
            GAMEMANAGER.add(new Shoot(position + ofVec2f(0, 50), LEFT, true));
            cooldown = 0;
        }
    }
}

bool Enemy::isAlive() const {
	return alive;
}

ofRectangle Enemy::bounds() {
	return ofRectangle(position, walkLeft.getFrameSize().x, walkLeft.getFrameSize().y);
}

void Enemy::collidedWith(GameObject* other) {
    Shoot *shoot = dynamic_cast<Shoot*>(other);
    if(shoot && !shoot->isEnemy()){
        alive = false;
        return;
    }
}

Animation& Enemy::getAnimation() {
    float distance = (position - hero.getPosition()).length();
    if (distance < 500){
        return dir ? attackRight : attackLeft;
    }
    return dir ? walkRight : walkLeft;
}