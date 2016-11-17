#pragma once
#include "ofMain.h"
#include <vector>
#include "animation.h"

#define WIDTH 60
#define HEIGHT 16
#define TILE 64

class TileMap {
public:
	ofImage* tiles;
	//declarei aqui a imagem do bg
	ofImage background;
	vector <ofImage*> textBox;
	ofImage house;
//	ofImage door;
	Animation door;
	ofVec2f position;
	ofVec2f spawnPoint;

	bool textBoxCheck;
	int textBoxNum;

	char map[HEIGHT][WIDTH] = {
		"                                                           ",
		"                                                           ",
		"                       %%%%%%%%%%%%                        ",
		"                       %          %                        ",
		"                       %  _ =  ++ %                        ",
		"             %%%%%%%%%%%%%%%%%%%%%%                        ",
		"             %                    %                        ",
		"             %                    %                        ",
		"         ##  %      --          ~ %                        ",
		"  *p         %%%%%%%%%%%%%%%%%%%%%%                 *      ",
		"######       %                    %                ###     ",
		"                                  %                        ",
		"  $*     $!*   /  <  >> ^^        %*  $*    *   !*       ##",
		"###################################################        ",
		"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@        ",
		"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@        " };

	void draw(const ofVec2f& camera, const ofVec2f& heroPos);
	void init();
	float getTextBoxWidth() const;
	float getTextBoxHeight() const;
	float getMapWidth() const;
	float getMapHeight() const;
	bool textBoxActive(int num);
	ofVec2f getSpawnPoint();
	char getTileChar(const ofVec2f& position);

};
