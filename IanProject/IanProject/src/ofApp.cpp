#include "ofApp.h"
#include "hero.h"
#include "tiro.h"

float before;

Hero hero;
Shoot shoot;

//--------------------------------------------------------------
void ofApp::setup() {
	before = ofGetElapsedTimef();
	
		heroInit(hero);
		shootInit(shoot, hero);	
}

//--------------------------------------------------------------
void ofApp::update() {
	float secs = ofGetElapsedTimef() - before;
	before = ofGetElapsedTimef();

		heroUpdate(hero, secs);
	
	if (shoot.isShooting) {
		shootUpdate(shoot, secs);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
		heroDraw(hero);
		if (shoot.isShooting) {
			shootDraw(shoot, hero);
		}
	

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == OF_KEY_RIGHT) {
		heroTurnRight(hero);
		heroWalk(hero);
	}
	if (key == OF_KEY_LEFT) {
		heroTurnLeft(hero);
		heroWalk(hero);
	}
	if (key == 'D') {
		heroTurnRight(hero);
		heroWalk(hero);
	}
	if (key == 'A') {
		heroTurnLeft(hero);
		heroWalk(hero);
	}
	if (key == 'x') {
		shoot.isShooting = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	if (key == OF_KEY_LEFT || key == OF_KEY_RIGHT)
	{
		heroStop(hero);
	}
	if (key == 'A' || key == 'D') {
		heroStop(hero);
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
