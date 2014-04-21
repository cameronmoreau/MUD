#include "GameStateManager.h"
#include "GameState.h"

void GameStateManager::init() {
	running = true;
}

void GameStateManager::cleanup() {
	//Clean up remaining states
	while (!states.empty()) {
		states.back()->cleanup();
		states.pop_back();
	}
}

void GameStateManager::changeGameState(GameState *state) {
	//Cleanup current states
	if (!states.empty()) {
		states.back()->cleanup();
		states.pop_back();
	}

	//Add and init new state
	states.push_back(state);
	states.back()->init();
}

void GameStateManager::pushGameState(GameState *state) {
	//Pause the current state
	if (!states.empty()) {
		states.back()->pause();
	}

	//Add and init the new state
	states.push_back(state);
	states.back()->init();
}
void GameStateManager::popGameState() {
	//Cleanup current state
	if (!states.empty()) {
		states.back()->cleanup();
		states.pop_back();
	}

	//Resume last state
	if (!states.empty()) {
		states.back()->resume();
	}
}

void GameStateManager::getInput() {
	states.back()->getInput(this);
}

void GameStateManager::draw() {
	states.back()->draw(this);
}
