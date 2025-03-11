#pragma once
#include <Qpixmap.h>
#include <string>
#include <QPainter>

using namespace std;


struct Location
{
	int X, Y;
};

struct Size
{
	int W, H;
};

class Entity
{
private:
	int hitpoints;
	Location loc;
	int moveSpeed;
	Size size;
public:
	int getHP() { return hitpoints; };
	void setHP(int HP) { hitpoints = HP; };
	Size getSize() { return size; };
	void setSize(Size newSize) { size = newSize; };
	Location getLocation() { return loc; };
	void setMoveSpeed(int newMoveSpeed) { moveSpeed = newMoveSpeed; };
	int getMoveSpeed() { return moveSpeed; };
	void setLocation(Location newLocation) { loc = newLocation; };
	virtual void draw(QPainter* painter) = 0;
	virtual void update() = 0;
	Entity(int x, int y, int w, int h);

};