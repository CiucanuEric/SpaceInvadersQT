#pragma once

#include "Entity.h"

class Projectile :public Entity
{
public:
	Projectile(int x, int y, int speed, int w, int h);
	void draw(QPainter* painter);
	void update();
};