#include "World.h"

World::World() {}

World::World(int id, string name, int northId, int eastId, int southId, int westId, char map[12][25]) {
	this->id = id;
	this->name = name;
	this->northId = northId;
	this->eastId = eastId;
	this->southId = southId;
	this->westId = westId;
	
	for (int y = 0; y < 12; y++)
	{
		for (int x = 0; x < 25; x++)
		{
			this->map[y][x] = map[y][x];
		}
	}
}

World::~World()
{
}

void World::displayMap() {
	for (int y = 0; y < 12; y++)
	{
		for (int x = 0; x < 25; x++)
		{
			cout << map[y][x];
		}
		cout << endl;
	}
}

string World::getName() { return name; }
int World::getId() { return id; }

int World::getNorthId() { return northId; }
int World::getEastId() { return eastId; }
int World::getSouthId() { return southId; }
int World::getWestId() { return westId; }
