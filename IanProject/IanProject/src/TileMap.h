#ifndef TileMap_h
#define TileMap_h

#include "ofApp.h"
#define TAM 10

class TileMap {
public:
	ofImage* tiles;
	ofVec2f position;
	char map[TAM][TAM] = {
		"        ",
		"    ####",
		"        ",
		"#####   ",
		"        ",
		"     ###",
		"        ",
		" $    ! ",
		"@#@ @@@@",
		"########" };

	void draw();
	void init();
};
#endif
