#pragma once

#include "Camera.h"
#include "Hero.h"
#include "GameManager.h"
#include "Screen.h"
#include "Button.h"
#include "TileMap.h"
#include "Enemy.h"
#include "animation.h"

class Game : public Screen {
private:
	Hero* hero;
	Enemy* enemy[3];
	TileMap tilemap;
	ofImage background;
	ofSoundPlayer music;
	Animation door;
	ofVec2f direction;
	Camera camera;
	vector<Button*> buttons;

	Animation walkLeftRed, walkRightRed, throwLeftRed, throwRightRed;
	Animation walkLeftBlue, walkRightBlue, throwLeftBlue, throwRightBlue;

	float count;
public:
	void init();
	void update(float secs);
	void draw();
	Screen* nextScreen();
};