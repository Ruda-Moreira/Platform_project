#ifndef TileMap_h
#define TileMap_h

#include "ofApp.h"

class TileMap {
public:
	ofImage* tiles;
	ofVec2f position;
	char map[3][3] = { '@', '#', '*',
					   '!', ' ', '$',
					   '@', ' ', '!' };


	void draw();
	void init();

};


#endif
