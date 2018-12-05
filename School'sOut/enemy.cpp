#include "enemy.h"
#include "searchingState.h"

Enemy::Enemy()
{
	setCurrentFrame(16);
	collisionType = entityNS::BOX;
}

Enemy::~Enemy() {}

void Enemy::update(float frameTime)
{
	spriteData.x += this->velocity.x * frameTime;
	spriteData.y += this->velocity.y * frameTime;
	if (getY() <= (GAME_BOUNDARY_YSTART))
		setY((float)GAME_BOUNDARY_YSTART);
	else if (getY() >= (GAME_BOUNDARY_YEND))
		setY((float)GAME_BOUNDARY_YEND - getHeight());
	if (getX() <= (GAME_BOUNDARY_XSTART))
		setX((float)GAME_BOUNDARY_XSTART);
	else if (getX() >= (GAME_BOUNDARY_XEND - getWidth()))
		setX((float)GAME_BOUNDARY_XEND - getWidth());
}

void Enemy::ai(float frameTime, Entity &ent)
{
	Entity::ai(frameTime, ent);
	if (aiState)
	{
		aiState->ai(frameTime, *this, ent);
	}
	else
		setAI(new SearchingState());
}

void Enemy::setAI(State * aiState)
{
	SAFE_DELETE(this->aiState);
	this->aiState = aiState;
}

State* Enemy::getAI()
{
	return aiState;
}

