//CWH: pragma once is nice, but it is not supported in the c++ standard.  
//Most modern compilers support it, but it is bad to get in the habit of 
//using non standard features
#ifndef Game_h
#define Game_h

//CWH: Nothing in this file references anything in these include files.
//It is good practice to only pull in header files that you are actually using

//CWH: My compiler doesn't like semi-colons after #include statements

//CWH: Don't use any namespace in a header file, especially std: http://www.cplusplus.com/forum/beginner/25538/

class Game
{
private:
	int screen;
	bool running;
        //CWH: adding a clear screen function to avoid system call
        void clearScreen();
public:
	Game();
	~Game();

	void update();
	void setScreen(int screen);
	void quitGame() { running = false; }
	bool isRunning() { return running; }

	enum screen {
		INTRO,
		LOGIN,
		REGISTER,
		PLAY
	};
};
#endif
