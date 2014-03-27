//CWH: changed pragmas to ifndef as per standard
#ifndef WorldLoader_h
#define WorldLoader_h

#include "World.h"
#include <string>

struct WorldLinks {
	int n, e, s, w;
};

class WorldLoader
{
private:
        //CWH: change strings to static constants so they don't get allocated every time
	static const std::string atlasPath;
	static const std::string worldsPath;

	WorldLinks setWorldLinks(int id);
public:
	World getWorld(int id);
};

#endif
