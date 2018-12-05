#include "state.h"
#include "enemy.h"

State::State()
{
}

State::~State()
{
}

void State::ai(float frameTime, Enemy & ent, Entity & t)
{

}

float State::getEntityDistXY(Enemy & ent, Entity & t)
{
	return abs(t.getX() - ent.getX()) + abs(t.getY() - ent.getY());
}

bool State::isEntityWithinRange(Enemy & ent, Entity & t, float dist)
{
	if (getEntityDistXY(ent, t) < dist)
		return true;
	return false;
}