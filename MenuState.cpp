#include "MenuState.h"
#include "GameStateManager.h"
#include "GameState.h"
#include "PlayerLoader.h"
#include <iostream>

MenuState MenuState::gMenuState;

void MenuState::init() {
	int screen = MenuState::MENU;
}
void MenuState::cleanup() {}

void MenuState::pause() {}
void MenuState::resume() {}

void MenuState::getInput(GameStateManager *game) {
	if (this->screen == MenuState::MENU) {
		char input = std::cin.get();
		input = tolower(input);

		switch (input) {
		case 'l':
			this->screen = MenuState::LOGIN;
			break;
		case 'r':
			this->screen = MenuState::REGISTER;
			break;
		case 'q':
			game->quit();
			break;
		default:
			std::cout << "Choice not found" << std::endl;
			std::cin.ignore();
			std::cin.get();
			break;
		}
	}
	else if (this->screen == MenuState::LOGIN) {
		PlayerLoader p;
		std::string user, pass;
		std::cout << "Login Page" << std::endl << std::endl;
		std::cout << "Username: ";
		std::cin >> user;
		std::cout << "Password: ";
		std::cin >> pass;
		std::cout << std::endl;


		//TODO: Add logged in state before pushing to play

		//Username and passworld is correct
		if (p.isLogin(user, pass)) {
			player = new Player(p.getUserId(user), user);
			std::cout << "Welcome, " << player->getUsername() << std::endl;
			std::cout << "Press enter to play" << std::endl;

			//Temperary data
			player->setPlayerWorldData(p.loadPlayerData(player->getUserId()));
			std::cin.ignore();
			std::cin.get();

			//TODO: Load saved data
			//std::setScreen(Game::PLAY);
		}
		else {
			std::cout << "Hmm, looks like an incorrect username or password" << std::endl;
			std::cout << "Press enter to go back to the main menu" << std::endl;
			std::cin.ignore();
			std::cin.get();
			this->screen = MenuState::MENU;
		}
	}
	else if (this->screen == MenuState::REGISTER) {
		PlayerLoader p;
		std::string user, pass, cpass;
		std::cout << "Register page" << std::endl << std::endl;
		std::cout << "Username: ";
		std::cin >> user;
		std::cout << "Password: ";
		std::cin >> pass;
		std::cout << "Confirm Password: ";
		std::cin >> cpass;
		std::cout << std::endl;

		if (pass != cpass) {
			std::cout << "Your passwords to not match" << std::endl;
		}
		else if (p.usernameIsTaken(user)) {
			std::cout << "That user name is taken" << std::endl;
		}
		else {
			p.createAccount(user, pass);
			//this->setScreen(Game::INTRO);
			std::cout << "Account Created!" << std::endl;
		}

		std::cout << std::endl;
		std::cin.ignore();
		std::cin.get();
	}
}

void MenuState::draw(GameStateManager *game) {
	game->clearScreen();
	if (this->screen == MenuState::MENU) {
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
}
