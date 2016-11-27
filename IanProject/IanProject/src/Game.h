#pragma once

#include "Camera.h"
#include "Hero.h"
#include "GameManager.h"
#include "Screen.h"
#include "Button.h"
#include "TileMap.h"
#include "Enemy.h"

class Game : public Screen {
private:
	Hero* hero;
	Enemy* enemy;
	TileMap tilemap;
	ofImage background;
	ofVec2f direction;
	Camera camera;
	vector<Button*> buttons;

	float count;
public:
	void init();
	void update(float secs);
	void draw();
	Screen* nextScreen();
};