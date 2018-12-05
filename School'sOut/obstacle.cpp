#include "obstacle.h"


Obstacle::Obstacle()
{
	collisionType = entityNS::BOX;
}

Obstacle::~Obstacle()
{
}

void Obstacle::update(float frameTime)
{
	Entity::update(frameTime);
}

void Obstacle::collisions()
{
}

