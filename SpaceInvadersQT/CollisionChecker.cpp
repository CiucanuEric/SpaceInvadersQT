#include "CollisionChecker.h"
#include <iostream>

bool CollisionChecker::isIntersecting(Entity* alien, Entity* projectile)
{
	if ((projectile->getLocation().X<alien->getLocation().X + alien->getSize().H
	&& projectile->getLocation().X>alien->getLocation().X)
	&& (projectile->getLocation().Y > alien->getLocation().Y
	&& projectile->getLocation().Y < alien->getLocation().Y + alien->getSize().W))
	{
		return true;
	}
	return false;
}

bool CollisionChecker::isOutOfBounds(Entity* entity, QRect frame)
{
	if ((entity->getLocation().X<0 || entity->getLocation().X + entity->getSize().W>frame.width())
	|| (entity->getLocation().Y<0 || entity->getLocation().Y + entity->getSize().H>frame.height()))
	{
		return true;
	}
	return false;
}

