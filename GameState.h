#ifndef GameState_h
#define GameState_h

#include "GameStateManager.h"

class GameState {
public:
	virtual void init() = 0;
	virtual void cleanup() = 0;

	virtual void pause() = 0;
	virtual void resume() = 0;

	virtual void getInput(GameStateManager *game) = 0;
	virtual void draw(GameStateManager *game) = 0;

	void changeGameState(GameStateManager *game, GameState *state) {
		game->changeGameState(state);
	}
protected:
	GameState() {}
};

#endif GameState_h