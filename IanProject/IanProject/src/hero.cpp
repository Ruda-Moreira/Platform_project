#include "hero.h"
#include "tiro.h"
#include "Keyboard.h"
#include "GameManager.h"

ofVec2f debugChar;
ofVec2f of1, of2;

Hero::Hero(TileMap& map) : state(IDLE), direction(RIGHT), tileMap(map), position(tileMap.getSpawnPoint()) {

}

//-------> MÉTODOS PRINCIPAIS
void Hero::init() {
    
    cooldown = 10;

	///DEBUG
	of1.set(4, 71);
	of2.set(62, 71);
	///
	walkRight.addFrame("img/IdleR.png");
	walkRight.addFrame("img/P2.png");
	walkRight.addFrame("img/P3.png");
	walkRight.setFrameTime(0.15f);

	walkLeft.addFrame("img/IdleL.png");
	walkLeft.addFrame("img/P5.png");
	walkLeft.addFrame("img/P6.png");
	walkLeft.setFrameTime(0.15f);

	jumpRight.addFrame("img/IdleR.png");
	jumpRight.addFrame("img/jumpR1.png");
	jumpRight.addFrame("img/jumpR2.png");
	jumpRight.addFrame("img/jumpR3.png");
	jumpRight.addFrame("img/jumpR4.png");
	jumpRight.addFrame("img/jumpR5.png");
	jumpRight.addFrame("img/IdleR.png");
	jumpRight.setFrameTime(0.1f);

	jumpLeft.addFrame("img/IdleL.png");
	jumpLeft.addFrame("img/jumpL1.png");
	jumpLeft.addFrame("img/jumpL2.png");
	jumpLeft.addFrame("img/jumpL3.png");
	jumpLeft.addFrame("img/jumpL4.png");
	jumpLeft.addFrame("img/jumpL5.png");
	jumpLeft.addFrame("img/IdleL.png");
	jumpLeft.setFrameTime(0.1f);
}

void Hero::update(float secs) {
    cooldown += secs;
	cout << state;
	ofVec2f speed(400, 0);
	switch (state) {
	case IDLE: {

		if (!tileMap.isNotSolid(position + of2) && !tileMap.isNotSolid(position + of1)) {
			cout << "deboa";
			
		}
		else if(!tileMap.isNotSolid(position + of2)) {
			cout << "PRA TRAZ";
			position -= ofVec2f(1, 0);
		}
		else if (!tileMap.isNotSolid(position + of1)) {
			cout << "PRA FRENTE";
			position += ofVec2f(1, 0);
		}

		if (KEYS.isPressed(OF_KEY_UP))
			jump();
		if (KEYS.isPressed(OF_KEY_LEFT))
			walk(LEFT);
		if (KEYS.isPressed(OF_KEY_RIGHT)) {
			if (!tileMap.isNotSolid(position + of2) && !tileMap.isNotSolid(position + of1))
				walk(RIGHT);
		}

		testFall();
		break;
	}

	case WALKING: {

		if (KEYS.isPressed(OF_KEY_UP)) { //somente se estiver no chao
			jump();
		}
		else if (KEYS.isPressed(OF_KEY_LEFT)) {
			walk(LEFT);
		}
		else if (KEYS.isPressed(OF_KEY_RIGHT)) {
			walk(RIGHT);
		}

		if (!KEYS.isPressed(OF_KEY_LEFT) &&
			!KEYS.isPressed(OF_KEY_RIGHT) &&
			!KEYS.isPressed(OF_KEY_UP)) {
			stop();
			state = IDLE;
		}

		cout << "walking" << endl;

		testFall();
		if (direction == RIGHT) {
			if (tileMap.isNotSolid(position + ofVec2f(TILE, 0))) {
				position += speed * secs;
			}
		}
		else {
			if (tileMap.isNotSolid(position)) {
				position -= speed * secs;
			}
		}
		getAnimation().update(secs);
		break;
	}

	case JUMPING: {

		if (!(!tileMap.isNotSolid(position + ofVec2f(4,0)) || !tileMap.isNotSolid(position + ofVec2f(62, 0)))) {
			position.y -= secs * 400;
		}
		
		jumpTime += secs;

		if (KEYS.isPressed(OF_KEY_LEFT)) {
			if (tileMap.isNotSolid(position - ofVec2f(2,0)) && tileMap.isNotSolid(position + of1 - ofVec2f(2, 0)))
				position -= speed * secs;
		}
		else if (KEYS.isPressed(OF_KEY_RIGHT)) {
			if (tileMap.isNotSolid(position + ofVec2f(TILE, 0) + ofVec2f(2,0)) && tileMap.isNotSolid(position + of2 + ofVec2f(2, 0)))
				position += speed * secs;
		}

		if (jumpTime > 0.5) {
			state = FALLING;
		}
		getAnimation().update(secs);
		break;
	}

	case FALLING: {
		//if (!tileMap.isSolid(position + ofVec2f(0, TILE))) {
		if (!tileMap.isNotSolid(position + of1) || !tileMap.isNotSolid(position + of2)) {
			state = IDLE;
		}
		else
			position.y += secs * 400;
		if (KEYS.isPressed(OF_KEY_LEFT)) {
			position -= speed * secs;
		}
		else if (KEYS.isPressed(OF_KEY_RIGHT)) {
			if (tileMap.isNotSolid(position + of2+ofVec2f(1,0)))
				position += speed * secs;
		}
		break;
	}
	}
    if(KEYS.isPressed('X') || KEYS.isPressed('x')){
        if(cooldown > 1) {
            shoot();
        }
    }
	blockBorder();
}

void Hero::draw(const ofVec2f& camera) {
	ofVec2f positionToDraw = position - ofVec2f(0, 26) - camera;
	getAnimation().draw(positionToDraw);
}

//--------> MÉTODOS DE TROCA DE ESTADO
void Hero::walk(bool direction) {
	if (state == JUMPING || state == FALLING || state == WALKING) return;
	state = WALKING;
	this->direction = direction;
	getAnimation().reset();
}

void Hero::jump() {
	if (state == FALLING || state == JUMPING) return;
	state = JUMPING;
	jumpTime = 0;
	getAnimation().reset();
}

void Hero::stop() {
	if (state != WALKING) return;
	state = IDLE;
}

void Hero::testFall() {
	//if (tileMap.isSolid(position + ofVec2f(0, TILE))) {
	bool e1 = tileMap.isNotSolid(position + of1);
	bool e2 = tileMap.isNotSolid(position + of2);
	if (e1 && e2) {
		state = FALLING;
		getAnimation().reset();
	}
}

//--------> MÉTODOS DE INTERAÇÃO
void Hero::shoot() {
	GAMEMANAGER.add(new Shoot(getHandPosition(), direction, false));
    cooldown = 0;
}

void Hero::blockBorder() {
	if (position.x <= 0) {
		position.x = 0;
	}
	else if (position.x >= tileMap.getMapWidth()) {
		position.x = tileMap.getMapWidth();
	}
}

void Hero::collidedWith(GameObject* other) {
    Shoot *shoot = dynamic_cast<Shoot*>(other);
    if(shoot && shoot->isEnemy()){
        position = tileMap.getSpawnPoint();
    }
}

//--------> MÉTODOS DE COMUNICAÇÃO (GETTERS - SETTERS)
bool Hero::isAlive() const {
	return true;
}

ofVec2f Hero::getPosition() const {
	return position;
}

ofVec2f Hero::getHandPosition() const {
	return position + ofVec2f(45, 45);
}

Animation& Hero::getAnimation() {
	switch (state) {
	case IDLE:
	case WALKING:
	case FALLING:
		return direction == RIGHT ? walkRight : walkLeft;
	case JUMPING:
		return direction == RIGHT ? jumpRight : jumpLeft;
	}
}

ofRectangle Hero::bounds() {
	return ofRectangle(position, walkLeft.getFrameSize().x, walkLeft.getFrameSize().y);
}

