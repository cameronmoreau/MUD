#ifndef LoginState_h
#define LoginState_h

#include "GameState.h"
class LoginState : public GameState
{
private:
	static LoginState gLoginState;
protected:
	LoginState() { }
public:
	void init();
	void cleanup();

	void pause();
	void resume();

	void getInput(GameStateManager *game);
	void draw(GameStateManager *game);

	static LoginState *getInstance() {
		return &gLoginState;
	}
};

#endif