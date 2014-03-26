#include "Game.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	Game game;
	game.setScreen(Game::INTRO);
	while (game.isRunning()) {
		game.update();
	}
	return 0;
}