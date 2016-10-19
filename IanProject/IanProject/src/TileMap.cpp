#include <stdio.h>
#include "TileMap.h"



void TileMap::init() {
	
	position = ofVec2f(0, 0);

	background.load("img/bg.jpg");
	textBox.load("img/box.png");
	tiles = new ofImage[255];
	tiles['!'].load("img/tile1.png");
	tiles['#'].load("img/tile2.png");
	tiles['@'].load("img/tile3.png");
	tiles['$'].load("img/tile4.png");
	tiles['*'].load("img/tile5.png");
	tiles['%'].load("img/tile_test1.png");
	tiles['/'].load("img/tile_test.png");
}

void TileMap::draw(ofVec2f camera, ofVec2f heroPos) {

	background.draw(position - camera);

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
		textBox.draw(boxPos - camera);
	}
}

float TileMap::getTextBoxWidth() {
	return textBox.getWidth();
}

float TileMap::getTextBoxHeight() {
	return textBox.getHeight();
}

float TileMap::getMapWidth() {
	return background.getWidth();
}

float TileMap::getMapHeight() {
	return background.getHeight();
}

bool TileMap::textBoxActive() {
	return textBoxCheck = true;
}

char TileMap::getTileChar(ofVec2f position) {
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