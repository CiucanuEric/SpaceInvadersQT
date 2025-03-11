#pragma once
#include "Entity.h"
#include "SpaceInvadersWidget.h"
#include <QRect>

class CollisionChecker
{
public:
	static bool isIntersecting(Entity* alien, Entity* projectile);
	static bool isOutOfBounds(Entity* entity,QRect frame);
};