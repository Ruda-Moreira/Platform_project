#include "Game.h"
#include "Keyboard.h"

void Game::init() {
	hero = new Hero(tilemap);
	enemy = new Enemy(ofVec2f(800, 712));
	GAMEMANAGER.add(enemy);
	GAMEMANAGER.add(hero);
	tilemap.init();
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