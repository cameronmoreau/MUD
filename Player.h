#ifndef Player_h
#define Player_h
#include "WorldObject.h"
#include "PlayerData.h"
#include <string>

class Player : public WorldObject
{
private:
	//Unique variables
	int userId;
	std::string username;

	//Current world
	int worldId;

public:
	Player();
	Player(int userId, std::string username);
	~Player();

	void setPlayerWorldData(PlayerData data);

	std::string getUsername() { return username; };
	int getUserId() { return userId; }
	int getCurrentWorldId() { return worldId; }
};

#endif