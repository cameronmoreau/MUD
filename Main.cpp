#include "Game.h"
#include "GameStateManager.h"
#include "MenuState.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	/*Game game;
	game.setScreen(Game::INTRO);
	while (game.isRunning()) {
		game.update();
	}*/
	GameStateManager game;
	game.init();
	game.changeGameState(MenuState::getInstance());

	while (game.isRunning()) {
		game.draw();
		game.getInput();
	}

	game.cleanup();

	return 0;
}