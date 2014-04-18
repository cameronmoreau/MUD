#ifndef WorldObject_h
#define WorldObject_h
class WorldObject
{
protected:
	int x;
	int y;

public:
	int getX() { return x; }
	int getY() { return y; }
	
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
};

#endif