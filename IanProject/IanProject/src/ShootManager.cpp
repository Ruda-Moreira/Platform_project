#include "ShootManager.h"

shootManager::shootManager() {

}

void shootManager::update(float secs) {
	for (int i = 0; i < tiro.size(); i++) {
		if (tiro[i])
			tiro[i]->update(secs);
	}
}

void shootManager::draw(const ofVec2f& camera) const {
	for (int i = 0; i < tiro.size(); i++) {
		if (tiro[i])
			tiro[i]->draw(camera);
	}
}

void shootManager::shooting(Hero& hero) {
	Shoot* s = new Shoot();
	s->init(hero);
	tiro.push_back(s);
}

shootManager::~shootManager() {
	for (int i = 0; i < tiro.size(); i++) {
		delete tiro[i];
	}
}