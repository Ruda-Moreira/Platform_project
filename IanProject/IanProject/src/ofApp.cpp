#include "ofApp.h"
#include "hero.h"
#include "tiro.h"

float before;

Hero hero[2];
Shoot shoot;

//--------------------------------------------------------------
void ofApp::setup() {
	before = ofGetElapsedTimef();
	for (int i = 0; i < 2; i++) {
		heroInit(hero[i]);
	}
	shootInit(shoot);
}

//--------------------------------------------------------------
void ofApp::update() {
	float secs = ofGetElapsedTimef() - before;
	before = ofGetElapsedTimef();

	for (int i = 0; i < 2; i++) {
		heroUpdate(hero[i], secs);
	}
	if (shoot.isShooting) {
		shootUpdate(shoot, hero[0], secs);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	for (int i = 0; i < 2; i++) {
		heroDraw(hero[i]);
		if (shoot.isShooting) {
			shootDraw(shoot, hero[i]);
		}
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == OF_KEY_RIGHT) {
		heroTurnRight(hero[0]);
		heroWalk(hero[0]);
	}
	if (key == OF_KEY_LEFT) {
		heroTurnLeft(hero[0]);
		heroWalk(hero[0]);
	}
	if (key == 'D') {
		heroTurnRight(hero[1]);
		heroWalk(hero[1]);
	}
	if (key == 'A') {
		heroTurnLeft(hero[1]);
		heroWalk(hero[1]);
	}
	if (key == 'x') {
		shoot.isShooting = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	if (key == OF_KEY_LEFT || key == OF_KEY_RIGHT)
	{
		heroStop(hero[0]);
	}
	if (key == 'A' || key == 'D') {
		heroStop(hero[1]);
	}
	if (key == 'x') {
		shoot.isShooting = false;
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
