#pragma once
#include "World.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

struct WorldLinks {
	int n, e, s, w;
};

class WorldLoader
{
private:
	string atlasPath = "res/world/world_atlas.txt";
	string worldsPath = "res/world/worlds.txt";

	WorldLinks setWorldLinks(int id);
public:
	World getWorld(int id);
};

