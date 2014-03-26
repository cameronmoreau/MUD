#pragma once
#include "Player.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

class PlayerLoader
{
private:
	string playersPath = "res/players/players.txt";
	string playersDataPath = "res/players/players_data.txt";
	int nextId();
public:
	PlayerLoader();
	~PlayerLoader();

	bool isLogin(string user, string pass);
	void createAccount(string user, string pass);
	bool usernameIsTaken(string user);
};

