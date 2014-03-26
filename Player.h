#pragma once
#include <string>

using namespace std;

class Player
{
private:
	string username;
public:
	Player(string username);
	~Player();

	string getUsername() { return username; };
};

