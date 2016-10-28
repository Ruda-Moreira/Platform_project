#include "ofApp.h"
#include "hero.h"
#include "tiro.h"
#include "TileMap.h"
#include "camera.h"
#include <vector>

float before;


Camera camera;
TileMap tilemap;
Hero hero(tilemap);
vector<Shoot*> shoot;


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

	for (int i = 0; i < shoot.size(); i++) {
		if(shoot[i])
		shoot[i]->update(secs);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	tilemap.draw(camera.getPosition(), hero.getPosition());
	hero.draw(camera.getPosition());
	for (int i = 0; i < shoot.size(); i++) {
        if(shoot[i])
		shoot[i]->draw(camera.getPosition());
	}	
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
	if (key == 'e') {
		Shoot* s = new Shoot();
		s->init(hero);
		shoot.push_back(s);
	}
	if (key == 'w') {
		hero.jump();
	}
	if (key == 'r') {
		if(tilemap.getTileChar(hero.getPosition()) == '/')
		tilemap.textBoxActive();
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
