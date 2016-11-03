#pragma once

#include "ofApp.h"
#include "hero.h"
#include "tiro.h"

class shootManager {

	private:
		vector<Shoot*> tiro;

	public:
		shootManager();
		void update(float secs);
		void draw(const ofVec2f& camera) const;
		~shootManager();

		void shooting(Hero& hero);
};