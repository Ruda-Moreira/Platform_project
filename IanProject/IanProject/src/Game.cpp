#include "Game.h"
#include "Keyboard.h"

void Game::init() {
	tilemap.init();

	music.load("audio/provisoria.aac");
	music.play();
	music.setLoop(true);
	
	walkLeftRed.addFrame("img/walkLeft.png");
	walkLeftRed.addFrame("img/walkLeft1.png");
	walkLeftRed.addFrame("img/walkLeft2.png");
	walkLeftRed.addFrame("img/walkLeft3.png");
	walkLeftRed.setFrameTime(0.3f);

	walkRightRed.addFrame("img/walkRight.png");
	walkRightRed.addFrame("img/walkRight1.png");
	walkRightRed.addFrame("img/walkRight2.png");
	walkRightRed.addFrame("img/walkRight3.png");
	walkRightRed.setFrameTime(0.3f);

	throwLeftRed.addFrame("img/throwE_0.png");
	throwLeftRed.addFrame("img/throwE_1.png");
	throwLeftRed.addFrame("img/throwE_2.png");
	throwLeftRed.addFrame("img/throwE_3.png");
	throwLeftRed.addFrame("img/throwE_4.png");
	throwLeftRed.addFrame("img/throwE_5.png");
	throwLeftRed.addFrame("img/throwE_6.png");
	throwLeftRed.addFrame("img/throwE_7.png");
	throwLeftRed.addFrame("img/throwE_8.png");
	throwLeftRed.setFrameTime(0.1f);

	throwRightRed.addFrame("img/throwD_0.png");
	throwRightRed.addFrame("img/throwD_1.png");
	throwRightRed.addFrame("img/throwD_2.png");
	throwRightRed.addFrame("img/throwD_3.png");
	throwRightRed.addFrame("img/throwD_4.png");
	throwRightRed.addFrame("img/throwD_5.png");
	throwRightRed.addFrame("img/throwD_6.png");
	throwRightRed.addFrame("img/throwD_7.png");
	throwRightRed.addFrame("img/throwD_8.png");
	throwRightRed.setFrameTime(0.1f);

	walkLeftBlue.addFrame("img/walkLeft1_b.png");
	walkLeftBlue.addFrame("img/walkLeft2_b.png");
	walkLeftBlue.addFrame("img/walkLeft3_b.png");
	walkLeftBlue.addFrame("img/walkLeft4_b.png");
	walkLeftBlue.setFrameTime(0.3f);

	walkRightBlue.addFrame("img/walkRight1_b.png");
	walkRightBlue.addFrame("img/walkRight2_b.png");
	walkRightBlue.addFrame("img/walkRight3_b.png");
	walkRightBlue.addFrame("img/walkRight4_b.png");
	walkRightBlue.setFrameTime(0.3f);

	throwLeftBlue.addFrame("img/throwE0_b.png");
	throwLeftBlue.addFrame("img/throwE1_b.png");
	throwLeftBlue.addFrame("img/throwE2_b.png");
	throwLeftBlue.addFrame("img/throwE3_b.png");
	throwLeftBlue.addFrame("img/throwE4_b.png");
	throwLeftBlue.addFrame("img/throwE5_b.png");
	throwLeftBlue.addFrame("img/throwE6_b.png");
	throwLeftBlue.addFrame("img/throwE7_b.png");
	throwLeftBlue.addFrame("img/throwE8_b.png");
	throwLeftBlue.setFrameTime(0.1f);

	throwRightBlue.addFrame("img/throwD0_b.png");
	throwRightBlue.addFrame("img/throwD1_b.png");
	throwRightBlue.addFrame("img/throwD2_b.png");
	throwRightBlue.addFrame("img/throwD3_b.png");
	throwRightBlue.addFrame("img/throwD4_b.png");
	throwRightBlue.addFrame("img/throwD5_b.png");
	throwRightBlue.addFrame("img/throwD6_b.png");
	throwRightBlue.addFrame("img/throwD7_b.png");
	throwRightBlue.addFrame("img/throwD8_b.png");
	throwRightBlue.setFrameTime(0.1f);

	hero = new Hero(tilemap);
	enemy[0] = new Enemy(ofVec2f(3600, 712), ofVec2f(4000, 712), 
		walkRightRed, walkLeftRed, throwRightRed, throwLeftRed, *hero);
	enemy[1] = new Enemy(ofVec2f(4500, 712), ofVec2f(4900, 712),
		walkRightRed, walkLeftRed, throwRightRed, throwLeftRed, *hero);
	enemy[2] = new Enemy(ofVec2f(5500, 712), ofVec2f(5900, 712),
		walkRightBlue, walkLeftBlue, throwRightBlue, throwLeftBlue, *hero);
	GAMEMANAGER.add(enemy[0]);
	GAMEMANAGER.add(enemy[1]);
	GAMEMANAGER.add(enemy[2]);
	GAMEMANAGER.add(hero);
}
void Game::update(float secs) {
	camera.update(hero->getPosition(), ofVec2f(tilemap.getMapWidth(), tilemap.getMapHeight()));
	GAMEMANAGER.update(ofGetLastFrameTime());

	if (KEYS.isPressed('r') || KEYS.isPressed('R')) {
		//AHAM EU SEI QUE ISSO AQUI FICOU LINDO 
		if (tilemap.getTileChar(hero->getPosition()) == '/') {
			tilemap.textBoxActive(0);
		}
		if (tilemap.getTileChar(hero->getPosition()) == '<') {
			tilemap.textBoxActive(1);
		}
		if (tilemap.getTileChar(hero->getPosition()) == '>') {
			tilemap.textBoxActive(2);
		}
		if (tilemap.getTileChar(hero->getPosition()) == '^') {
			tilemap.textBoxActive(3);
		}
		if (tilemap.getTileChar(hero->getPosition()) == '~') {
			tilemap.textBoxActive(4);
		}
		if (tilemap.getTileChar(hero->getPosition()) == '-') {
			tilemap.textBoxActive(5);
		}
		if (tilemap.getTileChar(hero->getPosition()) == '_') {
			tilemap.textBoxActive(6);
		}
		if (tilemap.getTileChar(hero->getPosition()) == '=') {
			tilemap.textBoxActive(7);
		}
		if (tilemap.getTileChar(hero->getPosition()) == '+') {
			tilemap.textBoxActive(8);
		}
		if (tilemap.getTileChar(hero->getPosition()) == ']') {
			tilemap.textBoxActive(9);
		}
	}
}
void Game::draw() {
	tilemap.draw(camera.getPosition(), hero->getPosition());
	GAMEMANAGER.draw(camera.getPosition());
}
Screen* Game::nextScreen() {
	return this;
}