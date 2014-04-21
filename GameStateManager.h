#ifndef GameStateManager_h
#define GameStateManager_h

#include <vector>

class GameState;

class GameStateManager
{
private:
	bool running;
	std::vector<GameState *> states;

public:
	void init();
	void cleanup();

	void changeGameState(GameState *state);
	void pushGameState(GameState *state);
	void popGameState();

	void getInput();
	void draw();

	bool isRunning() { return running; }
	void quit() { this->running = false; }

	void clearScreen();
};

#endif