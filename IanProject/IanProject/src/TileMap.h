#ifndef TileMap_h
#define TileMap_h
#include "ofWindowSettings.h"
#include "ofApp.h"
#define WIDTH 17
#define HEIGHT 13
#define TILE 64

class TileMap {
public:
	ofImage* tiles;
	ofVec2f position;
	ofVec2f spawnPoint;
	char map[HEIGHT][WIDTH] = {
		"                ",
		"                ",
		"     *$         ",
		"########        ",
		"                ",
		"          *     ",
		"         #######",
		"                ",
		"  $*p    $! * ! ",
		"################",
		"@@@@@@@@@@@@@@@@", 
		"                ",
		"               " };

	void draw();
	void init();
	ofVec2f getSpawnPoint();
	char getTileChar(ofVec2f position);

};
#endif
