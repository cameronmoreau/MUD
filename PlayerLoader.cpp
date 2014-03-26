#include "PlayerLoader.h"


PlayerLoader::PlayerLoader()
{
}


PlayerLoader::~PlayerLoader()
{
}

bool PlayerLoader::usernameIsTaken(string user) {
	string temp, temp2;
	ifstream file;
	file.open(playersPath);
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
	file.open(playersPath);
	while (!file.eof())
	{
		getline(file, line);
	}
	file.close();
	stringstream ss(line);
	getline(ss, lastId, ':');
	return atoi(lastId.c_str()) + 1;
}

void PlayerLoader::createAccount(string user, string pass) {
	int id = nextId();
	string player = to_string(id) + ":" + user + ":" + pass;
	ofstream file;
	file.open(playersPath, ios::app);
	file << endl << player;
	file.close();
}

bool PlayerLoader::isLogin(string user, string pass) {
	string temp, temp2;
	ifstream file;
	file.open(playersPath);
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