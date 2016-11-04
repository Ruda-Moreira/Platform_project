#ifndef TileMap_h
#define TileMap_h
#include "ofApp.h"
#define WIDTH 40
#define HEIGHT 16
#define TILE 64

class TileMap {
public:
	ofImage* tiles;
	//declarei aqui a imagem do bg
	ofImage background;
	ofImage textBox;
	ofImage house;
	ofVec2f position;
	ofVec2f spawnPoint;

	bool textBoxCheck;

	char map[HEIGHT][WIDTH] = {
		"                                       ",
		"                                       ",
		"                       %%%%%%%%%%%%    ",
		"                       %          %    ",
		"                       %          %    ",
		"             %%%%%%%%%%%%%%%%%%%%%%    ",
		"             %                    %    ",
		"             %                    %    ",
		"         ##  %                    %    ",
		"  *p         %%%%%%%%%%%%%%%%%%%%%%    ",
		"######       %                    %    ",
		"                                  %    ",
		"  $*     $!*                      %    ",
		"#######################################",
		"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
		"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" };

	void draw(const ofVec2f& camera, const ofVec2f& heroPos);
	void init();
	float getTextBoxWidth() const;
	float getTextBoxHeight() const;
	float getMapWidth() const;
	float getMapHeight() const;
	bool textBoxActive();
	ofVec2f getSpawnPoint();
	char getTileChar(const ofVec2f& position);

};
#endif
