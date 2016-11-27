#pragma once

#include "ofMain.h"
#include "Screen.h"

class ScreenManager {

private:
	Screen* current;

public:
	void init(Screen* first);
	void update();
	void draw();
};