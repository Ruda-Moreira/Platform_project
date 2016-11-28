#include "Menu.h"
#include "Game.h"

void Menu::init() {
	next = this;

	background.load("img/Book2.png");
	sound.load("audio/percys-theme.mp3");
	sound.play();
	sound.setLoop(true);
	posButtonCredits.set(500, 600);
	posButtonEnter.set(150, background.getHeight() / 2);
	posButtonExit.set(880, background.getHeight() / 2);

	Button* enter = new Button(posButtonEnter, "img/start.png", "img/start2.png");
	Button* credits = new Button(posButtonCredits, "img/credits.png", "img/credits2.png");
	Button* exit = new Button(posButtonExit, "img/exit.png", "img/exit2.png");

	buttons.push_back(enter);
	buttons.push_back(credits);
	buttons.push_back(exit);
}
void Menu::update(float secs) {
	for (int i = 0; i < buttons.size(); i++) {
		buttons[i]->Update(secs);
		if (ofGetMousePressed(OF_MOUSE_BUTTON_1) && buttons[i]->Check(ofVec2f(ofGetMouseX(), ofGetMouseY()))) {
			buttons[i]->SetClick();
		}

		if (buttons[i]->isClickFinished()) {
			if (i == 0) {
				next = new Game();
				sound.stop();
			}
		}
	}
}
void Menu::draw() {
	background.draw(0, 0, 1366, 768);
	for (int i = 0; i < buttons.size(); i++) {
		buttons[i]->Draw();
	}
}
Screen* Menu::nextScreen() {
	return next;
}