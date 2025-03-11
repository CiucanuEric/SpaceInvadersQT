#pragma once
#include "Entity.h"
#include "Projectile.h"

class Player :public Entity
{
private:
	int ammo;
	bool isEmptyAmmo;
public:
	void draw(QPainter* painter);
	void update();
	Projectile shoot();
	Player(int x, int y, int w, int h);
};
