#include "Button.h"

Button::Button(const ofVec2f& pos, string clicked, string notClicked) {
	position = pos;
	colorNotClicked.load(notClicked);
	colorClicked.load(clicked);
	//this->sound.load(sound);
	IsClicked = false;
	ClickFinished = false;
}

const bool Button::Check(const ofVec2f& posMouse) const {//checa colisão do mouse com o botão
	return (posMouse.x > position.x && posMouse.x < (position.x + SIZEX)
		&& posMouse.y > position.y && posMouse.y < (position.y + SIZEY));

}

bool Button::SetClick() {
	IsClicked = true;
	return IsClicked;
}

void Button::Update(float secs) {
	if (IsClicked) {
		clickTime += secs;
		//a cada 4 segundos o botão "desliga"
		if (clickTime > 0.6) {
			IsClicked = false;
			ClickFinished = true;
			//sound.stop();
		}
	}
}

void Button::Draw() const {
	if (!IsClicked) {
		colorClicked.draw(position.x, position.y);
	}
	else {
		colorNotClicked.draw(position.x, position.y);
	}
}

bool Button::isClickFinished() const {
	return ClickFinished;
}

Button::~Button() {

}