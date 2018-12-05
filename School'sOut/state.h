#ifndef _STATE_H            // Prevent multiple definitions if this 
#define _STATE_H            // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"

class Enemy;

class State
{
private:

public:
	State();
	~State();

	virtual void ai(float frameTime, Enemy & ent, Entity & t);

	float getEntityDistXY(Enemy & ent, Entity & t);
	bool isEntityWithinRange(Enemy & ent, Entity & t, float dist);

};

#endif