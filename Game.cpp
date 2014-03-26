#include "Game.h"


Game::Game()
{
}


Game::~Game()
{
}

void Game::update() {
	if (this->screen == Game::INTRO) {
		system("cls");
		cout << " ________         __                           " << endl;
		cout << "|  |  |  |.-----.|  |.----.-----.--------.-----." << endl;
		cout << "|  |  |  ||  -__||  ||  __|  _  |        |  -__|" << endl;
		cout << "|________||_____||__||____|_____|__|__|__|_____|" << endl << endl;
		cout << "L: Login" << endl;
		cout << "R: Register" << endl;
		cout << "Q: Quit" << endl << endl;
		cout << "P: Play (debug)" << endl << endl;
		cout << "Select an action: ";
		char input = cin.get();
		input = tolower(input);

		switch (input) {
		case 'l':
			this->setScreen(Game::LOGIN);
			break;
		case 'r':
			this->setScreen(Game::REGISTER);
			break;
		case 'q':
			this->quitGame();
			break;
		case 'p':
			this->setScreen(Game::PLAY);
			break;
		default:
			cout << "Choice not found" << endl;
			system("pause");
			break;
		}
	}
	else if (this->screen == Game::LOGIN) {
		system("cls");
		PlayerLoader p;
		string user, pass;
		cout << "Login Page" << endl << endl;
		cout << "Username: ";
		cin >> user;
		cout << "Password: ";
		cin >> pass;
		cout << endl;

		cout << p.isLogin(user, pass);
		system("pause");
	}
	else if (this->screen == Game::REGISTER) {
		system("cls");
		PlayerLoader p;
		string user, pass, cpass;
		cout << "Register page" << endl << endl;
		cout << "Username: ";
		cin >> user;
		cout << "Password: ";
		cin >> pass;
		cout << "Confirm Password: ";
		cin >> cpass;
		cout << endl;

		if (pass != cpass) {
			cout << "Your passwords to not match" << endl;
		}
		else if (p.usernameIsTaken(user)) {
			cout << "That user name is taken" << endl;
		}
		else {
			p.createAccount(user, pass);
			this->setScreen(Game::INTRO);
			cout << "Account Created!" << endl;
		}

		cout << endl;
		system("pause");
	}
	else if (this->screen == Game::PLAY) {
		system("cls");
		int input;
		WorldLoader wl;
		cout << "enter world ID, or 1 to goto the welcome room" << endl;
		cin >> input;
		World world = wl.getWorld(input);
		cout << world.getName();
		cout << endl;
		world.displayMap();

		system("pause");
	}
}

void Game::setScreen(int screen) {
	this->screen = screen;
}
