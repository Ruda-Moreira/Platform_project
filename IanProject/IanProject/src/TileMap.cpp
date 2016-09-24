#include <stdio.h>
#include "TileMap.h"


void TileMap::init() {
	position = ofVec2f(100, 100);
	tiles = new ofImage[255];
	tiles['!'].load("img/tile1.png");
	tiles['@'].load("img/tile2.png");
	tiles['*'].load("img/tile3.png");
	tiles['$'].load("img/tile4.png");
	tiles['#'].load("img/tile5.png");
}

void TileMap::draw() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			ofImage &tile = tiles[map[i][j]];
			if (tile.isAllocated()) {
				tile.draw(position.x + j* tile.getWidth(), position.y + i * tile.getHeight());
			}
		}
	}
}