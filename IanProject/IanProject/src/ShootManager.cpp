#include "ShootManager.h"

ShootManager::ShootManager() {
	
}

void ShootManager::update(float secs) {
	for (int i = 0; i < tiro.size(); i++) {
		if (tiro[i])
			tiro[i]->update(secs);
	}
}

void ShootManager::draw(const ofVec2f& camera) const {
	for (int i = 0; i < tiro.size(); i++) {
		if (tiro[i])
			tiro[i]->draw(camera);
	}
}

void ShootManager::shooting(Hero& hero) {
	Shoot* s = new Shoot();
	s->init(hero);
	tiro.push_back(s);
}

ShootManager::~ShootManager() {
	for (int i = 0; i < tiro.size(); i++) {
		delete tiro[i];
	}
}