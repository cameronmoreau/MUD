#include "PlayerLoader.h"
#include <fstream>
#include <sstream>
//CWH: needed for atoi in my compiler
#include <cstdlib>
#include <string>

//CWH: probably shouldn't even do this, but it is better than putting it in a header
using namespace std;

//CWH: when making something static it is better to initialize it in the cpp file
const std::string PlayerLoader::playersPath = "res/players/players.txt";
const std::string PlayerLoader::playersWorldDataPath = "res/players/players_world_data.txt";
const std::string PlayerLoader::playersDataPath = "res/players/players_data.txt";

PlayerLoader::PlayerLoader()
{
}


PlayerLoader::~PlayerLoader()
{
}

bool PlayerLoader::usernameIsTaken(string user) {
	string temp, temp2;
	ifstream file;
	file.open(playersPath.c_str());
	while (!file.eof()) {
		getline(file, temp);
		stringstream ss(temp);
		getline(ss, temp2, ':');
		getline(ss, temp2, ':');
		if (temp2 == user)
			return true;
	}
	file.close();

	return false;
}

int PlayerLoader::nextId() {
	string line, lastId;
	ifstream file;
	file.open(playersPath.c_str());
	while (!file.eof())
	{
		getline(file, line);
	}
	file.close();
	stringstream ss(line);
	getline(ss, lastId, ':');
	return atoi(lastId.c_str()) + 1;
}

PlayerData PlayerLoader::loadPlayerData(int id) {
	PlayerData data;

	string temp, temp2;
	ifstream file;
	file.open(playersWorldDataPath.c_str());
	while (!file.eof()) {
		getline(file, temp);
		stringstream ss(temp);
		//Get id
		getline(ss, temp2, ':');
		if (id == atoi(temp2.c_str())) {
			//Get last world
			getline(ss, temp2, ':');
			data.worldId = atoi(temp2.c_str());

			//Get last X
			getline(ss, temp2, ':');
			data.x = atoi(temp2.c_str());

			//Get last Y
			getline(ss, temp2, ':');
			data.y = atoi(temp2.c_str());
		}
	}
	file.close();

	return data;
}

void PlayerLoader::createAccount(string user, string pass) {
	int id = nextId();

	//Create player
	string player = to_string(id) + ":" + user + ":" + pass;
	ofstream file;
	file.open(playersPath.c_str(), ios::app);
	file << endl << player;
	file.close();

	//Generate player world data
	//Spawn in welcome spot
	player = to_string(id) + ":1:5:5";
	file.open(playersWorldDataPath.c_str(), ios::app);
	file << endl << player;
	file.close();
}

bool PlayerLoader::isLogin(string user, string pass) {
	string temp, temp2;
	ifstream file;
	file.open(playersPath.c_str());
	while (!file.eof()) {
		getline(file, temp);
		stringstream ss(temp);
		getline(ss, temp2, ':');
		getline(ss, temp2, ':');
		if (temp2 == user) {
			getline(ss, temp2, ':');
			if (temp2 == pass)
				return true;
		}
	}
	file.close();

	return false;
}

int PlayerLoader::getUserId(std::string user) {
	string temp, temp2;
	int tempId;
	ifstream file;
	file.open(playersPath.c_str());
	while (!file.eof()) {
		getline(file, temp);
		stringstream ss(temp);
		//user id
		getline(ss, temp2, ':');
		tempId = atoi(temp2.c_str());
		//username
		getline(ss, temp2, ':');
		if (temp2 == user) {
			return tempId;
		}
	}
	file.close();

	return -1;
}

std::string PlayerLoader::getUsername(int id) {
	string temp, temp2;
	int tempId;
	ifstream file;
	file.open(playersPath.c_str());
	while (!file.eof()) {
		getline(file, temp);
		stringstream ss(temp);
		//user id
		getline(ss, temp2, ':');
		tempId = atoi(temp2.c_str());
		getline(ss, temp2, ':');
		if (tempId == id)
			return temp2;
	}
	file.close();

	return 0;
}
