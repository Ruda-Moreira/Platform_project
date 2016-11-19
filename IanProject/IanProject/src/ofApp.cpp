#include "ofApp.h"
#include "hero.h"
#include "camera.h"
#include "GameManager.h"
#include "Keyboard.h"

Camera camera;
TileMap tilemap;
Hero* hero;


//--------------------------------------------------------------
void ofApp::setup() {
    hero = new Hero(tilemap);
    GAMEMANAGER.add(hero);
	tilemap.init();
}

//--------------------------------------------------------------
void ofApp::update() {
	camera.update(hero->getPosition(), ofVec2f(tilemap.getMapWidth(), tilemap.getMapHeight()));
    GAMEMANAGER.update(ofGetLastFrameTime());
}

//--------------------------------------------------------------
void ofApp::draw() {
	tilemap.draw(camera.getPosition(), hero->getPosition());
    GAMEMANAGER.draw(camera.getPosition());
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    KEYS.onPress(key);
	if (key == 'r' || key == 'R') {
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
//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	KEYS.onRelease(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
