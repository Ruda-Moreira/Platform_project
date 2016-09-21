#ifndef TileMap_h
#define TileMap_h

#include "ofApp.h"

class TileMap {
private:
	ofImage* tiles;
	char* linkedList;
public:
	void setNew(int width, int height);
	int getWidth();
	int getHeigh();
	int getTiled(int x, int y);
	void setTiled(int x, int y, ofImage tile);

};


#endif
