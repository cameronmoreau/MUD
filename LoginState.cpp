#include "LoginState.h"
#include "GameStateManager.h"
#include "GameState.h"
#include <iostream>

LoginState LoginState::gLoginState;

void LoginState::init() {}
void LoginState::cleanup() {}

void LoginState::pause() {}
void LoginState::resume() {}

void LoginState::getInput(GameStateManager *game) {
	char input = std::cin.get();
	input = tolower(input);

	switch (input) {
	case 'l':
		//this->changeGameState(Game::LOGIN);
		break;
	case 'r':
		//this->changeGameState(Game::REGISTER);
		break;
	case 'q':
		game->quit();
		break;
	case 'p':
		//this->setScreen(Game::PLAY);
		break;
	default:
		std::cout << "Choice not found" << std::endl;
		//CWH: ignore next character
		std::cin.ignore();
		std::cin.get();
		break;
	}
}

void LoginState::draw(GameStateManager *game) {
	game->clearScreen();
	std::cout << " ________         __                           " << std::endl;
	std::cout << "|  |  |  |.-----.|  |.----.-----.--------.-----." << std::endl;
	std::cout << "|  |  |  ||  -__||  ||  __|  _  |        |  -__|" << std::endl;
	std::cout << "|________||_____||__||____|_____|__|__|__|_____|" << std::endl << std::endl;
	std::cout << "L: Login" << std::endl;
	std::cout << "R: Register" << std::endl;
	std::cout << "Q: Quit" << std::endl << std::endl;
	std::cout << "P: Play (debug)" << std::endl << std::endl;
	std::cout << "Select an action: ";
}
