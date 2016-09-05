#include "ofApp.h"

//declarando estado de jogo
string game_state;
int r = 0;

//declarando Player
struct Player
{
	float posX, posY;
	int animaR = 0, animaL = 0;
	bool walkL = false, walkR = true, jump = false;

	bool keyLeft, keyRight, keySpace;
};
//declarando Player pt2
Player player;


//--------------------------------------------------------------
void ofApp::setup() {

	P1.load("images/P1.png");
	P2.load("images/P2.png");
	P3.load("images/P3.png");
	P4.load("images/P4.png");
	P5.load("images/P5.png");
	P6.load("images/P6.png");
	P7.load("images/P7.png");
	P8.load("images/P8.png");

	//estado de jogo
	game_state = "game";

	//Player position
	player.posX = 200;
	player.posY = 300;

}

//--------------------------------------------------------------
void ofApp::update() {
	ofSleepMillis(10);/*Lara, isso aqui é porque em cada PC roda em uma velocidade diferente.
					  Se ficar muito lento, pode apagar ou diminuir o número.*/

#pragma region PlayerMove
	if (game_state == "game")
	{
		if (player.keyLeft == true)
		{
			player.posX -= 5.0;
			player.animaL++;
			player.walkL = true;
			player.walkR = false;
		}

		if (player.keyRight == true)
		{
			player.posX += 5.0;
			player.animaR++;
			player.walkR = true;
			player.walkL = false;
		}

		if (player.keySpace == true)
		{
			if (r <= 40)
			{
				player.posY -= 20 - r;
				r++;
			}
			else
			{
				player.keySpace = false;
				r = 0;
			}
		}

	}
#pragma endregion
}

//--------------------------------------------------------------
void ofApp::draw() {
	//O código desse pulo tá bem fajuto, vai ter que fazer de novo
#pragma region PlayerJump
	if (player.keySpace == true)
	{
		if (player.walkR == true)
		{
			P2.draw(player.posX, player.posY, 15);
		}
		if (player.walkL == true)
		{
			P5.draw(player.posX, player.posY, 15);
		}
	}
#pragma endregion
	//Não sei se tem um jeito certo de fazer animação. Eu fiz assim e deu certo, mas fique à vontade pra mudar.
#pragma region PlayerWalkRight
	if (player.walkR == true && player.keySpace == false)
	{
		if (player.animaR == 0)
		{
			P1.draw(player.posX, player.posY, 15);
		}
		if (player.animaR <= 10 && player.animaR > 0)
		{
			P2.draw(player.posX, player.posY, 15);
		}
		if (player.animaR <= 20 && player.animaR > 10)
		{
			P1.draw(player.posX, player.posY, 15);
		}
		if (player.animaR <= 30 && player.animaR > 20)
		{
			P3.draw(player.posX, player.posY, 15);
		}
		if (player.animaR >= 30)
		{
			player.animaR = 0;
			P1.draw(player.posX, player.posY, 15);
		}
	}
#pragma endregion
#pragma region PlayerWalkLeft

	if (player.walkL == true && player.keySpace == false)
	{
		if (player.animaL == 0)
		{
			P4.draw(player.posX, player.posY, 15);
		}
		if (player.animaL <= 10 && player.animaL > 0)
		{
			P5.draw(player.posX, player.posY, 15);
		}
		if (player.animaL <= 20 && player.animaL > 10)
		{
			P4.draw(player.posX, player.posY, 15);
		}
		if (player.animaL <= 30 && player.animaL > 20)
		{
			P6.draw(player.posX, player.posY, 15);
		}
		if (player.animaL >= 30)
		{
			player.animaL = 0;
			P4.draw(player.posX, player.posY, 15);
		}
	}
#pragma endregion

	//Aí falta fazer ele atirar e rolar. Acho que o código pra rolar é quase o mesmo do que pra andar, só que com sprites diferentes.
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

	//pegando input
	if (game_state == "game")
	{
		if (key == OF_KEY_LEFT)
			player.keyLeft = true;
		if (key == OF_KEY_RIGHT)
			player.keyRight = true;
		if (key == OF_KEY_UP && player.jump == false)
		{
			player.keySpace = true;
			player.jump = true;
		}
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

	//pegando input
	if (game_state == "game")
	{
		if (key == OF_KEY_LEFT)
		{
			player.keyLeft = false;
			player.animaL = 0;
		}

		if (key == OF_KEY_RIGHT)
		{
			player.keyRight = false;
			player.animaR = 0;
		}

		if (key == OF_KEY_UP)
			player.jump = false;
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