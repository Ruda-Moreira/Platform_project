#include "ScreenManager.h"

void ScreenManager::init(Screen* first) {
	current = first;
	current->init();
}

void ScreenManager::update() {
	Screen* next = current->nextScreen();
	if (next != current) {
		next->init();
		delete current;
		current = next;
	}
	current->update(ofGetLastFrameTime());
}

void ScreenManager::draw() {
	current->draw();
}
