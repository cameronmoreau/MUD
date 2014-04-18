#include "Player.h"

Player::Player() {}

Player::Player(int userId, std::string username) {
	this->userId = userId;
	this->username = username;
}

void Player::setPlayerWorldData(PlayerData data) {
	this->worldId = data.worldId;
	this->x = data.x;
	this->y = data.y;
}

Player::~Player()
{
}
