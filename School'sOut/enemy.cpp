#include "enemy.h"

Enemy::Enemy() 
{
};
Enemy::~Enemy() {};

void Enemy::update(float frameTime)
{
	spriteData.x += this->velocity.x * frameTime;
	spriteData.y += this->velocity.y * frameTime;
}

void Enemy::ai(float frameTime, Entity &ent)
{
	Entity::ai(frameTime, ent);

	D3DXVECTOR2 toVector = D3DXVECTOR2(ent.getCenterX() - this->getCenterX(), ent.getCenterY() - this->getCenterY()); // Direction from AI Enemy to Player
	D3DXVECTOR2 vel = D3DXVECTOR2(0,0);
	if (toVector.y > 0)
	{
		vel.y = 75;
	}
	if (toVector.y < 0)
	{
		vel.y = -75;
	}
	if (toVector.x > 0)
	{
		vel.x = 75;
	}
	if (toVector.x < 0)
	{
		vel.x = -75;
	}
	setVelocity(vel);
}

