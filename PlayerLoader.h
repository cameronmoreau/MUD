#ifndef PlayerLoader_h
#define PlayerLoader_h

//CWH: unnecessary include files removed.  You don't want to pull in dependencies
//unless you are using them in the file you pull them into

#include <string>

class PlayerLoader
{
private:
        //CWH: These constants should be static so they don't get allocated for each instance of you class
	static const std::string playersPath;
	static const std::string playersDataPath;
	int nextId();
public:
	PlayerLoader();
	~PlayerLoader();

	//Login based functions
	bool isLogin(std::string user, std::string pass);
	void createAccount(std::string user, std::string pass);
	bool usernameIsTaken(std::string user);

	//User based function
	int getUserId(std::string user);
	std::string getUsername(int id);
};

#endif
