#include <stdio.h>
#include "TileMap.h"



void TileMap::init() {

	position = ofVec2f(0, 0);

	background.load("img/bg.jpg");
	house.load("img/house.png");
	door.addFrame("img/door.png");
	door.addFrame("img/door1.png");

	textBox.push_back(new ofImage("img/box1.png"));
	textBox.push_back(new ofImage("img/box2.png"));
	textBox.push_back(new ofImage("img/box3.png"));
	textBox.push_back(new ofImage("img/box4.png"));
	textBox.push_back(new ofImage("img/box5.png"));
	textBox.push_back(new ofImage("img/box6.png"));
	textBox.push_back(new ofImage("img/box7.png"));
	textBox.push_back(new ofImage("img/box8.png"));
	textBox.push_back(new ofImage("img/box9.png"));
	textBox.push_back(new ofImage("img/box10.png"));

	tiles = new ofImage[255];
	tiles['!'].load("img/tile1.png");
	tiles['#'].load("img/tile2.png");
	tiles['@'].load("img/tile3.png");
	tiles['$'].load("img/tile4.png");
	tiles['*'].load("img/tile5.png");
	tiles['%'].load("img/tile_test1.png");
	tiles['/'].load("img/nulltile.png");
	tiles['<'].load("img/nulltile.png");
	tiles['>'].load("img/nulltile.png");
	tiles['^'].load("img/nulltile.png");
	tiles['~'].load("img/nulltile.png");
	tiles['-'].load("img/nulltile.png");
	tiles['_'].load("img/nulltile.png");
	tiles['='].load("img/nulltile.png");
	tiles['+'].load("img/nulltile.png");
	tiles[']'].load("img/nulltile.png");
}

void TileMap::draw(const ofVec2f& camera, const ofVec2f& heroPos) {

	background.draw(position);
	house.draw(832 - camera.x, 192 - camera.y);
//	door.draw(827 - camera.x, 704 - camera.y);

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			ofImage &tile = tiles[map[i][j]];
			if (tile.isAllocated()) {
				tile.draw(position.x + j * tile.getWidth() - camera.x,
					position.y + i * tile.getHeight() - camera.y);
			}
		}
	}

	if (textBoxCheck) {
		ofVec2f boxPos(heroPos.x, heroPos.y - getTextBoxHeight() * 2);
		textBox[textBoxNum]->draw(boxPos - camera);
	}
}

float TileMap::getTextBoxWidth() const {
	return textBox[0]->getWidth();
}

float TileMap::getTextBoxHeight() const {
	return textBox[0]->getHeight();
}

float TileMap::getMapWidth() const {
	return background.getWidth();
}

float TileMap::getMapHeight() const {
	return background.getHeight();
}

bool TileMap::textBoxActive(int num) {
	textBoxNum = num;
	textBoxCheck = !textBoxCheck;
	return textBoxCheck;
}

bool TileMap::isSolid(const ofVec2f &position){
    char tile = getTileChar(position);
    return tile != '#' && tile != '@' && tile != '%';
}

char TileMap::getTileChar(const ofVec2f& position) {
	int height = position.x / TILE;
	int width = position.y / TILE;
	return map[width][height];
}

ofVec2f TileMap::getSpawnPoint() {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (map[i][j] == 'p') {
				ofVec2f result;
				result.x = result.x + j* TILE;
				result.y = result.y + i * TILE;
				return result;
			}
		}
	}
}