#include "Alien.h"

void Alien::draw(QPainter* painter)
{
	painter->drawRect(getLocation().X, getLocation().Y, getSize().W, getSize().H);
}
void Alien::update()
{
	if (isReadyToMove())
	{
		if (left)
		{
			setLocation({ getLocation().X - getMoveSpeed(),getLocation().Y });
			moveStep--;
		}
		else
		{
			setLocation({ getLocation().X + getMoveSpeed(),getLocation().Y });
			moveStep++;
		}
	}
	if (moveStep >= MAX_MOVEMENT)
	{
		left = true;
	}
	else if (moveStep <= 0)
	{
		left = false;
	}

}

bool Alien::isReadyToMove()
{
	if (timeSkip < MAX_TIME_SKIP)
	{
		timeSkip++;
		return false;
	}
	timeSkip = 0;
	return true;
}

Alien::Alien(int x, int y, int w, int h) : Entity(x,y,w,h)
{
	setMoveSpeed(5);
}