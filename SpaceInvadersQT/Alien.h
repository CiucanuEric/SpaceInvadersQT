#pragma once
#include "Entity.h"

#define MAX_TIME_SKIP 30
#define MAX_MOVEMENT 5

class Alien :public Entity
{
private:
	unsigned int moveStep = 0;
	bool left = false;
	int timeSkip = 0;
public:
	int score = 5;
	bool isReadyToMove();
	void draw(QPainter* painter);
	void update();
	Alien(int x, int y, int w, int h);

};