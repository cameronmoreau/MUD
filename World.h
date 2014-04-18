#ifndef World_h
#define World_h
#include "Player.h"
#include <string>
#include <iostream>
#include <vector>

class World
{
private:
	int id;
	std::string name;
	int northId, eastId, southId, westId;
	char map[12][25];
	Player *player;

public:
	World();
	World(int id, std::string name, int northId, int eastId, int southId, int westId, char map[12][25]);
	~World();

	void linkPlayer(Player &player) { this->player = &player;  }
	void displayMap();
	std::string getName();
	int getId();
	int getNorthId();
	int getEastId();
	int getSouthId();
	int getWestId();
};

#endif