#pragma once

#define WIDTH 120
#define HEIGHT 17
#define TILE 64

#include "ofMain.h"

class TileMap {
public:
	ofImage* tiles;
	//declarei aqui a imagem do bg
	ofImage background;
	vector <ofImage*> textBox;
	ofImage house;
	ofVec2f position;
	ofVec2f spawnPoint;

	bool textBoxCheck;
	int textBoxNum;

	char map[HEIGHT][WIDTH] = {
		"                                                                                                                       ",
		"                                                                                                                       ",
		"                                                                                                                       ",
		"                        %%%%%%%%%%%                                                                                    ",
		"                        %  _ =  ++%                                                                                    ",
		"             %%%%%%%%%%%%%%%%%%%%%%                                                                                    ",
		"             %                    %                                                                                    ",
		"             %                    %                                                                                    ",
		"             %      --          ~ %                                                                                    ",
		"             %%%%%%%%%%%%%%%%%%%%%%                                                                                    ",
		"             %                    %                                             #!c#!                                  ",                   
		"                                                                                                                       ",
		"  $*  p  $*   /  <  >> ^^         *  $*    *        *    $$           *         * $            $           *           ",
		"##!c!!c#cc#!cc#!cc###!!##c!!c#cc#!cc#!##!c!!#c#!##!c!#c#!!#!#!cc#!c#!cc#c!##!c!##!c!#cc!cc!c##c!#c!c##c#!#cc#c#!c!     ",
		"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     ",
		"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     ",
		"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     " };

	
	void init();
	void draw(const ofVec2f& camera, const ofVec2f& heroPos);
	float getTextBoxWidth() const;
	float getTextBoxHeight() const;
	float getMapWidth() const;
	float getMapHeight() const;
	bool textBoxActive(int num);
    bool isNotSolid(const ofVec2f& position);
	ofVec2f getSpawnPoint();
	char getTileChar(const ofVec2f& position);

};
