#include "Projectile.h"

Projectile::Projectile(int x, int y, int speed, int w=1, int h=10) : Entity(x,y,w,h)
{
	setMoveSpeed(speed);
}

void Projectile::draw(QPainter* painter)
{
	painter->drawLine(getLocation().X, getLocation().Y, getLocation().X, getLocation().Y + getSize().H);
}

void Projectile::update()
{
	setLocation({ getLocation().X,getLocation().Y -  getMoveSpeed() });
}