#include "WorldLoader.h"

World WorldLoader::getWorld(int id) {
	string name, temp, temp2;
	World world;
	ifstream file;
	int counter = 0;
	char map[8][15];
	file.open(worldsPath);
	while (!file.eof())
	{
		counter++;
		getline(file, temp);
		if (counter == 1)
		{
			stringstream ss(temp);
			getline(ss, name, ':');
			if (name == to_string(id)) {
				getline(ss, name, ':');
				for (int y = 0; y < 8; y++)
				{
					getline(file, temp2);
					for (int x = 0; x < 15; x++)
					{
						map[y][x] = temp2[x];
					}
				}
				WorldLinks wl = setWorldLinks(id);
				world = World(id, name, wl.n, wl.e, wl.s, wl.w, map);
				file.seekg(0, ios_base::end);
			}
		}
		else if (counter == 9)
		{
			counter = 0;
		}
	}
	file.close();

	return world;
}

WorldLinks WorldLoader::setWorldLinks(int id) {
	WorldLinks wl;
	string temp, temp2, temp3;
	ifstream file;
	file.open(atlasPath);
	while (!file.eof()) {
		getline(file, temp);
		stringstream ss(temp);
		getline(ss, temp2, ':');
		if (temp2 == to_string(id)) {
			getline(ss, temp2, ':');
			stringstream ss(temp2);
			getline(ss, temp3, ',');
			wl.n = atoi(temp3.c_str());
			getline(ss, temp3, ',');
			wl.e = atoi(temp3.c_str());
			getline(ss, temp3, ',');
			wl.s = atoi(temp3.c_str());
			getline(ss, temp3, ',');
			wl.w = atoi(temp3.c_str());
			file.seekg(0, ios_base::end);
		}
	}
	return wl;
}