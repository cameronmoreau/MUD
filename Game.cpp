#include "Game.h"
#include "PlayerLoader.h"
#include "WorldLoader.h"
#include <iostream>


using namespace std;


//using initilizer lists for your variables
Game::Game()
:screen(INTRO)
,running(true)
{
}


Game::~Game()
{
}

void Game::update() {
	if (this->screen == Game::INTRO) {
                //The system command is evil.  It immediately makes you code impossible to run on other platforms
		clearScreen();
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
                        //CWH: ignore next character
                        cin.ignore();
                        cin.get();
			break;
		}
	}
	else if (this->screen == Game::LOGIN) {
                clearScreen();
		PlayerLoader p;
		string user, pass;
		cout << "Login Page" << endl << endl;
		cout << "Username: ";
		cin >> user;
		cout << "Password: ";
		cin >> pass;
		cout << endl;

		cout << p.isLogin(user, pass);
                //CWH: ignore next character
                cin.ignore();
                cin.get();
	}
	else if (this->screen == Game::REGISTER) {
		clearScreen();
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
		cin.ignore();
                cin.get();
	}
	else if (this->screen == Game::PLAY) {
                clearScreen();
		int input;
		WorldLoader wl;
		cout << "enter world ID, or 1 to goto the welcome room" << endl;
		cin >> input;
		World world = wl.getWorld(input);
		cout << world.getName();
		cout << endl;
		world.displayMap();

		cin.ignore();
                cin.get();
	}
}

void Game::setScreen(int screen) {
	this->screen = screen;
}

//CWH: there isn't a good crossplatform way to clear the screen.
//Grabbed this implementation from: http://www.cplusplus.com/articles/4z18T05o/
void Game::clearScreen() {
	cout << string( 100, '\n' );
}
