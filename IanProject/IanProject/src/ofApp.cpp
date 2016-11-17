#include "ofApp.h"
#include "hero.h"
#include "tiro.h"
#include "TileMap.h"
#include "camera.h"
#include "ShootManager.h"
#include <vector>

float before;

ShootManager shootMng;
Camera camera;
TileMap tilemap;
Hero hero(tilemap);



//--------------------------------------------------------------
void ofApp::setup() {
	hero.init();
	tilemap.init();
}

//--------------------------------------------------------------
void ofApp::update() {
	float secs = ofGetLastFrameTime();
	hero.update(secs);
	camera.update(hero.getPosition(), ofVec2f(tilemap.getMapWidth(), tilemap.getMapHeight()));
	shootMng.update(secs);
}

//--------------------------------------------------------------
void ofApp::draw() {

	tilemap.draw(camera.getPosition(), hero.getPosition());
	hero.draw(camera.getPosition());
	shootMng.draw(camera.getPosition());
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == OF_KEY_RIGHT) {
		hero.turnRight();
		hero.walk();
	}
	if (key == OF_KEY_LEFT) {
		hero.turnLeft();
		hero.walk();
	}
	if (key == 'e' || key == 'E') {
		shootMng.shooting(hero);
	}
	if (key == 'w' || key == 'W') {
		hero.jump();
	}
	if (key == 'r' || key == 'R') {
		//AHAM EU SEI QUE ISSO AQUI FICOU LINDO 
		if (tilemap.getTileChar(hero.getPosition()) == '/') {
			tilemap.textBoxActive(0);
		}
		if (tilemap.getTileChar(hero.getPosition()) == '<') {
			tilemap.textBoxActive(1);
		}
		if (tilemap.getTileChar(hero.getPosition()) == '>') {
			tilemap.textBoxActive(2);
		}
		if (tilemap.getTileChar(hero.getPosition()) == '^') {
			tilemap.textBoxActive(3);
		}
		if (tilemap.getTileChar(hero.getPosition()) == '~') {
			tilemap.textBoxActive(4);
		}
		if (tilemap.getTileChar(hero.getPosition()) == '-') {
			tilemap.textBoxActive(5);
		}
		if (tilemap.getTileChar(hero.getPosition()) == '_') {
			tilemap.textBoxActive(6);
		}
		if (tilemap.getTileChar(hero.getPosition()) == '=') {
			tilemap.textBoxActive(7);
		}
		if (tilemap.getTileChar(hero.getPosition()) == '+') {
			tilemap.textBoxActive(8);
		}
		if (tilemap.getTileChar(hero.getPosition()) == ']') {
			tilemap.textBoxActive(9);
		}			
	}
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	if (key == OF_KEY_LEFT || key == OF_KEY_RIGHT) {
		hero.stop();
	}
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
