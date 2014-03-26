#pragma once
#include "PlayerLoader.h";
#include "World.h"
#include "WorldLoader.h"
#include <iostream>

using namespace std;

class Game
{
private:
	int screen;
	bool running = true;
public:
	Game();
	~Game();

	void update();
	void setScreen(int screen);
	void quitGame() { running = false; }
	bool isRunning() { return running; }

	enum screen {
		INTRO,
		LOGIN,
		REGISTER,
		PLAY
	};
};

