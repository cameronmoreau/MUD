#include "Player.h"

Player::Player() {}

Player::Player(int userId, std::string username) {
	this->userId = userId;
	this->username = username;
}


Player::~Player()
{
}
