#include "ofApp.h"
#include "hero.h"
#include "tiro.h"
#include "TileMap.h"
#include <vector>

float before;

Hero hero;
Shoot* shoot;
TileMap tilemap;

//coloquei aqui pq pra não colocar no draw, mas tá feio isso ai...


//--------------------------------------------------------------
void ofApp::setup() {
	
	before = ofGetElapsedTimef();
	hero.init(tilemap.getSpawnPoint());
	tilemap.init();
}

//--------------------------------------------------------------
void ofApp::update() {
	float secs = ofGetElapsedTimef() - before;
	before = ofGetElapsedTimef();

	hero.update(secs);
	shoot->update(secs);
	
}

//--------------------------------------------------------------
void ofApp::draw() {
	tilemap.draw();
	hero.draw();

	shoot->draw();
	
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
	if (key == 'D') {
		hero.turnRight();
		hero.walk();
	}
	if (key == 'A') {
		hero.turnLeft();
		hero.walk();
	}
	if (key == 'x') {
		vector<Shoot*> shoots;
		Shoot* shoots = new Shoot();
		shoots.push_back(shoot);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	if (key == OF_KEY_LEFT || key == OF_KEY_RIGHT)
	{
		hero.stop();
	}
	if (key == 'A' || key == 'D') {
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
