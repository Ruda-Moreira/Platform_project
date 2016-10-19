#include "ofApp.h"
#include "hero.h"
#include "tiro.h"
#include "TileMap.h"
#include <vector>

float before;

Hero hero;
TileMap tilemap;
vector<Shoot*> shoot;
ofVec2f posCamera;


//--------------------------------------------------------------
void ofApp::setup() {
	before = ofGetElapsedTimef();
	//ta dando erro no hero mas eu não mechi nessa função ._.
	hero.init(tilemap.getSpawnPoint(), &tilemap);
	tilemap.init();
}

//--------------------------------------------------------------
void ofApp::update() {
	//camera
	ofVec2f SCREEN_CENTER(ofGetWidth() / 2, ofGetHeight() / 2);
	posCamera = hero.getPosition() - SCREEN_CENTER;

	float maxX = tilemap.getMapWidth() - ofGetWidth();
	float maxY = tilemap.getMapHeight() - ofGetHeight();
	//odiei esse if aqui, quero tirar essa nhaca o quanto antes u_u
	if (posCamera.x <= 0) {
		posCamera.x = 0;
	}
	else if (posCamera.x >= maxX) {
		posCamera.x = maxX;
	}
	if (posCamera.y <= 0) {
		posCamera.y = 0;
	}
	else if (posCamera.y >= maxY) {
		posCamera.y = maxY;
	}


	float secs = ofGetLastFrameTime();

	hero.update(secs);
	for (int i = 0; i < shoot.size(); i++) {
		if(shoot[i])
		shoot[i]->update(secs);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	tilemap.draw(posCamera, hero.getPosition());
	hero.draw(posCamera);
	for (int i = 0; i < shoot.size(); i++) {
        if(shoot[i])
		shoot[i]->draw(posCamera);
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
		//acabei de perceber que quando eu faço a conferência com o getTileChar, ele me retorna
		//a 'p', que é o tile do player. como fazer pra detectar o tile '/' que está na mesma posição ?_?
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
