#ifndef MenuState_h
#define MenuState_h

#include "GameState.h"
#include "Player.h"

class MenuState : public GameState
{
private:
	static MenuState gMenuState;

	enum Screen {
		MENU,
		LOGIN,
		REGISTER
	};

	int screen;
	Player *player;

protected:
	MenuState() { }
public:
	void init();
	void cleanup();

	void pause();
	void resume();

	void getInput(GameStateManager *game);
	void draw(GameStateManager *game);

	static MenuState *getInstance() {
		return &gMenuState;
	}
};

#endif