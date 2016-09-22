#include <stdio.h>
#include "TileMap.h"


void TileMap::init() {
	position = ofVec2f(500, 500);
	tiles[0].load("img/tile1.png");
	tiles[1].load("img/tile2.png");
	tiles[2].load("img/tile3.png");
	tiles[3].load("img/tile4.png");
	tiles[4].load("img/tile5.png");
}

void TileMap::draw() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			switch (map[i][j]) {
			case '!':
				tiles[0].draw(position);
				break;
			case '@':
				tiles[1].draw(position);
				break;
			case'#':
				tiles[2].draw(position);
				break;
			case '$':
				tiles[3].draw(position);
				break;
			case'*':
				tiles[4].draw(position);
				break;
			}
		}
	}
}


//void TileMap::setNew(int width, int height) {
//
//}
//int TileMap::getWidth() { 
//
//}
//int TileMap::getHeigh() {
//
//}
//int TileMap::getTiled(int x, int y) {
//
//}
//void TileMap::setTiled(int x, int y, ofImage tile) {
//
//}