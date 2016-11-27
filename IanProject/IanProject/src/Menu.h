#pragma once

#include "ofMain.h"
#include "Screen.h"
#include "Button.h"

class Menu : public Screen {
private:
	vector <Button*> buttons;
	Screen* next;

	ofImage background;
	ofSoundPlayer sound;
	ofVec2f posButtonEnter;
	ofVec2f posButtonCredits;
	ofVec2f posButtonExit;

public:
	void init();
	void update(float secs);
	void draw();
	Screen* nextScreen();
	~Menu() {};
};