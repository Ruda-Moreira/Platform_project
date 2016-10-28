#pragma once

#include "ofApp.h"
#include "hero.h"
#include "tiro.h"

class shootManager {

	private:
		vector<Shoot*> tiro;

	public:

		Shoot& shoot;

		shootManager(Shoot& shoot);
		void update(float secs);
		void draw(const ofVec2f& camera) const;
		shootManager::~shootManager();

		void shooting(Hero& hero);
};