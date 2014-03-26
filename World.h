#pragma once
#include <string>
#include <iostream>

using namespace std;

class World
{
private:
	int id;
	string name;
	int northId, eastId, southId, westId;
	char map[8][15];

public:
	World();
	World(int id, string name, int northId, int eastId, int southId, int westId, char map[8][15]);
	~World();

	void displayMap();
	string getName();
	int getId();
	int getNorthId();
	int getEastId();
	int getSouthId();
	int getWestId();
};

