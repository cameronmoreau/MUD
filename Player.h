#ifndef Player_h
#define Player_h
#include <string>

class Player
{
private:
	//Unique variables
	int userId;
	std::string username;

	//World positions
	int x, y;
	//Current world
	int worldId;

public:
	Player();
	Player(int userId, std::string username);
	~Player();

	void setWorldId(int worldId) { this->worldId = worldId; }
	//Set players position for the world;
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }

	std::string getUsername() { return username; };
	int getUserId() { return userId; }
	int getCurrentWorldId() { return worldId; }
	int getX() { return x; }
	int getY() { return y; }
};

#endif