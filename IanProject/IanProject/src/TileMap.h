#ifndef TileMap_h
#define TileMap_h
#include "ofApp.h"
#define WIDTH 35
#define HEIGHT 16
#define TILE 64

class TileMap {
public:
	ofImage* tiles;
	//declarei aqui a imagem do bg
	ofImage background;
	ofImage textBox;
	ofVec2f position;
	ofVec2f spawnPoint;

	bool textBoxCheck;

	char map[HEIGHT][WIDTH] = {
		"                                  ",
		"                                  ",
		"                                  ",
		"             %%%%%%%%%%%%%%%%     ",
		"             %              %     ",
		"             %              %     ",
		"             %              %     ",
		"             %  //  //  //  %     ",
		"         ##  %%%%%%%%%%%%%%%%     ",
		"  *p         %              %     ",
		"######       %              %     ",
		"             %              %     ",
		"  $*     $!* %   //    //   %     ",
		"##################################",
		"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
		"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" };

	void draw(ofVec2f camera, ofVec2f heroPos);
	void init();
	float getTextBoxWidth();
	float getTextBoxHeight();
	float getMapWidth();
	float getMapHeight();
	bool textBoxActive();
	ofVec2f getSpawnPoint();
	char getTileChar(ofVec2f position);

};
#endif
