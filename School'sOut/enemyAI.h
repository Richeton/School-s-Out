#ifndef _ENEMYAI_H            // Prevent multiple definitions if this 
#define _ENEMYAI_H            // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"

class EnemyAI
{
private:
	//EnemyAI nextAI;
	bool nextMove;

public:
	EnemyAI();
	~EnemyAI();
	bool addAI(EnemyAI ai);
	bool runAI(Entity en);
	virtual bool exeAI(Entity en);
};

#endif