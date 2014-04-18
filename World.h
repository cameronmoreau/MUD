#ifndef World_h
#define World_h
#include <string>
#include <iostream>

using namespace std;

class World
{
private:
	//Static demensions for the stored map
	static const int width;
	static const int height;

	int id;
	string name;
	int northId, eastId, southId, westId;
	char map[12][25];

public:
	World();
	World(int id, string name, int northId, int eastId, int southId, int westId, char map[12][25]);
	~World();

	void displayMap();
	string getName();
	int getId();
	int getNorthId();
	int getEastId();
	int getSouthId();
	int getWestId();

	int getWidth() { return width; }
	int getHeight() { return height; }
};

#endif