#ifndef _COMBATSTATE_H            // Prevent multiple definitions if this 
#define _COMBATSTATE_H            // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "state.h"
#include "enemy.h"

class Entity;

class CombatState : public State
{
private:
	float attackDuration; // Attack duration
	float tempAttackDuration;
	float attackDist; // Attack Distance
	D3DXVECTOR2 direction;
public:
	CombatState();
	~CombatState();

	void ai(float frameTime, Enemy & ent, Entity & t);
};

#endif