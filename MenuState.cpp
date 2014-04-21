#include "MenuState.h"
#include "GameStateManager.h"
#include "GameState.h"
#include <iostream>

MenuState MenuState::gMenuState;

void MenuState::init() {}
void MenuState::cleanup() {}

void MenuState::pause() {}
void MenuState::resume() {}

void MenuState::getInput(GameStateManager *game) {
	std::cin.ignore();
	std::cin.get();
	game->quit();
}

void MenuState::draw(GameStateManager *game) {
	std::cout << "Hello" << std::endl;
}
