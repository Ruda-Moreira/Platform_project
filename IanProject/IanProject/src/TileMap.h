#ifndef TileMap_h
#define TileMap_h
#include "ofApp.h"
#define WIDTH 25
#define HEIGHT 15
#define TILE 64

class TileMap {
public:
	ofImage* tiles;
	//declarei aqui a imagem do bg
	ofImage background;
	ofVec2f position;
	ofVec2f spawnPoint;
	char map[HEIGHT][WIDTH] = {
		"                        ",
		"                        ",
		"                        ",
		"                        ",
		"             ###########",
		"                        ",
		"        ##              ",
		"  *                     ",
		"#######                 ",
		"                        ",
		"  $*     $! * !  *   !  ",
		"########################",
		"@@@@@@@@@@@@@@@@@@@@@@@@", 
		"                        ",
		"                        " };

	void draw();
	void init();
	ofVec2f getSpawnPoint();
	char getTileChar(ofVec2f position);

};
#endif
